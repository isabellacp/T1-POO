#include "Juridico.h"
#include <string>
#include <ctime>
#include <iostream>

using namespace std;
int Juridico::TotalClientesJuridico = 0;

//construtor
Juridico :: Juridico (string nome, string cpf, string endereco, string telefone, string 
    email, string cnpj, string atuacao, string funcao, string atualizacao){
	setNome(nome);
		setCpf(cpf);
	setEndereco(endereco);
		setTelefone(telefone);
	setEmail(email);
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
string Juridico::toString() const{
	string result;
	ostringstream sJuridico;
	sJuridico << endl<< "CNPJ: " << this->Cnpj << endl
	     << "Atuacao: " << this->Atuacao << endl
		<< "Funcao: " << this->Funcao << endl
		<< "Ultima data de atualizacao do Contrato " << this->Atualizacao <<endl;
	result = sJuridico.str();
	
	return result;

}



