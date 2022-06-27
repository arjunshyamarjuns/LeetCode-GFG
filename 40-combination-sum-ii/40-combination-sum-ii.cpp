class Solution {
public:
     vector<vector<int>> ans;
    void findCombination(int index, vector<int> &arr, vector<int> &ds, int target)
    {
        if (target == 0)
        {
            ans.push_back(ds);
            return;
        }
        for (int i = index; i < arr.size(); i++)
        {
            if (i > index && arr[i] == arr[i - 1])
                continue;
            if (arr[i] > target)
                break;
            ds.push_back(arr[i]);
            findCombination(i + 1, arr, ds, target - arr[i]);
            ds.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> ds;
        findCombination(0, candidates, ds, target);
        return ans;
    }
};