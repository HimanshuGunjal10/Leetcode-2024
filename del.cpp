#include <iostream>
#include "del.h"
using namespace std;

void A::foo()
{
    cout << "I'm in A" << endl;
}

void B::foo()
{
    cout << "I'm in B" << endl;
}

int main()
{
    A a;
    B b;
    C c;
    a.foo();
    b.foo();
    c.foo();
    cout << endl << "La fin!" << endl;
}