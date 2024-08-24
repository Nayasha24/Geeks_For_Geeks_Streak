//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    int solve(int w, vector<int> &wt, vector<int> &val, int idx, vector<vector<int>> &dp){
        if(idx>=wt.size()) return 0;
        if(dp[w][idx]!=-1) return dp[w][idx];
        
        int ans = 0;
        if(w-wt[idx]>=0){
            ans = max(ans, val[idx]+solve(w-wt[idx], wt, val, idx+1, dp));
        }
        ans = max(ans, solve(w, wt, val, idx+1, dp));
        
        return dp[w][idx]=ans;
    }
    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        // Your code here
        const int n=wt.size();
        vector<vector<int>> dp(W+1, vector<int> (n, -1));
        return solve(W, wt, val, 0, dp);
    }
};

//{ Driver Code Starts.

int main() {
    // taking total testcases
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        // reading number of elements and weight
        int n, w;
        vector<int> arr, val, wt, drr;
        string ip;
        int number;
        getline(cin, ip);
        stringstream ss(ip);

        while (ss >> number) {
            arr.push_back(number);
        }

        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            val.push_back(number);
        }

        w = arr[0];
        n = val.size();
        getline(cin, ip);
        ss.clear();
        ss.str(ip);

        while (ss >> number) {
            wt.push_back(number);
        }
        Solution ob;
        cout << ob.knapSack(w, wt, val) << endl;
    }
    return 0;
}
// } Driver Code Ends