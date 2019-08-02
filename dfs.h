/*Function prototypes for Depth First Search*/


/* Get the array of edges from MST
   This function should create an array of vertices having vertices in the order of DFS
   Return 0 on success and -1 on failure*/
struct dfsVertex{
	int vertexId;
	int color;
	int parentId;
};

int dfs(struct edge* minEdges, int vCount);
struct dfsVertex* findAdjNode(int vertex, int vCount);
void dfs_visit(struct dfsVertex *vertex);

