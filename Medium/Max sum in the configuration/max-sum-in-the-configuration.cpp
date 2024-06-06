//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
/*You are required to complete this method*/

#include <algorithm>
#include <bits/stdc++.h>
class Solution {
  public:
    long long max_sum(int a[], int n) {
        // Your code here
        long aSum = 0;
        long  PreviousPatternSum = 0;
        long mul=0;
        for(long i=0; i<n; i++)
        {
            aSum += a[i];
            PreviousPatternSum += a[i]*i;
        }
        int lastIndex = n - 1;
        long mx = PreviousPatternSum;
        while(lastIndex > 0)
        {
            long lastNum = a[lastIndex--];
            PreviousPatternSum = (PreviousPatternSum - ((n-1) * lastNum)) + (aSum - lastNum);
            mx = max(PreviousPatternSum, mx);
        }
        return mx;
    }
};

//{ Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) {
            cin >> A[i];
        }
        Solution ob;
        cout << ob.max_sum(A, N) << endl;
        /*keeping track of the total sum of the array*/
    }
}

// } Driver Code Ends