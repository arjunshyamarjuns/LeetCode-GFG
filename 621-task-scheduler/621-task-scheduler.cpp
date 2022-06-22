class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int> mp;  
        priority_queue<int> pq;
        for(auto c : tasks)
            mp[c]++;
        for(auto it : mp) 
            pq.push(it.second);
        int ans = 0;
        int cycle = n+1;
        while(!pq.empty()){
            int time = 0;
            vector<int> temp;
            for(int i=0 ; i<cycle ; ++i)
            {
                if(!pq.empty())
                {
                    temp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for(int i : temp) 
                if(--i) 
                pq.push(i);
            ans += (!pq.empty()) ? cycle : time;
        }
        return ans;
    }
};