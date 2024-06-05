//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {

  public:
    int findSwapValues(int a[], int n, int b[], int m) {
        // Your code goes here
        int sumofa = 0, sumofb = 0;
    
        // Calculate sum of array a
        for (int i = 0; i < n; i++) {
            sumofa += a[i];
        }
        
        // Calculate sum of array b
        for (int i = 0; i < m; i++) {
            sumofb += b[i];
        }
        
        int totalsum = sumofa + sumofb;
        
        // Check if total sum is odd
        if (totalsum % 2 != 0)
            return -1;
        
        int expectedsum = totalsum / 2;
        unordered_set<int> s;
        
        // Store all elements of array b in a hash set
        for (int i = 0; i < m; i++) {
            s.insert(b[i]);
        }
        
        // Check for each element in array a
        for (int i = 0; i < n; i++) {
            // Calculate the difference needed to balance the sums
            int diff = expectedsum - sumofa;
            
            // Check if there's a corresponding element in array b
            // that can balance the sums when swapped
            if (s.find(a[i] + diff) != s.end()) {
                return 1;
            }
        }
        
        // No valid swap found
        return -1;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int a[n];
        int b[m];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];

        Solution ob;
        cout << ob.findSwapValues(a, n, b, m);
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends