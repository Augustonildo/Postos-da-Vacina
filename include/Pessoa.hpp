class Pessoa
{
public:
    int id;
    Pessoa();
    Pessoa(int id, int idade, int localizacaoX, int localizacaoY);
    ~Pessoa();
    bool PreferePostoNovoAoAlocado(int idPosto);
    int GetIdade();
    int GetLocalizacaoX();
    int GetLocalizacaoY();
    int GetIdPostoAlocado();
    void SetIdPostoAlocado(int idPosto);
    void SetListaPostosProximos(int *listaPostosProximos, int tamanho);

private:
    int idade;
    int localizacaoX;
    int localizacaoY;
    int idPostoAlocado;
    int *listaPostosProximos;
    int RetornaPosicaoPosto(int idPosto);
};