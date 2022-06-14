class LRUCache {
public:

struct node{
    int key;
    int val;
    node* next;
    node* prev;
    
    node(int x,int y){
        key = x;
        val = y;
        next = NULL;
        prev = NULL;
    }
};

node* head = new node(-1,-1);
node* tail = new node(-1,-1);
int size;
unordered_map<int,node*> mp;

LRUCache(int capacity) {
    size = capacity;
    head ->next = tail;
    tail->prev = head;
}


void insertnode(node *newnode)
{
    auto temp = head->next;
    newnode->next = temp;
    newnode->prev = head;
    head->next = newnode;
    temp->prev = newnode;
}

void deletenode(node *del)
{
    auto nextnode = del->next;
    auto prevnode = del->prev;
    
    prevnode->next = nextnode;
    nextnode->prev = prevnode;
}

int get(int key) {
    
    if(mp.find(key) == mp.end()) return -1;
    
    node *temp = mp[key];
    
    deletenode(temp);
    mp.erase(key);
    
    insertnode(temp);
    mp[key] = head->next;
    
    return temp->val;
    
}

void put(int key, int value) {
    
    if(mp.find(key)!=mp.end()){
        node *temp =  mp[key];
        mp.erase(key);
        deletenode(temp);
    }
    
    if(mp.size() == size){
        mp.erase(tail->prev->key);
        deletenode(tail->prev);
    }
    
    node* newnode = new node(key,value);
    
    insertnode(newnode);
    
    mp[key] = head->next;       
}
};