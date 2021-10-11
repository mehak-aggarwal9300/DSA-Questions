//https://practice.geeksforgeeks.org/problems/ease-the-array0633/1/?category%5b%5d=Arrays&category%5b%5d=Arrays&difficulty%5b%5d=0&page=3&query=category%5b%5dArraysdifficulty%5b%5d0page3category%5b%5dArrays#


class Solution{
    public:
        void modifyAndRearrangeArr(int arr[], int n) 
    { 
        int j=0;
        for(int i=1;i<n;i++)
        {
            if((arr[i]!=0)&&(arr[i]==arr[j]))
            {
                arr[j]+=arr[i];
                arr[i]=0;
                i++;
                j+=2;
            }
            else 
            {
                j++;
            }
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]==0) 
            { 
                j=i;
                break;
            }
            
        }
        
        for(int i=j+1;i<n;i++)
        {
            if(arr[i]==0)
            {
                continue;
            }
            
            arr[j]=arr[i];
            arr[i]=0;
            
            j++;
            
        }
    }
    
}; 