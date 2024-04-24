class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int temp=-1;
       sort(arr.begin(),arr.end());
       for(int i = 0; i<arr.size()-1; i++)
       {
           if(arr[i]==arr[i+1])
            temp = arr[i];
       }
       return temp;
    }
};