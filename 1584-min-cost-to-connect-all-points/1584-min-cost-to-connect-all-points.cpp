class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<vector<pair<int,int>>> adjList(n);

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int w = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                adjList[i].push_back({j, w});
                adjList[j].push_back({i, w});
            }
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<bool> visited(n, false);
        pq.push({0, 0}); //

        int minSum = 0;

        while (!pq.empty()) {
            auto [weight, index] = pq.top();
            pq.pop();

            if (visited[index]) continue;
            visited[index] = true;
            minSum += weight;

            for (auto &temp : adjList[index]) {
                int idx = temp.first;
              int wg = temp.second;
                if (!visited[idx]) {
                    pq.push({wg, idx});
                }
            }
        }
        return minSum;
    }
};