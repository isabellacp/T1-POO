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
	bool debitoConta(float);
	void creditoConta(float);
	bool FazerLancamento(int, float);
	void imprimeExtrato(time_t inicial, time_t final);
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
	float getSaldoAtual() const;
	void setSaldoAtual(float saldoAtual);
private:
	static int NumeroGlobalP; //controla o numero da conta
	static double MontanteTotalP;
	int NumeroP;  //numero da conta
	string CPFcliente;
	time_t DataAbertura;
	float SaldoAtualP;
};


#endif /* CONTAPOUPANCA_H */

