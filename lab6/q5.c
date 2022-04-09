#include<stdio.h>

// count lines in a text file
//done
int main()
{
    int i;
    char c;
    FILE *fp;
    char str[80];
    int count=0;
    
    fp=fopen("test.txt","r");
    if(fp==NULL){
        printf("file not opened!\n");
        return 0;
    }
    // printf("\n\ncontents of the file:-\n");

    while (fgets(str,80,fp)!=NULL)  //reads line by line
    {
        count++;
        // printf("\n%s",str);
    }
    printf("The lines in file are: %d",count);
    // while (c=getc(fp)!=EOF)//is this right?
    // {
    //     printf("%c",c);
    // }
    fclose(fp);
    return 0;
}