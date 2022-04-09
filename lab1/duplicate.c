#include<stdio.h>

int main()
{
    int arr[] = {2,3,3,4,5,5,5,4};
    int len = 8;
	printf("duplicate elements are:");
	for(int i=0;i<len-1;i++)
	{
		for(int j=i+1;j<len;j++){
			if(arr[i]==arr[j]) 
			{	printf("\n %d",arr[j]);
				break;
			}
		}
	}
}