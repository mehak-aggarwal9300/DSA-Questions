#include<stdio.h>


void linear(int arr[],int n,int ele)
{   int i;
    for(i=0;i<n;i++)
    {
       if(arr[i]==ele)
       {
           printf("element found at pos %d",i+1);
           return;
       }
   }
      printf("element not found");
       return;
}

int recursivelinear(int arr[], int n,int key, int idx)
{
    if(idx==n) return -1;
    if(arr[idx]==key) return idx;
    else{
        return recursivelinear(arr,n,key,idx+1);
    }
    return -1;
}


void iterativebinary(int arr[],int beg,int end, int ele){
    printf("Hope your array is sorted!");
    int mid=(beg+end)/2;
    while(beg<=end){
        mid=(beg+end)/2;
        if(arr[mid]==ele){
            printf("Element found at pos: %d", mid+1);
            return;
        }
        else if(arr[mid]>ele){
            end=mid-1;
        }
        else{
            beg=mid+1;
        }
    }
    printf("Element not found!");
    return;
}


int recursivebinary(int arr[], int beg, int end, int ele)
{
    if(beg>end){
        return -1;
    }
    int mid=(beg+end)/2;
    if(arr[mid]==ele){
        printf("Element found at loc: %d",mid+1);
        return mid+1;
    }
    else if(arr[mid]>ele){
        recursivebinary(arr,beg,mid-1,ele);
    }
    else{
        recursivebinary(arr,mid+1,end,ele);
    }
}

int main()
{
   int n,i, ele;
   printf("Enter length:");
   scanf("%d",&n);
   int arr[n];
   for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
   }

   printf("Enter element to be searched:");
   scanf("%d",&ele);
    // linear(arr,n,ele);
    // iterativebinary(arr,0,n-1,ele);
    int rec = recursivebinary(arr,0,n-1,ele);
    if(rec==-1)printf("element not found");
    else printf("found");
    // int rec = recursivelinear(arr,n,ele,0);
    // if(rec==-1)printf("element not found");
    // else printf("found at %d",rec+1);
    return 0;
}