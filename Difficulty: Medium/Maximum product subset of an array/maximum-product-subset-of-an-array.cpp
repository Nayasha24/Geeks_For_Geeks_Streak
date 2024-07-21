//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long int findMaxProduct(vector<int>& arr) {
        // Write your code here
        long long int ans = 1;
        int maxNegative = -10;
        for(int i=0; i<arr.size(); i++){
            
            if(arr[i] != 0){
                ans = (ans*arr[i])%1000000007;
            }
            if(arr[i]<0 && maxNegative<arr[i]){
                maxNegative = arr[i];
            }
        }
        if(ans<0){
            return ans/maxNegative;
        }
        return ans;
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        long long int ans = ob.findMaxProduct(arr);
        cout << ans << endl;
    }
    return 0;
}

// } Driver Code Ends