class Solution {
public:
    static bool compare(string a,string b){
        return (a+b>b+a);
    }
    string largestNumber(vector<int>& nums) {
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            ans.push_back(to_string(nums[i]));
        }
        
        sort(ans.begin(),ans.end(),compare);
        string c = "";
        for(int i=0;i<ans.size();i++){
            c+= ans[i];
        }
        if(c[0]=='0')return "0";
        return c;
    }
};