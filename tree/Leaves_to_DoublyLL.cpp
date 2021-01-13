Node * extract(Node *root, Node** head)
{
    if(root->left != NULL )
    {
        if(root->left->left == NULL && root->left->right == NULL)
        {
            if(*head == NULL)
            {
                *head = root->left;
                root->left = NULL;
                (*head)->left = (*head);
                //(*head)->right = NULL;
            }
            else
            {
                Node *t = (*head)->left;
                t->right = root->left;
                root->left = NULL;
                t->right->left = t;
                (*head)->left = t->right;
            }
        }
        else
        {
            extract(root->left,head);
        }
    }
    if(root->right != NULL)
    {
        if(root->right->left == NULL && root->right->right == NULL)
        {
            if(*head == NULL)
            {
                *head = root->right;
                root->right = NULL;
                (*head)->left = (*head);
                //(*head)->right = NULL;
            }
            else
            {
                Node *t = (*head)->left;
                t->right = root->right;
                root->right = NULL;
                t->right->left = t;
                (*head)->left = t->right;
            }
        }
        else
        {
            extract(root->right,head);
        }
    }
}
Node * convertToDLL(Node *root){
    // add code here.
    Node *head = NULL;
    extract(root,&head);
    head->left = NULL;
    return head;
    
