//Brute Force 
class Solution {
public:
    int majorityElement(vector<int>& arr) {
       int min = arr.size()/2 + 1;
       int count;
       for(int i = 0; i<arr.size(); i++)
       {
           count = 0;
           for(int j = 0; j<arr.size(); j++)
           {    
               if(arr[j]==arr[i])
               count++;
               if(count>=min)
               return arr[j];
           }
       }
       return -1;
    }
};
TC: O(N*N)
SC: O(1)


//Better Solution - 1
class Solution {
public:
    int majorityElement(vector<int>& arr) {
       int min = arr.size()/2;
       map<int,int> mpp;
       for(int i = 0; i<arr.size(); i++)
       {
           mpp[arr[i]]++;
       }

       for(auto it:mpp)
       {
           if(it.second>min)
           return it.first;
       }
       return -1;
    }
};
TC: O(N*logN)
SC: O(N)


//Better Solution - 2
class Solution {
public:
    int majorityElement(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        return arr[arr.size()/2];
    }
};
TC: O(N*logN)
SC: O(1)


//optimal solution
class Solution {
public:
    int majorityElement(vector<int>& arr) {
        int count = 0,ele;
        for(int i = 0; i<arr.size(); i++)
        {
            if(count == 0)
            ele = arr[i];
            if(ele == arr[i])
            count++;
            else
            count--;
        }
        return ele;
    }
};

TC: O(N)
SC: O(1)



