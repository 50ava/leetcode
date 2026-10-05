class Solution {
public:

    bool inOrder(TreeNode* root, int Sum, int targetSum) {

        if (root == NULL)
            return false;

        Sum += root->val;

        if (root->left == NULL && root->right == NULL) {
            if (Sum == targetSum)
                return true;

            return false;
        }

        bool leftSide = inOrder(root->left, Sum, targetSum);
        bool rightSide = inOrder(root->right, Sum, targetSum);

        return leftSide || rightSide;
    }

    bool hasPathSum(TreeNode* root, int targetSum) {

        int Sum = 0;

        return inOrder(root, Sum, targetSum);
    }
};