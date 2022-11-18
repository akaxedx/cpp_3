#include "Stack.h"
#include "require.h"
using namespace std;
void
Stack::Link::initialize(void* dat, Link* nxt){
        data = dat;
        next = nxt;
}

void Stack::initialize(){head = 0;}//初始化栈,head为0表示栈顶

void Stack::push(void* dat){
        Link* newLink = new Link;
        newLink -> initialize(dat,head);
        head = newLink;
}//新数据存放栈顶

void* Stack::peek(){
        require(head != 0, "Stack empty");
        return head -> data;//返回栈顶数据
}

void* Stack::pop(){
        if(head == 0) return 0;
        void* result = head -> data;
        Link* oldHead = head;
        head = head -> next;//栈顶下移
        delete oldHead;//删除栈顶
        return result;
}

void Stack::cleanup(){
        require(head == 0, "Stack not empty");
}
