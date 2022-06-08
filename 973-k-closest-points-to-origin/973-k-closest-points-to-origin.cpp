class Solution {
public:
    typedef vector<int> v;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, v>> maxheap;
		for (auto i : points) {
			int distance = i[0]*i[0]+i[1]*i[1];
			maxheap.push({distance, i});
			if (maxheap.size() > k) maxheap.pop();
		}
		vector<vector<int>> ans;
		while (!maxheap.empty()) {
			ans.push_back(maxheap.top().second);
            maxheap.pop();
		}
		return ans;
    }
};