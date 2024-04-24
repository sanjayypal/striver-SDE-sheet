
//Brute Force
class Solution {
public:
    int removeDuplicates(vector<int>& arr) {
        set<int> set;
        for (int i = 0; i < arr.size(); i++) {
            set.insert(arr[i]);
        }
        int k = set.size();
        int j = 0;
        for (int x : set) {
            arr[j++] = x;
        }
        return k;
    }
};


//Optimal solution
int removeDuplicates(vector<int>& arr) {
     int i = 0;
     for(int j=1; j<arr.size(); j++)
     {
        if(arr[i]!=arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
     }
     return i+1;
    }