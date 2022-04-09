#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct stud{
    int roll;
    char name[50];
    float fees;
    char DOB[10];
}STUD;

FILE *fp,*fp2;

void create()
{
    fp=fopen("STUDENT_DETAILS.dat","wb");
    if(fp==NULL){
        printf("\nCouldn't open file!");
        return;
    }
    fclose(fp);

}

void insert(int n)
{
    STUD s1[n];
    int i=0;
    fp=fopen("STUDENT_DETAILS.dat","ab");
    if(fp==NULL)
    {
        printf("\nCouldn't open file!");
        return;
    }

    printf("Enter details:\n");
    printf("\n  Roll\tName\tFees\tDOB");
    while(i<n)
    {   
        printf("\n*r%d*",i+1); 

        scanf("%d",&s1[i].roll);
        // printf("Name: ");
        // gets(&s1.name);
        // getline(s1.name);
        //scanf ("%[^\n]%*c",s1.name);
        //scanf("%[^\n]",s1.name);
        // fgets(s1.name,sizeof(s1.name),stdin);
        // while(scanf("%s",s1.name)!='\n');
        scanf("%s",s1[i].name);
        //fflush(stdin);
        //getch();
        // printf("Fees: ");
        scanf("%f",&s1[i].fees);
        // printf("DOB: ");
        scanf("%s",s1[i].DOB);
        // printf("Roll no: %d\nName: %s\nFees: %f\nDOB: %s",s1.roll,s1.name,s1.fees,s1.DOB);
        // fprintf(fp,"Roll no: %d\nName: %s\nFees: %f\nDOB: %s",s1.roll,s1.name,s1.fees,s1.DOB);
        fwrite(&s1[i],sizeof(s1[i]),1,fp);
        i++;
    }
    fclose(fp);
    fp=fopen("STUDENT_DETAILS.dat","rb");
    if(fp==NULL){ printf("fp not found");   return;}
    fclose(fp);
    return;
}


void delete()
{
    STUD s1;
    int r,found=0;
    fp=fopen("STUDENT_DETAILS.dat","rb");
    if(fp==NULL){ printf("fp not found");   return;}
    fp2=fopen("temp.dat","wb");
    if(fp==NULL){ printf("fp not found");   return;}
    printf("\nEnter roll no. of student to be deleted");
    scanf("%d",&r);

    while(1)
    {
        fread(&s1,sizeof(s1),1,fp);
        if(feof(fp)) break;
        if(s1.roll!=r)
        {
            // printf("record not skipped");
            fwrite(&s1,sizeof(s1),1,fp2);
        }
    }

    fclose(fp);
    fclose(fp2);
    // if(!found) { printf("record not found"); return; }
    remove("STUDENT_DETAILS.dat");  		 
    rename("temp.dat", "STUDENT_DETAILS.dat");
    return;
}


void modify()
{
    STUD s;
    int res, r_no;
    fp=fopen("STUDENT_DETAILS.dat","rb+");
    if(fp==NULL){ printf("fp not found");   return;}

    printf("Enter record to be modified:");
    scanf("%d",&r_no);
    if(r_no>0)
    {
        fseek(fp,sizeof(s)*(r_no-1),SEEK_SET);
    }
    // res=fread(&s,sizeof(s),1,fp);
    // fseek(fp,-sizeof(s),SEEK_SET);
    // char c;
    // c = getc(fp);
    // if(res==1)
    // {
        // char name[20];
        // printf("\n====\nBefore\nRoll no: %d\nName: %s\nFees: %f\nDOB: %s",s.roll,s.name,s.fees,s.DOB);
        printf("\nNew roll no. : ");
        scanf("%d",&s.roll);
        printf("\nEnter new name:");
        scanf("%s",s.name);
        printf("New Fees : ");
        scanf("%f",&s.fees);
        printf("new DOB : ");
        scanf("%s",s.DOB);       
        fwrite(&s,sizeof(s),1,fp);
        fclose(fp);
        return;
    // }
    // else{
    //     printf("Record not found");
    // }

    // fclose(fp);
    // return;
   
}

void modify_name()
{
    STUD s;
    int res, r_no;
    fp=fopen("STUDENT_DETAILS.dat","rb+");
    if(fp==NULL){ printf("fp not found");   return;}

    printf("Enter record to be modified:");
    scanf("%d",&r_no);
    if(r_no>0)
    {
        fseek(fp,sizeof(s)*(r_no-1),SEEK_SET);
    }
        printf("\nEnter new name:");
        scanf("%s",s.name);
        fwrite(&s,sizeof(s),1,fp);
        fclose(fp);
        return;
    
}

void read()
{
    STUD s;
    int res;
    fp=fopen("STUDENT_DETAILS.dat","rb");
    if(fp==NULL){ printf("fp not found");   return;}
    printf("\nRoll no:\tName:\tFees:\tDOB:");
    while(1)
    {
        fread(&s,sizeof(s),1,fp);
        if(feof(fp)) break;
        // printf("\nRoll no: %d\tName: %s\tFees: %f\tDOB: %s",s.roll,s.name,s.fees,s.DOB);
        printf("\n%d\t%s\t%f\t%s",s.roll,s.name,s.fees,s.DOB);

    }
    fclose(fp);
    return;
}

void read_n(int r_no)
{
    STUD s;
    int res;
    fp=fopen("STUDENT_DETAILS.dat","rb");
    if(fp==NULL){ printf("fp not found");   return;}
    if(r_no>0)
    {
        fseek(fp,sizeof(s)*(r_no-1),SEEK_SET);

    }
    res=fread(&s,sizeof(s),1,fp);
    if(res==1)
    {
        printf("Roll no: %d\nName: %s\nFees: %f\nDOB: %s",s.roll,s.name,s.fees,s.DOB);
    }
    else{
        printf("Record not found");
    }

    fclose(fp);
    return;
    
}


int main(){
    create();
    insert(8);
    read();
    delete();
    modify_name();
    modify();  
    read();

    return 0;
}