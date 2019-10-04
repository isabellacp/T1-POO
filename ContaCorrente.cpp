//
// Created by isabe on 03/10/2019.
//

#include <string>
#include "ContaCorrente.h"
int ContaCorrente::NumeroGlobal =0;
ContaCorrente::ContaCorrente(string cpf_cliente) {
    Numero = NumeroGlobal++; // contador de conta corrente: cada vez que instanciar a classe, gera um novo numero de conta (evita contas com numeração repetida)
    CPFcliente = cpf_cliente;
    SaldoAtual = 0;
    DataAbertura = time(0); //retorna a data atual
}



char *ContaCorrente::GetDataAbertura() {
    return (char *) ctime(&DataAbertura);
}



void ContaCorrente::FazerLancamento(int tipo, float valor) {
    switch (tipo) {
        case 1: {
            SaldoAtual = debitoConta(valor);
            case 2: {
                SaldoAtual = creditoConta(valor);
            }
        }
    }
}
    void ContaCorrente::ImprimirExtrato() {

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
//debita o valor da conta
    float ContaCorrente::debitoConta(float valor) {
        return SaldoAtual -= valor;
    }
//credita um valor na conta
    float ContaCorrente::creditoConta(float valor) {
        return SaldoAtual += valor;
    }

    void ContaCorrente::AlterarDados(string cpf_cliente) {

    }

    string ContaCorrente::toString() {
        return string();
    }
