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

int makeConnected(int n, const vector<vector<int>>& connections) {
    UnionFind un(n);
    int availableEdges = 0;

    for(const vector<int>& connection : connections)
        availableEdges += !(un.join(connection[0], connection[1]));
    
    int cc = un.getCCs();
    if(cc == 1)
        return 0;
    else
        return (availableEdges >= cc - 1? cc - 1 : -1);
}
};
