#ifndef MENU_H
#define MENU_H
#include <ctime>
#include <list>
#include "ContaCorrente.h"
#include "Cliente.h"
#include "Juridico.h"
#include "ContaPoupanca.h"


int menuGeral();
int menuContas();
int menuClientes();
void CadastrarClienteFis(list<Cliente*> ListaDeClientes);
void AlteraDadosClienteFis(list<Cliente*>ListaDeClientes, list<ContaCorrente*>ListaDeContas);
void deletaClienteFis(list<Cliente*>ListaDeClientes, list<ContaCorrente*>ListaDeContas);
void CadastrarClienteJur(list<Juridico*>ListaClientesJur);
void AlteraDadosClienteJur(list<Juridico*>ListaClientesJur);
void deletaClienteJur(list<Juridico*>ListaClientesJur, list<ContaCorrente*>ListaDeContas);
void criaContaCorrente(list<ContaCorrente*> ListaDeContas);
void alteraContaCorrente(list<ContaCorrente*>ListaDeContas);
void deletaContaCorrente(list<ContaCorrente*>ListaDeContas);
void lancamentoContaCorrente(list<ContaCorrente*>ListaDeContas);
void exibeExtratoContaCorrente(list<ContaCorrente*>ListaDeContas);
void exibeDadosContaCorrente(list<ContaCorrente*>ListaDeContas);
void criaContaPoup(list<ContaPoupanca*>ListaContasPoup);
void deletaContaPoup(list<ContaPoupanca*> ListaContasPoup);
void lancamentoContaPoup(list<ContaPoupanca*> ListaContasPoup);
void exibeExtratoContaPoup(list<ContaPoupanca*> ListaContasPoup);

#endif