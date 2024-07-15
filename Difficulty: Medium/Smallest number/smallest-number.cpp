//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string smallestNumber(int s, int d) {
        // code here
        if(9*d<s) return "-1";
        if(d==1) return to_string(s);
        string sb="";
        s=s-1;
        for(int i =0; i<d-1; i++){
            if(s>=9){
                sb='9'+sb;
                s=s-9;
            }
            else{
                sb=to_string(s)+sb;
                s=0;
            }
        }
        int a = s+1;
        return to_string(a)+sb;
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
        int s, d;
        cin >> s >> d;
        Solution ob;
        cout << ob.smallestNumber(s, d) << "\n";
    }

    return 0;
}
// } Driver Code Ends