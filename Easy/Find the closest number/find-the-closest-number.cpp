//{ Driver Code Starts
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends

#include <math.h>
class Solution{
    public:
    int findClosest( int n, int k,int arr[]) 
    { 
        // Complete the function
        int low = 0;
        int high = n - 1;
        int closest = arr[0];
        
        while (low <= high) {
            int mid = low + (high - low) / 2;
            
            // Update closest if current mid is closer or if it's equally close but greater
            if (abs(arr[mid] - k) < abs(closest - k) || 
               (abs(arr[mid] - k) == abs(closest - k) && arr[mid] > closest)) {
                closest = arr[mid];
            }
            
            if (arr[mid] < k) {
                low = mid + 1;
            } else if (arr[mid] > k) {
                high = mid - 1;
            } else {
                return arr[mid]; // Exact match found
            }
        }
        
        return closest;
    } 
};

//{ Driver Code Starts.
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        int arr[n];
        for (int i=0; i<n; i++)
        {
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.findClosest(n,k,arr)<<endl;
    }
}

// } Driver Code Ends