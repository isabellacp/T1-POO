//
// Created by isabe on 03/10/2019.
//

#ifndef T1_POO_CONTACORRENTE_H
#define T1_POO_CONTACORRENTE_H

#include <ctime>
#include <string>
#include <list>
#include <sstream>
#include "Lancamento.h"

using  namespace std;



class ContaCorrente {
public:
    //construtor
    ContaCorrente(string cpf_cliente);

    ~ContaCorrente();
	list <Lancamento*>  lista_lancamentos; //struct que armazena dados sobre as operações feitas nas contas
    int GetNumero();
	bool FazerLancamento(int, double);

    bool FazerLancamento(int, double, tm data);
    list <Lancamento*> getLancamentos(); //getter - retorna o extrato
    bool debitoConta (double, tm);
    void creditoConta (double, tm);
    static int getQuantidadeContas();
    static double getMontanteTotal();
    void imprimeExtrato(tm, tm);
    string toString() const;

    //getter e setter para o CPF do cliente
    const string &getCpFcliente() const;
    void setCpFcliente(const string &cpFcliente);

    //getter e setter para a Data de Abertura da conta
    tm getDataAbertura() const;
    void setDataAbertura(tm dataAbertura);

    //getter e setter para o SaldoAtual
    double getSaldoAtual() const;
    void setSaldoAtual(double saldoAtual);

	//getter e setter para o LimiteChequeEspecial
	double getLimiteChequeEspecial() const;
	void setLimiteChequeEspecial(double limiteChequeEspecial);



private:
    static int NumeroGlobal;
    static double MontanteTotal;
    int Numero;
    string CPFcliente;
    time_t DataAbertura;
    double SaldoAtual;
	double LimiteChequeEspecial;

};



#endif //T1_POO_CONTACORRENTE_H
