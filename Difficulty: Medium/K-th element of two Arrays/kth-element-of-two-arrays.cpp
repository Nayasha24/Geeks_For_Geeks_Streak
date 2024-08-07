//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int kthElement(int k, vector<int>& arr1, vector<int>& arr2) {
        // code here
        size_t m=arr1.size();
        size_t n=arr2.size();
        int i=0,j=0;
        int c=0;
        while (i<m && j<n){
            if (arr1[i]<arr2[j]){
                
                if ((c)==k-1) return arr1[i];
                c++;
                i++;
                }
            
            else {
                if ((c)==k-1) return arr2[j];
                c++;
                j++;
            }
            
        }
        
        
        //chk left out arrays
        while (i<m){
            if ((c)==k-1) return arr1[i];
            c++;
            i++;
        }
        
          while (j<n){
            if ((c)==k-1) return arr2[j];
            c++;
            j++;
        }
    }
};

//{ Driver Code Starts.

// Driver code
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        int n, m, k;
        cin >> k;
        cin.ignore();
        string input;
        int num;
        vector<int> arr1, arr2;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr1.push_back(num);
        }

        getline(cin, input);
        stringstream s3(input);
        while (s3 >> num) {
            arr2.push_back(num);
        }

        Solution ob;
        cout << ob.kthElement(k, arr1, arr2) << endl;
    }
    return 0;
}
// } Driver Code Ends