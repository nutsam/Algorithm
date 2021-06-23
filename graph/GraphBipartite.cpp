class Solution {
public:
    /*
    //DFS
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> color(graph.size());
        for(int i = 0; i < graph.size(); i ++){
            if (color[i] == 0 && !valid(graph, 1, i, color)) {
                return false;
            }
        }
        return true;
    }
    
    bool valid(vector<vector<int>>& graph, int c, int node, vector<int>& color){
        
        if(color[node] != 0) return color[node] == c;
        color[node] = c;
        
        for(auto a : graph[node]){
            if(!valid(graph, c * -1, a, color))
                return false;
        }
        return true;
    }
    */
    /*
    //BFS
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> color(graph.size());
        for (int i = 0; i < graph.size(); i ++) {
            if (color[i] != 0) continue;
            color[i] = 1;
            queue<int> q{{i}};
            
            while (!q.empty()) {
                int t = q.front();
                q.pop();
                for (auto a : graph[t]) {
                    if (color[a] == color[t]) return false;
                    if (color[a] == 0) {
                        color[a] = -1 * color[t];
                        q.push(a);
                    }
                }
            }
        }
        return true;
    }
    */
    //Union find
    bool isBipartite(vector<vector<int>>& graph) {
        
        vector<int> root(graph.size());
        for(int i = 0; i < graph.size(); i ++) root[i] = i;
        for(int i = 0; i < graph.size(); i ++){
            if(graph[i].size() == 0) continue;
            
            int x = find(root, i);
            int y = find(root, graph[i][0]);
            if(x == y) return false;
            
            for(int j = 1; j < graph[i].size(); j ++){
                int child = find(root, graph[i][j]);
                if(x == child) return false;
                root[child] = y;
            }
        }
        return true; 
    }
    
    int find(vector<int>& root, int node){
        return root[node] == node ? node : find(root, root[node]);
    }
    
    
};
