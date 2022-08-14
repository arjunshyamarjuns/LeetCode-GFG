class Solution {
public:
    bool isValid(string expr) {
        stack<char> temp;
        for(int i=0;i<expr.length();i++)
        {
            if(temp.empty())
            {
                temp.push(expr[i]);
            }
             else if((temp.top()=='('&& expr[i]==')')  ||  (temp.top()=='{' && expr[i]=='}')  ||  (temp.top()=='[' && expr[i]==']'))
            {
                temp.pop();
            }
            else
            {
                temp.push(expr[i]);
            }
        }
        if(temp.empty())
        {
            return true;
        }
        return false;
    }
};