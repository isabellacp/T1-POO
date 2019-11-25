#include <ctime>
#include <list>
#include <string>
#include <locale>
#include "ContaCorrente.h"
#include "Cliente.h"
#include "Juridico.h"
#include "ContaPoupanca.h"
#include "Menu.h"
#include "testes.h"
#include <iostream>
using namespace std;
//Prototipos

int main() {
	std::locale::global(std::locale("en_US.utf8")); // acentos

	list<Cliente*> ListaDeClientes;			//lista de clientes físicos
	list<Juridico*> ListaClientesJur;		//lista de clientes jur
	list<ContaCorrente*> ListaDeContas;    //lista de contas correntes
	list <ContaPoupanca*> ListaContasPoup; //lista de contas poupança
	bool sair = false;
    RodarTeste1();
    RodarTeste2();
    RodarTeste3();
    RodarTeste4();
    cout << "  "<< endl;
    cout << "----------------MENU DE FUNCIONALIDADES-------------------- " << endl;
	while (!sair) {
        cin.clear();
        int optGeral = 0, optClientes = 0, optContas = 0;


        //Menu Geral (escolha de funcionalidade)
        optGeral = menuGeral();

        switch (optGeral) {
            case 1: {

                optClientes = menuClientes();
                break;
            }
            case 2: {
                optContas = menuContas();
                break;
            }
            case 3: {
                cout << "Total de Contas Correntes:" << endl;
                cout << ContaCorrente::getQuantidadeContas() << endl;
                break;
            }
            case 4: {
                cout << "Montante Total:" << endl;
                cout << fixed << ContaCorrente::getMontanteTotal() + ContaPoupanca::getMontanteTotal() << endl;
                break;
            }
            case 5: {
                cout << "Total de Clientes Físicos Cadastrados:" << endl;
                cout << Cliente::getTotalClientesFisico() << endl;
                break;
            }
            case 6: {
                cout << "Total de Clientes Juridicos Cadastrados:" << endl;
                cout << Juridico::getTotalClientesJuridico() << endl;
            }
            case 7: {
                cout << "Total de Contas Poupança:" << endl;
                cout << ContaPoupanca::getQuantidadeContasP() << endl;
            }

        }

        optGeral = 0;



        //ignora /n que pode ainda estar no cin depois de ler o numero acima
        if (cin.peek() == '\n') {
            cin.ignore();
        }
        if (optClientes == 0) {
            continue;
        } 

        //gerenciamento de clientes
        switch (optClientes) {
            case 1: {
                CadastrarClienteFis(ListaDeClientes);
                break;
            }
            case 2: {
                AlteraDadosClienteFis(ListaDeClientes, ListaDeContas, ListaContasPoup);
                break;
            }
            case 3: {
                deletaClienteFis(ListaDeClientes, ListaDeContas, ListaContasPoup);
                break;
            }
            case 4: {
                CadastrarClienteJur(ListaClientesJur, ListaDeClientes);
                break;
            }
            case 5: {
                AlteraDadosClienteJur(ListaClientesJur);
                break;
            }
            case 6: {
                deletaClienteJur(ListaClientesJur, ListaDeContas);
                break;
            }
        }
        optClientes = 0;

        if (cin.peek() == '\n') {
            cin.ignore();
        }
        if (optContas == 0) {
            continue;
        }
        //gerenciamento de contas
        switch (optContas) {
            case 1: {
                criaContaCorrente(ListaDeContas,ListaDeClientes);
                break;
            }
            case 2: {
                alteraContaCorrente(ListaDeContas);
                break;
            }
            case 3: {
                deletaContaCorrente(ListaDeContas);
                break;
            }
            case 4: {
                lancamentoContaCorrente(ListaDeContas);
                break;
            }
            case 5: {
                exibeExtratoContaCorrente(ListaDeContas);
                break;
            }
            case 6: {
                exibeDadosContaCorrente(ListaDeContas);
                break;
            }
            case 7: {
                criaContaPoup(ListaContasPoup);
                break;
            }
            case 8: {
                deletaContaPoup(ListaContasPoup);
                break;
            }
            case 9: {
                lancamentoContaPoup(ListaContasPoup);
                break;
            }
            case 10: {
                exibeExtratoContaPoup(ListaContasPoup);

            }

        }

        optContas = 0;
    }
	return 0;
}

