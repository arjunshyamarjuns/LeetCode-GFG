struct Node{
    Node* links[26];
    bool flag = false;
    bool containsKey(char c){
        return links[c-'a']!=NULL;
    }
    void put(char c, Node* node){
        links[c-'a']=node;
    }
    Node* getRef(char c){
        return links[c-'a'];
    }
    void markEnd(){
        flag = true;
    }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        int n = word.size();
        string duplicate = "";
        for(int i=0; i<n; ++i){
            duplicate+=word[i];
            if(search(duplicate)) return;
            if(!node->containsKey(word[i])){
                node->put(word[i], new Node());
            }
            node=node->getRef(word[i]);
        }
        
        node->markEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        int n = word.size();
        for(int i=0; i<n; ++i){
            if(!node->containsKey(word[i])){
                return false;
            }
            node = node->getRef(word[i]);
        }
        return node->flag;
    }
    
    
    string replaceWord(string sentence, string word){
        Node* node = root;
        int n=word.size();
        string newWord = "";
        for(int i=0; i<n && node; ++i){
            if(node->containsKey(word[i])){
                newWord+=word[i];
            }
            node=node->getRef(word[i]);
        }
        if(!node && !search(newWord)) newWord=""; // the word doesn't match with the entire dictionary word
        if(newWord=="") return word;
        else return newWord;
    }
};

class Solution {
public:
    static bool comp(string& a, string& b) {
        return a.size()<b.size();
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        // sort according to size
        sort(dictionary.begin(), dictionary.end(), comp);
        
        Trie* root = new Trie();
        for(string s:dictionary) root->insert(s);
        
        string res = ""; // output string
        
        int n = sentence.size();
        int start = 0;
        for(int i=0; i<n; ++i){
            if(sentence[i]==' '){
                string word = sentence.substr(start, i-start);
                string replaced=root->replaceWord(sentence, word); // get the replaced word
                res+=replaced;
                res+=" ";
                start = i+1;
            }
        }
        res+=root->replaceWord(sentence, sentence.substr(start, n-start)); //replace last word
        return res;
    }
};