//https://leetcode.com/problems/monotonic-array/ 

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        bool inc=true,dec=true;
        for(auto i=nums.begin();i!=nums.end()-1;i++)
        {   //check increasing
            if(*i>*(i+1))
            {   
                inc=false;
                break;
            }
        }
        if(inc==false)
        for(auto i=nums.begin();i!=nums.end()-1;i++)
        {   //check decreasing
                if(*i<*(i+1))
                { 
                    dec=false;
                }
        }
        return inc||dec;
    
    }
        
};