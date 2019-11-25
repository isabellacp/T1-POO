#include <list>
#include <ctime>
#include <string>
#include <sstream>

#include "ContaPoupanca.h"
#include "Cliente.h"
using namespace std;

//controla o numero da conta poupanca
int ContaPoupanca::NumeroGlobalP = 0;
//guarda o montante total das contas poupanca
double ContaPoupanca::MontanteTotalP = 0;

//construtor
ContaPoupanca::ContaPoupanca(string cpf_cliente){
        
            NumeroGlobalP++;
            NumeroP = NumeroGlobalP;
            CPFcliente = cpf_cliente;
            SaldoAtualP = 0;
            DataAbertura = time(0);
        
} 

//destrutor
ContaPoupanca::~ContaPoupanca(){

    if(NumeroGlobalP > 0) NumeroGlobalP--;
    MontanteTotalP -= getSaldoAtual();
    setSaldoAtual(0);

}
    


//retorna numero da conta
int ContaPoupanca::GetNumero() {
    return NumeroP;
}

//debita o valor da conta
bool ContaPoupanca::debitoConta(double valor) {
    if ( getSaldoAtual() < valor) {
        return false;
    }
	Lancamento* lancamento = new Lancamento("debito", valor, SaldoAtualP);

	lancamentos.push_back(lancamento);
	//realização de debito em conta
	setSaldoAtual(SaldoAtualP - valor);
	//atualização do montante total do banco
	MontanteTotalP -= valor;
    return true;
}

//credita um valor na conta
void ContaPoupanca::creditoConta(double valor) {
    Lancamento* lancamento = new Lancamento("credito", valor,  SaldoAtualP);

    lancamentos.push_back(lancamento);
    //realização do credito em conta
    setSaldoAtual(SaldoAtualP + valor);
    //atualização do montante total do banco
    MontanteTotalP += valor;
}

//retorna se o lancamento eh feito
bool ContaPoupanca::FazerLancamento(int tipo, double valorP){
	switch (tipo) {
	case 1: {
		return debitoConta(valorP);
		break;
	}
	case 2: {
		creditoConta(valorP);
		return true;
		break;
	}
	}
	return true;
}


//retorna o extrato
list<Lancamento*> ContaPoupanca::getLancamentos() {
    return lancamentos;
}

//retorna a quantidade de contas poupanca
int ContaPoupanca::getQuantidadeContasP() {
    return NumeroGlobalP;
}

//retorna o montante total das contas poupanca
double ContaPoupanca::getMontanteTotal() {
    return MontanteTotalP;
}

string ContaPoupanca::toString() const{
    string result;
    ostringstream sContaPoupanca;  
    sContaPoupanca  << endl<<"Número da conta: "
                    << this->NumeroP << endl
                    << "Data de abertura: "
                    << this->getDataAbertura() 
                    << "CPF: "
                    << this->CPFcliente << endl
					<< fixed << "Saldo atual: "
                    << this->SaldoAtualP;
	result = sContaPoupanca.str();
	return result;
}

//retorna o cpf do cliente
const string &ContaPoupanca::getCpfCliente() const{
    return CPFcliente;
}

//obtem o cpf
void ContaPoupanca::setCpfCliente(const string &cpFcliente) {
    CPFcliente = cpFcliente;
}

//retorna a data de abertura da conta
char* ContaPoupanca::getDataAbertura() const {
	return (char*)ctime(&DataAbertura);
}

//define a data
void ContaPoupanca::setDataAbertura(time_t dataAbertura) {
    DataAbertura = dataAbertura;
}

//retorna o saldo total atual
double ContaPoupanca::getSaldoAtual() const {
    return SaldoAtualP;
}

//define o saldo atual 
void ContaPoupanca::setSaldoAtual(double saldoAtual) {
    SaldoAtualP = saldoAtual;

}

void ContaPoupanca::imprimeExtrato(tm inicial_t, tm final_t) {
	time_t inicial = mktime(&inicial_t);
	time_t final = mktime(&final_t);

	 if (final < inicial) {
		return;
	}
	double SaldoInicial, SaldoFinal;
	bool primeiro = false;
	for (auto& lancamento : this->getLancamentos()) {
		time_t dataLancamento = mktime(&lancamento->getDataLancamento());
		if (dataLancamento >= inicial && dataLancamento <= final) {
			if (primeiro == false) {
				primeiro = true;
				SaldoInicial = lancamento->getSaldoAnterior();
			}
			if (lancamento->getType()== "debito") {
				cout << dataLancamento << ":" << lancamento->getValor() << endl;
				SaldoFinal = lancamento->getSaldoAnterior() - lancamento->getValor();
			}
			else if (lancamento->getType() == "credito") {
				cout << dataLancamento << ":" << lancamento->getValor() << endl;
				SaldoFinal = lancamento->getSaldoAnterior() + lancamento->getValor();
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

