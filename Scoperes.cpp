#include <iostream>
using namespace std;
int a = 10;
void f(){
        cout << "all" << endl;
};

struct S{
        int a;
        void f();
};

void S::f(){
        ::f();
        ::a++;
        a--;
        cout << "a = " << a << endl;
        cout << "::a = " << ::a <<endl;
}
int main(){
        S s; 
        s.a = 10;
        s.f();
        ::f();
}
