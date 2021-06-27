#include "Pessoa.hpp"

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
    void SetListaPrioridade(int *listaPrioridade);

private:
    int capacidade;
    int numeroPessoasAlocadas;
    int *idPessoasAlocadas;
    int localizacaoX;
    int localizacaoY;
    int *listaPrioridade;
    int RetornaPosicaoPessoa(int idPessoa);
};