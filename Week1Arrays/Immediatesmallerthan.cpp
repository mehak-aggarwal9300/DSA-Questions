// https://practice.geeksforgeeks.org/problems/find-immediate-smaller-than-x/1/
// idk didn't submit

class Solution{
    public:
    // User function to complete
    // arr[]: input array
    // n: size of array
    // k: find element smaller and closest to it. 
    int immediateSmaller(int arr[], int n, int x)
    {
        if(n==1) 
        {   if(arr[n-1]<x)
                return arr[n-1];
            else return -1;
        }
        
        int ssf=immediateSmaller(arr,n-1,x);
        if((arr[n-1]>ssf)&&(arr[n-1]<x)) ssf=arr[n-1];
        
        return ssf;
        
    }
};