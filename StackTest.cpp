#include "Stack.h"
#include "require.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main(int argc, char* argv[]){
        requireArgs(argc, 1);
        ifstream in(argv[1]);
        assure(in, argv[1]);
        Stack textlines;
        textlines.initialize();
        string line;
        while(getline(in, line))
                textlines.push(new string(line));
        string* s;
        while((s = (string*)textlines.pop()) != 0){
                cout << *s <<endl;
                delete s;
        }
        textlines.cleanup();
}
