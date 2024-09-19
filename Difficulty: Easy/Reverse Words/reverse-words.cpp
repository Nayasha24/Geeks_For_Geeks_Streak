//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
        stack<string>st;
        string help="";
        for(int i=0;i<str.size();i++){
            if(str[i] !='.') help+=str[i];
            else {
                st.push(help);
                help="";
            }
        }
        st.push(help);
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
            if(st.size()!=0) ans+='.';
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends