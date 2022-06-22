class MedianFinder {
public:
    priority_queue<int> max;
    priority_queue<int,vector<int>,greater<int>> min;
public:
    
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        //insert value in heap
        if(max.empty() && min.empty() || num < max.top())
            max.push(num);
        else
            min.push(num);
        
        // balance heaps
        if(max.size() > min.size()+1)
        {
            min.push(max.top());
            max.pop();
        }
        else if(min.size() > max.size()+1)
        {
            max.push(min.top());
            min.pop();
        }
    }
    
    double findMedian() {
        if(max.size() == min.size())
            return (double(max.top()) + double(min.top())) / 2.0;
        else if(max.size() > min.size())
            return max.top();
        else
            return min.top();
    }
};
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */