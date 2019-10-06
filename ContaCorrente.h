//
// Created by isabe on 03/10/2019.
//

#ifndef T1_POO_CONTACORRENTE_H
#define T1_POO_CONTACORRENTE_H

#include <ctime>
#include <string>
#include  <list>
using  namespace std;

struct Lancamento{
    string type;
    float valor = 0;
    time_t DataLancamento = time (0);

};


class ContaCorrente {
public:
    //construtor
    ContaCorrente(string cpf_cliente);

    list <struct Lancamento>  extrato; //struct que armazena dados sobre as operações feitas nas contas
    char *GetDataAbertura();    //getter - retorna uma representação em string da data de abertura da conta
    int GetNumero();
    void FazerLancamento(int, float);
    list <struct Lancamento> getExtrato(); //getter - retorna o extrato
    bool debitoConta (float);
    void creditoConta (float);
    static int getQuantidadeContas();
    static int getMontanteTotal();
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
    static float MontanteTotal;
    int Numero;
    string CPFcliente;
    time_t DataAbertura;
    float SaldoAtual;


};



#endif //T1_POO_CONTACORRENTE_H