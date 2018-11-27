#include <iostream>
using namespace std;
int main()
{
//To merge two sorted arrays
//Enter two sorted arrays
int s1,s2;
cout<<"Enter size of first and second array\n";
cin>>s1>>s2;
//Make arrays of one more element to mark infinity
int a[s1+1],b[s2+1];
cout<<"Enter the elements of first array\n";
for(int i=0;i<s1;i++)
cin>>a[i];
//Mark the end of each array as infinity to copy another array if one ends
a[s1]=100000;
cout<<"Enter the elements of second array\n";
for(int i=0;i<s2;i++)
cin>>b[i];
//Mark the end as infinity
b[s2]=100000;

//A new array of size s1+s2 is made
int r[s1+s2];
//Two pointers are used to mark the merged index of each array
int m=0,n=0;
for(int i=0;i<s1+s2;i++)
{
	if(a[m]<=b[n])	//whichever is least 
	{
		r[i]=a[m];	//copy the value to new array of size s1 + s2
		m++;		//the pointer is moved further
	}
	else
	{
		r[i]=b[n];	//copy the value to new array
		n++;		//the second pointer is moved further
	}
}
for(int i=0;i<s1+s2;i++)
cout<<r[i]<<" ";

}
