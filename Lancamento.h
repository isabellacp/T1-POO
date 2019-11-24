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
	time_t getDataLancamento();
	void setDataLancamento(time_t);

	float getSaldoAnterior();


private:
	string type;
	float valor = 0;
	time_t DataLancamento = time(0);
	float SaldoAnterior;

};

#endif