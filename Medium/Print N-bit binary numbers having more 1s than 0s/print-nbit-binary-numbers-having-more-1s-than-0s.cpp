//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    void solve(vector<string> &ans,int ones,int zeros,string temp,int n,int i){
        if(i==n){
            ans.push_back(temp);
            return;
        }
        solve(ans,ones+1,zeros,temp+'1',n,i+1);
        if(zeros+1<=ones){
            solve(ans,ones,zeros+1,temp+'0',n,i+1);
        }
        return;
    }
	vector<string> NBitBinary(int n)
	{
	    vector <string> ans;
        string s="";
        solve(ans,0,0,s,n,0);
        return ans;
	}
};

//{ Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		int n;
   		cin >> n;
        Solution ob;
   		vector<string> ans = ob.NBitBinary(n);

   		for(auto i:ans)
   			cout << i << " ";

   		cout << "\n";
   	}

    return 0;
}
// } Driver Code Ends