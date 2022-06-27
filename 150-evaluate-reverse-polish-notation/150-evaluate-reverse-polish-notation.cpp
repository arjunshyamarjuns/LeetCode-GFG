class Solution {
public:
    int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for(int i=0;i<tokens.size();++i){
        if(tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/"){
            int x=stoi(tokens[i]);
            s.push(x);
        }
        else{
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            int ans;
            if(tokens[i]=="+"){
                ans=a+b;
                s.push(ans);
            }
            else if(tokens[i]=="/"){
                ans=b/a;
                s.push(ans);
            }
            else if(tokens[i]=="*"){
                ans=a*b;
                s.push(ans);
            }
            else{
                ans=b-a;
                s.push(ans);
            }
        }
    }
    return s.top();
}
};