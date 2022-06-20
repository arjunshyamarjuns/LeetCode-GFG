class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> st;
        for(string &s: wordList) st.insert(s);
        
        if(st.find(endWord) == st.end()) return 0;
        
        queue<string> q;
        q.push(beginWord);
        int ladderLength = 1;
        
        while(q.empty() == false) {
            int n = q.size();
            for(int i = 0; i < n; i++) {
                string word = q.front(); q.pop();
                
                if(word == endWord) return ladderLength;
                
                st.erase(word);
                
                for(int j = 0; j < word.length(); j++) {
                    char ch = word[j];
                    for(int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if(st.find(word) != st.end()) {
                            q.push(word);
                        }
                    }
                    word[j] = ch;
                }
            }
            
            ladderLength++;
        }
        
        return 0;
    }
};