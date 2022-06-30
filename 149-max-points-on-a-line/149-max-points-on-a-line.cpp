class Solution {
    int gcd(int a, int b) {
        if(b==0) return a;
        return gcd(b,a%b);
    }
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<3) return n;
        int ans=2;
        for(int i=0; i<n-1; i++) {        
            map<pair<int,int>,int> slopes;
            for(int j=i+1; j<n; j++) {
                int num=points[j][1]-points[i][1], den=points[j][0]-points[i][0];
                if(num*den<0) num=-1*abs(num);
                else num=abs(num);
                den=abs(den);
                int h=gcd(abs(num),den);
                num/=h, den/=h;
                slopes[{num,den}]++;
                ans=max(ans,slopes[{num,den}]+1);
            }
        }
        return ans;
    }
};