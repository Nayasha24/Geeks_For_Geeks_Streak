//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    void helper(stack<char>&Ch, unordered_map<char, vector<char>>&mp, char c, int arr[]){
        for(auto it: mp[c]){
            if(arr[it-'a']>0){
                arr[it-'a']=0;
                helper(Ch, mp, it, arr);
            }
        }
        Ch.push(c);
        
    }
    
    string findOrder(string dict[], int N, int K) {
        //code here
        unordered_map<char, vector<char>> mp;
        string s, sn;
        stack<char> Ch;
        char c;
        int j, a, b, arr[26]={0};
        for(int i=0; i<N-1; i++){
            s=dict[i];
            sn=dict[i+1];
            a = s.length();
            b = sn.length();
            j=0;
            while(j<a && j<b){
                if(s[j]==sn[j]) j++;
                else{
                    mp[s[j]].push_back(sn[j]);
                    arr[s[j]-'a']=1;
                    arr[sn[j]-'a']=1;
                    break;
                }
            }
        }
        for(int i=0; i<26; i++){
            if(arr[i]>0){
                c='a'+i;
                arr[c-'a']=0;
                helper(Ch, mp, c, arr);
            }
        }
        s="";
        while(!Ch.empty()){
            s.push_back(Ch.top());
            Ch.pop();
        }
        return s;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends