#include <iostream>
#include <ctime>
#include <list>

using namespace std;

//struct para encapsular dados de um lancamento;
struct Lancamento{
    string tipo;
    int valor;
    time_t DataLancamento;
};


//Classe Conta Corrente
class ContaCorrente {
public:
    //construtor
    ContaCorrente(int numero, string cpfCLIENTE, float saldoATUAL) {
        Numero = numero;
        CPFcliente = cpfCLIENTE;
        SaldoAtual= saldoATUAL;
        DataAbertura = time(0); //retorna a data atual

    };
    //getter - retorna uma representação em string da data de abertura da conta
    char *GetDataAbertura() {
        return (char *) ctime(&DataAbertura);
    }
    void ImprimirExtrato();
    void FazerLancamento();
private:
    int Numero;
    string CPFcliente;
    time_t DataAbertura;
    float SaldoAtual;
    list <Lancamento> ListaLancamento;

};

// Classe Cliente
class Cliente {
public:
    Cliente(string nome, string cpf, string endereco, string telefone, string email) {
        Nome = nome;
        CPF = cpf;
        Endereco = endereco;
        Telefone = telefone;
        Email = email;
    };   //Construtor
    void CriaConta();
    void AlterarConta();


private:
    string Nome;
    string CPF;
    string Endereco;
    string Telefone;
    string Email;
    ContaCorrente Conta;
};

int main() {

    return 0;
}