class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {


           vector<vector<int>> adj(n);
           vector<bool> visited(n, false);

        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int> q;
        q.push(source);
        visited[source]=true;
    while(!q.empty()){
        int front=q.front();
        if(front==destination) return true;
        q.pop();

        for(int c:adj[front]){
            if(!visited[c]){
                q.push(c);
                visited[c]=true;
            }
        }
    }
        return false;
        
    }
};




// class Solution {
// private:
//     bool dfs(int node, vector<vector<int>>& adj, vector<bool>& visited, int destination) {
//         if (node == destination) return true;

//         visited[node] = true;

//         for (int neighbor : adj[node]) {
//             if (!visited[neighbor]) {
    
//                 if (dfs(neighbor, adj, visited, destination)) {
//                     return true;
//                 }
//             }
//         }
//         return false;
//     }

// public:
//     bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
    
//         vector<vector<int>> adj(n);

//         for (int i = 0; i < edges.size(); i++) {
//             int u = edges[i][0];
//             int v = edges[i][1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }

//         vector<bool> visited(n, false);

//         return dfs(source, adj, visited, destination);
//     }
// };