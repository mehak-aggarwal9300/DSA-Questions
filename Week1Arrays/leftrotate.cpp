//https://practice.geeksforgeeks.org/problems/rotate-array-by-n-elements-1587115621/1/?category%5B%5D=Arrays&category%5B%5D=Arrays&difficulty%5B%5D=0&page=1&query=category%5B%5DArraysdifficulty%5B%5D0page1category%5B%5DArrays


class Solution{
    public:
    
    void swap(int* a,int* b){
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

    
    //Function to rotate an array by d elements in counter-clockwise direction. 
    void rotateArr(int arr[], int k, int n){
        k=k%n; //rotating index can be greater than length of array too
        k=k<0?k+n:k;

        reverse(arr,0,k-1);    //p1'
        reverse(arr,k,n-1);    //p2'
        reverse(arr,0,n-1);      // (whole)' i.e. (p2'p1')' i.e. p2p1
    }
};