//
// Created by isabe on 03/10/2019.
//

#ifndef T1_POO_CLIENTE_H
#define T1_POO_CLIENTE_H

#include <string>
#include "ContaCorrente.h"

using namespace std;

// Classe Cliente
class Cliente{
public:
    //Construtor
    Cliente(string nome, string cpf, string endereco, string telefone, string email);
    ~Cliente();
    void CriaConta();
    void ExlcuirConta();
//getter e setters
    const string &getNome() const;
    void setNome(const string &nome);

    const string &getCpf() const;
    void setCpf(const string &cpf);

    const string &getEndereco() const;
    void setEndereco(const string &endereco);

    const string &getTelefone() const;
    void setTelefone(const string &telefone);

    const string &getEmail() const;

    void setEmail(const string &email);

    ContaCorrente *getConta() const;

    void setConta(ContaCorrente *conta);

private:
    string Nome;
    string CPF;
    string Endereco;
    string Telefone;
    string Email;
    ContaCorrente *Conta;

};

#endif //T1_POO_CLIENTE_H
