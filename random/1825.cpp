
class MKAverage {
private:
    multiset<int> smaller;
    multiset<int> bigger;
    multiset<int> mid;
    vector<int> nums;
    int m;
    int k;
    int x;
    int i;
    int total;
    long long sum;

    void distribute(){
        while((int)smaller.size() < k){
            int num = *mid.begin();
            smaller.insert(num);
            sum -= num;

            auto i = mid.find(num);
            mid.erase(i);
        }
        while((int)bigger.size() < k){
            int num = *mid.rbegin();
            bigger.insert(num);
            sum -= num;

            auto i = mid.find(num);
            mid.erase(i);
        }
    }
    void add(int num){
        if(total < m){
            ++total;
            mid.insert(num);
            sum += num;

            if(total == m)
                distribute();
            return;
        }
        if(num >= *mid.rbegin()){
            bigger.insert(num);
            shiftLeft();
        }
        else if(num <= *mid.begin()){
            smaller.insert(num);
            shiftRight();
        }
        else{
            mid.insert(num);
            sum += num;
            shiftLeft();
            shiftRight();
        }

    }
    bool check(int num, multiset<int>& st){
        auto i = st.find(num);
        if(i != st.end()){
            st.erase(i);
            return true;
        }
        return false;
    }
    void remove(int num){
        if(check(num, smaller) || check(num, bigger))
            return;
        check(num, mid);
        sum -= num;
        shiftLeft();
    }
    void shiftLeft(){
        if((int)smaller.size() < k){
            int num = *mid.begin();
            smaller.insert(num);

            sum -= num;

            auto i = mid.find(num);
            mid.erase(i);
        }
        if((int)mid.size() < x){
            int num = *bigger.begin();
            mid.insert(num);

            sum += num;

            auto i = bigger.find(num);
            bigger.erase(i);
        }
    }
    void shiftRight(){
        if((int)bigger.size() < k){
            int num = *mid.rbegin();
            bigger.insert(num);

            sum -= num;

            auto i = mid.find(num);
            mid.erase(i);
        }
        if((int)mid.size() < x){
            int num = *smaller.rbegin();
            mid.insert(num);

            sum += num;

            auto i = smaller.find(num);
            smaller.erase(i);
        }
    }
public:
    MKAverage(int m, int k) {
        this->m = m;
        this->k = k;
        this->x = (m - k * 2);
        this->total = 0;
        this->sum = 0;
        this->i = 0;
    }
    
    void addElement(int num) {
        nums.push_back(num);
        if((int)nums.size() > m)
            remove(nums[i++]);
        add(num);
    }
    
    int calculateMKAverage() {
        if((int)nums.size() < m)
            return -1;
        return sum / x;
    }
};
