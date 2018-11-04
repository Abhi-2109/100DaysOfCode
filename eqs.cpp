#include <bits/stdc++.h>
#define pb push_back
using namespace std;
int main()
{
stack<int> a,b,c;
int x,s=0,p,y,z,flag=0;
vector<int> s1,s2,s3;
cin>>p>>y>>z;
for(int i=1;i<=p;i++)
{cin>>x; s1.pb(x);}
for(int i=1;i<=y;i++)
{cin>>x; s2.pb(x);}
for(int i=1;i<=z;i++)
{cin>>x; s3.pb(x);}

for(int i=1;i<=p;i++)
{s+=s1.back(); a.push(s); s1.pop_back();}
s=0;
for(int i=1;i<=y;i++)
{s+=s2.back(); b.push(s); s2.pop_back();}
s=0;
for(int i=1;i<=z;i++)
{s+=s3.back(); c.push(s); s3.pop_back();}
s=0;
while((!a.empty()||!b.empty()||!c.empty())&&!(a.top()==b.top()&&b.top()==c.top()))
{
  int max1=max(max(a.top(),b.top()),c.top());
  if(a.top()==max1)
  a.pop();
  else if(b.top()==max1)
  b.pop();
  else
  c.pop();
  if(a.empty()||b.empty()||c.empty())
    {   flag=1; break; }
}
if(flag==1)
cout<<"0"<<endl;
else
cout<<a.top()<<endl;
}
