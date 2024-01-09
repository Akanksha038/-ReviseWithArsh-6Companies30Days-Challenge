// // /**
// //  * Definition for a binary tree node.
// //  * struct TreeNode {
// //  *     int val;
// //  *     TreeNode *left;
// //  *     TreeNode *right;
// //  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
// //  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
// //  * };
// //  */
// // // class Solution {
// // // public:
// // //     int ma=0;
// // //     int maxSumBST(TreeNode* root) {
// // //         if(!root){
// // //             return 0;
            
// // //         }
// // //         int l=maxSumBST(root->left);
// // //         int r=maxSumBST(root->right);
// // //         ma=max(ma,l+r+root->val);
// // //         return l+r+root->val;
        
        
// // //     }
// // // };



// // struct T {
// //   bool isBST;
// //   int max;
// //   int min;
// //   int sum;
// //   T() : isBST(false) {}
// //   T(bool isBST, int max, int min, int sum)
// //       : isBST(isBST), max(max), min(min), sum(sum) {}
// // };

// // class Solution {
// //  public:
// //   int maxSumBST(TreeNode* root) {
// //     int ans = 0;
// //     traverse(root, ans);
// //     return ans;
// //   }

// //  private:
// //   T traverse(TreeNode* root, int& ans) {
// //     if (root == nullptr)
// //       return T(true, INT_MIN, INT_MAX, 0);

// //     const T left = traverse(root->left, ans);
// //     const T right = traverse(root->right, ans);

// //     if (!left.isBST || !right.isBST)
// //       return T();
// //     if (root->val <= left.max || root->val >= right.min)
// //       return T();

// //     // The `root` is a valid BST.
// //     const int sum = root->val + left.sum + right.sum;
// //     ans = max(ans, sum);
// //     return T(true, max(root->val, right.max), min(root->val, left.min), sum);
// //   }
// // };




// class Solution {
//     int ans = 0;
//     pair<int, int> postorder(TreeNode *root) {
//         pair<int, int> r{root->val, root->val};
//         bool isBST = true;
//         if (root->left) {
//             auto left = postorder(root->left);
//             if (root->val <= left.second) isBST = false;
//             r.second = max(left.second, root->val);
//             r.first = min(left.first, root->val);
//         }
//         if (root->right) {
//             auto right = postorder(root->right);
//             if (root->val >= right.first) isBST = false;
//             r.second = max(right.second, root->val);
//             r.first = min(right.first, root->val);
//         }
//         root->val += (root->left ? root->left->val : 0) + (root->right ? root->right->val : 0);
//         if (isBST) ans = max(ans, root->val);
//         return isBST ? r :  pair<int,int>{ INT_MIN, INT_MAX };
//     }
// public:
//     int maxSumBST(TreeNode* root) {
//         if (!root) return 0;
//         postorder(root);
//         return ans;
//     }
// };



class Solution {
public:

class info
{
    public: 
    int maxi;
    int mini;
    bool isBST;
    int sum;
};

info solve(TreeNode* root, int &ans)
{
    // base case
    if(root==NULL)
    {
        return {INT_MIN, INT_MAX, true, 0};
    }

    info left=solve(root->left, ans);
    info right=solve(root->right, ans);

    info currNode;

    currNode.sum=left.sum + right.sum + root->val;
    currNode.maxi=max(root->val, right.maxi);
    currNode.mini=min(root->val, left.mini);

    if(left.isBST && right.isBST && (root->val > left.maxi && root->val < right.mini))
    {
        currNode.isBST=true;
    }
    else
    {
        currNode.isBST=false;
    }

    // answer update
    if(currNode.isBST)
    {
        ans=max(ans, currNode.sum);
    }

    return currNode;
}

    int maxSumBST(TreeNode* root) {
        
        int maxSum=0;
        info temp=solve(root, maxSum);
        return maxSum;
    }
};