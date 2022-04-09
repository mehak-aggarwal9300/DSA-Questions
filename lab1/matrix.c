#include<stdio.h>
#include<stdbool.h>

#define true 1
#define false 0

bool identity(int a[][3],int m, int n){ //ask, matrix in function, without bound cannot be defined?? error arha thaa without 3
    if(m!=n) return false;  
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if((i==j)&&(a[i][j]!=1)){ return false; }
            if((i!=j)&&(a[i][j]!=0)){ return false; }
            
        }
    }
    return true;
}

bool sparse(int a[][3], int m, int n){
    int threshold = (m*n)/2, zcount=0;
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
             if(a[i][j]==0) zcount++;
        }
    }
    if(zcount>=threshold) return true;
    return false;
}

bool equal(int m1[][3],int m2[][3],int a, int b, int p, int q){
    if((a!=p)||(b!=q)) return false;
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++){
            if(m1[i][j]!=m2[i][j]) return false;
        }
    }
     return true;
}

void lowertriangle(int a[][3], int m,int n){
    if(m!=n)return;
    for(int i=0;i<m;i++)
    {
        for(int j=0;i>=j;j++)
        {
            printf("%d",a[i][j]);
        } printf("\n");
    }
}


int main(){

int mat[3][3]={1,3,0,1,1,0,5,9,2};
int mat2[3][3]={1,0,0,0,1,0,0,0,1};
bool id= identity(mat,3,3); if(id==true){printf("Matrix is identity\n");}
bool sp= sparse(mat,3,3); if(sp==true){printf("Matrix is sparse\n");}
bool eq= equal(mat,mat2,3,3,3,3); if(eq==true){printf("Matrices are equal\n");}

lowertriangle(mat,3,3);



}