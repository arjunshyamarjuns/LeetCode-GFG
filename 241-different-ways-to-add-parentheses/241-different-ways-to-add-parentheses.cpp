class Solution {
public:
    vector<int> diffWaysToCompute(string exp) {
        vector<int> ans;
        int n=exp.length();
        if(n==1 || n==2) return {stoi(exp)};
        for(int i=0; i<n; i++){
            if(exp[i]!='*'&&exp[i]!='+'&&exp[i]!='-') continue;
            vector<int> left=diffWaysToCompute(exp.substr(0,i));
            vector<int> right=diffWaysToCompute(exp.substr(i+1));
            for(auto &a: left)
                for(auto &b: right)
                    switch(exp[i]){
                        case '+': ans.push_back(a+b); break;
                        case '-': ans.push_back(a-b); break;
                        case '*': ans.push_back(a*b); break;
                    }
        }
        return ans;
    }
};