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
        if(cpf_cliente == CPF ){
            NumeroGlobalP++;
            NumeroP = NumeroGlobalP;
            CPFcliente = cpf_cliente;
            SaldoAtualP = 0;
            DataAbertura = time(0);
        }
} 

//destrutor
ContaPoupanca::~ContaPoupanca(){
        NumeroGlobalP--;
        MontanteTotalP -= getSaldoAtual();
}
    

//retorna data de abertura da conta
time_t ContaPoupanca::getDataAbertura() const{
    return this->DataAbertura;
}

//retorna numero da conta
int ContaPoupanca::GetNumero() {
    return NumeroP;
}

//debita o valor da conta
bool ContaPoupanca::debitoConta(float valorP) {
    struct LancamentoP lancP;
    //inserção da operação no extrato
    lancP.type = "debito";
    lancP.valorP = valorP;
	lancP.SaldoAnteriorP = SaldoAtualP; 
    extratoP.push_front(lancP);
    //realização do debito em conta
    setSaldoAtual(SaldoAtualP - valorP);
    //atualização do montante total do banco
    MontanteTotalP -= valorP;
    return true;
}

//credita um valor na conta
void ContaPoupanca::creditoConta(float valorP) {
    struct LancamentoP lancP;
    //inserção da operação no extrato
    lancP.type = "credito";
    lancP.valorP = valorP;
	lancP.SaldoAnteriorP = SaldoAtualP;
    extratoP.push_front(lancP);
    //realização do credito em conta
    setSaldoAtual(SaldoAtualP + valorP);
    //atualização do montante total do banco
    MontanteTotalP += valorP;
}

//retorna se o lancamento eh feito
bool ContaPoupanca::FazerLancamento(int tipo, float valorP){
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
list<struct LancamentoP> ContaPoupanca::getExtrato() {
    return extratoP;
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
    sContaPoupanca  << "Número da conta: " <<
                    << this->NumeroP << endl
                    << "Data de abertura: " <<
                    << this->DataAbertura << endl
                    << "CPF: " <<
                    << this->CPFcliente << endl
                    << "Saldo atual: " <<
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
time_t ContaPoupanca::getDataAbertura() const {
    return this->DataAbertura;
}

//define a data
void ContaPoupanca::setDataAbertura(time_t dataAbertura) {
    DataAbertura = dataAbertura;
}

//retorna o saldo total atual
float ContaPoupanca::getSaldoAtual() const {
    return SaldoAtualP;
}

//define o saldo atual 
void ContaPoupanca::setSaldoAtual(float saldoAtual) {
    SaldoAtualP = saldoAtual;

}


