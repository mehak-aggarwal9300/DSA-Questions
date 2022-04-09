#include<stdio.h>
#include<stdlib.h>

//error: function returns address of local variable [-Wreturn-local-addr]
//all local variables are destroyed and your pointer will be pointing to someplace in the memory that you no longer own.
//If a pointer is referring to an object that is destroyed, the pointer is said to be a dangling pointer until it is given a new value.

// int *merge(int *arr1,int *arr2){
//     int i=0;
//     int arr3[(sizeof(arr1)+sizeof(arr2))/4];
    
//     while(i<((sizeof(arr1)+sizeof(arr2))/4))
//     if(*arr1>*arr2) 
//     {   arr3[i]=*arr1;
//         i++;
//         arr1++;
//     }
//     else
//     {   arr3[i]=*arr2;
//         i++;
//         arr2++;
//     }
//     //rn rest of the arr2 and arr1 is left
//     return arr3;

// }

void mergearr(int a1[],int a2[],int m, int n, int arr3[])
{ 
    int i=0,j=0,k=0;
    while(m>i&&n>j){
        if(a1[i]>a2[j])
        {   //when both arrays have elements
            arr3[k]=a2[j];
            j++;
            k++;
        }
        else 
        {   arr3[k]=a1[i];
            i++;
            k++;
        }        

    }
    while(n>j){
        // only a2 has elements
        arr3[k]=a2[j];
        j++;
        k++;    
    }

    while(m>i){
        // only 1 has elements
        arr3[k]=a1[i];
        k++;
        i++;
        }   
    // return arr3;
}


void display(int arr[],int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr1[]={1,3,5,10,18,60,67,70};
    int arr2[]={4,6,7,9,34,38,50};
    int m= sizeof(arr1)/sizeof(arr1[0]);
    int n= sizeof(arr2)/sizeof(arr2[0]);
    int arr3[m+n];
    printf("Array 1:");
    display(arr1,m);
    printf("\nArray 2:");  
    display(arr2,n);      
    mergearr(arr1,arr2,m,n,arr3);
    printf("\nMerged array:");
    display(arr3,m+n);

    return 0;
}