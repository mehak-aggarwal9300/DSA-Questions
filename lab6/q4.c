#include<stdio.h>
//done
// write contents in a text file

int main()
{
    int i;
    FILE *fp;
    char c;
    char str[]="This is the content of the file test.txt";
    fp=fopen("test.txt","w");
    for(i=0;str[i]!='\0';i++)
    {
        fputc(str[i],fp);
    }
    fclose(fp);
    //contents have been added to text file

    //now, to check
    fp=fopen("test.txt","r");
    if(fp!=NULL){
        printf("\nthe file test.text created and opened succesfully!\n");
    }
    // printf("\n\ncontents of the file:-\n");

    // while (c=getc(fp)!=EOF)//is this right?
    // {
    //     printf("%c",c);
    // }
    fclose(fp);
    return 0;
}