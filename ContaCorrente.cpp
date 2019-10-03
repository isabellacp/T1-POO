//
// Created by isabe on 03/10/2019.
//

#include "ContaCorrente.h"
int ContaCorrente::NumeroGlobal =0;
ContaCorrente::ContaCorrente(string cpf_cliente)  {
    Numero = NumeroGlobal++; // contador de conta corrente: cada vez que instanciar a classe, gera um novo numero de conta (evita contas com numeração repetida)
    CPFcliente = cpf_cliente;
    SaldoAtual = 0;
    DataAbertura = time(0); //retorna a data atual
}

char *ContaCorrente::GetDataAbertura() {
    return (char *) ctime(&DataAbertura);
}

void ContaCorrente::FazerLancamento() {

}

void ContaCorrente::ImprimirExtrato(){

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

