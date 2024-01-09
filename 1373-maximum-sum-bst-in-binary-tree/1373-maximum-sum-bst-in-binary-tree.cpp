/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
// class Solution {
// public:
//     int ma=0;
//     int maxSumBST(TreeNode* root) {
//         if(!root){
//             return 0;
            
//         }
//         int l=maxSumBST(root->left);
//         int r=maxSumBST(root->right);
//         ma=max(ma,l+r+root->val);
//         return l+r+root->val;
        
        
//     }
// };



struct T {
  bool isBST;
  int max;
  int min;
  int sum;
  T() : isBST(false) {}
  T(bool isBST, int max, int min, int sum)
      : isBST(isBST), max(max), min(min), sum(sum) {}
};

class Solution {
 public:
  int maxSumBST(TreeNode* root) {
    int ans = 0;
    traverse(root, ans);
    return ans;
  }

 private:
  T traverse(TreeNode* root, int& ans) {
    if (root == nullptr)
      return T(true, INT_MIN, INT_MAX, 0);

    const T left = traverse(root->left, ans);
    const T right = traverse(root->right, ans);

    if (!left.isBST || !right.isBST)
      return T();
    if (root->val <= left.max || root->val >= right.min)
      return T();

    // The `root` is a valid BST.
    const int sum = root->val + left.sum + right.sum;
    ans = max(ans, sum);
    return T(true, max(root->val, right.max), min(root->val, left.min), sum);
  }
};