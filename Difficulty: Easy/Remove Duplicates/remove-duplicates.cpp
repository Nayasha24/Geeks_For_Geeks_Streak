//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++
#include <cstring>
class Solution {
  public:

    string removeDups(string str) {
        // Your code goes here
        unordered_set<char> seen;
        string res = "";
        for (char ch : str) {
            if (seen.find(ch) == seen.end()) {
                seen.insert(ch);
                res += ch;
            }
        }
        return res;
    }
};

//{ Driver Code Starts.

int main() {

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;

        Solution ob;
        cout << ob.removeDups(s) << "\n";
    }

    return 0;
}
// } Driver Code Ends