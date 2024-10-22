class Solution {
public:
class UnionFind{
private:
    int forests;
    vector<int> parent;
    vector<int> rank;

    void link(int x, int y){
        if(x > y)
            swap(x, y);
        parent[x] = y;

        if(rank[x] == rank[y])
            ++rank[y];
    }
public:
    UnionFind(int n) : forests(n), parent(vector<int>(n)), rank(vector<int>(n)) {
        for(int i=0 ; i<n ; ++i)
            parent[i] = i, rank[i] = 1;
    }
    int findSet(int x){
        if(x == parent[x])
            return x;
        return parent[x] = findSet(parent[x]);
    }
    bool join(int x, int y){
        x = findSet(x), y = findSet(y);

        if(x != y)
            forests--, link(x, y);
        return x != y;
    }
    int getCCs(){return forests;}
};

bool valid(const string& str1, const string& str2){
    int diff = 0;
    for(int i=0 ; i<(int)str1.size() && diff < 3; ++i){
        if(str1[i] != str2[i])
            ++diff;
    }
    return diff <= 2;
}
int numSimilarGroups(const vector<string>& strs) {
    UnionFind un((int)strs.size());

    for(int i=0 ; i<(int)strs.size() - 1; ++i){
        for(int j=i+1 ; j<(int)strs.size() ; ++j){
            if(valid(strs[i], strs[j]))
                un.join(i, j);
        }
    }

    return un.getCCs();
}
};
