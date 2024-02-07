#include <vector>
#include <functional>

class Solution {
public:
    // Function to count the number of subgraphs for each diameter
    vector<int> countSubgraphsForEachDiameter(int n, vector<vector<int>>& edges) {
        // Convert edges into an adjacency list for a graph representation
        vector<vector<int>> graph(n);
        for (auto& edge : edges) {
            int u = edge[0] - 1, v = edge[1] - 1; // Convert to zero-based indexing
            graph[u].emplace_back(v);
            graph[v].emplace_back(u);
        }

        // Answer array to store the counts of subgraphs for each diameter
        vector<int> answer(n - 1, 0);
        int nextNode = 0;
        int mask = 0;
        int maxDiameter = 0;

        // Depth-first search function to explore the graph
        function<void(int, int)> dfs = [&](int node, int distance) {
            mask ^= 1 << node; // Toggle the node in the current mask
            if (maxDiameter < distance) {
                maxDiameter = distance; // Update the max diameter found
                nextNode = node; // Update the node for the next DFS call
            }
            for (int neighbor : graph[node]) { // Visit all connected nodes
                if (mask >> neighbor & 1) { // If the neighbor is in the current mask
                    dfs(neighbor, distance + 1); // Recursive DFS
                }
            }
        };

        // Iterate over all possible subgraphs; represented by bit masks
        for (int currentMask = 1; currentMask < (1 << n); ++currentMask) {
            // Skip masks with single bit set (no edges in such subgraphs)
            if ((currentMask & (currentMask - 1)) == 0) {
                continue;
            }

            // Perform a DFS from the rightmost set bit in the current mask
            mask = currentMask;
            maxDiameter = 0;
            int startNode = 31 - __builtin_clz(mask); // Find rightmost set bit
            dfs(startNode, 0);

            // If after the DFS the mask is 0, all nodes were visited
            if (mask == 0) {
                mask = currentMask;
                maxDiameter = 0;
                dfs(nextNode, 0); // Perform another DFS to find the diameter
                ++answer[maxDiameter - 1]; // Increment the count for this diameter
            }
        }

        return answer;
    }
};
