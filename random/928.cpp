class Solution {
public:
void buildGraph(vector<vector<int>>& graph, vector<vector<int>>& adjacencyList, int n){
    for(int i=0 ; i<n ; ++i){
        for(int j=0 ; j<n ; ++j){
            if(i == j)
                continue;
            if(graph[i][j] == 1)
                adjacencyList[i].push_back(j);
        }
    }
}

int dfs(int node, const vector<vector<int>>& graph, 
        const unordered_set<int>& infected, vector<bool>& visited, 
        bool& isInfected){
    
    if(visited[node])
        return 0;
    if(infected.find(node) != infected.end())
        isInfected = true;
    
    int nodes = 1;
    visited[node] = true;
    for(int child : graph[node])
        nodes += dfs(child, graph, infected, visited, isInfected);
    return nodes;
}
int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
    int n = graph.size();
    vector<vector<int>> adjacencyList(n);
    buildGraph(graph, adjacencyList, n);

    unordered_set<int> infected {initial.begin(), initial.end()};

    int minIdxNode = INT_MAX;
    int minInfectedNodes = n;

    for(int infectedNode : initial){ // O(n^2)
        // remove from the infected nodes
        infected.erase(infectedNode);
        // dfs and get the number of current infected node in every cc
        // minimize between them
        vector<bool> visited(n); // O(n)
        visited[infectedNode] = true;
        int totalInfected = 0;
        for(int node = 0 ; node < n ; ++node){ // O(n + m)
            bool isInfected = false;
            int numOfInfectedNodes = 0;
            if(!visited[node])
                numOfInfectedNodes = dfs(node, adjacencyList, infected, visited, isInfected);
            if(isInfected)
                totalInfected += numOfInfectedNodes;
        }

        infected.insert(infectedNode);
        if(minInfectedNodes > totalInfected){
            minInfectedNodes = totalInfected;
            minIdxNode = infectedNode;
        }
        else if(minInfectedNodes == totalInfected)
            minIdxNode = min(minIdxNode, infectedNode);
    }

    return minIdxNode;

}
};
