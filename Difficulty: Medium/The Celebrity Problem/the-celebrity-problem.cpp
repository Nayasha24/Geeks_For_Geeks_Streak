//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    // Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& mat) {
        // code here
        int n = mat.size(), a[3001], r[3001];
        memset(a,0,sizeof(a)); memset(r,0,sizeof(r));
        for ( int i = 0; i<n; i++ ){
            for ( int j = 0; j<n; j++ ){
                a[i] += mat[i][j]; r[j] += mat[i][j]; 
            }
        }
        for ( int i = 0; i<n; i++ ){
            if ( a[i] == 0 && r[i] == n-1 ) return i;
        } return -1;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int> > M(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> M[i][j];
            }
        }
        Solution ob;
        cout << ob.celebrity(M) << endl;
    }
}

// } Driver Code Ends