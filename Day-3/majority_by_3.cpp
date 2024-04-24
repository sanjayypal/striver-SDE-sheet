#include<bits/stdc++.h>

//Brute Force Solution
class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        vector<int> ans;
        int min = arr.size()/3;
        for(int i = 0; i<arr.size(); i++)
        {
            if(ans.size()==0 || ans[0]!=arr[i])
            {
              int cnt = 0;
              for(int j = 0; j<arr.size(); j++)   
              {
                  if(arr[i]==arr[j])
                  cnt++;
              }

              if(cnt>arr.size()/3)
              ans.push_back(arr[i]);
              if(ans.size()==2)
              break;
            }
            
        }
        return ans;
    }
};


// Better Solution 
#include<bits/stdc++.h>
class Solution {
public:
    vector<int> majorityElement(vector<int>& arr) {
        vector<int> ans;
        int min = arr.size()/3;
        map<int,int> mpp;
        for(int i=0; i<arr.size(); i++)
        {
            mpp[arr[i]]++;
        }

        for(auto it:mpp)
        {
            if(it.second > min)
            ans.push_back(it.first);
        }
        return ans;
       
    }
};



//Optimal Solution
