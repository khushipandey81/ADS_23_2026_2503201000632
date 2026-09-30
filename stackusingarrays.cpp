#include <iostream>
using namespace std;

    int stack[5];
    int top=-1;
    void push (int x)
    {
        if (top==4){
        cout<<"stack is overflow";
    }
    
    else {
    stack[++top]=x;
    }
}
int main (){
    push(5);
    push(20);
    cout<< stack[top];
    return 0;
}


