#ifndef LANCAMENTO_H
#define LANCAMENTO_H

#include <string>
#include <time.h>
using namespace std;
class Lancamento {
public:
	Lancamento(string type, float valor, float saldoAnterior);
	string getType();
	float getValor();
	tm getDataLancamento();
	void setDataLancamento(int dia, int mes, int ano, int hora, int segundo);
	void setDataLancamento(tm);

	float getSaldoAnterior();
	string toString();


private:
	string type;
	float valor = 0;
	time_t DataLancamento;
	float SaldoAnterior;

};

#endif