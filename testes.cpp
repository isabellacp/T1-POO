#include <list>
#include <string>
#include "ContaCorrente.h"
#include "Cliente.h"
#include "Juridico.h"
#include "ContaPoupanca.h"
#include <iostream>
#include "Menu.h"

void RodarTeste1() {
    list<Cliente *> ListaDeClientes;            //lista de clientes físicos
    list<Juridico *> ListaClientesJur;        //lista de clientes jur
    list<ContaCorrente *> ListaDeContas;    //lista de contas correntes
    list<ContaPoupanca *> ListaContasPoup; //lista de contas poupança
    bool sair = false;
    //Cenario de Teste C1
    cout << " ----------------CENARIO DE TESTE 1-------------------- " << endl;

    //Pessoa Física 01
    string nomePF1 = "pessoa fisica 1", cpfPF1 = "1101", enderecoPF1 = "pf street, 100 ", telefonePF1 = "123456789", emailPF1 = "fulano@detal.com";
    Cliente *pf1 = new Cliente(nomePF1, cpfPF1, enderecoPF1, telefonePF1, emailPF1);
    ListaDeClientes.push_front(pf1); //adicionando o novo cliente na lista de clientes
    cout << "Cliente Criado: Pessoa Física 01" << pf1->toString() << endl;
    ContaCorrente *ccPessoaF1 = new ContaCorrente(cpfPF1); //criando Conta Corrente para a Pessoa Física 01
    ListaDeContas.push_front(ccPessoaF1); //adicionando a nova conta na lista de contas correntes
    ccPessoaF1->FazerLancamento(2, 100.00); //creditando 100 reais na conta

    cout << "Conta Corrente criada para Pessoa Física 01:" << ccPessoaF1->toString() << endl;
    //criar poupança para PF1
    ContaPoupanca *cpPessoaF1 = new ContaPoupanca(cpfPF1);
    ListaContasPoup.push_front(cpPessoaF1);
    cpPessoaF1->FazerLancamento(2, 200); // CREDITA 200 REAIS NA CONTA POUPANÇA

    cout << "Conta Poupança criada para Pessoa Física 01:" << cpPessoaF1->toString() << endl;

    //Pessoa Física 02
    string nomePF2 = "pessoa fisica 2", cpfPF2 = "1102", enderecoPF2 = "pf street, 200 ", telefonePF2 = "7891011", emailPF2 = "fulano2@detal.com";
    Cliente *pf2 = new Cliente(nomePF2, cpfPF2, enderecoPF2, telefonePF2, emailPF2);
    ListaDeClientes.push_front(pf2);
    cout << "Cliente Criado: Pessoa Física 02" << pf2->toString() << endl;
    ContaCorrente *ccPessoaF2 = new ContaCorrente(cpfPF2);
    ListaDeContas.push_front(ccPessoaF2);
    cout << "Conta Corrente criada para Pessoa Física 02:" << ccPessoaF2->toString() << endl;

    //cria poupança para PF02
    ContaPoupanca *cpPessoaF2 = new ContaPoupanca(cpfPF2);
    ListaContasPoup.push_front(cpPessoaF2);
    cpPessoaF1->FazerLancamento(2, 50); //creditando 50 reais na conta poupança
    cout << "Conta Poupança criada para Pessoa Física 02:" << cpPessoaF2->toString() << endl;


    //listar clientes fisicos
    cout << "Total de Clientes Físicos Cadastrados:" << endl;
    cout << Cliente::getTotalClientesFisico() << endl;
    //listar clientes juridicos
    cout << "Total de Clientes Juridicos Cadastrados:" << endl;
    cout << Juridico::getTotalClientesJuridico() << endl;
    //listar contas correntes
    cout << "Total de Contas Correntes:" << endl;
    cout << ContaCorrente::getQuantidadeContas() << endl;
    //listar contas poupança
    cout << "Total de Contas Poupança:" << endl;
    cout << ContaPoupanca::getQuantidadeContasP() << endl;

    //Pessoa Juridica 01 (vinculado à Pessoa Física 01)
    string nomePJ1 = "pessoa juridica 01", telefonePJ1 = "13579", emailPJ1 = "empresa1@fulano.com", cnpjPJ1 = "1201", atuacaoPJ1 = "comercio", funcaoPJ1 = "detal", atualizacaoPJ1 = "10/01/2005";
    Juridico *pj1 = new Juridico(nomePF2, cpfPF1, enderecoPF1, telefonePJ1, emailPJ1, cnpjPJ1, atuacaoPJ1, funcaoPJ1,
                                 atualizacaoPJ1);
    ListaClientesJur.push_front(pj1);
    cout << "Cliente Criado: Pessoa JurÍdica 01" << pj1->toString() << endl;
    ContaCorrente *ccPessoaJ1 = new ContaCorrente(cnpjPJ1); //criando Conta Corrente para a Pessoa Jurídica 01
    ListaDeContas.push_front(ccPessoaJ1); //adicionando a nova conta na lista de contas correntes
    ccPessoaJ1->FazerLancamento(2, 1000000); //creditando 1,000,000.00 reais na conta
    cout << "Conta Corrente criada para Pessoa Jurídica 01:" << ccPessoaJ1->toString() << endl;

    //Pessoa Juridica 02 (vinculado à Pessoa Física 02)
    string nomePJ2 = "pessoa juridica 02", telefonePJ2 = "12345", emailPJ2 = "empresa2@fulano.com", cnpjPJ2 = "1202", atuacaoPJ2 = "educação", funcaoPJ2 = "etcetc", atualizacaoPJ2 = "10/01/2005";
    Juridico *pj2 = new Juridico(nomePJ2, cpfPF2, enderecoPF2, telefonePJ2, emailPJ2, cnpjPJ2, atuacaoPJ2, funcaoPJ2,
                                 atualizacaoPJ2);
    ListaClientesJur.push_front(pj2);
    cout << "Cliente Criado: Pessoa JurÍdica 02" << pj2->toString() << endl;
    ContaCorrente *ccPessoaJ2 = new ContaCorrente(cnpjPJ2); //criando Conta Corrente para a Pessoa Jurídica 01
    ListaDeContas.push_front(ccPessoaJ2); //adicionando a nova conta na lista de contas correntes
    ccPessoaJ2->FazerLancamento(2, 500000); //creditando 1,000,000.00 reais na conta
    cout << "Conta Corrente criada para Pessoa Jurídica 02:" << ccPessoaJ2->toString() << endl;


    //listar clientes fisicos
    cout << "Total de Clientes Físicos Cadastrados:" << endl;
    cout << Cliente::getTotalClientesFisico() << endl;
    //listar clientes juridicos
    cout << "Total de Clientes Juridicos Cadastrados:" << endl;
    cout << Juridico::getTotalClientesJuridico() << endl;
    //listar contas correntes
    cout << "Total de Contas Correntes:" << endl;
    cout << ContaCorrente::getQuantidadeContas() << endl;
    //listar contas poupança
    cout << "Total de Contas Poupança:" << endl;
    cout << ContaPoupanca::getQuantidadeContasP() << endl;
    //exibir montante total do banco
    cout << "Montante Total do Banco:" << endl;
    cout << fixed << ContaCorrente::getMontanteTotal() + ContaPoupanca::getMontanteTotal() << endl;

    //deletando as contas inicializadas
    ListaDeContas.remove(ccPessoaF1);  // remove conta da lista
    delete (ccPessoaF1);
    ListaDeContas.remove(ccPessoaF2);
    delete (ccPessoaF2);
    ListaContasPoup.remove(cpPessoaF1);
    delete (cpPessoaF1);
    ListaContasPoup.remove(cpPessoaF2);
    delete (cpPessoaF2);
    ListaDeContas.remove(ccPessoaJ1);
    delete (ccPessoaJ1);
    ListaDeContas.remove(ccPessoaJ2);
    delete (ccPessoaJ2);

    ListaDeClientes.remove(pf1);
    delete (pf1);
    ListaDeClientes.remove(pf2);
    delete (pf2);
    ListaClientesJur.remove(pj1);
    delete (pj1);
    ListaClientesJur.remove(pj2);
    delete (pj2);


}

void RodarTeste2() {
    list<Cliente *> ListaDeClientes;            //lista de clientes físicos
    list<Juridico *> ListaClientesJur;        //lista de clientes jur
    list<ContaCorrente *> ListaDeContas;    //lista de contas correntes
    list<ContaPoupanca *> ListaContasPoup; //lista de contas poupança

    //Cenario de Teste C2
    std::cout << " ----------------CENARIO DE TESTE 2-------------------- " << endl;

    //Pessoa Física 01
    string nomePF1 = "pessoa fisica 1", cpfPF1 = "1102", enderecoPF1 = "pf street, 200 ", telefonePF1 = "7891011", emailPF1 = "fulano2@detal.com";
    Cliente *pf1 = new Cliente(nomePF1, cpfPF1, enderecoPF1, telefonePF1, emailPF1);
    ListaDeClientes.push_front(pf1); //adicionando o novo cliente na lista de clientes
    cout << "Cliente Físico pf1 Criado: " << pf1->toString() << endl;
    ContaCorrente *ccPessoaF1 = new ContaCorrente(cpfPF1); //criando Conta Corrente para a Pessoa Física 01
    ListaDeContas.push_front(ccPessoaF1); //adicionando a nova conta na lista de contas correntes

    ccPessoaF1->FazerLancamento(2, 100.00); //creditando 100 reais na conta
    cout << "Conta Corrente c1 criada para pf1:  " << ccPessoaF1->toString() << endl;
    //criar poupança para PF1
    ContaPoupanca *cpPessoaF1 = new ContaPoupanca(cpfPF1);
    ListaContasPoup.push_front(cpPessoaF1);
    cpPessoaF1->FazerLancamento(2, 200); // CREDITA 200 REAIS NA CONTA POUPANÇA
    cpPessoaF1->setSaldoAtual(200);
    cout << "Conta Poupança p1 criada para pf1: " << cpPessoaF1->toString() << endl;
    //lancamentos
    cout << "-________________" << endl;
    cout << "   Lançamentos   " << endl;
    cout << "-________________" << endl;
    ccPessoaF1->FazerLancamento(1, 100); //debito de 100,00 na conta corrente
    cout << "Saldo atual Conta Corrente c1: " << ccPessoaF1->getSaldoAtual() << endl; //out saldo atual
    ccPessoaF1->FazerLancamento(2, 50); //credita 50 na conta corrente
    cout << "Saldo atual Conta Corrente c1: " << ccPessoaF1->getSaldoAtual() << endl; //out saldo atual
    cpPessoaF1->FazerLancamento(2, 30); //credita 30 na conta poupanca
    cout << "Saldo atual Conta Poupança p1:" << cpPessoaF1->getSaldoAtual() << endl; //out saldo atual
    cout << "" << endl;


    //EXIBIR EXTRATO DE CONTA CORRENTE 1
    cout << "EXTRATO DE CONTA CORRENTE c1 " << endl;
    for (auto &lancamento : ccPessoaF1->getLancamentos()) {
        cout << lancamento->toString() << endl;
    }
    cout <<"Saldo Final:"<< ccPessoaF1->getSaldoAtual()  <<endl;

    //EXIBIR EXTRATO POUPANCA 1
    cout << "EXTRATO DE CONTA POUPANCA p1" << endl;
    for (auto &lancamentoPoup : cpPessoaF1->getLancamentos()) {
        cout << lancamentoPoup->toString() << endl;
    }
    cout <<"Saldo Final:"<< cpPessoaF1->getSaldoAtual()  <<endl;

    //Pessoa Juridica 01
    string nomePJ1 = "pessoa juridica 01", telefonePJ1 = "13579", emailPJ1 = "empresa1@fulano.com", cnpjPJ1 = "1201", atuacaoPJ1 = "comercio", funcaoPJ1 = "detal", atualizacaoPJ1 = "10/01/2005";
    Juridico *pj1 = new Juridico(nomePJ1, cpfPF1, enderecoPF1, telefonePJ1, emailPJ1, cnpjPJ1, atuacaoPJ1, funcaoPJ1,
                                 atualizacaoPJ1);
    ListaClientesJur.push_front(pj1);
    cout << "Cliente Jurídico pj1 Criado: " << pj1->toString() << endl;
    ContaCorrente *ccPessoaJ1 = new ContaCorrente(cnpjPJ1); //criando Conta Corrente para a Pessoa Jurídica 01
    ListaDeContas.push_front(ccPessoaJ1); //adicionando a nova conta na lista de contas correntes
    ccPessoaJ1->FazerLancamento(2, 1000000); //creditando 1,000,000.00 reais na conta
    cout << "Conta Corrente c3 criada para pj1:" << ccPessoaJ1->toString() << endl;

    //Pessoa Juridica 02
    string nomePJ2 = "pessoa juridica 02", telefonePJ2 = "813579", emailPJ2 = "empresa2@fulano.com", cnpjPJ2 = "12201", atuacaoPJ2 = "comercio 2", funcaoPJ2 = "detal 2", atualizacaoPJ2 = "10/01/2005";
    Juridico *pj2 = new Juridico(nomePF1, cpfPF1, enderecoPF1, telefonePJ2, emailPJ2, cnpjPJ2, atuacaoPJ2, funcaoPJ2,
                                 atualizacaoPJ2);
    ListaClientesJur.push_front(pj2);
    cout << " Cliente Jurídico pj2 Criado: " << pj2->toString() << endl;
    ContaCorrente *ccPessoaJ2 = new ContaCorrente(cnpjPJ2); //criando Conta Corrente para a Pessoa Jurídica 02
    ListaDeContas.push_front(ccPessoaJ2); //adicionando a nova conta na lista de contas correntes
    ccPessoaJ2->FazerLancamento(2, 500000); //creditando 500,000.00 reais na conta
    cout << "Conta Corrente  c4 criada para pj2" << ccPessoaJ2->toString() << endl;

    ccPessoaJ1->FazerLancamento(1, 100000); //lancamento debito 100.000,00 em c3
    cout << "Saldo Atual Pessoa juridica 1:" << ccPessoaJ1->getSaldoAtual() << endl;
    ccPessoaJ1->FazerLancamento(1, 200000); //lancamento  debito 200.000,00 em c3
    cout << "Saldo Atual Pessoa juridica 1:" << ccPessoaJ1->getSaldoAtual() << endl;
    ccPessoaJ2->FazerLancamento(1, 30000); //lancamento  debito 30.000,00 em c4
    cout << "Saldo Atual Pessoa juridica 2:" << ccPessoaJ2->getSaldoAtual() << endl;

    //EXIBIR EXTRATO DE C3
    cout << "EXTRATO DE CONTA CORRENTE c3 " << endl;
    for (auto &lancamento : ccPessoaJ1->getLancamentos()) {
        cout << lancamento->toString() << endl;
    }
    cout <<"Saldo Final:"<< ccPessoaJ1->getSaldoAtual()  <<endl;

    //EXIBIR EXTRATO DE C4
    cout << "EXTRATO DE CONTA CORRENTE c4 " << endl;
    for (auto &lancamento : ccPessoaJ2->getLancamentos()) {
        cout << lancamento->toString() << endl;
    }
    cout <<"Saldo Final:"<< ccPessoaJ2->getSaldoAtual() <<endl;

    //exibir montante total do banco
    cout << "Montante Total do Banco:" << endl;
    cout << fixed << ContaCorrente::getMontanteTotal() + ContaPoupanca::getMontanteTotal() << endl;


    //deletando as contas inicializadas
    ListaDeContas.remove(ccPessoaF1);  // remove conta da lista
    delete (ccPessoaF1);
    ListaContasPoup.remove(cpPessoaF1);
    delete (cpPessoaF1);
    ListaDeContas.remove(ccPessoaJ1);
    delete (ccPessoaJ1);
    ListaDeContas.remove(ccPessoaJ2);
    delete (ccPessoaJ2);

    ListaClientesJur.remove(pj1);
    delete (pj1);
    ListaClientesJur.remove(pj2);
    delete (pj2);
    ListaDeClientes.remove(pf1);
    delete (pf1);
}

void RodarTeste3() {
    list<Cliente *> ListaDeClientes;            //lista de clientes físicos
    list<Juridico *> ListaClientesJur;        //lista de clientes jur
    list<ContaCorrente *> ListaDeContas;    //lista de contas correntes
    list<ContaPoupanca *> ListaContasPoup; //lista de contas poupança
    cout << " ----------------CENARIO DE TESTE 3-------------------- " << endl;
    //Pessoa Física 01
    string nomePF1 = "pessoa fisica 1", cpfPF1 = "1101", enderecoPF1 = "pf street, 100 ", telefonePF1 = "123456789", emailPF1 = "fulano@detal.com";
    Cliente *pf1 = new Cliente(nomePF1, cpfPF1, enderecoPF1, telefonePF1, emailPF1);
    ListaDeClientes.push_front(pf1); //adicionando o novo cliente na lista de clientes
    cout << "Cliente Criado: Pessoa Física 01" << pf1->toString() << endl;
    //Pessoa Jurídica 01
    cout << "    " << endl;
    string nomePJ1 = "Pessoa Jurídica 01", cpfPJ1 = "1111", enderecoPJ1 = "aaaa, 900", telefonePJ1 = "13589", emailPJ1 = "empresaA@fulano.com", cnpjPJ1 = "1222", atuacaoPJ1 = "comercio", funcaoPJ1 = "detal", atualizacaoPJ1 = "10/01/2005";
    Juridico *pj1 = new Juridico(nomePJ1, cpfPJ1, enderecoPJ1, telefonePJ1, emailPJ1, cnpjPJ1, atuacaoPJ1, funcaoPJ1,
                                 atualizacaoPJ1);
    ListaClientesJur.push_front(pj1);
    cout << "Cliente Jurídico Criado pj1" << pj1->toString() << endl;
    //criando Conta Corrente para a Pessoa Jurídica 01
    ContaCorrente *ccPessoaJ1 = new ContaCorrente(cnpjPJ1);
    ListaDeContas.push_front(ccPessoaJ1); //adicionando a nova conta na lista de contas correntes
    ccPessoaJ1->FazerLancamento(2, 1000000); //creditando 1,000,000.00 reais na conta
    cout << "Conta Corrente c1 criada para pj1:" << ccPessoaJ1->toString() << endl;
    cout << ccPessoaJ1->getLancamentos().front()->toString();
    cout << "    " << endl;
    //lançar débito de 100, 000.00 em 15 / 11 / 2019 em conta corrente de pj1
    ccPessoaJ1->FazerLancamento(1, 100000, ConstrutorData(15, 11, 2019));
    cout << "Saldo atual Conta Corrente c1: " << ccPessoaJ1->getSaldoAtual() << endl;

    //lançar débito de 200, 000.00 em 16 / 11 / 2019 em  conta corrente de pj1
    ccPessoaJ1->FazerLancamento(1, 200000, ConstrutorData(16, 11, 2019));
    cout << "Saldo atual Conta Corrente c1: " << ccPessoaJ1->getSaldoAtual() << endl;

    //lançar crédito de 400, 000.00 em 17 / 11 / 2019 em  conta corrente de pj1
    ccPessoaJ1->FazerLancamento(2, 400000, ConstrutorData(17, 11, 2019));
    cout << "Saldo atual Conta Corrente c1: " << ccPessoaJ1->getSaldoAtual() << endl;
    cout << "    " << endl;

    //exibir extrato de c1 considerando todo o período
    cout << "EXTRATO INTEGRAL DE CONTA CORRENTE c1 " << endl;

    for (auto &lancamento : ccPessoaJ1->getLancamentos()) {
        cout << lancamento->toString() << endl;
    }
    cout << "Saldo Inicial:1000000.00 " << endl;
    cout << "Saldo Final:" << ccPessoaJ1->getSaldoAtual() << endl;
    //exibir extrato de c1 de 15 / 11 / 2019 a 16 / 11 / 2019
    cout << " EXTRATO DE CONTA CORRENTE c1 --- INICIO: 15 / 11 / 2019 ||| FIM: 16 / 11 / 2019" << endl;
    ccPessoaJ1->imprimeExtrato(ConstrutorData(15, 11, 2019), ConstrutorData(16, 11, 2019));
    cout << "______________________________________________________________________________" << endl;
    //exibir extrato de c1 de 16 / 11 / 2019 a 17 / 11 / 2019
    cout << " EXTRATO DE CONTA CORRENTE c1 --- INICIO: 16 / 11 / 2019 ||| FIM: 17 / 11 / 2019" << endl;
    ccPessoaJ1->imprimeExtrato(ConstrutorData(16, 11, 2019), ConstrutorData(17, 11, 2019));

    //deletando as contas inicializadas
    ListaDeContas.remove(ccPessoaJ1);
    delete (ccPessoaJ1);
    ListaClientesJur.remove(pj1);
    delete (pj1);
    ListaDeClientes.remove(pf1);
    delete (pf1);


}

void RodarTeste4() {
    list<Cliente *> ListaDeClientes;            //lista de clientes físicos
    list<Juridico *> ListaClientesJur;        //lista de clientes jur
    list<ContaCorrente *> ListaDeContas;    //lista de contas correntes
    list<ContaPoupanca *> ListaContasPoup; //lista de contas poupança
    cout << " ----------------CENARIO DE TESTE 4-------------------- " << endl;

    string nomePF1 = "pessoa fisica 1", cpfPF1 = "1101", enderecoPF1 = "pf street, 100 ", telefonePF1 = "123456789", emailPF1 = "fulano@detal.com";
    Cliente *pf1 = new Cliente(nomePF1, cpfPF1, enderecoPF1, telefonePF1, emailPF1);
    ListaDeClientes.push_front(pf1); //adicionando o novo cliente na lista de clientes

    //criando Conta Corrente para a Pessoa Física 01
    ContaCorrente *ccPessoaF1 = new ContaCorrente(cpfPF1);
    ListaDeContas.push_front(ccPessoaF1);
    ccPessoaF1->FazerLancamento(2, 100.00); //creditando 100 reais na conta
    //criando poupança para PF1
    ContaPoupanca *cpPessoaF1 = new ContaPoupanca(cpfPF1);
    ListaContasPoup.push_front(cpPessoaF1);
    cpPessoaF1->FazerLancamento(2, 200); // CREDITA 200 REAIS NA CONTA POUPANÇA

    cout << "  " << endl;

    cout << " Testar situações de restrição " << endl;
    cout << "______________________________________________________________________________________________" << endl;
    //cadastramento de cliente Pessoa Física (Jurídica?)para proprietário não cadastrado
    cout << " SITUACAO 01: cadastramento de cliente Pessoa Física (Jurídica?)para proprietário não cadastrado" << endl;
    CadastrarClienteJur(ListaClientesJur, ListaDeClientes);
    cout << "--FIM DA SITUAÇÃO 01 --" << endl;
    cout << "______________________________________________________________________________________________" << endl;

    //criação de conta para cliente não cadastrado
    cout << " SITUACAO 02:criação de conta para cliente não cadastrado" << endl;
    criaContaCorrente(ListaDeContas,ListaDeClientes);
    cout << "--FIM DA SITUAÇÃO 02 --" << endl;
    cout << "______________________________________________________________________________________________" << endl;

    //lançamento que geraria saldo negativo em Conta Poupança
    cout << " SITUACAO 03: lançamento que geraria saldo negativo em Conta Poupança" << endl;
    cout << "Conta Poupanca criada para Pessoa Física 01:" << cpPessoaF1->toString() << endl;
    cout << "---tentiva de débito de 300,00 reais---" << cpPessoaF1->toString() << endl;
     bool status = cpPessoaF1->FazerLancamento(1, 300);
    if (!status) {
        cout << "Sem saldo suficiente para esta operação!" << endl;
    }
    cout << "--FIM DA SITUAÇÃO 03 --" << endl;
    cout << "______________________________________________________________________________________________" << endl;

    //remoção de conta com lançamentos
    cout << " SITUACAO 04: remoção de conta com lançamentos" << endl;
    cout << "Conta Corrente criada para Pessoa Física 01:" << ccPessoaF1->toString() << endl;
    {
    int numeroDaConta = ccPessoaF1->GetNumero();
    bool achou = false;
    auto ptrConta = ListaDeContas.begin(); // ponteiro para primeira conta da lista
    while (ptrConta != ListaDeContas.end()) { // enquanto nao acabarem as contas
        if (numeroDaConta == (*ptrConta)->GetNumero()) {
            achou = true;
            if ((*ptrConta)->getLancamentos().size() != 0) {
                cout << "Essa conta não pode ser deletada pois há lançamentos vinculados a ela" << endl;
                break;
            }
            ListaDeContas.erase(ptrConta); // remove conta da lista
            delete (*ptrConta);
            break;
        }
        ptrConta++; // avanca para a proxima conta
    }
    if (!achou) {
        cout << "Conta nao encontrada " << endl;
    }
}
    cout << "______________________________________________________________________________________________" << endl;

    // remoção de cliente com contas associadas
    cout << " SITUAÇÃO 05: remoção de cliente com contas associadas " << endl;
    cout << "Cliente Criado: Pessoa Física 01" << pf1->toString() << endl;
    {
        bool achou = false;
        bool temconta = false;
        string cpf = pf1->getCpf();

        auto ptrCliente = ListaDeClientes.begin(); // inicia no primeiro cliente

        while (ptrCliente != ListaDeClientes.end()) { // enquanto nao acabar os clientes
            if (cpf == (*ptrCliente)->getCpf()) {
                achou = true;
                break;

            }
            ptrCliente++; // avança para o primeiro cliente
        }
        if (!achou) {
            cout << "Cliente não encontrado" << endl;

        }

        bool possuiContaCorrente = false;
        for (auto &ContaCorrente : ListaDeContas) {
            if (cpf == ContaCorrente->getCpFcliente()) {
                possuiContaCorrente = true;
                cout << "Esse cliente não pode ser deletado pois há pelo menos 01 ContaCorrente vinculada a ele" << endl;
                break;
            }
        }
        if (!possuiContaCorrente) {
            bool possuiContaPoup = false;
            for (auto &ContaPoupanca : ListaContasPoup ) {
                if (cpf == ContaPoupanca->getCpfCliente()) {
                    possuiContaPoup = true;
                    cout << "Esse cliente não pode ser deletado pois há pelo menos 01 ContaPoupanca vinculada a ele" << endl;
                    break;
                }
            }
            if (!possuiContaPoup) {
                ListaDeClientes.erase(ptrCliente); //remove cliente da lista
                delete (*ptrCliente);
            }
        }


    }
    cout << "______________________________________________________________________________________________" << endl;

    ListaDeContas.remove(ccPessoaF1);
    delete (ccPessoaF1);
    ListaContasPoup.remove(cpPessoaF1);
    delete (cpPessoaF1);
    ListaDeClientes.remove(pf1);
    delete (pf1);

}