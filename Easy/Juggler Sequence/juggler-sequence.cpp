//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void seqGen(vector<long long> &res, long long n){
        if (n<=1) return;
        if(n%2==0){
            n=sqrt(n);
            res.push_back(n);
            seqGen(res, n);
        }
        else{
            n=n*sqrt(n);
            res.push_back(n);
            seqGen(res,n);
        }
    }
    vector<long long> jugglerSequence(long long n) {
        vector<long long> res;
        res.push_back(n);
        seqGen(res, n);
        return res;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;

        Solution ob;
        vector<long long> ans = ob.jugglerSequence(n);
        for (long long u : ans)
            cout << u << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends