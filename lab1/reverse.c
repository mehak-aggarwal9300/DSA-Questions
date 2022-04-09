#include<stdio.h>

int main()
{
    int arr[]={10,20,30,40,50};
    int size = sizeof(arr)/4;

    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");

    for(int i=0,j=size-1;i<=j;i++,j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }

}