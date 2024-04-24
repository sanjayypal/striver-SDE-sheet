#include<bits/stdc++.h>
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3] = {0,0,0};
        int n=nums.size();
        for(int i=0; i<n; i++)
          {
              if(nums[i]==0)
                arr[0]++;
              else if(nums[i]==1)
                arr[1]++;
              else
                arr[2]++;
          }

          int count0 = arr[0];
          int count1 = arr[1];
          int count2 = arr[2];
          
          for(int i=0; i<count0; i++)
          {
             nums[i] = 0;
          }
          for(int i=count0; i<count0+count1; i++)
          {
             nums[i] = 1;
          }
          for(int i=count0+count1; i<count0+count1+count2; i++)
          {
             nums[i] = 2;
          }
        
    }
};