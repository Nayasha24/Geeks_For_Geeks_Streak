//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{
    public:
        vector <int> search(string pattern, string text)
        {
            #define d 256
            int m = pattern.size();
            int n = text.size();
            vector <int> res;
            int i, j;
            int p=0; //hash function of pattern
            int t=0; //hash function of text
            int q=3; //a prime number
            int h = 1;
            for (i = 0; i < m - 1; i++)
                h = (h * d) % q;
            
            for (i = 0; i < m; i++) {
                p = (d * p + pattern[i]) % q;
                t = (d * t + text[i]) % q;
            }
            for (i = 0; i <= n - m; i++) {
                if (p == t) {
                    for (j = 0; j < m; j++) {
                        if (text[i + j] != pattern[j]) {
                            break;
                        }
                    }
         
         
                    if (j == m)
                        res.push_back(i+1);
                }
                
                if (i < n - m) {
                    t = (d * (t - text[i] * h) + text[i + m]) % q;
         
              
                    if (t < 0)
                        t = (t + q);
                }
            }
            return res;
        }
     
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}

// Contributed By: Pranay Bansal

// } Driver Code Ends