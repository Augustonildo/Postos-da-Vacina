#include "Pessoa.hpp"
#include <iostream>

using namespace std;

Pessoa::Pessoa() {}

Pessoa::Pessoa(int id, int idade, int localizacaoX, int localizacaoY)
{
    this->id = id;
    this->idade = idade;
    this->localizacaoX = localizacaoX;
    this->localizacaoY = localizacaoY;
    this->idPostoAlocado = -1;
}

Pessoa::~Pessoa() {}

int Pessoa::RetornaPosicaoPosto(int idPosto)
{
    int i = 0;
    while (true)
    {
        if (listaPostosProximos[i] == idPosto)
            return i;
        i++;
    }
    return -1;
}

bool Pessoa::PreferePostoNovoAoAlocado(int idPosto)
{
    if (RetornaPosicaoPosto(idPosto) < RetornaPosicaoPosto(idPostoAlocado))
    {
        return true;
    }
    return false;
}

int Pessoa::GetIdade()
{
    return idade;
}

int Pessoa::GetLocalizacaoX()
{
    return localizacaoX;
}

int Pessoa::GetLocalizacaoY()
{
    return localizacaoY;
}

int Pessoa::GetIdPostoAlocado()
{
    return idPostoAlocado;
}

void Pessoa::SetIdPostoAlocado(int idPosto)
{
    this->idPostoAlocado = idPosto;
}

void Pessoa::SetListaPostosProximos(int *listaPostosProximos, int tamanho)
{
    this->listaPostosProximos = (int *)malloc(tamanho * sizeof(int));
    for (int i = 0; i < tamanho; i++)
    {
        this->listaPostosProximos[i] = listaPostosProximos[i];
    }
}