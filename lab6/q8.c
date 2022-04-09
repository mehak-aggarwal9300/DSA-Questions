#include <stdio.h>
#include <string.h>
#define MAX 200

//encrypt
  int main() 
  {
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

        ch=fgetc(fp1); 
        while(ch!=EOF) 
        { 
                 ch=ch+100;
                 fputc(ch,fp2);
                 ch=fgetc(fp1);
        }
        
        fclose(fp1);
        fclose(fp2);
        remove("file.txt");  		 
        rename("temp.txt", "file.txt");
        fp1=fopen("file.txt","r"); 
        while (fgets(str,50,fp1)!=NULL) //while end of file is not reached
        {
            printf(str);            
        }
        fclose(fp1);
        return 0;

  } 
