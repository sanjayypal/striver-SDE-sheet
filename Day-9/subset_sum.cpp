//Find all sub-sequence of the given string

#include<bits/stdc++.h>
using namespace std;
void findSubsequence(string str,string output,int idx)
{
    //base case
    if(idx>= str.length())
    {
        cout<<"->"<<output<<endl;
        return;
    }

    char ch = str[idx];
    //exclude
    findSubsequence(str,output,idx+1);
    
    //include
    output.push_back(ch);
    findSubsequence(str,output,idx+1);
}

int main()
{
    string str = "abc";
    string output = "";
    findSubsequence(str,output,0);
    return 0;
}