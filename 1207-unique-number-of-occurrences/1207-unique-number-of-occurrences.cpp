class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n=arr.size();
        unordered_map<int,int>unmap;
        set<int>mset;
        for(int i=0;i<n;i++)
        {
            unmap[arr[i]]++;
        }
        for(auto it : unmap)
        {
            mset.insert(it.second);
        }
        if(mset.size()==unmap.size())
        {
            return true;
        }
        return false;
    }
};