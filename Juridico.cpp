#include "Juridico.h"

int Juridico::TotalClientesJuridico = 0;

//construtor
Juridico :: Juridico (string nome, string cpf, string endereco, string telefone, string 
    email, string cnpj, string atuacao, string funcao, string atualizacao):Cliente(nome, cpf, endereco, telefone, email) {
	TotalClientesJuridico++;
	NumeroClienteJuridico = TotalClientesJuridico;
       Cnpj = cnpj;
       Atuacao = atuacao;
       Funcao = funcao;
       Atualizacao = atualizacao;         
}



//getters e setters
const string &Juridico::getCnpj() const {
    return Cnpj;
}

void Juridico::setCnpj(const string cnpj) {
    Cnpj = cnpj;
}

const string &Juridico::getAtuacao() const {
    return Atuacao;
}

void    Juridico ::setAtuacao(string atuacao) {
    atuacao = atuacao;

}

const string &Juridico::getFuncao() const {
    return Funcao;
}

void Juridico::setFuncao(string funcao) {
    funcao = funcao;
}

const string &Juridico::getAtualizacao() const {
    return Atualizacao;
}

void Juridico::setAtualizacao(string atualizacao) {
    atualizacao = atualizacao;
}

int Juridico::getTotalClientesJuridico() {
	return TotalClientesJuridico;
}

