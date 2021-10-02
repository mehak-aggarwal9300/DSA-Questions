

class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        
        int large=a[n-1];
        vector<int> temp;
        temp.push_back(large);
        for(int i=n-2;i>=0;i--)
        {   
            if(a[i]>=large)
            {
                temp.push_back(a[i]);
                large=a[i];
            }
            
        }
        reverse(temp.begin(),temp.end());
        return temp;
    }
};

