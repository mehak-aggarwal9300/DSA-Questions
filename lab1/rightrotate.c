#include<stdio.h>

//reverse by pointers***

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
void rotate(int* arr,int n,int k){
    k=k%n; //rotating index can be greater than length of array too
    k= k<0?k+n:k;

    reverse(arr,0,n-k-1);    //p1'
    reverse(arr,n-k,n-1);    //p2'
    reverse(arr,0,n-1);      // (whole)' i.e. (p2'p1')' i.e. p2p1


}
void display(int* arr,int n){
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    } printf("\n");

}

int main()
{
    int ar[]={2,9,8,1,3,5,7};
    int *arr=ar;
    //or input k(no. of rotations)
    display(arr,7); //to display original
    rotate(arr,7,3); //k=3
    display(arr,7);

    rotate(arr,7,1);
    display(arr,7);

    rotate(arr,7,2);
    display(arr,7);

}

