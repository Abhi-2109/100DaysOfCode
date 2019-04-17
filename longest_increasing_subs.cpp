#include<iostream>
using namespace std;

int lis(int* arr,int n)
{
	int* dp=new int[n+1];
  //Set minimum LIS to 1 for all elements
	for(int i=0;i<n;i++) dp[i]=1;
	
	for(int i=0;i<n;i++){
  //Check previous elements and choose maximum LIS if the element is <= the current element
		for(int j=0;j<i;j++){
			if(arr[j]<=arr[i]){
			dp[i]=max(dp[j]+1,dp[i]);
				}
			}
		}
		int best=0;
		for(int i=0;i<n;i++){
    //Print length of LIS for each element till that position
			cout<<dp[i]<<" ";
			if(best<dp[i])
			best=dp[i];
		}
		cout<<endl;
		return best;
}
int main(){
	int n; cin>>n;
	int* a=new int[n];
	for(int i=0;i<n;i++) cin>>a[i];
	cout<<lis(a,n)<<endl;
}
