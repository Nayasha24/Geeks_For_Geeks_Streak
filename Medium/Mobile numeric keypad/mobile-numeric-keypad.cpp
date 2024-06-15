//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    long long getCount(int n) {
        // Your code goes here
        vector<long long> dp(10,1);
        for(int i=1;i<n;i++){
            vector<long long> temp(10,0);
            temp[0]=dp[0]+dp[8];
            temp[1]=dp[1]+dp[2]+dp[4];
            temp[2]=dp[2]+dp[1]+dp[3]+dp[5];
            temp[3]=dp[3]+dp[2]+dp[6];
            temp[4]=dp[4]+dp[1]+dp[5]+dp[7];
            temp[5]=dp[5]+dp[2]+dp[6]+dp[8]+dp[4];
            temp[6]=dp[6]+dp[3]+dp[5]+dp[9];
            temp[7]=dp[7]+dp[4]+dp[8];
            temp[8]=dp[8]+dp[0]+dp[9]+dp[7]+dp[5];
            temp[9]=dp[9]+dp[6]+dp[8];
            
            for(int i=0;i<10;i++){
                dp[i]=temp[i];
            }
            
        }
        long long  ans=0;
        for(int i=0;i<10;i++){
            ans+=dp[i];
        }
        return(ans);  
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        Solution ob;
        cout << ob.getCount(n) << "\n";
    }
    return 0;
}

// } Driver Code Ends