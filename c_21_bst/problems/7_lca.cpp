/*
LCA -lowest common ancesstor ->first intersection point
Subscribe to TUF+

Hints
Company
Given the root node of a binary search tree (BST) and two node values p,q.



Return the lowest common ancestors(LCA) of the two nodes in BST.


Example 1

Input : root = [5, 3, 6, 2, 4, null, 7] , p = 2, q = 4

Output : [3]

Explanation :

Below is image of the BST



Example 2

Input : root = [5, 3, 6, 2, 4, null, 7] , p = 2, q = 7

Output : [5]

Explanation :

Below is image of the BST
*/

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int data) {
        val = data;
        left = right = nullptr;
}
};


TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(root==nullptr) return nullptr;
    int curval=root->val;
    if(curval>p->val && curval>q->val) return  lowestCommonAncestor(root->left,p,q);
    if(curval<p->val && curval<q->val) return lowestCommonAncestor(root->right,p,q);
    return root;

}