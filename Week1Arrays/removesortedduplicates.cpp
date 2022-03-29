// https://leetcode.com/problems/remove-duplicates-from-sorted-array/submissions/

//doesn't work for [1,1,2,2,3,3]

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        //input array is sorted, increasing
        int k=nums.size();
        if(nums.size()>0)
        for(auto it=nums.begin();it!=nums.end()-1;it++)
        {   int next=1;
            while(((it+next)!=nums.end())&&(*it==*(it+next)))
            {
                nums.erase(it+next);
                k--;
                cout<<"k:"<<k<<"\t size:"<<nums.size()<<"\n";                
            }
        }
        return k;
    }
};