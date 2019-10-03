//
// Created by isabe on 03/10/2019.
//

#ifndef T1_POO_CONTACORRENTE_H
#define T1_POO_CONTACORRENTE_H

#include <ctime>
#include <string>

using  namespace std;

struct LANCAMENTO{
    string tipo;
    int valor;
    time_t DataLancamento;
};

class ContaCorrente {
public:
    //construtor
    ContaCorrente(string cpf_cliente);
    //getter - retorna uma representação em string da data de abertura da conta
    char *GetDataAbertura();
    int GetNumero();
    void FazerLancamento();
    void ImprimirExtrato();
    void AlterarDados(string cpf_cliente);
    string toString();

    const string &getCpFcliente() const;

    void setCpFcliente(const string &cpFcliente);

    time_t getDataAbertura() const;

    void setDataAbertura(time_t dataAbertura);

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
