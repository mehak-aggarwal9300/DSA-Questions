#include <iostream>
#include<vector>
#include<math.h>
using namespace std;

int decimalToBinary(int N)
{
 
    // To store the binary number
    int B_Number = 0;
    int cnt = 0;
    while (N != 0) {
        int rem = N % 2;
        int c = pow(10, cnt);
        B_Number += rem * c;
        N /= 2;
 
        // Count used to store exponent value
        cnt++;
    }
 
    return B_Number;
}

void getOneBits(int n){
    int b=decimalToBinary(n);
    
    vector<int> ans;
    int temp=b;
    int i=0,count=0;
    
    while(temp>0)
    {
        int digit=temp%10;
        temp=temp/10;
        if(digit==1)
        {
            count++;
        }
        i++;
    }

}

int main()
{
    getOneBits(37);
}


