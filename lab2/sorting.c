#include<stdio.h>

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
  
void bubbleSort(int arr[], int n)
{   printf("Bubble sort");
   int i, j;
   for (i = 0; i < n-1; i++)      
    {   
        printf("\niteration %d",i+1);
        // Last i elements are already in place   
       for (j = 0; j < n-i-1; j++) 
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
    }
}

void selectionSort(int arr[], int n)
{    printf("Selection sort");
    int i, j, min_idx;
 
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {    printf("\niteration %d",i+1);
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
 
        // Swap the found minimum element with the ith element
        swap(&arr[min_idx], &arr[i]);
    }
}

void insertionSort(int arr[], int n)
{   printf("Insertion sort");

    int i, key, j;
    for (i = 1; i < n; i++) {
         printf("\niteration %d",i);
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// mergesort is an extension to merge sorted lists
//doubt: dry run, code in c
void mergeSort(int arr[], int l, int r)
{   
    if (l < r) {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l + (r - l) / 2;    //doubt: understand this
        // int m=(l+r)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void merge(int arr[],int l,int m,int r){
    int i,j,k;
    int n1=m-l+1;
    int n2=r-m;
    //doubt: any other way to avoid making temp? is temp here bad for optimization?
    int L[n1], R[n2];
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i=0;
    j=0;
    k=l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
  
}


void swap2(int arr[], int i, int j) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
  }


int partition(int arr[],int pivot, int lo, int hi){
    printf("\npivot: %d [%d",pivot,hi);
    int i=lo,j=lo;

    while (i<=hi)
    {
        if(arr[i]<=pivot){
            swap2(arr,i,j);
            i++;
            j++;
        }else{
            i++;
        }
    }
    printf("->%d]",j-1);
    return j-1;
    
}

void quicksort(int arr[],int lo, int hi){
    if(lo>hi){ return;}
    int pivot=arr[hi];
    int pidx=partition(arr,pivot,lo,hi);
    quicksort(arr,lo,pidx-1);
    quicksort(arr,pidx+1,hi);
    
}


void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    // bubbleSort(arr, n);
    // selectionSort(arr, n);
    // insertionSort(arr, n);
    //  printf("Merge sort");
    // mergeSort(arr,0,n-1);
    quicksort(arr,0,n-1);
    printf("\nSorted array: \n");
    printArray(arr, n);
    return 0;
}