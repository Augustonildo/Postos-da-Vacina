#include "Posto.hpp"
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

    return sqrt(((pessoa_X - this->localizacaoX) ^ 2) + ((pessoa_Y - this->localizacaoY) ^ 2));
}

bool Posto::AlocarPessoaParaVacinacao(int idPessoa)
{
    if (capacidade <= numeroPessoasAlocadas)
    {
        return false;
    }
    idPessoasAlocadas[numeroPessoasAlocadas] = idPessoa;
    numeroPessoasAlocadas++;
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
