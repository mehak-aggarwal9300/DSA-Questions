//https://practice.geeksforgeeks.org/problems/first-repeating-element4018/1/?category%5B%5D=Arrays&category%5B%5D=Arrays&difficulty%5B%5D=0&page=2&query=category%5B%5DArraysdifficulty%5B%5D0page2category%5B%5DArrays

//optimize...
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(arr[i]==arr[j]) return i+1; 
        }
    }
    return -1;