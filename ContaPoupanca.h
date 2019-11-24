#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H


#include <list>
#include <ctime>
#include <string>
#include <iostream>

#include "Cliente.h"
#include "Lancamento.h"
using namespace std;


class ContaPoupanca{
public:
	//construtor
	ContaPoupanca(string cpf_cliente);
	//destrutor
	~ContaPoupanca();

	list <Lancamento*> lancamentos;

	//retorna o numero da conta
	int GetNumero();
	bool debitoConta(double);
	void creditoConta(double);
	bool FazerLancamento(int, double);
	void imprimeExtrato(tm inicial, tm final);
	//retorna o extrato
	list <Lancamento*> getLancamentos();
	static int getQuantidadeContasP();
	static double getMontanteTotal();
	string toString() const;

	//getter e setter para o CPF do cliente
	const string& getCpfCliente() const;
	void setCpfCliente(const string& cpfCliente);


	//getter e setter para a Data de Abertura da conta
	char* getDataAbertura() const;
	void setDataAbertura(time_t dataAbertura);

	//setter e getter para o saldoAtual
	double getSaldoAtual() const;
	void setSaldoAtual(double saldoAtual);
private:
	static int NumeroGlobalP; //controla o numero da conta
	static double MontanteTotalP;
	int NumeroP;  //numero da conta
	string CPFcliente;
	time_t DataAbertura;
	double SaldoAtualP;
};


#endif /* CONTAPOUPANCA_H */

