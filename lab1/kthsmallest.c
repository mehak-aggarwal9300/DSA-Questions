// time complexity O(n)
//Quickselect
#include<stdio.h>

void swap(int arr[], int i ,int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int partition(int arr[],int pivot, int lo,int hi)
{  printf("\npivot: %d ",pivot);
    int i=lo,j=lo;
    while(i<=hi){
        if(arr[i]<=pivot){
            swap(arr,i,j);
            i++; 
            j++;    //pivot pe reach krne ke baad ek extra ++ ho rha hai

        }else i++;
        
    } 
    printf("pivot index: %d",j-1);
    return (j-1);

}

int quickselect(int arr[],int lo, int hi, int k){ //k is index
    int pivot=arr[hi];
    int pindx= partition(arr,pivot, lo,hi);
    if(pindx==k) return arr[pindx];
    else if(pindx<k){
        return quickselect(arr,pindx+1,hi,k);
    } else return quickselect(arr,lo,pindx-1,k);
}

void print(int arr[],int size){
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
}

int main()
{
    int arr[]={2,8,1,3,7,6,4,5};
    int size=sizeof(arr)/4;
    printf("Array: ");
    print(arr,size);
    int k=4;
    int ans= quickselect(arr,0,size-1,k-1);
    printf("\n%dth smallest element is: %d", k, ans);


}