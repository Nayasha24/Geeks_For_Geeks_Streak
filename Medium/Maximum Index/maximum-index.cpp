//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
        
    // A[]: input array
    // N: size of array
    // Function to find the maximum index difference.
    // int calcDiff(int a[], int l, int r){
    //     if (a[l]<=a[r] && r>=l){
    //         return r-l;
    //     }
    //     else{
    //         return max({calcDiff(a, l + 1, r),
    //                     calcDiff(a, l, r - 1),
    //                     calcDiff(a, l + 1, r - 1)});
    //     }
    // }
    int maxIndexDiff(int a[], int n) 
    { 
        int maxDiff = -1;
        if (n==1) return 0;
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j > i; --j) {
                if (a[j] >= a[i]) { // If there's a valid pair
                    maxDiff = max(maxDiff, j - i); // Update the maximum difference
                    break; // Break from the inner loop as we don't need to consider further elements
                }
            }
        }
        return maxDiff;
    }
};

//{ Driver Code Starts.
  
/* Driver program to test above functions */
int main() 
{
    int T;
    //testcases
    cin>>T;
    while(T--){
        int num;
        //size of array
        cin>>num;
        int arr[num];
        
        //inserting elements
        for (int i = 0; i<num; i++)
            cin>>arr[i];
        Solution ob;
        
        //calling maxIndexDiff() function
        cout<<ob.maxIndexDiff(arr, num)<<endl;    
        
    }
    return 0;
} 
// } Driver Code Ends