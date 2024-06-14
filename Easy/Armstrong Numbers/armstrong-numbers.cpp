//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n) {
        // code here
        int sum = 0, digit, number = n;
        
        // Loop to process each digit of the number
        while (n > 0) {
            // Extract the last digit by taking the remainder when divided by 10
            digit = n % 10;
            // Add the cube of the digit to the sum
            sum += digit * digit * digit;
            // Remove the last digit by dividing n by 10
            n /= 10;
        }
        
        // Debugging statement to check the sum (uncomment to use)
        // cout << sum << endl;

        // Check if the computed sum of cubes of digits equals the original number
        if (sum == number)
            return "true";
        else
            return "false";
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
        cout << ob.armstrongNumber(n) << endl;
    }
    return 0;
}

// } Driver Code Ends