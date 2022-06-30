class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low=0, high=1e14;
        long long mid;
        
        while(low<=high) {
            mid=low+(high-low)/2;
            
            if(canCompleteTrips(time,totalTrips,mid))
                high=mid-1;
            else
                low=mid+1;
        }
        return low;
    }
    
    bool canCompleteTrips(vector<int>& time, int totalTrips, long long givenTime) {
        long long totalPossibleTrips=0;
        
        for(int i=0;i<time.size();i++)
            totalPossibleTrips+=givenTime/time[i];
        
        return totalPossibleTrips>=totalTrips;
    }
};