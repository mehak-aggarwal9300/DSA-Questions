//see why not working vscode mei
#include<stdio.h>
void main ()
{
    int arr[50],n,i;
    printf("enter number of elements in array");
    scanf("%d",&n);
    printf("enter %d elements in array\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    int array[n];
    int visited = -1;  //helps us to avoid counting the same element again
    for(int i = 0; i <n; i++){
        int count = 1;
        for(int j = i+1; j < n; j++){
            if(arr[i] == arr[j]){
                count++;
                array[j] = visited;
            }
        }
        if(array[i] != visited)
            array[i] = count;
    }
    printf("Element vs Frequency\n ");
    for(int i = 0; i <n; i++){
        if(array[i] != visited){
            printf(" %d", arr[i]);
            printf(" | ");
            printf(" %d\n", array[i]);
        }
    }
    return;
}