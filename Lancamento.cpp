#include "Lancamento.h"
#include <string>
#include <sstream>
using namespace std;
Lancamento::Lancamento(string type, float valor, float saldoAnterior)
{
	this->type = type;
	this->valor = valor;
	this->SaldoAnterior = saldoAnterior;
}

string Lancamento::getType()
{
	return type;
}

float Lancamento::getValor()
{
	return valor;
}

tm Lancamento::getDataLancamento()
{
	return *localtime(&DataLancamento);
}
void Lancamento::setDataLancamento(tm data)
{
	DataLancamento = mktime(&data);
}


float Lancamento::getSaldoAnterior()
{
	return SaldoAnterior;
}
string Lancamento::toString() {
		
		ostringstream output;
		output << "Tipo: " << type << endl;
		output << "Valor: " << valor << endl;
			output << "Saldo Anterior: " << SaldoAnterior << endl;
			output << "Data: " << ctime(&DataLancamento) << endl;
	
		return output.str();
	

}
