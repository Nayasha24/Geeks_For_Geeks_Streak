//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    int isValid(string str) {
        int n=str.length();
        string val="";
        int count=0;
        for(int i=0;i<n;i++){
            if(str[i]=='.'){
                if(val==""){
                    return false;
                }
                else if(val.length()>1){
                    if(val[0]=='0'){
                        return false;
                    }
                    else if(stoi(val)<0 || stoi(val)>255){
                        return false;
                    }
                }
                val="";
                count++;
            }
            else{
                val+=str[i];
            }
        }
        if(count!=3){
            return false;
        }
        if(val.length()>1){
            if(val[0]=='0'){
                return false;
            }
            else if(stoi(val)<0 || stoi(val)>255){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.

int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        // if (s.size() == 3) {
        //     cout << "false" << endl;
        //     return 0;
        // }
        Solution ob;
        bool f = ob.isValid(s);
        if (f)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends