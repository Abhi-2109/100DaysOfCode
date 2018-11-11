#include <stack>
#include <iostream>
#include <algorithm>
using namespace std;
int main() {
    int test,x,ch;
    cin>>test;
    stack<int> a,b;
    while(test>0)
    {
    cin>>ch;
    switch(ch)
    {
        case 1: cin>>x;
               a.push(x); //push everything to stack a
               break;
        case 2:
            if(b.empty()) //if b is empty then the front of queue is at the end of stack 'a'
            {
            while(!a.empty())
            {
                b.push(a.top());  //push every item to stack 'b' till 'a' is not empty
                a.pop();          //pop the top of stack 'a'
            }
            }
            else  { //else the front of queue is at the top of stack 'b'
              b.pop();  //remove the front of queue
              break; }
            b.pop();
            break;
        case 3:
            if(b.empty()) {
            while(!a.empty())
            {
                b.push(a.top());
                a.pop();
            }
            cout<<b.top()<<endl;
            }
            else  //if b is not empty then print top of b
            cout<<b.top()<<endl;
            break;
    }
        test--;
    }
    return 0;
}
