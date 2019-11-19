 //
// Created by isabe on 03/10/2019.
//

#include <string>
#include "ContaCorrente.h"
#include <iostream>
#include <sstream>

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
    if (SaldoAtual+LimiteChequeEspecial < valor) {
        return false;
    }
    struct Lancamento lanc;
    //inserção da operação no extrato
    lanc.type = "debito";
    lanc.valor = valor;
    if (data != 0) { 
        lanc.DataLancamento = data;
    }
	lanc.SaldoAnterior = SaldoAtual; 
    lista_lancamentos.push_front(lanc);
    //realização do debito em conta
    setSaldoAtual(SaldoAtual - valor);
    //atualização do montante total do banco
    MontanteTotal -= valor;
    return true;
}

//credita um valor na conta
void ContaCorrente::creditoConta(float valor, time_t data) {
    struct Lancamento lanc;
    //inserção da operação no extrato
    lanc.type = "credito";
    lanc.valor = valor;
    if (data != 0) { 
        lanc.DataLancamento = data;
    }
	lanc.SaldoAnterior = SaldoAtual;
    lista_lancamentos.push_front(lanc);
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

void ContaCorrente::imprimeExtrato(time_t inicial, time_t final){
    if(final < inicial){
        return;
    }
    float SaldoInicial, SaldoFinal;
    bool primeiro = false;
    for (auto &Lancamento : this->getLista_lancamentos()) {
        if(Lancamento.DataLancamento >= inicial && Lancamento.DataLancamento <= final){
            if (primeiro == false){
                primeiro = true;
                SaldoInicial = Lancamento.SaldoAnterior;
            }
            if (Lancamento.type == "debito"){
                cout << Lancamento.DataLancamento << ":" << Lancamento.valor << endl;
                SaldoFinal = Lancamento.SaldoAnterior - Lancamento.valor;
            }
            else if (Lancamento.type == "credito"){
                cout << Lancamento.DataLancamento << ":" << Lancamento.valor << endl;
                SaldoFinal = Lancamento.SaldoAnterior + Lancamento.valor;
            } 
        }
    }
    if (primeiro == false){
        cout << "Não há lançamentos neste intervalo";
    }
    else{
        cout << "Saldo Final: " << SaldoFinal;
    }
}

//retorna o extrato
list<struct Lancamento> ContaCorrente::getLista_lancamentos() {
    return lista_lancamentos;
}

int ContaCorrente::GetNumero() {
    return Numero;
}


//getters e setters
const string &ContaCorrente::getCpFcliente() const {
    return CPFcliente;
}

void ContaCorrente::setCpFcliente(const string &cpFcliente) {
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
