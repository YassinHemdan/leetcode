static const auto _ = []() {
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cerr.tie(nullptr);
    std::cin.tie(nullptr);
    return nullptr;
}();
class MedianFinder {
private:
    multiset<int> maxHeap;
    multiset<int> minHeap;
    bool isEven = true;

    void moveFromMinToMax(){
        maxHeap.insert(*minHeap.begin());
        auto i = minHeap.find(*minHeap.begin());
        minHeap.erase(i);
    }
    void moveFromMaxToMin(){
        minHeap.insert(*maxHeap.rbegin());
        auto i = maxHeap.find(*maxHeap.rbegin());
        maxHeap.erase(i);
    }
public:
    MedianFinder() {}
    void clear(){
        minHeap.clear();
        maxHeap.clear();
    }
    void addNum(int num) {
        if(isEven){
            minHeap.insert(num);
            moveFromMinToMax();
        }
        else{
            maxHeap.insert(num);
            moveFromMaxToMin();
        }
        isEven = !isEven;
    }
    void removeNum(int num){
        auto i = maxHeap.find(num);
        if(i != maxHeap.end()){
            maxHeap.erase(i);
            if((int)maxHeap.size() < minHeap.size())
                moveFromMinToMax(), isEven = false;
            else
                isEven = true;
        }
        else{
            auto i = minHeap.find(num);
            minHeap.erase(i);
            if((int)maxHeap.size() > minHeap.size() + 1)
                moveFromMaxToMin(), isEven = true;
            else
                isEven = false;
        }
    }
    double findMedian() {
        if(isEven)
            return ((double)*minHeap.begin() + (double)*maxHeap.rbegin()) / 2;
        return *maxHeap.rbegin();
    }
};
class Solution {
private:
    MedianFinder finder;
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        finder.clear();
        vector<double> ans;
        for(int i=0 ; i<k ; ++i)
            finder.addNum(nums[i]);
        
        ans.push_back(finder.findMedian());
        for(int i=k ; i<(int)nums.size() ; ++i){
            finder.removeNum(nums[i - k]);
            finder.addNum(nums[i]);
            ans.push_back(finder.findMedian());
        }
        return ans;
    }
};
