#include "Pessoa.hpp"
#include <iostream>

using namespace std;

class Posto
{
public:
    int id;
    Posto();
    Posto(int id, int capacidade, int localizacaoX, int localizacaoY);
    ~Posto();
    float DistanciaPessoa(Pessoa pessoa);
    bool AlocarPessoaParaVacinacao(int idPessoa);
    void DesalocarPessoaParaVacinacao(int idPessoa);
    void ListarPessoasAlocadas();
    int GetCapacidade();

private:
    int capacidade;
    int numeroPessoasAlocadas;
    int *idPessoasAlocadas;
    int localizacaoX;
    int localizacaoY;
};