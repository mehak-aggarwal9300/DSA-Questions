#include<stdio.h>
#define MAX 3
int create(int [MAX][MAX]); //ask!!! why int??
int linear(int [3][3]);


int main(){

    int mat[3][3];
    create(mat);
    linear(mat);
    return 0;

}

int create( int mat[3][3])
{
    int i, j;
    printf("Enter elements:\n");
    for(i=0;i<MAX;i++){
        for(j=0;j<MAX;j++){
            scanf("%d",&mat[i][j]);
        }
    }
}

int linear(int mat[3][3]){
    int item,i,j;
    printf("enter ele to be searched:");
    scanf("%d",&item);

    for (i=0 ;i<MAX;i++)
    {
        for (j=0;j<MAX;j++)
            if(item==mat[i][j])
            {   printf ( "The location is :%d %d", i+1,j+1 );
                return 0;
            }
    }
}