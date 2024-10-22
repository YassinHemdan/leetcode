static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    std::cin.tie(nullptr);
    return nullptr;
}();
class MedianFinder {
private:
    // holds the greater values and gets for me the maximum among them
    priority_queue<int> maxHeap;
    // holds the smaller values and gets for me the minimum among them
    priority_queue<int, vector<int>, greater<int>> minHeap;
    bool even = true;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // we need to maintain two things:
        // 1- the maxHeap always contains numbers <= the minHeap
        // 2- the sizes of the two heaps are always equal or one greater than the other by only 1
        if(even){
            maxHeap.push(num);
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }
        else{
            minHeap.push(num);
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        even = !even;
    }
    
    double findMedian() {
        if(even)
            return (double)(maxHeap.top() + minHeap.top()) / 2;
        return minHeap.top();
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
