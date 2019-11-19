#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H


#include <list>
#include <ctime>

#include "Cliente.h"
using namespace std;

struct LancamentoP{
    string typeP;
    float valorP = 0;
    time_t DataLancamentoP = time (0);
	float SaldoAnteriorP= 0; 

};

class ContaPoupanca{
public:
	//construtor
	ContaPoupanca(string cpf_cliente);
	//destrutor
	~ContaPoupanca();

	list <struct LancamentoP> extratoP;

	//retorna o numero da conta
	int GetNumero();
	bool debitoConta(float);
	void creditoConta(float);
	bool FazerLancamento(int, float);
	//retorna o extrato
	list <struct LancamentoP> getExtrato();
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

