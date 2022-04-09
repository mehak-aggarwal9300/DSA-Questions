#include<stdio.h>
#include<string.h>


int funclen(char str[])
{
    int i=0, len=0;
    while(str[i]!='\0')
    {
        len++;
        i++;
    }
    return len;
}

void funrev(char str[], int len){

    int i,j;
    char tmp;
    for(i=0,j=len-1;i<j;i++,j--){
        tmp=str[i];
        str[i]=str[j];
        str[j]=tmp;
    }
    printf("\nfrom function: %s",str);

}

void funcopy(char* source, char* target){
    //https://www.geeksforgeeks.org/different-ways-to-copy-a-string-in-c-c/

    //method 1
    /*1.pass arrays 
        create new string using malloc
        s2 = (char*)malloc(20);
        2. copy elements of array one by one using for-loop
        3. return (char*)s2
    */

    //method 2
    /*  pass arrays
        char *s2= (char*)malloc(20);
        assign new pointers p1=s,p2=s2
        while loop mei *p2=*p1, p1++, p2++
        *p2='\0'
    */
    
    //method 3, formal parameter as pointer
    while (*target++ = *source++);
    
}

void funconcat(char str1[], char str2[]){
    int i=0,j=0;
    while (str1[i]!='\0')
    {
        i++;
    }

    while (str2[j]!='\0')
    {   
        str1[i]=str2[j];
        i++;
        j++;
    }

    str1[i]='\0';
    
}

int main(){

    char str[]="Hello";
    char str2[]="Mehak";
    char t[20];

    //using built-in functions
    // printf("%d\n",strlen(str));
    // printf("%s\n",strrev(str));
    // printf("%s\n",strcpy(str,"Yoda")); 
    // printf("%s\n",strcat(str,str2)); //s1<-s1+s2

    int len = funclen(str);
    printf("len: %d",len);
    funrev(str,len);    //since char array, call by reference
    printf("\nreversed string from main: %s",str);
    funcopy(str2,t);
    printf("\ncopied string: %s",t);
    funconcat(str,str2);
    printf("\nconcatenated: %s",str);

    return 0;
}