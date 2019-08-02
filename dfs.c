#include"main.h"

struct dfsVertex* dfsVertices;
struct dfsVertex* stack;
struct edge* graphEdges;
int *arr;
int arrIndex=-1;
int top=-1;
struct dfsVertex* findAdjNode(int vertex, int vCount){
	//printf("\nInside findAdjNode");
	//printf("\nMST edges are:");
	int i;
	for(i=0;i<=vCount;i++){
		//printf("Checking edge no. %d:(%d %d) %d\n",i,graphEdges[i].vertexId1,graphEdges[i].vertexId2,graphEdges[i].weight);
		if(graphEdges[i].vertexId1==vertex){
			if(dfsVertices[graphEdges[i].vertexId2].color==0){
				dfsVertices[graphEdges[i].vertexId2].color==1;
				return &dfsVertices[graphEdges[i].vertexId2];
			}
		}	
	}	
	return NULL;
}

int dfs(struct edge* minEdges, int vCount){
	//printf("\nInside dfs");
	dfsVertices= NULL;
	dfsVertices= (struct dfsVertex*)malloc(sizeof(struct dfsVertex)*(vCount+1));
	arr = (int*)malloc(sizeof(int)*(vCount+1));
	stack=(struct dfsVertex*)malloc(sizeof(struct dfsVertex)*(vCount+1));
	//adjList(minEdges,1,vCount);
	//For each explicit vertex in the MST do the following
	//int n=startVertex;
	graphEdges=minEdges;
	int i;
	for(i=0;i<=vCount;i++){
		dfsVertices[i].vertexId=i;
		dfsVertices[i].parentId=-1;
		dfsVertices[i].color=0;
		//n++;
	}
	for(i=0;i<=vCount;i++){
		if(dfsVertices[i].color == 0){
			dfs_visit(&dfsVertices[i]);
		}
	}
	/*for(i=0;i<vCount;i++)
		printf("edge no. %d:(%d %d) %d\n",i,graphEdges[i].vertexId1,graphEdges[i].vertexId2,dfsdfsgraphEdges[i].weight);*/
		
	return 0;
}
void dfs_visit(struct dfsVertex *vertex){
	//printf("\nInside dfs_visit");
	struct dfsVertex* adjVertex;
	struct dfsVertex u;
	u=(*vertex);
	int i;
	stack[++top]=(*vertex);	
	vertex->color=1;	
	printf("\n%d",u.vertexId);
	arr[++arrIndex]=u.vertexId;
	while(top!=-1){
		adjVertex=findAdjNode(u.vertexId,vCount);
		while(adjVertex!=NULL){
			//printf("Got adj of %d, %d",u.vertexId,adjVertex->vertexId);
			printf("\n%d",adjVertex->vertexId);
			arr[++arrIndex]=adjVertex->vertexId;
			adjVertex->parentId=u.vertexId;
			adjVertex->color=1;
			stack[++top]=(*adjVertex);
			u=(*adjVertex);
			adjVertex=findAdjNode(u.vertexId,vCount);
		}
		top--;
		u=stack[top];			
	}
	printf("\nDFS path is ");
	for(i=0;i<=arrIndex;i++)
		printf("->%d",arr[i]);
}

void dfsTour(){
	
}
