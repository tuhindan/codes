Node * DLL(Node *root, Node* X)
{
    Node *temp = root;
    if(root->left)
    {
         temp = DLL(root->left,X);
         temp->right = root;
         root->left = temp;
    }
    temp = root;
    if(root->right)
    {
         temp =  DLL(root->right,root);
    }
    if(X && root->left == NULL){
        root->left = X;
        X->right = root;
    }
    return temp;
}

Node * bToDLL(Node *root)
{
    // your code here
    Node* temp = DLL(root,NULL);
    while(temp->left)
        temp = temp->left;
    return temp;
    
}
