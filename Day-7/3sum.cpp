//Brute Force 
//TC : n*3
vector<vector<int>> threeSum(vector<int>& arr) {
        set<vector<int>> st;
        int n = arr.size();

        for(int i = 0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                for(int k=j+1; k<n; k++)
                {
                    if(arr[i]+arr[j]+arr[k] == 0)
                    {
                        vector<int> temp = {arr[i],arr[j],arr[k]};
                        sort(temp.begin(),temp.end());
                        st.insert(temp);
                    }
                }
            }
        }

        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }


    //Better Solution
    vector<vector<int>> threeSum(vector<int>& arr) {
        set<vector<int>> st;
        int n = arr.size();
    for (int i = 0; i < n; i++) {
        set<int> hashset;
        for (int j = i + 1; j < n; j++) {
            //Calculate the 3rd element:
            int third = -(arr[i] + arr[j]);

            //Find the element in the set:
            if (hashset.find(third) != hashset.end()) {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashset.insert(arr[j]);
        }
    }

    //store the set in the answer:
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
    }


    //Optimal Solution
    vector<vector<int>> threeSum(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for (int i = 0; i < n; i++) {
            if (i != 0 && arr[i] == arr[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum < 0)
                    j++;
                else if (sum > 0)
                    k--;
                else {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    ans.push_back(temp);
                    j++;
                    k--;
                    // skip the duplicates:
                    while (j < k && arr[j] == arr[j - 1])
                        j++;
                    while (j < k && arr[k] == arr[k + 1])
                        k--;
                }
            }
        }
        return ans;
    }