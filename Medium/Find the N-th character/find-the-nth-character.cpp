//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{
  public:
    char nthCharacter(string s, int r, int n) {
        for (int i = 0; i < r; i++) {
            std::stringstream ss;
            int j=0;
            for (char c : s) {
                if (c == '0')
                    ss << "01";
                else
                    ss << "10";
                j++;
                if (j==n) break;
            }
            s = ss.str();
        }
        return s[n];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, N;
        string S;
        cin >> S >> R >> N;
        Solution ob;
        cout << ob.nthCharacter(S, R, N) << endl;
    }
    return 0;
}
// } Driver Code Ends