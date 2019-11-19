//
// Created by isabe on 03/10/2019.
//

#ifndef T1_POO_CONTACORRENTE_H
#define T1_POO_CONTACORRENTE_H

#include <ctime>
#include <string>
#include <list>
#include <iostream>
using  namespace std;

struct Lancamento{
    string type;
    float valor = 0;
    time_t DataLancamento = time (0);
	float SaldoAnterior; 

};


class ContaCorrente {
public:
    //construtor
    ContaCorrente(string cpf_cliente);

    ~ContaCorrente();
    list <struct Lancamento>  lista_lancamentos; //struct que armazena dados sobre as operações feitas nas contas
    char *GetDataAbertura();    //getter - retorna uma representação em string da data de abertura da conta
    int GetNumero();
    bool FazerLancamento(int, float);
    list <struct Lancamento> getLista_lancamentos(); //getter - retorna o extrato
    bool debitoConta (float);
    void creditoConta (float);
    static int getQuantidadeContas();
    static float getMontanteTotal();
    void imprimeExtrato(time_t, time_t);
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

	//getter e setter para o LimiteChequeEspecial
	float getLimiteChequeEspecial() const;
	void setLimiteChequeEspecial(float limiteChequeEspecial);



private:
    static int NumeroGlobal;
    static float MontanteTotal;
    int Numero;
    string CPFcliente;
    time_t DataAbertura;
    float SaldoAtual;
	float LimiteChequeEspecial;

};



#endif //T1_POO_CONTACORRENTE_H
