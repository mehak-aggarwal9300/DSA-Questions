
void swap(int a[],int i,int j)
{
    int tmp=a[i];
    a[i]=a[j];
    a[j]=tmp;
}

void sort012(int a[], int n)
{   
    int after0=-1,before2=-1;
    for(int i=0;i<n;i++)
    {
        if(a[i]!=0) 
        {   after0 = i;
            break;
        }
    }
    
    for(int j=n-1;j>=0;j--)
    {
        if(a[j]!=2)
        {
            before2 = j;
            break;
        }
    }
    // int i=0;
    while(after0<before2)
    {   
        if(a[after0]==0)after0++;
        if(a[before2]==2)before2--;
        if((a[after0]==2)&&(a[before2==0])) 
        {   swap(a,after0,before2);
            after0++;
            before2--;
        }
        else if(a[after0]==2)
        {
             swap(a,after0,before2);
            before2--;
        }
        else if(a[before2]==0)
        {
             swap(a,after0,before2);
            after0++;
        }
            
    }
    
}