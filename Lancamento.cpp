#include "Lancamento.h"

Lancamento::Lancamento(string type, float valor, float saldoAnterior)
{
	this->type = type;
	this->valor = valor;
	this->DataLancamento = time(0);
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

time_t Lancamento::getDataLancamento()
{
	return DataLancamento;
}
void Lancamento::setDataLancamento(time_t data)
{
	DataLancamento = data;
}


float Lancamento::getSaldoAnterior()
{
	return SaldoAnterior;
}
