//
// Created by isabe on 03/10/2019.
//
#include <ctime>
#include <list>
#include <string>
#include "ContaCorrente.h"

#include <sstream>
#include <iostream>
#include "Lancamento.h"

using namespace std;

int ContaCorrente::NumeroGlobal = 0;
double ContaCorrente::MontanteTotal = 0;

ContaCorrente::ContaCorrente(string cpf_cliente) {
	NumeroGlobal++;
	Numero = NumeroGlobal; // contador de conta corrente: cada vez que instanciar a classe, gera um novo numero de conta (evita contas com numeração repetida)
	CPFcliente = cpf_cliente;
	SaldoAtual = 0;
	DataAbertura = time(0); //retorna a data atual
	LimiteChequeEspecial = 100.00; //limite inicial 
}

ContaCorrente::~ContaCorrente() {
	NumeroGlobal--;
	MontanteTotal -= getSaldoAtual();
}


//debita o valor da conta
bool ContaCorrente::debitoConta(float valor, time_t data) {
	if (SaldoAtual + LimiteChequeEspecial < valor) {
		return false;
	}
	Lancamento* lancamento = new Lancamento("debito", valor, SaldoAtual);
	//inserção da operação no extrato
	if (data != 0) {
		lancamento->setDataLancamento(data);
	}
	lista_lancamentos.push_front(lancamento);
	//realização do debito em conta
	setSaldoAtual(SaldoAtual - valor);
	//atualização do montante total do banco


	MontanteTotal -= valor;
	return true;
}

//credita um valor na conta
void ContaCorrente::creditoConta(float valor, time_t data) {
	Lancamento* lancamento = new Lancamento("credito", valor, SaldoAtual);
	//inserção da operação no extrato
	if (data != 0) {
		lancamento->setDataLancamento(data);
	}
	lista_lancamentos.push_front(lancamento);
	//realização do credito em conta
	setSaldoAtual(SaldoAtual + valor);
	//atualização do montante total do banco


	MontanteTotal += valor;
}

bool ContaCorrente::FazerLancamento(int tipo, float valor, time_t data) {
	switch (tipo) {
	case 1: {
		return debitoConta(valor, data);
		break;
	}
	case 2: {
		creditoConta(valor, data);
		return true;
		break;
	}
	}
	return true;

}

void ContaCorrente::imprimeExtrato(time_t inicial, time_t final) {
	if (final < inicial) {
		return;
	}
	float SaldoInicial, SaldoFinal;
	bool primeiro = false;
	for (auto& lancamento : this->getLancamentos()) {
		if (lancamento->getDataLancamento() >= inicial && lancamento->getDataLancamento()<= final) {
			if (primeiro == false) {
				primeiro = true;
				SaldoInicial = lancamento->getSaldoAnterior();
			}
			if (lancamento->getType() == "debito") {
				cout << lancamento->getDataLancamento() << ":" << lancamento->getValor()<< endl;
				SaldoFinal = lancamento->getSaldoAnterior() - lancamento->getValor();
			}
			else if (lancamento->getType() == "credito") {
				cout << lancamento->getDataLancamento()<< ":" << lancamento->getValor()<< endl;
				SaldoFinal = lancamento->getSaldoAnterior()+ lancamento->getValor();
			}
		}
	}
	if (primeiro == false) {
		cout << "Não há lançamentos neste intervalo";
	}
	else {
		cout << "Saldo Final: " << SaldoFinal;
	}
}

list<Lancamento*> ContaCorrente::getLancamentos() {
	return lista_lancamentos;
}

int ContaCorrente::GetNumero() {
	return Numero;
}


//getters e setters
const string& ContaCorrente::getCpFcliente() const {
	return CPFcliente;
}

void ContaCorrente::setCpFcliente(const string& cpFcliente) {
	CPFcliente = cpFcliente;
}

char* ContaCorrente::getDataAbertura() const {
	return (char*)ctime(&DataAbertura);
}

void ContaCorrente::setDataAbertura(time_t dataAbertura) {
	DataAbertura = dataAbertura;
}

float ContaCorrente::getSaldoAtual() const {
	return SaldoAtual;
}

void ContaCorrente::setSaldoAtual(float saldoAtual) {
	SaldoAtual = saldoAtual;

}

float ContaCorrente::getLimiteChequeEspecial() const
{
	return LimiteChequeEspecial;
}

void ContaCorrente::setLimiteChequeEspecial(float limiteChequeEspecial)
{
	LimiteChequeEspecial = limiteChequeEspecial;
}



string ContaCorrente::toString() const {
	string result;
	ostringstream sContaCorrente;
	sContaCorrente << endl << " Numero: " << this->Numero << endl
		<< " CPF Cliente: " << this->CPFcliente << endl
		<< fixed << " Saldo Atual: " << this->SaldoAtual << endl
		<< " Limite Cheque Especial: " << this->LimiteChequeEspecial << endl
		<< " Data de Abertura: " << this->getDataAbertura() << endl;
	result = sContaCorrente.str();

	return result;


}

int ContaCorrente::getQuantidadeContas() {
	return NumeroGlobal;
}

float ContaCorrente::getMontanteTotal() {
	return MontanteTotal;
}
