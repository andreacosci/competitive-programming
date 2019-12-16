/*This is a function problem.You only need to complete the function given below*/
/*The function takes an adjacency matrix representation of the graph (g)
and an integer(v) denoting the no of vertices as its arguments.
You are required to complete below method */
bool isBipartite(int G[][MAX],int V)
{
     //Your code here
     int col[V], vis[V];
     memset(col, 0, sizeof(col));
     memset(vis, 0, sizeof(col));
     
     for(int i = 0; i < V; i++) {
     	vis[i] = 1;
	 	for(int j = 0; j < V; j++) {
	 		if (G[i][j]) {
				if (!vis[j]) {
					vis[j] = 1;
					col[j] = col[i] ^ 1;
				} else if (col[i] == col[j])
					return false;
			}
		 }
	 }	
	 
	 return true;
}
