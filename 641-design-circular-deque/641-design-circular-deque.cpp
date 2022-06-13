class MyCircularDeque {
public:
  MyCircularDeque(int k) : k_(k) {
    elements_.resize(k);
  }

  bool insertFront(int value) {
    if (full_) {
      return false;
    }
    begin_idx_ = (begin_idx_ - 1 + k_) % k_;
    elements_[begin_idx_] = value;
    if (begin_idx_ == end_idx_) {
      full_ = true;
    }
    return true;
  }

  bool insertLast(int value) {
    if (full_) {
      return false;
    }
    elements_[end_idx_] = value;
    end_idx_ = (end_idx_ + 1) % k_;
    if (begin_idx_ == end_idx_) {
      full_ = true;
    }
    return true;
  }

  bool deleteFront() {
    if (begin_idx_ == end_idx_ && !full_) {
      return false;
    }
    begin_idx_ = (begin_idx_ + 1) % k_;
    if (full_) {
      full_ = !full_;
    }
    return true;
  }

  bool deleteLast() {
    if (begin_idx_ == end_idx_ && !full_) {
      return false;
    }
    end_idx_ = (end_idx_ - 1 + k_) % k_;
    if (full_) {
      full_ = !full_;
    }
    return true;
  }

  int getFront() {
    if (begin_idx_ == end_idx_ && !full_) {
      return -1;
    }
    return elements_[begin_idx_];
  }

  int getRear() {
    if (begin_idx_ == end_idx_ && !full_) {
      return -1;
    }
    return elements_[(end_idx_ - 1 + k_) % k_];
  }

  bool isEmpty() { return !full_ && begin_idx_ == end_idx_; }

  bool isFull() { return full_; }

 private:
  std::vector<int> elements_;
  int begin_idx_ = 0;
  int end_idx_ = 0;
  const int k_ = 0;
  bool full_ = false;
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */