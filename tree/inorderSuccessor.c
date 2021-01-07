Node * inOrderSuccessor(Node *root, Node *x)
{
    //Your code here
    Node * temp = NULL;
    //printf("%d\n",root->data);
    if(x->data < root->data ){
        temp =  inOrderSuccessor(root->left,x);
        if(temp == NULL)
            temp = root;
        return temp;
    }
    if(x->data > root->data ){
        return inOrderSuccessor(root->right,x);
    }
    if(root->right != NULL)
    {
        Node * temp = root->right;
        
        while (temp->left != NULL)
        {
            temp = temp->left;
        }
        return temp;
    }
    return NULL;
}
