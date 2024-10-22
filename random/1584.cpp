class Solution {
public:
struct Node{
    int idx;
    int x;
    int y;

    Node() : idx(-1), x(-1), y(-1) {}
    Node(int idx, int x, int y) : idx(idx), x(x), y(y) {}
    void set(int idx, int x, int y) {this->idx = idx, this->x = x, this->y = y;}
};

struct Edge{
    Node to;
    int weight;

    Edge(Node to, int weight) : to(to), weight(weight){}
    bool operator <(const Edge &e) const {
		return weight > e.weight;
	}
};


void rebuildNodes(const vector<vector<int>>& points, vector<Node>& nodes){
    int n = points.size();
    nodes = vector<Node>(n);

    for(int i=0 ; i<n ; ++i)
        nodes[i].set(i, points[i][0], points[i][1]);
}

int manhattan(Node node1, Node node2){
    return abs(node1.x - node2.x) + abs(node1.y - node2.y);
}
int MST(const vector<Node>& nodes){
    int n = nodes.size();
    int OO = 2 * 1e6 * 1000;

    vector<bool> visited(n);
    vector<int> dist(n, OO);
    priority_queue<Edge> pq;

    pq.push(Edge(nodes.front(), 0));
    dist[nodes.front().idx] = 0;
    int mstCost = 0;
    
    while(!pq.empty()){
        Edge e = pq.top();
        pq.pop();

        int nodeIdx = e.to.idx;
        int edgeWeight = e.weight;

        if(visited[nodeIdx])
            continue;
        
        mstCost += edgeWeight;
        for(int i=0 ; i<n ; ++i){
            int to = nodes[i].idx;
            int weight = manhattan(e.to, nodes[i]);

            if(dist[to] > weight)
                dist[to] = weight, pq.push(Edge(nodes[i], weight));
        }
        visited[nodeIdx] = true;
    }
    return mstCost;
}
int minCostConnectPoints(vector<vector<int>>& points) {
    vector<Node> nodes;   
    rebuildNodes(points, nodes); 

    return MST(nodes);
}
};
