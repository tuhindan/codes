#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        bool lock;
        int id; 
        //string s;
        Node* parent;
        //vector<Node *> child;
        unordered_set<string> locked_dec;
};

unordered_map<string, Node *> w_map;

bool addLock(string s, int id) {
    Node* root = w_map[s];
    Node* temp = root;

    if(root->locked_dec.size())
        return false;

    //cout<<2<<" "<<temp->parent->s<<endl;
    while(temp) {
        //cout<<"test"<<" "<<temp->s<<endl;
        if(temp->lock)
            return false;
        temp = temp->parent;
    }

    root->id = id;
    root->lock = true;
    temp = root->parent;

    //cout<<3<<endl;
    while(temp) {
        //cout<<4<<endl;
        temp->locked_dec.insert(s);
        temp = temp->parent; 
        //cout<<5<<endl;
    }
    
    return true;
}

bool removeLock(string s, int id) {
    Node* root = w_map[s];
    Node* temp = root;

    if(!root->lock || root->id != id)
        return false;
    
    temp = root->parent;
    while(temp) {
        //cout<<4<<endl;
        temp->locked_dec.erase(s);
        temp = temp->parent; 
        //cout<<5<<endl;
    }

    root->lock= false;
    return true;
}

bool upgradeLock(string s, int id) {
    cout<<1<<endl;
    Node* root = w_map[s];
    Node* temp = root;

    cout<<2<<endl;
    while(temp) {
        if(temp->lock)
            return false;
        temp = temp->parent;
    }

    cout<<3<<endl;
    if(root->locked_dec.size() == 0)
        return false;
    

    int len = root->locked_dec.size();

    cout<<4<<endl;
    for(auto itr = root->locked_dec.begin() ; itr != root->locked_dec.end() ; ++itr) {
        temp = w_map[(*itr)];
        if(temp->id != id)
            return false;
    }

    cout<<5<<endl;
    for(auto itr = root->locked_dec.begin() ; itr != root->locked_dec.end() ; ++itr) {
        removeLock((*itr),id);
    }

    return addLock(s,id);
}

int main(void) {
    int n,m,q;
    cin>>n>>m>>q;

    queue<Node *> t;
    Node* head = NULL;

    string s;
    cin>>s;
    Node *temp = new Node();//( Node *)malloc(sizeof(struct Node));
    temp->parent = NULL;
    temp->lock = false;
    //temp->s = s;
    w_map[s] = temp;
    head = temp;
    n--;
    t.push(temp);

    while(n) {
        Node *root = t.front();
        t.pop();

        for(int i = 0 ; i < m && n ; i++) {
            cin>>s;
            //cout<<root->s<<" "<<s<<endl;
            temp = new Node();//( Node *)malloc(sizeof(struct Node));
            temp->parent = root;
            temp->lock = false;
            //temp->s = s;
            //root->child.push_back(temp);
            w_map[s] = temp;
            t.push(temp);
            n--;
        }
    }

    while(q--) {
        int type, id;
        string s;
        bool flag = false;
        cin>>type>>s>>id;

        if(type == 1 && addLock(s,id))
            flag = true; 
            
        if(type == 2 && removeLock(s,id))
            flag = true;

        if(type == 3 && upgradeLock(s,id))
            flag = true;

        if(flag)
            cout<<"true"<<endl;
        else    
            cout<<"false"<<endl;
    }

}
