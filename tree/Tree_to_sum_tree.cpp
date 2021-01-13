int sum(Node *node)
{
    if(node == NULL)
        return 0;
    
    int left = 0;
    int right = 0;
    int data = node->data;
    node->data = sum(node->left) + sum(node->right);
    return node->data + data;
}
void toSumTree(Node *node)
{
    // Your code here
    sum(node);
    return;
    
}
