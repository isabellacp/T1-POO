//
// Created by isabe on 03/10/2019.
//

#ifndef T1_POO_CONTACORRENTE_H
#define T1_POO_CONTACORRENTE_H

#include <ctime>
#include <string>

using  namespace std;

struct List{
    string type;
    int valor = 0;
    time_t DataLancamento = time (0);
    int size=0; ///tamanho do array
    string array[sizeof(size)];
};

class ContaCorrente {
public:
    //construtor
    ContaCorrente(string cpf_cliente);

    struct List  ext;

    //getter - retorna uma representação em string da data de abertura da conta
    char *GetDataAbertura();
    int GetNumero();
    void FazerLancamento(int, float);
    void ImprimirExtrato();
    void AlterarDados(string cpf_cliente);
    float debitoConta (float);
    float creditoConta (float);
    string toString();

    //getter e setter para o CPF do cliente
    const string &getCpFcliente() const;
    void setCpFcliente(const string &cpFcliente);

    //getter e setter para a Data de Abertura da conta
    time_t getDataAbertura() const;
    void setDataAbertura(time_t dataAbertura);

    //getter e setter para o SaldoAtual
    float getSaldoAtual() const;
    void setSaldoAtual(float saldoAtual);



private:
    static int NumeroGlobal;
    int Numero;
    string CPFcliente;
    time_t DataAbertura;
    float SaldoAtual;

};



#endif //T1_POO_CONTACORRENTE_H
