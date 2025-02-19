//
//  main.cpp
//  ap exp 6
//
//  Created by saurav saha on 19/02/25.
//
#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (!root) {
            return 0;
        }

        // Recursively calculate the depth of the left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);

        // Return the maximum depth + 1 (for the current node)
        return max(leftDepth, rightDepth) + 1;
    }
};

int main() {
    Solution solution;

    // Example 1
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(9);
    root1->right = new TreeNode(20);
    root1->right->left = new TreeNode(15);
    root1->right->right = new TreeNode(7);
    cout << "Maximum depth for Example 1: " << solution.maxDepth(root1) << endl;

    // Example 2
    TreeNode* root2 = new TreeNode(1);
    root2->right = new TreeNode(2);
    cout << "Maximum depth for Example 2: " << solution.maxDepth(root2) << endl;

    return 0;
}
