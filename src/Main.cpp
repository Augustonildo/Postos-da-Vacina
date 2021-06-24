#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

int main(int argc, char* argv[]) {
    istringstream stream;
    string nomeArquivo;
    cin >> nomeArquivo;
    ifstream arquivoComandos(nomeArquivo);
    string linhaArquivo, codificacao, decodificacao;

    if(arquivoComandos.is_open()) {
        getline(arquivoComandos, linhaArquivo);
        while(getline(arquivoComandos, linhaArquivo)) { }
        arquivoComandos.close();
    } else {
        cout << "Erro! Arquivo " << nomeArquivo << " não foi encontrado" << endl;
        return -1;
    }
    return 0;
}