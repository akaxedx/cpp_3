#include "Clib.h"
#include "CppLib.h"
#include <iostream>
using namespace std;

struct A{
        int i[100];
};

struct B{
        void f();
};

void B::f(){}
int main(){
        cout << "sizeof struct A = " << sizeof(A)
             << " bytes //int[100]" << endl;
        cout << "sizeof struct B = " << sizeof(B)
             << " bytes //void f()" << endl;
        cout << "sizeof(CStash) in C = "
             << sizeof(CStash) << " bytes //int,int,int,uchar" << endl;
        cout << "sizeof(Stash) in C++ = "
             << sizeof(Stash) << " bytes //int*3,uchar*1,void()*3,void*()*1,int()*1" << endl;
}
