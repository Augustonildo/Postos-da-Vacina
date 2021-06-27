#include "Posto.hpp"
#include <iostream>
#include <math.h>

using namespace std;
Posto::Posto() {}

Posto::Posto(int id, int capacidade, int localizacaoX, int localizacaoY)
{
    this->id = id;
    this->capacidade = capacidade;
    this->numeroPessoasAlocadas = 0;
    this->idPessoasAlocadas = (int *)malloc(capacidade * sizeof(int));
    this->localizacaoX = localizacaoX;
    this->localizacaoY = localizacaoY;
}

Posto::~Posto() {}

float Posto::DistanciaPessoa(Pessoa pessoa)
{
    int pessoa_X = pessoa.GetLocalizacaoX();
    int pessoa_Y = pessoa.GetLocalizacaoY();

    return sqrt((pow((pessoa_X - this->localizacaoX), 2)) + (pow((pessoa_Y - this->localizacaoY), 2)));
}

int Posto::RetornaPosicaoPessoa(int idPessoa)
{
    int i = 0;
    while (true)
    {
        if (listaPrioridade[i] == idPessoa)
            return i;
        i++;
    }
    return -1;
}

bool Posto::AlocarPessoaParaVacinacao(int idPessoa)
{
    if (capacidade == numeroPessoasAlocadas)
    {
        int maiorPosicaoNaFilaPrioridade = -1;
        int pessoaMenosPrioritariaAlocada = -1;
        for (int i = 0; i < capacidade; i++)
        {
            int posicaoPessoaAtual = RetornaPosicaoPessoa(listaPrioridade[i]);
            if (posicaoPessoaAtual > maiorPosicaoNaFilaPrioridade)
            {
                maiorPosicaoNaFilaPrioridade = posicaoPessoaAtual;
                pessoaMenosPrioritariaAlocada = listaPrioridade[i];
            }
        }

        int posicaoNaFilaPrioridadeNovaPessoa = RetornaPosicaoPessoa(idPessoa);
        if (posicaoNaFilaPrioridadeNovaPessoa < maiorPosicaoNaFilaPrioridade)
        {
            DesalocarPessoaParaVacinacao(pessoaMenosPrioritariaAlocada);
            return AlocarPessoaParaVacinacao(idPessoa);
        }
        return false;
    }
    idPessoasAlocadas[numeroPessoasAlocadas] = idPessoa;
    numeroPessoasAlocadas++;

    //TODO: REMOVER INSTRUÇÃO DE TESTE
    cout << "Alocada pessoa " << idPessoa << " no posto " << this->id << endl;
    return true;
}

void Posto::DesalocarPessoaParaVacinacao(int idPessoa)
{
    int posicaoPessoa;
    for (int i = 0; i < capacidade; i++)
    {
        if (idPessoasAlocadas[i] == idPessoa)
        {
            posicaoPessoa = i;
            break;
        }
    }

    for (int i = posicaoPessoa; i < capacidade - 1; i++)
    {
        idPessoasAlocadas[i] = idPessoasAlocadas[i + 1];
    }

    numeroPessoasAlocadas--;
    //TODO: REMOVER INSTRUÇÃO DE TESTE
    cout << "Desalocada pessoa " << idPessoa << " do posto " << this->id << endl;
}

void Posto::ListarPessoasAlocadas()
{
    for (int i = 0; i < numeroPessoasAlocadas; i++)
    {
        cout << idPessoasAlocadas[i] << " ";
    }
    cout << endl;
}

int Posto::GetCapacidade()
{
    return this->capacidade;
}

void Posto::SetListaPrioridade(int *listaPrioridade)
{
    this->listaPrioridade = listaPrioridade;
}