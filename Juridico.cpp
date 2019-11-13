#include "Juridico.h"

int Juridico::TotalClientesJuridico = 0;

//construtor
Juridico :: Juridico (string nome, string cpf, string endereco, string telefone, string 
    email, string cnpj, string atuacao, string funcao, string atualizacao) {
	TotalClientesJuridico++;
	NumeroClienteJuridico = TotalClientesJuridico;
	Nome = nome;
        CPF = cpf;
       Endereco = endereco;
       Telefone = telefone;
       Email = email;
       cnpj = cnpj;
       atuacao = atuacao;
       funcao = funcao;
       atualizacao = atualizacao;         
}



//getters e setters
const string &Juridico::getCnpj() const {
    return cnpj;
}

void Juridico::setCnpj(const string cpnj) {
    cnpj = cnpj;
}

const string &Juridico::getAtuacao() const {
    return atuacao;
}

void    Juridico ::setAtuacao(string atuacao) {
    atuacao = atuacao;

}

const string &Juridico::getFuncao() const {
    return funcao;
}

void Juridico::setFuncao(string funcao) {
    funcao = funcao;
}

const string &Juridico::getAtualizacao() const {
    return atualizacao;
}

void Juridico::setAtualizacao(string atualizacao) {
    atualizacao = atualizacao;
}

int Juridico::getTotalClientesJuridico() {
	return TotalClientesJuridico;
}

