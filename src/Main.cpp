#include "Posto.hpp"
#include <algorithm>

using namespace std;

struct Distancia_Posto_Pessoa
{
    int distancia;
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
        pessoas[i] = Pessoa(i, idade, localizacaoX, localizacaoY, numeroPostos);

        Distancia_Posto_Pessoa dist[numeroPostos];
        for (int j = 0; j < numeroPostos; j++)
        {
            dist[j].distancia = postos[j].DistanciaPessoa(pessoas[i]);
            dist[j].idPosto = postos[j].id;
        }

        sort(dist, dist + numeroPostos, ordenarMaisProximo);
        int listaIdPostosOrdenado[numeroPostos];
        for (int j = 0; j < numeroPostos; j++)
        {
            pessoas[i].SetListaPostosProximos(listaIdPostosOrdenado);
        }
    }

    //Ordenando lista pessoas em ordem decrescente.
    //Essa lista também funcionará como lista de prioridade geral
    sort(pessoas, pessoas + numeroPessoas, ordenarMaisVelho);

    int numeroAlocados = 0;
    while (numeroAlocados < numeroPessoas && numeroAlocados < capacidadeTotalPostos)
    {
        for (int i = 0; i < numeroPostos; i++)
        {
            for (int j = 0; j < numeroPessoas; j++)
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
                    postos[idPostoAlocadoAtual].DesalocarPessoaParaVacinacao(pessoas[j].id);
                    postos[i].AlocarPessoaParaVacinacao(pessoas[j].id);
                    pessoas[j].SetIdPostoAlocado(postos[i].id);
                }
            }
        }
    }

    for (int i = 0; i < numeroPostos; i++)
    {
        cout << postos[i].id << endl;
        postos[i].ListarPessoasAlocadas();
    }
    return 0;
}