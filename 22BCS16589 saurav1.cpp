//
//  main.cpp
//  ap exp 6
//
//  Created by saurav saha on 19/02/25.
//

#include <iostream>
#include <vector>
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size() - 1);
    }

private:
    TreeNode* buildBST(vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        // Find the middle element
        int mid = left + (right - left) / 2;

        // Create the root node
        TreeNode* root = new TreeNode(nums[mid]);

        // Recursively build the left and right subtrees
        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }
};

// Helper function to print the tree (in-order traversal)
void printTree(TreeNode* root) {
    if (!root) {
        cout << "null ";
        return;
    }
    printTree(root->left);
    cout << root->val << " ";
    printTree(root->right);
}

int main() {
    Solution solution;

    // Example 1
    vector<int> nums1 = {-10, -3, 0, 5, 9};
    TreeNode* root1 = solution.sortedArrayToBST(nums1);
    cout << "BST for Example 1: ";
    printTree(root1);
    cout << endl;

    // Example 2
    vector<int> nums2 = {1, 3};
    TreeNode* root2 = solution.sortedArrayToBST(nums2);
    cout << "BST for Example 2: ";
    printTree(root2);
    cout << endl;

    return 0;
}
