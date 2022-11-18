#include "Clib.h"
#include <fstream>
#include <iostream>
#include <string.h>
#include <cassert>
using namespace std;

int main(){
	CStash intStash, stringStash;
	int i;
	char* cp;
	ifstream in;
	string line;
	const int bufsize = 150;
	initialize(&intStash, sizeof(int));//初始化intStash,元素大小为int即8bit
	for(int i = 0; i < 100; i++)
                add(&intStash, &i);//给结构体存入数据
	for(int i = 0; i < count(&intStash); i++)
		cout << "fetch(&intStash, " << i << ") = "
		     << *(int*)fetch(&intStash, i)//fetch为void*类型转为int*后再*取值
		     << endl;
	initialize(&stringStash,sizeof(char)*bufsize);//bufsize为每个元素所占的最大大小
	in.open("ClibTest.cpp");
	assert(in);
	while(getline(in, line))
		add(&stringStash,line.c_str());
	i = 0;
	while((cp = (char*)fetch(&stringStash,i++)) != 0)
		cout << "fetch(&stringStash, " << i << ") = "
	             << cp << endl;
	cleanup(&intStash);
	cleanup(&stringStash);
}
