#include<stdio.h>
#include<stdlib.h>
#define MAX 6


void ins_beg(int a[],int *size){
    int i,data,ele;
    if((*size)>=MAX)
    {
        printf("\nArray full!");
        return;
    }
    printf("Enter new element is to inserted:");
    scanf("%d", &data);
    for(i=*(size);i>0;i--) a[i]=a[i-1]; 
    a[0]=data;
    (*size)=(*size)+1;
}

void ins_end(int a[], int *size){
    int i,data;
    if((*size)>=MAX){
         printf("Array full!");
         return;
    }

    scanf("%d",&data);
    a[*size]=data;
    (*size)=(*size)+1;
    
}

void ins_ele(int a[],int *size, int ele){
    int i, data,index;
    if(*size>=MAX){ 
        printf("Array full!");
        return;
    }

    for(index=0;index<(*size);index++){
        if(a[index]==ele)
        break;
    }

    if(index==(*size)){ 
        printf("element not found!");
        return;
    }

    for(i=*(size);i>index;i--) a[i]=a[i-1]; //check
    scanf("%d", &data);
    a[index]=data;
    (*size)=(*size)+1;

}

void del_end(int a[], int *size){
    if((*size)<=0){
        printf("Empty array");
        return;
    }
    a[(*size)-1]=0; //delete 
    (*size)=(*size)-1;  //reducing size

}

void del_beg(int a[],int *size){
    int i,tmp;
    if((*size)<=0){
        printf("Empty array");
        return;
    }

    for(i=0;i<(*size)-1;i++) a[i]=a[i+1];
    a[i]=0;
    (*size)=(*size)-1;
        // printf("%d",(*size));

}

void del_ele(int a[],int *size,int ele){
    int i, index;
    if((*size)<0){
        printf("Empty array");
        return;
    }

    for(index=0;index<(*size);index++){
        if(a[index]==ele)
        break;
    }
    if(index==(*size)){ 
        printf("element not found!");
        return;
    }
    for(i=index;i<(*size)-1;i++) a[i]=a[i+1]; //check
    (*size)=(*size)-1;

}

void display(int a[],int *size){
    int i;
    if((*size)<=0)printf("Underflow");
    for(i=0;i<(*size);i++) printf("%d ", a[i]);
}

int main(){
int arr[]={}, *p;
int size=sizeof(arr)/sizeof(arr[0]);
ins_beg(arr,&size);
del_beg(arr,&size);
// del_beg(arr,p);   //check 
                        //size=6 is received in function parameter 
// del_ele(arr,p,5);
// del_beg(arr,&arr[3]);
// ins_beg(arr,p);
display(arr,&size);
return 0;
}


//TRASH
// printf("\n Menu\n");
    // 1.Insertion at beg \n
    // 2. Insertion at end \n
    // 3. Insertion after an element 
    // 4. Deletion from beg \n
    // 5. Deletion from end \n
    // 6. Delete an element \n
    // 7. Display array \n
    // 8. Exit");
// printf("\n Enter your choice:");
// scanf("%d",&choice);

// do
// {
//     printf("\n Menu\n 1.Insertion at beg \n2. Insertion at end \n3. Insertion after an element \n4. Deletion from beg \n5. Deletion from end \n6. Delete an element \n 7. Display array \n 8. Exit");
//     printf("\n Enter your choice:");
//     scanf("%d",&choice);
//     switch(choice)
//     {
//     case 1: //insert_beg(a[],*size);
//         break;
//     case 2: //insert_end(a[],*size);
//         break;
//     case 3: break;
//     case 4: break;
//     case 5: break;
//     case 6: break;
//     case 7: break;
//     case 8: exit(0);
    
//     default:
//         printf("\nWrong choice");
//         break;
//     }
// } while(choice!=8);
