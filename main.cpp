#include <iostream>
#include <ctime>
#include <list>
#include <locale>

#include "ContaCorrente.h"
#include "Cliente.h"
#include "Juridico.h"
#include "ContaPoupanca.h"

using namespace std;


int main() {
    std::locale::global(std::locale("en_US.utf8")); // acentos

    list<Cliente*> ListaDeClientes;			//lista de clientes físicos
	list<Juridico*> ListaClientesJur;		//lista de clientes jur
    list<ContaCorrente*> ListaDeContas;    //lista de contas correntes
	list <ContaPoupanca*> ListaContasPoup; //lista de contas poupança
    int menu_geral=0, menu_clientes=0, menu_contas=0;
    bool sair = false;

    //casos de teste
    /* string nome = "fulano de tal", cpf = "17436740822", endereco = "bacurau, 220", telefone = "123456789", email = "fulano@detal.com";
    Cliente* cliente_A = new Cliente(nome, cpf, endereco, telefone, email);
    ListaDeClientes.push_front(cliente_A);
    cout << "Cliente criado: " << cliente_A->toString() << endl;
    ContaCorrente* conta_A = new ContaCorrente("17436740822");
    conta_A->FazerLancamento(2, 100.80f);  //creditando 100 reais na conta
	conta_A->FazerLancamento(1, 25.80f); 
    ListaDeContas.push_front(conta_A);
    cout << "Conta criada: " << conta_A->toString() << endl; */

	string nomePF1 = "pessoa fisica 1", cpfPF1 = "1101", enderecoPF1 = "pf street, 100 ", telefonePF1 = "123456789", emailPF1 = "fulano@detal.com";
	//Cenario de Teste C1

	//Pessoa Física 01
	Cliente* pf1 = new Cliente(nomePF1, cpfPF1, enderecoPF1, telefonePF1, emailPF1); 
	ListaDeClientes.push_front(pf1); //adicionando o novo cliente na lista de clientes
	cout << "Cliente Criado: Pessoa Física 01" << pf1->toString() << endl; 
	ContaCorrente* ccPessoaF1 = new ContaCorrente(cpfPF1); //criando Conta Corrente para a Pessoa Física 01
	ListaDeContas.push_front(ccPessoaF1); //adicionando a nova conta na lista de contas correntes

	ccPessoaF1->FazerLancamento(2, 100.00); //creditando 100 reais na conta
	cout << "Conta Corrente criada para Pessoa Física 01:" << ccPessoaF1->toString() << endl;
	//criar poupança para PF1
	ContaPoupanca* cpPessoaF1 = new ContaPoupanca(cpfPF1); 
	ListaContasPoup.push_front(cpPessoaF1);
	cpPessoaF1->FazerLancamento(2, 200); // CREDITA 200 REAIS NA CONTA POUPANÇA
	cout << "Conta Poupança criada para Pessoa Física 01:" << cpPessoaF1->toString() << endl;

	//Pessoa Física 02
	string nomePF2 = "pessoa fisica 2", cpfPF2 = "1102", enderecoPF2 = "pf street, 200 ", telefonePF2 = "7891011", emailPF2 = "fulano2@detal.com";
	Cliente* pf2 = new Cliente(nomePF2, cpfPF2, enderecoPF2, telefonePF2, emailPF2); 
	ListaDeClientes.push_front(pf2); 
	cout << "Cliente Criado: Pessoa Física 02" << pf2->toString() << endl;
	ContaCorrente* ccPessoaF2 = new ContaCorrente(cpfPF2); 
	ListaDeContas.push_front(ccPessoaF2); 
	cout << "Conta Corrente criada para Pessoa Física 02:" << ccPessoaF2->toString() << endl;

	//cria poupança para PF02
	ContaPoupanca* cpPessoaF2 = new ContaPoupanca(cpfPF2);
	ListaContasPoup.push_front(cpPessoaF2);
	cpPessoaF1->FazerLancamento(2, 50); //creditando 50 reais na conta poupança 
	cout << "Conta Poupança criada para Pessoa Física 02:" << cpPessoaF2->toString() << endl;


	//listar clientes fisicos
	cout << "Total de Clientes Físicos Cadastrados:" << endl;
	cout << Cliente::getTotalClientesFisico() << endl;
	//listar clientes juridicos
	cout << "Total de Clientes Juridicos Cadastrados:" << endl;
	cout << Juridico::getTotalClientesJuridico()<< endl;
	//listar contas correntes
	cout << "Total de Contas Correntes:" << endl;
	cout << ContaCorrente::getQuantidadeContas() << endl;
	//listar contas poupança
	cout << "Total de Contas Poupança:" << endl;
	cout << ContaPoupanca::getQuantidadeContasP() << endl;

	//Pessoa Juridica 01 (vinculado à Pessoa Física 01)
	string nomePJ1 = "pessoa juridica 01", telefonePJ1 = "13579", emailPJ1 = "empresa1@fulano.com", cnpjPJ1="1201", atuacaoPJ1 = "comercio", funcaoPJ1= "detal", atualizacaoPJ1 = "10/01/2005";
	Juridico* pj1 = new Juridico(nomePF2, cpfPF1, enderecoPF1, telefonePJ1, emailPJ1, cnpjPJ1, atuacaoPJ1, funcaoPJ1, atualizacaoPJ1);
	ListaClientesJur.push_front(pj1);
	cout << "Cliente Criado: Pessoa JurÍdica 01" << pj1->toString() << endl;
	ContaCorrente* ccPessoaJ1 = new ContaCorrente(cnpjPJ1); //criando Conta Corrente para a Pessoa Jurídica 01
	ListaDeContas.push_front(ccPessoaJ1); //adicionando a nova conta na lista de contas correntes
	ccPessoaJ1->FazerLancamento(2, 1000000); //creditando 1,000,000.00 reais na conta
	cout << "Conta Corrente criada para Pessoa Jurídica 01:" << ccPessoaJ1->toString() << endl;

	//Pessoa Juridica 02 (vinculado à Pessoa Física 02)
	string nomePJ2 = "pessoa juridica 02", telefonePJ2 = "12345", emailPJ2 = "empresa2@fulano.com", cnpjPJ2 = "1202", atuacaoPJ2= "educação", funcaoPJ2 = "etcetc", atualizacaoPJ2 = "10/01/2005";
	Juridico* pj2 = new Juridico(nomePJ2, cpfPF2, enderecoPF2, telefonePJ2, emailPJ2, cnpjPJ2, atuacaoPJ2, funcaoPJ2, atualizacaoPJ2);
	ListaClientesJur.push_front(pj2);
	cout << "Cliente Criado: Pessoa JurÍdica 02" << pj2->toString() << endl;
	ContaCorrente* ccPessoaJ2 = new ContaCorrente(cnpjPJ2); //criando Conta Corrente para a Pessoa Jurídica 01
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

	//exibir montante total do banco
	cout << "Montante Total do Banco:" << endl;
	cout << fixed << ContaCorrente::getMontanteTotal() << endl;
	
	//Cenario de Teste C2
	//Cenario de Teste C3
	//Cenario de Teste C4







    while(!sair) {
		cin.clear();
    //Menu Geral
    cout << "Escolha a Funcionalidade desejada" << endl;
    cout << "1- Gerenciamento de Clientes" << endl;
    cout << "2- Gerenciamento de Contas" << endl;
    cout << "3- Consulta de Total de Contas Correntes" << endl;
    cout << "4- Consulta de Montante Total" << endl;
	cout << "5- Consulta de Total de Clientes Físicos" << endl;
	cout << "6- Consulta de Total de Clientes Juridicos" << endl;
	cout << "7- Consulta de Total de Contas Poupanca" << endl;
        cin >> menu_geral;

        //escolha de funcionalidade
        switch (menu_geral) {
            case 1: {
                cout << "Escolha a Funcionalidade desejada" << endl;
                cout << "1- Cadastrar Cliente Fisico" << endl;
                cout << "2- Alterar Dados do Cliente Fisico" << endl;
                cout << "3- Excluir Cliente Fisico" << endl;
				cout << "4- Cadastrar Cliente Juridico" << endl;
				cout << "5- Alterar Dados do  Cliente Juridico" << endl;
				cout << "6- Excluir Cliente Juridico" << endl;

                cin >> menu_clientes;

                break;
            }
            case 2: {
                cout << "Escolha a Funcionalidade desejada" << endl;
                cout << "1- Abrir Conta Corrente" << endl;
                cout << "2- Alterar Dados de Conta Corrente" << endl;
                cout << "3- Excluir Conta Corrente" << endl;
                cout << "4- Lançamento em Conta Corrente" << endl;
                cout << "5- Extrato de Conta Corrente" << endl;
				cout << "6- Exibir dados de Conta Corrente" << endl;
				cout << "7- Abrir Conta Poupança" << endl;
				cout << "8- Excluir Conta Poupança" << endl;
				cout << "9- Lançamento em Conta Poupança" << endl;
				cout << "0- Extrato de Conta Poupança" << endl;
			

                cin >> menu_contas;
                break;
            }
            case 3: {
                cout << "Total de Contas Correntes:" << endl;
                cout << ContaCorrente::getQuantidadeContas() << endl;
                break;
            }
            case 4: {
                cout << "Montante Total:" << endl;
                cout << ContaCorrente::getMontanteTotal() << endl;
                break;
            }
			case 5:{
				cout << "Total de Clientes Físicos Cadastrados:" << endl;
				cout << Cliente::getTotalClientesFisico() << endl;
				break;
			}
			case 6:{
			}
			case 7:{

			}


        }

        menu_geral = 0;



        //ignora /n que pode ainda estar no cin depois de ler o numero acima
        if (cin.peek() == '\n') {
            cin.ignore();
        }

//gerenciamento de clientes
        switch (menu_clientes) {
            case 1: {
                string nome, cpf, endereco, email, telefone;

                cout << "Insira seu nome:" << endl;
                getline(cin, nome);
                cout << "Insira seu CPF:" << endl;
                getline(cin, cpf);
                cout << "Insira seu endereço:" << endl;
                getline(cin, endereco);
                cout << "Insira seu telefone:" << endl;
                getline(cin, telefone);
                cout << "Insira seu e-mail:" << endl;
                getline(cin, email);
                Cliente* novoCliente = new Cliente(nome, cpf, endereco, telefone, email);
                ListaDeClientes.push_front(novoCliente);
                break;
            }
            case 2: {
                bool achou = false;
                string cpf, nome, email, endereco, telefone;
                cout << "Insira seu CPF:" << endl;
				getline(cin, cpf);
                //busca cpf do cliente na lista de clientes
                for (auto &Cliente : ListaDeClientes) {
                    if (cpf == Cliente->getCpf()) {
                        achou = true;
                        cout << "Insira seu nome:" << endl;
                        getline(cin, nome);
                        cout << "Insira seu CPF:" << endl;
                        getline(cin, cpf);
                        cout << "Insira seu endereço:" << endl;
                        getline(cin, endereco);
                        cout << "Insira seu telefone:" << endl;
                        getline(cin, telefone);
                        cout << "Insira seu e-mail:" << endl;
                        getline(cin, email);

                        Cliente->setNome(nome);
                        Cliente->setCpf(cpf);
                        Cliente->setEndereco(endereco);
                        Cliente->setTelefone(telefone);
                        Cliente->setEmail(email);
                        break;
                    }

                }
                if(!achou)
                    cout << "Cliente não encontrado" << endl;


                break;
            }
            case 3: {
                bool achou = false;

                string cpf;
                cout << "Insira o CPF do cliente que deseja deletar:" << endl;
                getline(cin, cpf);

                auto ptrCliente = ListaDeClientes.begin(); // inicia no primeiro cliente

                while (ptrCliente != ListaDeClientes.end()) { // enquanto nao acabar os clientes
                    if (cpf == (*ptrCliente)->getCpf()) {
                        achou=true;
                        ListaDeClientes.erase(ptrCliente); //remove cliente da lista
						delete(*ptrCliente);
                        break;
                    }
                    ptrCliente++; // avança para o primeiro cliente
                }
                if(!achou)
                    cout << "Cliente não encontrado"<<endl;
                break;
            }
        }
        menu_clientes = 0;
        switch (menu_contas) {
            case 1: {
                string cpf;
                cout << "Insira o cpf do cliente para criação da conta:" << endl;
                getline(cin, cpf);
                ContaCorrente* nova_conta = new ContaCorrente(cpf);
                ListaDeContas.push_front(nova_conta);
                cout << "Conta Aberta com Sucesso! O numero da sua conta é:" << nova_conta->GetNumero() << endl;
                break;
            }
            case 2: {
                bool achou = false;
                int numeroDaConta;
				 
                cout << "Insira o número da conta que deseja alterar" << endl;
                cin >> numeroDaConta;
				if (cin.peek() == '\n') {
					cin.ignore();
				}

                for (auto &ContaCorrente : ListaDeContas) {
                    if (numeroDaConta == ContaCorrente->GetNumero()) {
                        achou = true;
                        string cpf;
                        cout << "Insira o novo cpf para a conta:" << endl;
                        getline(cin, cpf);
                        ContaCorrente->setCpFcliente(cpf);
						float novoLimite;
						cout << "Insira o novo limite de Cheque Especial para a conta:" << endl;
						cin >> novoLimite;
						ContaCorrente->setLimiteChequeEspecial(novoLimite); 
						
			
				
                        break;
                    }
                }
                if(!achou)
                    cout << "Conta nao encontrada"<<endl;
               break;


            }
            case 3: {
                bool achou = false;
                int numeroDaConta;
                cout << "Insira o número da conta que deseja deletar" << endl;
                cin >> numeroDaConta;
                auto ptrConta = ListaDeContas.begin(); // ponteiro para primeira conta da lista

                while (ptrConta != ListaDeContas.end()) { // enquanto nao acabarem as contas
                    if (numeroDaConta == (*ptrConta)->GetNumero()) {
						achou = true;
						if((*ptrConta)->getExtrato()!=nullptr){
							cout << "Essa conta não pode ser deletada pois há lançamentos vinculados a ela" << endl;
							break; 
						}


                        ListaDeContas.erase(ptrConta); // remove conta da lista
						delete(*ptrConta); 
                        break;
                    } 
                    ptrConta++; // avanca para a proxima conta
                }
                if(!achou)
                    cout << "Conta nao encontrada "<<endl;

                break;
            }
            case 4: {
                bool achou = false;
                int numeroDaConta;
                int tipo_lancamento;
                float valor;
                cout << "Insira o número da conta que deseja fazer o lançamento:" << endl;
                cin >> numeroDaConta;

                cout << "Escolha o tipo de lançamento:" << endl;
                cout << "1- Débito em Conta" << endl;
                cout << "2- Crédito em Conta" << endl;
                cin >> tipo_lancamento;
                cout << "Digite o valor a ser lançado:" << endl;
                cin >> valor;

                for (auto &ContaCorrente : ListaDeContas) {

                    if (numeroDaConta == ContaCorrente->GetNumero()) {
                        achou = true;
                        if(!ContaCorrente->FazerLancamento(tipo_lancamento, valor)) {
                                cout <<  "Sem saldo suficiente!" << endl;
                        }
                        break;
                    }
                }
                if(!achou)
                    cout << "Conta nao encontrada"<< endl;

                break;
            }

            case 5: {
                int numeroDaConta;
                bool achou = false;
                cout << "Insira o número da conta que deseja ver o extrato" << endl;
                cin >> numeroDaConta;

                //loop na lista de contas
                for (auto &ContaCorrente : ListaDeContas) {
                    //encontra a conta desejada
                    if (numeroDaConta == ContaCorrente->GetNumero()) {
                        achou = true;
                        //loop na lista de lancamento da conta desejada
                        for (auto const &lancamento : *(ContaCorrente->getExtrato())) {
                            std::cout << lancamento.valor << "-" << lancamento.type << "-"
                                      << ctime(&lancamento.DataLancamento) << endl;
                        }
                        break;
                    }
                }
                if(!achou)
                    cout << "Conta nao encontrada"<<endl;

                break;
            }
			case 6: {
				int numeroDaConta;
				bool achou = false;
				cout << "Insira o número da conta que deseja ver" << endl;
				cin >> numeroDaConta;

				//loop na lista de contas
				for (auto& ContaCorrente : ListaDeContas) {
					//encontra a conta desejada
					if (numeroDaConta == ContaCorrente->GetNumero()) {
						achou = true;
						cout << ContaCorrente->toString() << endl;
						
						break;
					}
				}
				if (!achou)
					cout << "Conta nao encontrada" << endl;

				break;
			}



        }
        menu_contas =0;
    }
    return 0;
}