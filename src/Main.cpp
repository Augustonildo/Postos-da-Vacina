#include "Posto.hpp"
#include <algorithm>
#include <iostream>

using namespace std;

struct Distancia_Posto_Pessoa
{
    float distancia;
    int idPosto;
} typedef Distancia_Posto_Pessoa;

bool ordenarMaisVelho(Pessoa a, Pessoa b) { return (a.GetIdade() > b.GetIdade()); }

bool ordenarMaisProximo(Distancia_Posto_Pessoa c, Distancia_Posto_Pessoa d) { return (c.distancia < d.distancia); }

int main(int argc, char *argv[])
{
    int numeroPostos, numeroPessoas, capacidadeTotalPostos = 0;
    cin >> numeroPostos;
    Posto postos[numeroPostos];

    for (int i = 0; i < numeroPostos; i++)
    {
        int capacidade, localizacaoX, localizacaoY;
        cin >> capacidade >> localizacaoX >> localizacaoY;
        postos[i] = Posto(i, capacidade, localizacaoX, localizacaoY);
        capacidadeTotalPostos += capacidade;
    }

    cin >> numeroPessoas;
    Pessoa pessoas[numeroPessoas];
    for (int i = 0; i < numeroPessoas; i++)
    {
        int idade, localizacaoX, localizacaoY;
        cin >> idade >> localizacaoX >> localizacaoY;
        pessoas[i] = Pessoa(i, idade, localizacaoX, localizacaoY);

        Distancia_Posto_Pessoa dist[numeroPostos];
        for (int j = 0; j < numeroPostos; j++)
        {
            dist[j].distancia = postos[j].DistanciaPessoa(pessoas[i]);
            dist[j].idPosto = postos[j].id;
        }

        stable_sort(dist, dist + numeroPostos, ordenarMaisProximo);
        int listaIdPostosOrdenado[numeroPostos];
        for (int j = 0; j < numeroPostos; j++)
        {
            listaIdPostosOrdenado[j] = dist[j].idPosto;
        }
        pessoas[i].SetListaPostosProximos(listaIdPostosOrdenado, numeroPostos);
    }

    //Ordenando lista pessoas em ordem decrescente.
    //Essa lista também funcionará como lista de prioridade geral
    stable_sort(pessoas, pessoas + numeroPessoas, ordenarMaisVelho);

    //Cria lista de prioridades somente com id de pessoa
    int idPessoasPrioridade[numeroPessoas];
    for (int i = 0; i < numeroPessoas; i++)
    {
        idPessoasPrioridade[i] = pessoas[i].id;
    }

    //Informa lista de prioridade para cada um dos postos
    for (int i = 0; i < numeroPostos; i++)
    {
        postos[i].SetListaPrioridade(idPessoasPrioridade);
    }

    int numeroAlocados = 0;
    while (numeroAlocados < numeroPessoas && numeroAlocados < capacidadeTotalPostos)
    {
        for (int j = 0; j < numeroPessoas; j++)
        {
            for (int i = 0; i < numeroPostos; i++)
            {
                int idPostoAlocadoAtual = pessoas[j].GetIdPostoAlocado();
                if (idPostoAlocadoAtual == -1)
                {
                    if (postos[i].AlocarPessoaParaVacinacao(pessoas[j].id))
                    {
                        pessoas[j].SetIdPostoAlocado(postos[i].id);
                        numeroAlocados++;
                    }
                }
                else if (pessoas[j].PreferePostoNovoAoAlocado(postos[i].id))
                {
                    if (postos[i].AlocarPessoaParaVacinacao(pessoas[j].id))
                    {
                        postos[idPostoAlocadoAtual].DesalocarPessoaParaVacinacao(pessoas[j].id);
                        pessoas[j].SetIdPostoAlocado(postos[i].id);
                    }
                }
            }
        }
    }

    for (int i = 0; i < numeroPostos; i++)
    {
        postos[i].ListarPessoasAlocadas();
    }
    return 0;
}