//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool kPangram(string str, int k) {
        int len=0;
        unordered_map<char,int>mp;
        for(auto c:str){
            if(c!=' '){
                mp[c]++;
                len++;
            }
        }
        if(len<26) return false;
        if(mp.size()==26) return true;
        int req=26-mp.size();
        if(len-mp.size()>=req&&req<=k) return true;
        
        return false;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        cin.ignore();
        string str;
        getline(cin, str);

        int k;
        cin >> k;

        Solution ob;
        bool a = ob.kPangram(str, k);
        if (a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
    return 0;
}
// } Driver Code Ends