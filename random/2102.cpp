class SORTracker {
private:
    struct location{
        string name;
        int score;
        location(const string& name, int score) : name(name), score(score) {}
        bool operator <(const location& other)const {
            if(other.score == score)
                return name > other.name;
            return score < other.score;
        }
    };
    set<location> minHeap;
    set<location> maxHeap;
public:
    SORTracker() {
        
    }
    
    void add(const string& name, int score) {
        minHeap.insert(location(name, score));
        location loc = *minHeap.begin();
        minHeap.erase(loc);

        maxHeap.insert(loc);
    }
    
    string get() {
        location loc = *maxHeap.rbegin();
        maxHeap.erase(loc);
        
        string name = loc.name;
        minHeap.insert(loc);

        return name;
    }
};
