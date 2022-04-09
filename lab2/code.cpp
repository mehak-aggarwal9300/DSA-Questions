#include <iostream>
#include<vector>
using namespace std;


int solve(int N, vector<int> A, vector<int> B)
{
    int ans=N;
    for(int i=N-1;i>=1;i--)
    {
        int j=i-1;
        while(j>=0)
        {
            if(A[i]<A[j]&&B[i]<B[j])
            {
                ans--;
                break;
            }
            j--;
        }
    }
    return ans;
}

int main() {

vector<int> A{12,14,12,6,10};
    vector<int> B{6,0,4,10,8};
    cout<<solve(5,A,B);
    /*
    int sA=0,sB=0;
    for (auto i = A.begin(),x=B.begin(); i != A.end(),x != B.end(); ++i,++x) {

        if(sA>*i&&sB>*x)
        {
            i--;
            x--;
            continue;
        }

        for (auto j = A.begin(),y=B.begin(); j != A.end(),y != B.end(); ++j,++y) {
        if (*i<*j && *x<*y) {

            if(sA<*i&&sB<*x)
            {
                sA=*i;
                sB=*j;
            }
            A.erase(i);
            B.erase(x);
            i--;
            x--;
        }
        }
        }
        cout<<A.size();
    */

}


int func(int arr[],int X,int K)
{
    int count=0;

    int backup[arr.size()];
    for(int i=0;i<arr.size();i++)
    {
        backup[i]=-1;
    }
    for(int i=0;i<arr.size();i++)
    {
        if(arr[i]==X)
        {   
            count++;
            backup[count]=i;
        }
    }
    //in for loop of queries
    v.push_back(backup[k]);


    return -1;
}


