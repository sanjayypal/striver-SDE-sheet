//Brute Force
class Solution {
public:
    int trap(vector<int>& arr) {
       int total_storage = 0;
       int n = arr.size();
       for(int i = 0; i<n; i++)
       {
        int temp1 = INT_MIN;
        for(int j=i; j>=0; j--)
          temp1 = max(temp1,arr[j]);

        int temp2 = INT_MIN;
        for(int j=i; j<n; j++)
         temp2 = max(temp2,arr[j]);
        
        total_storage+= min(temp1,temp2) - arr[i];
       }
       return total_storage;
    }
};



//Better Approach
  int trap(vector<int>& arr) {
       int total_storage = 0;
       int n = arr.size();

       vector<int> prefix_max(n);
       vector<int> suffix_max(n);

       prefix_max[0] = arr[0];
       for(int i=1; i<n; i++)
        prefix_max[i] = max(arr[i],prefix_max[i-1]);

       suffix_max[n-1] = arr[n-1];
       for(int i=n-2; i>=0; i--)
        suffix_max[i] = max(arr[i],suffix_max[i+1]);

       for(int i=0; i<n; i++)
         total_storage += min(prefix_max[i],suffix_max[i]) - arr[i];
        
        return total_storage;
    }

    //Optimal Solution
    int trap(vector<int>& arr) {
      int total_storage = 0;
      int n = arr.size();
      int left = 0,right =n-1;
      int right_max = 0,left_max = 0;
    while(left<=right)
    {
        if(arr[left]<=arr[right])
        {
            if(arr[left]>=left_max)
             left_max = arr[left];
            else
             total_storage += left_max - arr[left];
            left++;
        }
        else{
            if(arr[right]>= right_max)
             right_max = arr[right];
            else
             total_storage += right_max - arr[right];      
            right--;
        }
    }
    return total_storage;
    }