class Node {
    public:
        mutex lock_node;
        mutex lock_count;
        mutex lock_set;
        int count;
        string s;
        bool lock;
        int id;
        Node *parent;
        //vector<Node *> child;
        unordered_set<string> locked_dec;
};

unordered_map<string, Node *> w_map;

bool Lock(string s, int id) {
    Node* root = w_map[s];
    
    root->lock_count.lock();
    root->lock_node.lock();
    if(root->count != 0) {
        root->lock_node.unlock();
        root->lock_count.unlock();
        return false;
    }
    
    if(root->lock){
        root->lock_node.unlock();
        root->lock_count.unlock();
        return false;
    }
    
    root->lock_set.lock();
    if(root->locked_dec.size()) {
        root->lock_set.unlock();
        root->lock_node.unlock();
        root->lock_count.unlock();
        return false;
    }
    root->lock_set.unlock();
    root->lock_count.unlock();
    
    Node* temp = root->parent;
    bool flag = true;
    while(temp) {
        temp->lock_count.lock(); 
        if(temp->lock_node.try_lock()) {
            if(temp->lock) {
                flag = false;
            } else {
                temp->count++;
            }
            temp->lock_node.unlock();
            temp->lock_count.unlock();
            
            if(!flag)
                break;
        } else {
            temp->lock_count.unlock(); 
            flag = false;
            break;
        }
        temp = temp->parent;
    }
    
    if(!flag) {
        Node* temp1 = root->parent;
        while(temp1 != temp) {
            temp1->lock_count.lock(); 
            temp1->count--;
            temp1->lock_node.unlock();
            temp1 = temp1->parent;
        }

        root->lock_node.unlock();
        return false;
    }

    root->id = id;
    root->lock = true;
    
    temp = root->parent;
    while(temp) {
        temp->lock_set.lock();
        temp->locked_dec.insert(s);
        temp->lock_set.unlock();
        
        temp->lock_count.unlock();
        temp->count--;
        temp->lock_count.unlock();
        temp = temp->parent;
    }
    
    return true;
}
