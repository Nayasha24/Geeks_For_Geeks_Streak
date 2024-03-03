//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
  public:
    vector<int> duplicates(long long arr[], int n) {
        unordered_map<long long, int> frequency;

        for(int i = 0; i < n; i++) {
            frequency[arr[i]]++;
        }

        vector<int> dup;

        for(auto it : frequency) {
            if(it.second > 1) {
                dup.push_back(it.first);
            }
        }

        if (dup.empty()) {
            return {-1};
        }

        sort(dup.begin(), dup.end());

        return dup;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        long long a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends