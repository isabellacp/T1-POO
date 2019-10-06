//
// Created by isabe on 03/10/2019.
//

#include <string>
#include "ContaCorrente.h"

int ContaCorrente::NumeroGlobal = 0;
float ContaCorrente::MontanteTotal = 0;

ContaCorrente::ContaCorrente(string cpf_cliente) {
    Numero = ++NumeroGlobal; // contador de conta corrente: cada vez que instanciar a classe, gera um novo numero de conta (evita contas com numeração repetida)
    CPFcliente = cpf_cliente;
    SaldoAtual = 0;
    DataAbertura = time(0); //retorna a data atual
}

//debita o valor da conta
bool ContaCorrente::debitoConta(float valor) {
    if (SaldoAtual < valor){
        return false;
    }
    struct Lancamento lanc;
    //inserção da operação no extrato
    lanc.type = "debito";
    lanc.valor = valor;
    extrato.push_front(lanc);
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
    extrato.push_front(lanc);
    //realização do credito em conta
    setSaldoAtual(SaldoAtual + valor);
    //atualização do montante total do banco
    MontanteTotal += valor;
}

void ContaCorrente::FazerLancamento(int tipo, float valor) {
    switch (tipo) {
        case 1: {
            debitoConta(valor);
            break;
        }
        case 2: {
            creditoConta(valor);
            break;
        }
    }
}

//retorna o extrato
list <struct Lancamento> ContaCorrente::getExtrato() {
    return extrato;
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
char *ContaCorrente::GetDataAbertura() {
    return (char *) ctime(&DataAbertura);
}

string ContaCorrente::toString() {
    return string();
}

 int ContaCorrente::getQuantidadeContas (){
    return NumeroGlobal;
}

int ContaCorrente::getMontanteTotal() {
    return MontanteTotal;
}
