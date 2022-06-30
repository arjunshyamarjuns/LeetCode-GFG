class Solution {
private:
    int bSearchUpper(int tar, vector<int> &arr) {
        int l = 0, r = arr.size();
        while (l < r) {
            int m = l + (r - l) / 2;
            if (arr[m] >= tar) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        return l;
    }
public:
    vector<int> countRectangles(vector<vector<int>>& rectangles, vector<vector<int>>& points) {
        vector<vector<int>> heightLookup(101, vector<int>()); // O(H)
        
		// O(M) time
        for (vector<int> &eachR : rectangles) {
            heightLookup[eachR[1]].push_back(eachR[0]);
        }

		// O(MlogM) time
        for (vector<int> &eachH : heightLookup) {
            sort(eachH.begin(), eachH.end(), greater<int>());
        }
        
		// O(NlogM) time
        vector<int> res;
        for (vector<int> &eachP : points) {
            int cnt = 0;
            for (int i = 100; i >= eachP[1]; i--) {
                if (heightLookup[i].empty()) continue;
                cnt += bSearchUpper(eachP[0], heightLookup[i]);
            }
            res.push_back(cnt);
        }
        return res;
    }
};