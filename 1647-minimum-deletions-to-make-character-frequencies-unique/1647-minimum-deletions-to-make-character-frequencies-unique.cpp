class Solution {
public:
    int minDeletions(string s) {
       unordered_map<char,int>mpp;
        for(int i = 0;i < s.length();i++){
            mpp[s[i]]++;
        }
        set<int>st;
        int count = 0;
        // for(auto it : mpp){
        //     cout << it.first << " : " << it.second << endl;
        // }
        for(auto it : mpp){
            if(st.find(it.second) == st.end()){
                st.insert(it.second);
            }
            else{
                while(st.find(it.second) != st.end() && it.second != 0){
                    it.second--;
                    count++;
                }
                if(it.second != 0){
                    st.insert(it.second);
                }
            }
            
        }
        return count;
        
    }
};