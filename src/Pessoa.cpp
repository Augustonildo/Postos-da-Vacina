#include "Pessoa.hpp"
#include <stdlib.h>

Pessoa::Pessoa() {}

Pessoa::Pessoa(int id, int idade, int localizacaoX, int localizacaoY, int tamanhoListaPostoProximo)
{
    this->id = id;
    this->idade = idade;
    this->localizacaoX = localizacaoX;
    this->localizacaoY = localizacaoY;
    this->idPostoAlocado = -1;
    this->tamanhoListaPostoProximo = tamanhoListaPostoProximo;
}

Pessoa::~Pessoa() {}

int Pessoa::RetornaPosicaoPosto(int idPosto)
{
    for (int i = 0; i < tamanhoListaPostoProximo; i++)
    {
        if (listaPostosProximos[i] == idPosto)
            return i;
    }
    return -1;
}

bool Pessoa::PreferePostoNovoAoAlocado(int idPosto)
{
    if (RetornaPosicaoPosto(idPosto) < RetornaPosicaoPosto(idPostoAlocado))
    {
        idPostoAlocado = idPosto;
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

void Pessoa::SetListaPostosProximos(int *listaPostosProximos)
{
    this->listaPostosProximos = listaPostosProximos;
}