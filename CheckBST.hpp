#include <stack>
#include <climits>

// BAD IMPLEMENTATION
struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
}; 

/*
 * 	In-order visit will check the element from the min -> max in a BST.
 * 	So just remember the last element we saw and check if the next is bigger.
 */ 
bool isBST(Node* root) {
    int last_val = INT_MIN;
    std::stack<Node *> s; 
    Node *curr = root; 
  
    while (curr != NULL || s.empty() == false) 
    { 
        while (curr !=  NULL) 
        { 
            s.push(curr); 
            curr = curr->left; 
        } 

        curr = s.top(); 
        s.pop(); 
  
        if (curr -> data < last_val)
            return 0;
        else
            last_val = curr -> data;
  
        curr = curr->right; 
  
    } 
    
    return 1;
}
