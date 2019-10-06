#include <iostream>
#include <ctime>
#include <list>
#include "ContaCorrente.h"
#include "Cliente.h"


using namespace std;


int main() {
    ContaCorrente a = ContaCorrente("asdasdad");
    cout << a.GetNumero()<< endl;

    float v = 1.20;
    float d = 3.20;
    int deb=1, cred=2;

    ContaCorrente::getQuantidadeContas();
    cout << ContaCorrente::getQuantidadeContas() << endl;
    /*cout << a.getSaldoAtual() << endl;
    a.FazerLancamento(cred,d);
    cout << a.getSaldoAtual() << endl;
    a.FazerLancamento(1,v);
    cout << a.getSaldoAtual() << endl;*/

    ContaCorrente b = ContaCorrente("asdasdad");
    ContaCorrente c = ContaCorrente("asdasdad");
    ContaCorrente f = ContaCorrente("asdasdad");
    ContaCorrente e = ContaCorrente("asdasdad");
    cout << ContaCorrente::getQuantidadeContas() << endl;

    return 0;
}