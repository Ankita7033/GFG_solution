class Solution {
  public:
    bool dfs(int node, vector<vector<int>>& adj, vector<int>& visi , int parent) {
        
        visi[node]=1;
        
        for(auto it:adj[node]){
            if(!visi[it]){
                if(dfs(it,adj,visi,node)) {
                    return true;
                }
            }
                else if( it != parent){
                    return true;
                }
            
        }
        return false;
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>>adj(V);
        
        //create adj list
        for(auto it: edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        ///visited vector
        vector<int>visi(V,0);
        for(int i=0;i<V;i++){
            if(!visi[i]){
               if( dfs(i,adj,visi,-1)) {
                   return true;
               }
            }
        }
        return false;
        
        
    }
};