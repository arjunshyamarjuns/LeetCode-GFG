class MyCircularQueue {
public:
       int head,tail,size;
    vector<int> queue;
    
    MyCircularQueue(int k) {
        queue.resize(k);
        size = k;
        tail = -1;
        head = 0;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        tail = (tail+1)%size;
        queue[tail] = value;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        if(head == tail){
            head = 0;
            tail = -1;
            return true;
        }
        head = (head+1)%size;
        return true;
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return queue[head];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return queue[tail];
    }
    
    bool isEmpty() {
        if(tail == -1)
            return true;
        return false;
    }
    
    bool isFull() {
        if(head == (tail+1)%size && tail!=-1){
            return true;
        }
        return false;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */