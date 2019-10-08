#include <iostream>
#include <ctime>
#include <list>

#include "ContaCorrente.h"
#include "Cliente.h"


using namespace std;


int main() {
    list<Cliente> ListaDeClientes;
    list<ContaCorrente> ListaDeContas;
    int menu_geral, menu_clientes, menu_contas;

    //casos de teste
    string nome = "fulano de tal", cpf = "17436740822", endereco = "bacurau, 220", telefone = "123456789", email = "fulano@detal.com";
    Cliente cliente_A = Cliente(nome, cpf, endereco, telefone, email);
    ListaDeClientes.push_front(cliente_A);


    ContaCorrente conta_A = ContaCorrente("17436740822");
    conta_A.FazerLancamento(2, 100.80);  //creditando 100 reais na conta
    conta_A.FazerLancamento(1, 25.80);



    //Menu Geral
    cout << "Escolha a Funcionalidade desejada" << endl;
    cout << "1- Gerenciamento de Clientes" << endl;
    cout << "2- Gerenciamento de Contas" << endl;
    cout << "3- Consulta de Total de Contas" << endl;
    cout << "4- Consulta de Montante Total" << endl;
    cin >> menu_geral;

    //escolha de funcionalidade
    switch (menu_geral) {
        case 1: {
            cout << "Escolha a Funcionalidade desejada" << endl;
            cout << "1- Cadastrar Cliente" << endl;
            cout << "2- Alterar Dados do Cliente" << endl;
            cout << "3- Excluir Cliente" << endl;
            cin >> menu_clientes;

            break;
        }
        case 2: {
            cout << "Escolha a Funcionalidade desejada" << endl;
            cout << "1- Abrir Conta" << endl;
            cout << "2- Alterar Dados de Conta" << endl;
            cout << "3- Excluir Conta" << endl;
            cout << "4- Lançamento em Conta" << endl;
            cout << "5- Extrato de Conta" << endl;
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
            cout << ContaCorrente::getMontanteTotal();
            break;
        }
    }



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
            Cliente novoCliente = Cliente(nome, cpf, endereco, telefone, email);
            ListaDeClientes.push_front(novoCliente);
            break;
        }
        case 2: {
            string cpf, nome, email, endereco, telefone;
            cout << "Insira seu CPF:" << endl;
            cin >> cpf;
            //busca cpf do cliente na lista de clientes
            for (auto &Cliente : ListaDeClientes) {
                if (cpf == Cliente.getCpf()) {
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

                    Cliente.setNome(nome);
                    Cliente.setCpf(cpf);
                    Cliente.setEndereco(endereco);
                    Cliente.setTelefone(telefone);
                    Cliente.setEmail(email);
                    break;
                }

            }


            break;
        }
        case 3: {
            string cpf;
            cout << "Insira o CPF do cliente que deseja deletar:" << endl;
            getline(cin, cpf);

            auto ptrCliente = ListaDeClientes.begin(); // inicia no primeiro cliente

            while (ptrCliente != ListaDeClientes.end()) { // enquanto nao acabar os clientes
                if (cpf == (*ptrCliente).getCpf()) {
                    ListaDeClientes.erase(ptrCliente); //remove cliente da lista
                    break;
                }
                ptrCliente++; // avança para o primeiro cliente
            }
            break;
        }
    }

    switch (menu_contas) {
        case 1: {
            string cpf;
            int numero;
            cout << "Insira o cpf do cliente para criação da conta:" << endl;
            getline(cin, cpf);
            ContaCorrente nova_conta = ContaCorrente(cpf);
            ListaDeContas.push_front(nova_conta);
            cout << "Conta Aberta com Sucesso! O numero da sua conta é:" << nova_conta.GetNumero();
            break;
        }
        case 2: {
            int numeroDaConta;
            cout << "Insira o número da conta que deseja alterar" << endl;
            cin >> numeroDaConta;
            for (auto &ContaCorrente : ListaDeContas) {
                if (numeroDaConta == ContaCorrente.GetNumero()) {
                    string cpf;
                    cout << "Insira o novo cpf para a conta:" << endl;
                    getline(cin, cpf);
                    ContaCorrente.setCpFcliente(cpf);
                    break;
                }
            }
            break;
        }
        case 3: {
            int numeroDaConta;
            cout << "Insira o número da conta que deseja deletar" << endl;
            cin >> numeroDaConta;
            auto ptrConta = ListaDeContas.begin(); // ponteiro para primeira conta da lista

            while (ptrConta != ListaDeContas.end()) { // enquanto nao acabarem as contas
                if (numeroDaConta == (*ptrConta).GetNumero()) {
                    ListaDeContas.erase(ptrConta); // remove conta da lista
                    break;
                }
                ptrConta++; // avanca para a proxima conta
            }
            break;
        }
        case 4: {
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
                if (numeroDaConta == ContaCorrente.GetNumero()) {
                    ContaCorrente.FazerLancamento(tipo_lancamento, valor);
                    break;
                }
            }
            break;
        }

        case 5: {
            int numeroDaConta;

            cout << "Insira o número da conta que deseja ver o extrato" << endl;
            cin >> numeroDaConta;

            //loop na lista de contas
            for (auto &ContaCorrente : ListaDeContas) {
                //encontra a conta desejada
                if (numeroDaConta == ContaCorrente.GetNumero()) {
                    //loop na lista de lancamento da conta desejada
                    for (auto const &lancamento : ContaCorrente.getExtrato()) {
                        std::cout << lancamento.valor << "-" << lancamento.type << "-"
                                  << ctime(&lancamento.DataLancamento) <<endl;
                    }
                    break;
                }
            }

            break;
        }

    }



    /* ContaCorrente a = ContaCorrente("asdasdad");
   cout << a.GetNumero()<< endl;

   float v = 1.20;
   float d = 3.20;
   int deb=1, cred=2;

  ContaCorrente::getQuantidadeContas();
   cout << ContaCorrente::getQuantidadeContas() << endl;
   cout << a.getSaldoAtual() << endl;
   a.FazerLancamento(cred,d);
   cout << a.getSaldoAtual() << endl;
   a.FazerLancamento(deb,v);
   cout << a.getSaldoAtual() << endl;
   for (auto const& lancamento : a.getExtrato()) {
       std::cout << lancamento.valor << "-" << lancamento.type << "-" << ctime(&lancamento.DataLancamento);
   }
   std::cout << ContaCorrente::getMontanteTotal();

   ContaCorrente b = ContaCorrente("asdasdad");
   ContaCorrente c = ContaCorrente("asdasdad");
   ContaCorrente f = ContaCorrente("asdasdad");
   ContaCorrente e = ContaCorrente("asdasdad");
   cout << ContaCorrente::getQuantidadeContas() << endl;*/



    return 0;
}