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

    if(NumeroGlobal > 0) NumeroGlobal--;
	MontanteTotal -= getSaldoAtual();
	setSaldoAtual(0);
}


//debita o valor da conta
bool ContaCorrente::debitoConta(double valor, tm data) {
	if (SaldoAtual + LimiteChequeEspecial < valor) {
		return false;
	}
	Lancamento* lancamento = new Lancamento("debito", valor, SaldoAtual);
	//inserção da operação no extrato
	
	lancamento->setDataLancamento(data);
	
	lista_lancamentos.push_back(lancamento);
	//realização do debito em conta
	setSaldoAtual(SaldoAtual - valor);
	//atualização do montante total do banco


	MontanteTotal -= valor;
	return true;
}

//credita um valor na conta
void ContaCorrente::creditoConta(double valor, tm data) {
	Lancamento* lancamento = new Lancamento("credito", valor, SaldoAtual);
	//inserção da operação no extrato
	
		lancamento->setDataLancamento(data);
	
	lista_lancamentos.push_back(lancamento);
	//realização do credito em conta
	setSaldoAtual(SaldoAtual + valor);
	//atualização do montante total do banco


	MontanteTotal += valor;
}

bool ContaCorrente::FazerLancamento(int tipo, double valor, tm data) {
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
bool ContaCorrente::FazerLancamento(int tipo, double valor) {
    time_t t = time(0); 
	tm* agora = localtime(&t);
	return FazerLancamento(tipo, valor, *agora);

}

void ContaCorrente::imprimeExtrato(tm inicial_struct, tm final_struct) {

	time_t final = mktime(&final_struct);
	time_t inicial = mktime(&inicial_struct);

	if (final < inicial) {
		return;
	}
	double SaldoInicial, SaldoFinal;
	bool primeiro = false;
	for (auto& lancamento : this->getLancamentos()) {
	    tm tmCopy = lancamento->getDataLancamento();
		time_t dataLancamento = mktime(&tmCopy);

		if (dataLancamento >= inicial && dataLancamento <= final) {
			if (primeiro == false) {
				primeiro = true;
				SaldoInicial = lancamento->getSaldoAnterior();
			}
			if (lancamento->getType() == "debito") {
				cout << "Debito de " << lancamento->getValor()<< " em "<< ctime(&dataLancamento);
				SaldoFinal = lancamento->getSaldoAnterior() - lancamento->getValor();
			}
			else if (lancamento->getType() == "credito") {
                cout << "Credito de " << lancamento->getValor()<< " em "<< ctime(&dataLancamento);
				SaldoFinal = lancamento->getSaldoAnterior()+ lancamento->getValor();
			}
		}
	}
	if (primeiro == false) {
		cout << "Não há lançamentos neste intervalo";
	}
	else {
        cout << "Saldo Inicial: " << SaldoInicial <<endl;

        cout << "Saldo Final: " << SaldoFinal <<endl;
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

tm ContaCorrente::getDataAbertura() const {
	return *localtime(&DataAbertura);
}

void ContaCorrente::setDataAbertura(tm dataAbertura) {
	DataAbertura = mktime(&dataAbertura);
}

double ContaCorrente::getSaldoAtual() const {
	return SaldoAtual;
}

void ContaCorrente::setSaldoAtual(double saldoAtual) {
	SaldoAtual = saldoAtual;

}

double ContaCorrente::getLimiteChequeEspecial() const
{
	return LimiteChequeEspecial;
}

void ContaCorrente::setLimiteChequeEspecial(double limiteChequeEspecial)
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
		<< " Data de Abertura: " << ctime(&this->DataAbertura) << endl;
	result = sContaCorrente.str();

	return result;


}

int ContaCorrente::getQuantidadeContas() {
	return NumeroGlobal;
}

double ContaCorrente::getMontanteTotal() {
	return MontanteTotal;
}
