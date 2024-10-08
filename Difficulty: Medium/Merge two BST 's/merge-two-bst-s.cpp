//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
    // Function to return a list of integers denoting the node
    // values of both the BST in a sorted order.
    void solve(Node* root,vector<int>& v)
    {
        if(!root)  return;
        solve(root->left,v);
        v.push_back(root->data);
        solve(root->right,v);
    }
    vector<int> merge(Node *root1, Node *root2) {
        // Your code here
        vector<int> l1;
        vector<int> l2;
        solve(root1,l1);
        solve(root2,l2);
        int n = l1.size();
        int m = l2.size();
        int l=0,r=0;
        vector<int> ans;
        while(l<n && r<m)
        {
            if(l1[l] < l2[r])
            {
                ans.push_back(l1[l]);
                l++;
            }
            else if(l2[r]<l1[l])
            {
                ans.push_back(l2[r]);
                r++;
            }
            else{
                ans.push_back(l1[l]);
                ans.push_back(l2[r]);
                l++;
                r++;
            }
        }
        while(l<n)
        {
            ans.push_back(l1[l]);
            l++;
        }
         while(r<m)
        {
            ans.push_back(l2[r]);
            r++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends