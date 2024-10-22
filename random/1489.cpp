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

struct edge{
    int idx;
    int from;
    int to;
    int w;
    edge(int idx, int from, int to, int w) : idx(idx), from(from), to(to), w(w){}
    bool operator <(const edge& e) const{
        return w < e.w;
    }
};

int kruskal(int n, const vector<edge>& edgeList, const vector<edge>& edgesAdd, 
            const unordered_set<int>& edgesIgnore){
    
    UnionFind un(n);
    int mstCost = 0;
    for(const edge& e : edgesAdd) // forcing to add some edges
        un.join(e.from, e.to), mstCost += e.w;
    
    for(const edge& e : edgeList)
        if((edgesIgnore.find(e.idx) == edgesIgnore.end()) && un.join(e.from, e.to))
            mstCost += e.w;
    
    return mstCost;

}

void buildEdgeList(const vector<vector<int>>& edges, vector<edge>& edgeList){
    int idx = 0;
    for(const vector<int>& e : edges)
        edgeList.push_back(edge(idx, e[0], e[1], e[2])), ++idx;
}
vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, const vector<vector<int>>& edges) {
    vector<int> critical;
    vector<int> pseudoCritical;
    vector<edge> edgeList;

    buildEdgeList(edges, edgeList);
    sort(edgeList.begin(), edgeList.end());
    // initially we create an optimal mst and return its weight
    int mstOptimalCost = kruskal(n, edgeList, { }, { });

    // for every edge, we will do two things:
    // 1 - we gonna try to force adding it. then compute the mst weight
    // 2 - we gonna remove it then compute the mst weight
    for(const edge& e : edgeList){
        int mstOptimalCost2 = kruskal(n, edgeList, { e }, { });

        // it means the edges which is forced to be added made an mst with a bigger weight
        // this will not be a part of any mst.
        if(mstOptimalCost < mstOptimalCost2)
            continue;
        
        int mstOptimalCost3 = kruskal(n, edgeList, { }, { e.idx });

        if(mstOptimalCost == mstOptimalCost3)
            pseudoCritical.push_back(e.idx);
        else
            critical.push_back(e.idx);
    }
    return {critical, pseudoCritical};
}
};
