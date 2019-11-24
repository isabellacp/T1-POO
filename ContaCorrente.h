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
	bool FazerLancamento(int, float);

    bool FazerLancamento(int, float, tm data);
    list <Lancamento*> getLancamentos(); //getter - retorna o extrato
    bool debitoConta (float, tm);
    void creditoConta (float, tm);
    static int getQuantidadeContas();
    static float getMontanteTotal();
    void imprimeExtrato(tm, tm);
    string toString() const;

    //getter e setter para o CPF do cliente
    const string &getCpFcliente() const;
    void setCpFcliente(const string &cpFcliente);

    //getter e setter para a Data de Abertura da conta
    tm getDataAbertura() const;
    void setDataAbertura(tm dataAbertura);

    //getter e setter para o SaldoAtual
    float getSaldoAtual() const;
    void setSaldoAtual(float saldoAtual);

	//getter e setter para o LimiteChequeEspecial
	float getLimiteChequeEspecial() const;
	void setLimiteChequeEspecial(float limiteChequeEspecial);



private:
    static int NumeroGlobal;
    static double MontanteTotal;
    int Numero;
    string CPFcliente;
    time_t DataAbertura;
    float SaldoAtual;
	float LimiteChequeEspecial;

};



#endif //T1_POO_CONTACORRENTE_H
