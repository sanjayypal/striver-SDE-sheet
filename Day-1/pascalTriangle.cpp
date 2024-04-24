 #include<bits/stdc++.h>
 using namespace std;

   vector<vector<int>> generate(int numRows) {
        if (numRows == 0) return {};
        if (numRows == 1) return {{1}};
        
        vector<vector<int>> prevRows = generate(numRows - 1);
        vector<int> newRow(numRows, 1);
        
        for (int i = 1; i < numRows - 1; i++) {
            newRow[i] = prevRows.back()[i - 1] + prevRows.back()[i];
        }
        
        prevRows.push_back(newRow);
        return prevRows;
    }

    int main(){
        vector<vector<int>> res = generate(3);
        int n = res.size();
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<=i; j++)
            {
                cout<< res[i][j];
            }
            cout<<endl;
        }

        return 0;
    }