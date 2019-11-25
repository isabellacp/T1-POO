
#ifndef JURIDICO_H
#define JURIDICO_H
#include <string>
#include <ctime>
#include "Cliente.h"


using namespace std;

//classe juridico que herda cliente
class Juridico : public Cliente {
public:
    Juridico (string nome, string cpf, string endereco, string telefone, string 
    email, string cnpj, string atuacao, string funcao, string atualizacao); //construtor
    ~Juridico();
    //getters e setters
    const string &getCnpj() const;
    void setCnpj (const string);
    const string &getAtuacao() const;
    void setAtuacao (string);
    const string &getFuncao() const;
    void setFuncao (string);
    const string &getAtualizacao() const;
    void setAtualizacao (string);
    static int getTotalClientesJuridico();
	string toString() const;
    static void resetTotal();

private: 
    static int TotalClientesJuridico; 
    int NumeroClienteJuridico; 
    string Cnpj;
    string Atuacao;
    string Funcao;
    string Atualizacao;

};

#endif /* JURIDICO_H */

