Node* BST(Node* root,Node* x){
    Node* k = NULL;
    if(x == NULL || x->data < root->data)
    {
        if(root->left != NULL){
            k = BST(root->left,x);
            if(k != NULL )
            {
                if(k->data > root->data)
                {
                    return NULL;
                }
            }
            else
                return NULL;
        }
        if(root->right != NULL){
            return BST(root->right,root);
        
        }
        return root;
    }
    
    return NULL;
    
}

bool isBST(Node* root) {
    // Your code here
    if (BST(root,NULL) == NULL)
        return false;
    return true;
    
}
