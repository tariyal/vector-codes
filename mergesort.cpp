#include <iostream>
#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& arr,int l,int mid,int r)
{
	vector<int> newarr(r-l+1);
	int i=l,j=mid+1,k=0,var;
	while(i<=mid || j<=r )
	{
		var=1;
		if(i>mid) var = 0;
		if(var==0 || (j<=r && arr[i]>arr[j])){
			newarr[k]=arr[j];
			j++;
		}
		else{
			newarr[k]=arr[i];
			i++;
		}
		k++;
	}
	for(i=l;i<=r;i++)
		arr[i] = newarr[i-l];
}
void printarr(vector<int> arr)
{
	for(int i=0;i<arr.size();i++)
		cout<<arr[i]<<" ";
	cout<<endl;
}
void mergesort(vector<int>& arr,int l,int r)
{
	if(l>=r) return ;
	int mid = l+(r-l)/2;
	mergesort(arr,l,mid);
	mergesort(arr,mid+1,r);
	merge(arr,l,mid,r);
}	
int main() {
	// your code goes here
	int N;
	cin>>N;
	vector<int> arr(N);
	for(int i=0;i<N;i++)
		cin>>arr[i];
	mergesort(arr,0,N-1);
	printarr(arr);
	return 0;
}
