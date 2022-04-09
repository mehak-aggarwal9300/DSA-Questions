#include <stdio.h>
#include <string.h>
#define MAX 200
//done
//merge two files 
  int main() 
  {
        char ch;
        FILE *fp1, *fp2, *fp3;
        char str[50];
		
        fp1 = fopen("file1.txt", "r");
        if (!fp1) 
		{
                printf(" File not found!\n");
                return 0;
        }

        fp2 = fopen("file2.txt", "r");
        if (!fp2) 
		{
                printf(" File not found!\n");
                return 0;
        }

        fp3 = fopen("merged.txt", "w");
        if (!fp3) 
		{
                printf("fp3 not found!!\n");
                fclose(fp1);
                fclose(fp2);
                return 0;
        }
        
        //way1 to read a file
        while (fgets(str,50,fp1)!=NULL) //while end of file is not reached
        {
                    fputs(str,fp3);               
        }
        while (fgets(str,50,fp2)!=NULL) //while end of file is not reached
        {
                    fputs(str,fp3);               
        }
        fclose(fp1);
        fclose(fp2); 
        fclose(fp3);		 
        fp3=fopen("merged.txt","r"); 
        //way2 to read a file
        ch=fgetc(fp3); 
        printf("\nThe contents of merged file: \n"); 
        while(ch!=EOF) 
        {   
                printf("%c",ch); 
                 ch=fgetc(fp3); 
        }
        fclose(fp1);
        return 0;

  } 
