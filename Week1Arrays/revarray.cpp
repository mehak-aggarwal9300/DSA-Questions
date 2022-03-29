//https://practice.geeksforgeeks.org/problems/reverse-an-array/0#
//didn't get accepted :\

#include <iostream>
using namespace std;

void swap(int* a,int* b)
{
     int temp=*a;
    *a=*b;
    *b=temp;   
}

void reverse(int* arr,int l,int r)
{
    while(l<r){
            
        swap(&arr[l],&arr[r]);
        l++;
        r--;
    }

}


int main() {
	int t,n;
	cin>>t>>n;
	int arr[n];
	
	for(int cs=1;cs<=t;cs++)
	for(int i=0;i<n;i++)
	{
	    cin>>arr[i];
	}
     reverse(arr,0,n-1) ; 
    
    
	for(int i=0;i<n;i++)
	{
	    cout<<arr[i]<<" ";
	}
    
	return 0;
}