#include<bits/stdc++.h>
using namespace std;

void printSub(vector<int> &arr,int start,int end)
{
    //base case
    if(end>arr.size())
    return;
    for(int i=start; i<end; i++)
    cout<<arr[i]<<" ";
    cout<<endl;

    //RE call
    printSub(arr,start,end+1);
}


int main()
{
    vector<int> arr = {1,2,3,4,5};
    for(int start=0; start<arr.size(); start++)
    {
        int end = start;
        printSub(arr,start,end);
        cout<<endl;
    }
    return 0;
}

