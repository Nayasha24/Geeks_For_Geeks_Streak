//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    /*You are required to complete this method*/
    int wildCard(string p, string s) {
        // code here
        int sIdx = 0, pIdx = 0, lastWildcardIdx = -1,
        sBacktrackIdx = -1, nextToWildcardIdx = -1;
        while (sIdx < s.size()) {
            if (pIdx < p.size()
                && (p[pIdx] == '?' || p[pIdx] == s[sIdx])) {
                ++sIdx;
                ++pIdx;
            }
            else if (pIdx < p.size() && p[pIdx] == '*') {
                lastWildcardIdx = pIdx;
                nextToWildcardIdx = ++pIdx;
                sBacktrackIdx = sIdx;
    
            }
            else if (lastWildcardIdx == -1) {
                return false;
            }
            else {
                pIdx = nextToWildcardIdx;
                sIdx = ++sBacktrackIdx;
            }
        }
        for (int i = pIdx; i < p.size(); i++) {
            if (p[i] != '*')
                return false;
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string pat, text;
        cin >> pat;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> text;
        Solution obj;
        cout << obj.wildCard(pat, text) << endl;
    }
}

// } Driver Code Ends