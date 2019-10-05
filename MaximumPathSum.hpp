/*
struct Node{
	int data;
	Node *left, *right;
};
*/

/*
  A more compact version of this solution:
  https://www.geeksforgeeks.org/find-maximum-path-sum-two-leaves-binary-tree/
*/
int path(Node* root,int *res)
{
    if(!root)
        return 0;
        
    int left = path(root->left,res);
    int right = path(root->right,res);
    
    *res = max(*res, left+right+root->data);
    
    return max(left,right)+root->data;
}

int maxPathSum(struct Node *root)
{
    int res=INT_MIN;
    int p=path(root,&res);
    return res;
}
