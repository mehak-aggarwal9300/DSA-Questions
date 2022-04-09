#include<stdio.h>
//some problem
#define MAX 4
void add(int a[][MAX],int b[][MAX],int c[][MAX],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
           c[i][j]=a[i][j]+b[i][j];
           printf("\nthe sum of %d & %d is %d",a[i][j],b[i][j],c[i][j]);
        }
    }
}

void sub(int a[][MAX],int b[][MAX],int c[][MAX],int m,int n)
{
    int i,j;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
           c[i][j]=a[i][j]-b[i][j];
           printf("\nthe diff of %d & %d is %d",a[i][j],b[i][j],c[i][j]);
        }
    }
    
}

void display(int arr[][MAX], int m, int n)
{ printf("\n");
  for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        printf("%d ", arr[i][j]);
      } printf("\n");
    }
}


int main()
{
    int m,n;
    printf("Enter the number of Row and Column: \n");
    scanf("%d %d",&m, &n);

    int arr1[m][n];

    printf("Enter %d elements: \n", (m*n));
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        scanf("%d", &arr1[i][j]);
      }
    }

    int arr2[m][n];


    printf("Enter %d elements: \n", (m*n));
    for(int i=0; i<m; i++){
      for(int j=0; j<n; j++){
        scanf("%d", &arr2[i][j]);
      }
    }

    int arr3[m][n];
    add(arr1,arr2,arr3,m,n);
    sub(arr1,arr2,arr3,m,n);
    display(arr3,m,n);

    return 0;
}
