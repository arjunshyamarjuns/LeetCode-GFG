class Node {
    public:
    Node *child[26]={0};
    bool endOfWord=0;
};
Node *root;
class Trie {
public:
    Trie() {
        root = new Node();
    }
    void insert(string s) {
        auto p=root;
        for(int i=0;i<s.size();i++) {
            int ind=s[i]-'a';
            if(p->child[ind]==0) p->child[ind]=new Node();
            p=p->child[ind];
        }
        p->endOfWord=true;
    }
    
    bool search(string s) {
        auto p=root;
        for(int i=0;i<s.size();i++) {
            int ind=s[i]-'a';
            if(p->child[ind]==0) return 0;
            p=p->child[ind];
        }
        return p!=0 && p->endOfWord==true;
    }
    
    bool startsWith(string s) {
        auto p=root;
        for(int i=0;i<s.size();i++) {
            int ind=s[i]-'a';
            if(p->child[ind]==0) return 0;
            p=p->child[ind];
        }
        return p!=0;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */