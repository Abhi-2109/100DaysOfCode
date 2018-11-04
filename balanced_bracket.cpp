#include <iostream>
#include <stack>
using namespace std;
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
  string s;
  int f=0;
  stack<char> s1;
  cin>>s;
  for(int i=0;i<s.length();i++)
  {
    if(f==1)
    break;
    char ch=s[i];

    switch(ch)
    {
      case '{':
      case  '(':
      case '[': s1.push(ch);  //push the opening brackets on the stack
      break;
        //For closing brackets
        //Ensure that the stack is not empty as opening bracket is must for closing bracket
        //if the top of stack contains the matching opening bracket then pop it
        //else mark as unbalanced (f=1)
      case '}':
        if(s1.empty())
        f=1;  //mark unbalanced if stack is already empty
        else if(s1.top()=='{')
        s1.pop(); //pop the matching opening bracket
        else
        f=1;  //mark unbalanced
        break;
      case ')':
        if(s1.empty())
        f=1;
        else
        if(s1.top()=='(')
        s1.pop();
        else
        f=1;
        break;
      case ']':
      if(s1.empty())
      f=1;
      else if(s1.top()=='[')
      s1.pop();
      else
      f=1;
      break;
    }
  }
  if(s1.empty()&&f!=1)
  cout<<"YES\n";
  else
  cout<<"NO\n";
}
}
