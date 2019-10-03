#include <iostream>
#include <ctime>
#include <list>
#include "ContaCorrente.h"
#include "Cliente.h"


using namespace std;


int main() {
    ContaCorrente a = ContaCorrente("asdasdad");
    cout << a.GetNumero()<< endl;
    ContaCorrente b = ContaCorrente("asdasdad");
    cout << b.GetNumero()<< endl;
    ContaCorrente c = ContaCorrente("asdasdad");
    return 0;
}