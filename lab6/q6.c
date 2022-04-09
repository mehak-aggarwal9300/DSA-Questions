#include <stdio.h>
#include <string.h>
#define MAX 200
//done
//delete a line from file- copy contents w/o that line and then delete and rename
  int main() 
  {
        int n;
        char ch;
        FILE *fp1, *fp2;
        char str[50];
		
        fp1 = fopen("file.txt", "r");
        if (!fp1) 
		{
                printf(" File not found!\n");
                return 0;
        }
        fp2 = fopen("temp.txt", "w");
        if (!fp2) 
		{
                printf("fp2 not found!!\n");
                fclose(fp1);
                return 0;
        }
        printf(" enter line no.: ");
        scanf("%d", &n);
        int count=0;
        //way1 to read a file
        while (fgets(str,50,fp1)!=NULL) //while end of file is not reached
        {

                count++;    
                if (count!=n) 
                {
                    fputs(str,fp2);
                }               
        }
        fclose(fp1);
        fclose(fp2);
        remove("file.txt");  		 
        rename("temp.txt", "file.txt");
        fp1=fopen("file.txt","r"); 
        //way2 to read a file
        ch=fgetc(fp1); 
        printf("\nThe contents of file: \n"); 
        while(ch!=EOF) 
        { 
                printf("%c",ch); 
                 ch=fgetc(fp1); 
        }
        fclose(fp1);
        return 0;

  } 
