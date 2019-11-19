 //
// Created by isabe on 03/10/2019.
//

#include <string>
#include "ContaCorrente.h"

using namespace std;

int ContaCorrente::NumeroGlobal = 0;
float ContaCorrente::MontanteTotal = 0;

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
bool ContaCorrente::debitoConta(float valor) {
    if (SaldoAtual+LimiteChequeEspecial < valor) {
        return false;
    }
    struct Lancamento lanc;
    //inserção da operação no extrato
    lanc.type = "debito";
    lanc.valor = valor;
	lanc.SaldoAnterior = SaldoAtual; 
    lista_lancamentos.push_front(lanc);
    //realização do debito em conta
    setSaldoAtual(SaldoAtual - valor);
    //atualização do montante total do banco
    MontanteTotal -= valor;
    return true;
}

//credita um valor na conta
void ContaCorrente::creditoConta(float valor) {
    struct Lancamento lanc;
    //inserção da operação no extrato
    lanc.type = "credito";
    lanc.valor = valor;
	lanc.SaldoAnterior = SaldoAtual;
    lista_lancamentos.push_front(lanc);
    //realização do credito em conta
    setSaldoAtual(SaldoAtual + valor);
    //atualização do montante total do banco
    MontanteTotal += valor;
}

bool ContaCorrente::FazerLancamento(int tipo, float valor) {
    switch (tipo) {
        case 1: {
            return debitoConta(valor);
            break;
        }
        case 2: {
            creditoConta(valor);
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

time_t ContaCorrente::getDataAbertura() const {
    return DataAbertura;
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

char *ContaCorrente::GetDataAbertura() {
    return (char *) ctime(&DataAbertura);
}

string ContaCorrente::toString() {
    return "Conta: " + to_string(Numero) + " CPF: " + CPFcliente + " Saldo: " + to_string(SaldoAtual) + " Limite de Cheque Especial:" + to_string (LimiteChequeEspecial);
}

int ContaCorrente::getQuantidadeContas() {
    return NumeroGlobal;
}

float ContaCorrente::getMontanteTotal() {
    return MontanteTotal;
}
