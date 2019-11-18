#ifndef CONTAPOUPANCA_H
#define CONTAPOUPANCA_H

#include <string>
#include <list>
#include <ctime>

#include "Cliente.h"
using namespace std;

struct LancamentoP{
    string typeP;
    float valorP = 0;
    time_t DataLancamentoP = time (0);
	float SaldoAnteriorP; 

};

class ContaPoupanca : public Cliente{
public:
    //construtor
    ContaPoupanca();
    //destrutor
    ~ContaPoupanca();
    
    list <struct LancamentoP> extratoP;
    char *GetDataAbertura();
    //retorna o numero da conta
    int GetNumero(); 
    void debitoConta(float);
    void creditoConta(float);
    bool FazerLancamento(int, float);
    //retorna o extrato
    list <struct LancamentoP> getExtrato();    
    static int getQuantidadeContas(); 
    static float getMontanteTotal();
    string toString();
    
    //getter e setter para o CPF do cliente
    const string &getCpfCliente() const;
    void setCpfCliente(const string &cpfCliente);
    
    
     //getter e setter para a Data de Abertura da conta
    time_t getDataAbertura() const;
    void setDataAbertura(time_t dataAbertura);
    
    //setter e getter para o saldoAtual
    float getSaldoAtual() const;
    void setSaldoAtual(float saldoAtual);
private:
    static int NumeroGlobalP; //controla o numero da conta
    static float MontanteTotalP;
    int NumeroP;  //numero da conta
    string CPFcliente;
    time_t DataAbertura;
    float SaldoAtualP;
}


#endif /* CONTAPOUPANCA_H */

