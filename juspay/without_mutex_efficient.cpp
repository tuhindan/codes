class Node {
    public:
        string s;
        int lock;
        int id;
        Node *parent;
        //vector<Node *> child;
        unordered_set<string> locked_dec;
};

unordered_map<string, Node *> w_map;

bool get_lock(Node *root) {
    root->lock++;
    if(root->lock != 1) {
        root->lock--;
        return false;
    }
    return true;
}

void remove_lock(Node *root) {
    root->lock--;
}

bool Lock(string s, int id) {
    Node* root = w_map[s];
    
    if(!get_lock(root))
    {
        return false;
    }
    
    root->id = id;
    
    if(root->locked_dec.size()) {
        root->id = -1;
        remove_lock(root)
        return false;
    }


    Node* temp = root->parent;
    bool flag = true;
    while(temp) {
        temp->lock++;
        temp->locked_dec.insert(s);

        if(temp->id != -1) {
            flag = false;
            temp->locked_dec.erase(s);
        }
        
        temp->lock--;
        
        if(!flag)
            break;
     
        temp = temp->parent;
    }
    
    if(!flag) {
        Node* temp1 = root->parent;
        while(temp1 != temp) {
            temp1->lock--;
            temp1->locked_dec.erase(s);
            temp1 = temp1->parent;
        }

        root->id = -1;
        remove_lock(root);
        return false;
    }
    
    return true;
}
