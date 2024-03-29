
#include <ctime>
#include <list>
#include "ContaCorrente.h"
#include "Cliente.h"
#include "Juridico.h"
#include "ContaPoupanca.h"

using namespace std;

tm ConstrutorData(int dia, int mes, int ano) {

    time_t now = time(0);
    tm *data = localtime(&now);
    data->tm_mday = dia;
    data->tm_year = ano - 1900;
    data->tm_mon = mes - 1;
    return *data;
}

tm LerData() {
    int dia, mes, ano, hora, minuto;

    cout << "Insira o dia" << endl;
    cin >> dia;
    cout << "Insira o mes" << endl;
    cin >> mes;
    cout << "Insira o ano" << endl;
    cin >> ano;
    cout << "Insira a hora" << endl;
    cin >> hora;
    cout << "Insira o minuto" << endl;
    cin >> minuto;

    time_t now = time(0);
    tm *data = localtime(&now);
    data->tm_mday = dia;
    data->tm_mon = mes - 1;
    data->tm_year = ano - 1900;
    data->tm_hour = hora;
    data->tm_min = minuto;
    return *data;

}

int menuGeral() {
    cin.clear();
    std::locale::global(std::locale("en_US.utf8")); // acentos
    int opt;
    cout << "----:: Escolha a Funcionalidade desejada ::-------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1- Gerenciamento de Clientes" << endl;
    cout << "2- Gerenciamento de Contas" << endl;
    cout << "3- Consulta de Total de Contas Correntes" << endl;
    cout << "4- Consulta de Montante Total" << endl;
    cout << "5- Consulta de Total de Clientes Físicos" << endl;
    cout << "6- Consulta de Total de Clientes Jurídicos" << endl;
    cout << "7- Consulta de Total de Contas Poupança" << endl;
    cin >> opt;

    return opt;
}

int menuContas() {
    cin.clear();

    std::locale::global(std::locale("en_US.utf8")); // acentos
    int opt;
    cout << "----:: Escolha a Funcionalidade desejada ::-------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1- Abrir Conta Corrente" << endl;
    cout << "2- Alterar Dados de Conta Corrente" << endl;
    cout << "3- Excluir Conta Corrente" << endl;
    cout << "4- Lan�amento em Conta Corrente" << endl;
    cout << "5- Extrato de Conta Corrente" << endl;
    cout << "6- Exibir dados de Conta Corrente" << endl;
    cout << "7- Abrir Conta Poupança" << endl;
    cout << "8- Excluir Conta Poupança" << endl;
    cout << "9- Lan�amento em Conta Poupança" << endl;
    cout << "10- Extrato de Conta Poupança" << endl;
    cin >> opt;
    return opt;
}

int menuClientes() {
    cin.clear();

    std::locale::global(std::locale("en_US.utf8")); // acentos
    int opt;
    cout << "----:: Escolha a Funcionalidade desejada ::-------" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "1- Cadastrar Cliente Fisico" << endl;
    cout << "2- Alterar Dados do Cliente Fisico" << endl;
    cout << "3- Excluir Cliente Fisico" << endl;
    cout << "4- Cadastrar Cliente Juridico" << endl;
    cout << "5- Alterar Dados do  Cliente Juridico" << endl;
    cout << "6- Excluir Cliente Juridico" << endl;
    cin >> opt;
    return opt;
}

void CadastrarClienteFis(list<Cliente *> ListaDeClientes) {
    cin.clear();

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
    Cliente *novoCliente = new Cliente(nome, cpf, endereco, telefone, email);
    ListaDeClientes.push_front(novoCliente);
    cout << "Cliente Cadastrado com sucesso!" << endl;
    cout << "________________________________" << endl;
    cout << novoCliente->toString() << endl;
    cout << "________________________________" << endl;
}

void AlteraDadosClienteFis(list<Cliente *> ListaDeClientes, list<ContaCorrente *> ListaDeContas,
                           list<ContaPoupanca *> ListaContasPoup) {
    cin.clear();

    bool achou = false;
    string cpf, nome, email, endereco, telefone;
    cout << "Insira seu CPF:" << endl;
    getline(cin, cpf);
    //busca cpf do cliente na lista de clientes
    for (auto &cliente : ListaDeClientes) {
        if (cpf == cliente->getCpf()) {
            achou = true;
            for (auto &contaCorrente : ListaDeContas) {
                if (cpf == contaCorrente->getCpFcliente()) {

                    cout << "Esse cliente não pode ser alterado pois há contas vinculados a ele" << endl;

                    break;
                } else {
                    for (auto &contaPoup : ListaContasPoup) {
                        if (cpf == contaPoup->getCpfCliente()) {

                            cout << "Esse cliente não pode ser alterado pois há contas vinculados a ele" << endl;

                            break;
                        }
                    }
                }

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

                cliente->setNome(nome);
                cliente->setCpf(cpf);
                cliente->setEndereco(endereco);
                cliente->setTelefone(telefone);
                cliente->setEmail(email);
            }
        }
    }
    if (!achou)
        cout << "Cliente não encontrado, digite enter para voltar ao menu!" << endl;
}


void deletaClienteFis(list<Cliente *> ListaDeClientes, list<ContaCorrente *> ListaDeContas,
                      list<ContaPoupanca *> ListaContasPoup) {
    cin.clear();

    bool achou = false;
    bool temconta = false;
    string cpf;
    cout << "Insira o CPF do cliente que deseja deletar:" << endl;
    getline(cin, cpf);

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
            cout << "Esse cliente não pode ser deletado pois há contas vinculados a ele" << endl;
            break;
        }
    }
    if (!possuiContaCorrente) {
        bool possuiContaPoup = false;
        for (auto &ContaPoupanca : ListaContasPoup) {
            if (cpf == ContaPoupanca->getCpfCliente()) {
                possuiContaPoup = true;
                cout << "Esse cliente não pode ser deletado pois há pelo menos 01 ContaPoupanca vinculada a ele"
                     << endl;
                break;
            }
        }
        if (!possuiContaPoup) {
            ListaDeClientes.erase(ptrCliente); //remove cliente da lista
        }
    }
}


void CadastrarClienteJur(list<Juridico *> ListaClientesJur, list<Cliente *> ListaDeClientes) {
    cin.clear();

    bool achou = false;
    string cpfPJ;
    cout << "Insira o CPF do sócio marjoritario:" << endl;
    getline(cin, cpfPJ);
    //busca cpf do cliente na lista de clientes
    for (auto &cliente : ListaDeClientes) {
        if (cpfPJ == cliente->getCpf()) {
            achou = true;
            string nomePJ, cpfPJ, enderecoPJ, telefonePJ, emailPJ, cnpjPJ, atuacaoPJ, funcaoPJ, atualizacaoPJ;
            cout << "Insira o nome da Pessoa Juridica:" << endl;
            getline(cin, nomePJ);
            cout << "Insira o endereço:" << endl;
            getline(cin, enderecoPJ);
            cout << "Insira o telefone:" << endl;
            getline(cin, telefonePJ);
            cout << "Insira o e-mail:" << endl;
            getline(cin, emailPJ);
            cout << "Insira o CNPJ:" << endl;
            getline(cin, cnpjPJ);
            cout << "Insira a atuação:" << endl;
            getline(cin, atuacaoPJ);
            cout << "Insira a funcao" << endl;
            getline(cin, funcaoPJ);
            cout << "Insira a data da ultima atualização do contrato" << endl;
            getline(cin, atualizacaoPJ);

            Juridico *pj = new Juridico(nomePJ, cpfPJ, enderecoPJ, telefonePJ, emailPJ, cnpjPJ, atuacaoPJ, funcaoPJ,
                                        atualizacaoPJ);
            ListaClientesJur.push_front(pj);
            cout << "Cliente Cadastrado com sucesso!" << endl;
            cout << "________________________________" << endl;
            cout << pj->toString() << endl;
            cout << "________________________________" << endl;

        }
    }
    if (!achou)
        cout
                << "CADASTRO DE PESSOA JÚRIDICA NÃO AUTORIZADO! O sócio marjoritário não está cadastrado como cliente físico."
                << endl;

}

void AlteraDadosClienteJur(list<Juridico *> ListaClientesJur, list<ContaCorrente *> ListaDeContas) {
    cin.clear();

    bool achou = false;
    string cpf;
    cout << "Insira o CPF associado ao cliente juridico que deseja alterar dados" << endl;
    getline(cin, cpf);
    auto ptrCliente = ListaClientesJur.begin(); // inicia no primeiro cliente
    while (ptrCliente != ListaClientesJur.end()) { // enquanto nao acabar os clientes
        if (cpf == (*ptrCliente)->getCpf()) {
            achou = true;
            break;
        }
    }
    if (!achou) {
        cout << "Cliente Juridico nao encontrado" << endl;
        return;
    }


    bool possuiContaCorrente = false;
    for (auto &ContaCorrente : ListaDeContas) {
        if (cpf == ContaCorrente->getCpFcliente()) {
            possuiContaCorrente = true;
            cout << "Esse cliente não pode ter seu CNPJ alterado pois há contas vinculados a ele" << endl;
            return;
        }
    }


    string nomePJ, cpfPJ, enderecoPJ, telefonePJ, emailPJ, cnpjPJ, atuacaoPJ, funcaoPJ, atualizacaoPJ;

    cout << "Insira o nome da Pessoa Juridica:" << endl;
    getline(cin, nomePJ);
    cout << "Insira o CPF do sócio marjoritario:" << endl;
    getline(cin, cpfPJ);
    cout << "Insira o endereço:" << endl;
    getline(cin, enderecoPJ);
    cout << "Insira o telefone:" << endl;
    getline(cin, telefonePJ);
    cout << "Insira o e-mail:" << endl;
    getline(cin, emailPJ);
    cout << "Insira o CNPJ:" << endl;
    getline(cin, cnpjPJ);
    cout << "Insira a atuação:" << endl;
    getline(cin, atuacaoPJ);
    cout << "Insira a funcao" << endl;
    getline(cin, funcaoPJ);
    cout << "Insira a data da ultima atualização do contrato" << endl;
    getline(cin, atualizacaoPJ);

    (*ptrCliente)->setNome(nomePJ);
    (*ptrCliente)->setCpf(cpfPJ);
    (*ptrCliente)->setEndereco(enderecoPJ);
    (*ptrCliente)->setTelefone(telefonePJ);
    (*ptrCliente)->setEmail(emailPJ);
    (*ptrCliente)->setAtuacao(atuacaoPJ);
    (*ptrCliente)->setCnpj(cnpjPJ);
    (*ptrCliente)->setFuncao(funcaoPJ);


}

void deletaClienteJur(list<Juridico *> ListaClientesJur, list<ContaCorrente *> ListaDeContas) {
    cin.clear();

    bool achou = false;
    string cpf;
    cout << "Insira o CPF associado ao cliente juridico que deseja deletar:" << endl;
    getline(cin, cpf);
    auto ptrCliente = ListaClientesJur.begin(); // inicia no primeiro cliente

    while (ptrCliente != ListaClientesJur.end()) { // enquanto nao acabar os clientes
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
            cout << "Esse cliente não pode ser deletado pois há contas vinculados a ele" << endl;
            break;
        }
    }
    if (!possuiContaCorrente) {
        ListaClientesJur.erase(ptrCliente); //remove cliente da lista
    }
}

void criaContaCorrente(list<ContaCorrente *> ListaDeContas, list<Cliente *> ListaDeClientes) {
    cin.clear();

    bool achou = false;
    string cpf;
    cout << "Insira o CPF do cliente ja cadastrado no sistema:" << endl;
    getline(cin, cpf);
    //busca cpf do cliente na lista de clientes
    for (auto &cliente : ListaDeClientes) {
        if (cpf == cliente->getCpf()) {
            achou = true;
            ContaCorrente *nova_conta = new ContaCorrente(cpf);
            ListaDeContas.push_front(nova_conta);
            cout << "Conta Aberta com Sucesso! O numero da sua conta corrente é:" << nova_conta->GetNumero()
                 << endl;

        }
    }
    if (!achou)
        cout << "ABERTURA DE CONTA NÃO AUTORIZADA! O cliente náo esta cadastrado no sistema." << endl;


}

void alteraContaCorrente(list<ContaCorrente *> ListaDeContas) {
    cin.clear();

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
        }
    }
    if (!achou)
        cout << "Conta nao encontrada" << endl;
}

void deletaContaCorrente(list<ContaCorrente *> ListaDeContas) {
    cin.clear();

    bool achou = false;
    int numeroDaConta;
    cout << "Insira o número da conta que deseja deletar" << endl;
    cin >> numeroDaConta;
    auto ptrConta = ListaDeContas.begin(); // ponteiro para primeira conta da lista

    while (ptrConta != ListaDeContas.end()) { // enquanto nao acabarem as contas
        if (numeroDaConta == (*ptrConta)->GetNumero()) {
            achou = true;
            if ((*ptrConta)->getLancamentos().size() != 0) {
                cout << "Essa conta não pode ser deletada pois há lançamentos vinculados a ela" << endl;
                break;
            }


            ListaDeContas.erase(ptrConta); // remove conta da lista
            break;
        }
        ptrConta++; // avanca para a proxima conta
    }
    if (!achou)
        cout << "Conta nao encontrada " << endl;
}

void lancamentoContaCorrente(list<ContaCorrente *> ListaDeContas) {
    cin.clear();

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
    tm data = LerData();

    for (auto &ContaCorrente : ListaDeContas) {

        if (numeroDaConta == ContaCorrente->GetNumero()) {
            achou = true;
            if (!ContaCorrente->FazerLancamento(tipo_lancamento, valor, data)) {
                cout << "Sem saldo suficiente!" << endl;
            }

        }
    }
    if (!achou)
        cout << "Conta nao encontrada" << endl;

}

void exibeExtratoContaCorrente(list<ContaCorrente *> ListaDeContas) {
    cin.clear();

    int numeroDaConta;
    bool achou = false;
    cout << "Insira o número da conta que deseja ver o extrato" << endl;
    cin >> numeroDaConta;

    //loop na lista de contas
    for (auto &contaCorrente : ListaDeContas) {
        if (numeroDaConta == contaCorrente->GetNumero()) {
            achou = true;
            tm inicio, fim;
            cout << "Insira o inicio do intervalo de duração do extrato:" << endl;
            inicio = LerData();
            cout << "Insira o final do intervalo de duração do extrato:" << endl;
            fim = LerData();

            contaCorrente->imprimeExtrato(inicio, fim);

        }
    }
    if (!achou)
        cout << "Conta nao encontrada" << endl;

}

void exibeDadosContaCorrente(list<ContaCorrente *> ListaDeContas) {
    cin.clear();

    int numeroDaConta;
    bool achou = false;
    cout << "Insira o número da conta que deseja ver" << endl;
    cin >> numeroDaConta;

    //loop na lista de contas
    for (auto &contaCorrente : ListaDeContas) {
        //encontra a conta desejada
        if (numeroDaConta == contaCorrente->GetNumero()) {
            achou = true;
            cout << contaCorrente->toString() << endl;
        }
    }
    if (!achou)
        cout << "Conta nao encontrada" << endl;
}

void criaContaPoup(list<ContaPoupanca *> ListaContasPoup) {
    cin.clear();

    string cpf;
    cout << "Insira o cpf do cliente para criação da conta poupança:" << endl;
    getline(cin, cpf);
    ContaPoupanca *nova_conta = new ContaPoupanca(cpf);
    ListaContasPoup.push_front(nova_conta);
    cout << "Conta Aberta com Sucesso! O numero da sua conta é:" << nova_conta->GetNumero() << endl;
}

void deletaContaPoup(list<ContaPoupanca *> ListaContasPoup) {
    cin.clear();

    bool achou = false;
    int numeroDaConta;
    cout << "Insira o número da conta poupanca que deseja deletar" << endl;
    cin >> numeroDaConta;
    auto ptrConta = ListaContasPoup.begin(); // ponteiro para primeira conta da lista

    while (ptrConta != ListaContasPoup.end()) { // enquanto nao acabarem as contas
        if (numeroDaConta == (*ptrConta)->GetNumero()) {
            achou = true;
            if ((*ptrConta)->getLancamentos().size() != 0) {
                cout << "Essa conta não pode ser deletada pois há lançamentos vinculados a ela" << endl;
            }
            ListaContasPoup.erase(ptrConta); // remove conta da lista

        }
        ptrConta++; // avanca para a proxima conta
    }
    if (!achou)
        cout << "Conta nao encontrada " << endl;
}

void lancamentoContaPoup(list<ContaPoupanca *> ListaContasPoup) {
    cin.clear();

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

    for (auto &ContaPoupanca : ListaContasPoup) {

        if (numeroDaConta == ContaPoupanca->GetNumero()) {
            achou = true;
            if (!ContaPoupanca->FazerLancamento(tipo_lancamento, valor)) {
                cout << "Sem saldo suficiente!" << endl;
            }
        }
    }
    if (!achou)
        cout << "Conta nao encontrada" << endl;

}

void exibeExtratoContaPoup(list<ContaPoupanca *> ListaContasPoup) {
    cin.clear();

    int numeroDaConta;
    bool achou = false;
    cout << "Insira o número da conta que deseja ver o extrato" << endl;
    cin >> numeroDaConta;

    //loop na lista de contas
    for (auto &contaPoupanca : ListaContasPoup) {
        if (numeroDaConta == contaPoupanca->GetNumero()) {
            achou = true;
            tm inicio, fim;
            cout << "Insira o inicio do intervalo de duração do extrato:" << endl;
            inicio = LerData();
            cout << "Insira o final do intervalo de duração do extrato:" << endl;
            fim = LerData();

            contaPoupanca->imprimeExtrato(inicio, fim);

        }
    }
    if (!achou)
        cout << "Conta nao encontrada" << endl;

}