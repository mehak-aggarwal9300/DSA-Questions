//TLE

#include<iostream>
#include<limits.h>
#include<vector>

using namespace std;

int maxSubArray(vector<int>& nums) {
        
        int sum = INT_MIN;
        int starti=0;
        int endi=nums.size()-1;
        for(int i=0;i<nums.size();i++)
        {   //cout<<i;
            // if(nums[i]<0) continue;
            int msfi=i;
            int j=i+1;
            vector<int> arr;
            arr.push_back(nums[i]);
            while(j<nums.size())
            {   //cout<<"j"<<j;
                int prev = arr.back();
                int cs=prev+nums[j];
                if(cs>arr[msfi-i]) msfi=j;    
                arr.push_back(cs);
                j++;
            }
            if(sum<arr[msfi-i])
            {
                sum=arr[msfi-i];
                starti=i;
                endi=msfi;
            }
        
        }
        return sum;
    }

int main()
{
    vector<int> v1{-2,1,-3,4,-1,2,1,-5,4};
    cout<<maxSubArray(v1);
    return 0;
}