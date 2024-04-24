//Brute Force

class Solution {
public:
    int longestConsecutive(vector<int>& arr) {
        int count=1,temp=1;
        sort(arr.begin(),arr.end());
        if(arr.size()==0)
        return 0;
        for(int i=1; i<arr.size(); i++)
        {
            if(arr[i-1]==arr[i])
            continue;
            if(arr[i-1]+1 == arr[i])
            count++;
            else
            {
                if(temp<count)
                temp = count;
                else
                count=1;
            }
            if(temp<count)
            temp=count;

        }
        return temp;
    }
};