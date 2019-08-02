#include"main.h"
int j;
struct MST_node{
	int rank;
	int vertexId;
	struct MST_node* parent;
};

struct MST_node **MSTHeads;

int MSTCount=0;

//each vertex is in different component initially and is the parent of itself
void makeSet(int vertexId){
	MSTHeads[MSTCount]=(struct MST_node*)malloc(sizeof(struct MST_node));
	MSTHeads[MSTCount]->vertexId=vertexId;
	MSTHeads[MSTCount]->parent=MSTHeads[MSTCount];
	MSTHeads[MSTCount]->rank=0;
	MSTCount++;
}

//will return the parent of the node
struct MST_node* findSet(int vertexId){
	if(MSTHeads[vertexId]!=MSTHeads[vertexId]->parent)
		MSTHeads[vertexId]->parent = findSet(MSTHeads[vertexId]->parent->vertexId);
	return MSTHeads[vertexId]->parent;
}

//Links two disconnected component
void link(struct MST_node* x,struct MST_node* y){
	if(x->rank > y->rank){
		y->parent=x;
	}
	else{
		x->parent=y;
		if(x->rank == y->rank)
			y->rank = y->rank +1;
	}
}

void unionSet(int x, int y){
	link(findSet(x),findSet(y));
}

//vCount contains the largest verexid of vertices starting from 0
int buildMinSpanningTree(struct edge **sortedEdgeList,struct edge *minSpanningTreeEdges, int eCount, int vCount){

	int i;
	int n;
	int par;
	int cno=0;	//Will contain the component number
	int cost=0;	//Will contain the total cost of the tree
	i=0;
	n=0;
	j=-1;
	MSTCount=0;
	MSTHeads = NULL;
	struct edge* excludedEdges= (struct edge*)malloc(sizeof(struct edge)*eCount);
	MSTHeads = (struct MST_node**)malloc(vCount*sizeof(struct MST_node*));
	
	printf("\n\n------------------------MST---------------------------------------\n\n");
	printf("\nTotal number of vertices = %d\nTotal number of explicitly specified vertices = %d\n",numVertices,vCount+1);
	
		
	printf("\n---------------The sorted edge list is---------------------\n");
	for(i=0;i<eCount;i++){
		printf("(%d %d) %d\n",sortedEdgeList[i]->vertexId1,sortedEdgeList[i]->vertexId2,sortedEdgeList[i]->weight);
	}
	
	//Initially building all n vertices as trees in their own right.
	printf("\n--------------Building tree with following explicit vertices-------------------\n");
	for(i=0;i<=vCount;i++){
		printf("%s  \n",vertices[i]);
		makeSet(i);
	}

	i=0;
	//Adding edges between vertices in ascending order of weight
	//Will check until (vertex count -1) edges have been taken or all edges have been covered
	while((n<=vCount)&&(i<eCount)){

		//Checking if an edge is forming cycle or not		
		if(findSet(sortedEdgeList[i]->vertexId1) != findSet(sortedEdgeList[i]->vertexId2)){
			minSpanningTreeEdges[n]=(*sortedEdgeList[i]);
			cost=cost+minSpanningTreeEdges[n].weight;
			
			// Joining trees together to create a larger tree
			unionSet(sortedEdgeList[i]->vertexId1,sortedEdgeList[i]->vertexId2);
			n++;
		}
		else
		excludedEdges[++j]=(*sortedEdgeList[i]);
		i++;
		
	}

	int max,min;
	int minVertex1,minVertex2;
	int maxVertex1,maxVertex2;

	max=minSpanningTreeEdges[0].weight;
	min=minSpanningTreeEdges[0].weight;
	
	minVertex1=minSpanningTreeEdges[0].vertexId1;
	minVertex2=minSpanningTreeEdges[0].vertexId2;
	
	maxVertex1=minSpanningTreeEdges[0].vertexId1;
	maxVertex2=minSpanningTreeEdges[0].vertexId2;

	//Printing the minimum spanning trees
	int f=0;
	if((n==vCount)&&((vCount+1)==numVertices)){
		printf("\n--------------Minimum Spanning tree constructed--------------\n");
		printf("Edges used are: \n");
		printf("====================\n");
		for(i=0;i<n;i++){
			printf("edge no. %d:(%d %d) %d\n",i,minSpanningTreeEdges[i].vertexId1,minSpanningTreeEdges[i].vertexId2,minSpanningTreeEdges[i].weight);
			if(minSpanningTreeEdges[i].weight > max){
				max = minSpanningTreeEdges[i].weight;
				maxVertex1=minSpanningTreeEdges[i].vertexId1;
				maxVertex2=minSpanningTreeEdges[i].vertexId2;
			}
			if(minSpanningTreeEdges[i].weight<min){
				min = minSpanningTreeEdges[i].weight;
				minVertex1=minSpanningTreeEdges[i].vertexId1;
				minVertex2=minSpanningTreeEdges[i].vertexId2;
			}
		}
		printf("\nEdge with max weight : (%d %d) : %d ",maxVertex1,maxVertex2,max);
		printf("\nEdge with min weight : (%d %d) : %d ",minVertex1,minVertex2,min);
		printf("\nCost of minimum spanning tree is: %d",cost);
		printf("\n====================\n");
		if(j>=0){
			printf("\nExcluded edges are:\n");
			printf("====================\n");
			for(i=0;i<=j;i++)	
				printf("edge no. %d:(%d %d) %d\n",i,excludedEdges[i].vertexId1,excludedEdges[i].vertexId2,excludedEdges[i].weight);
		}
		else{
			printf("\nNo excluded egdes\n");
		}
				
		return 1;
	}

	else{
		cno=1;
		printf("--------------	  Global spanning tree could not be constructed, graph has components	--------------\n");
		if(numVertices>(vCount+1))
		printf("--------------The number of explicitly specified vertices are less than the total number of vertices--------------");

		for(par=0;par<=vCount;par++){
			for(i=0;i<n;i++){
				if((findSet(minSpanningTreeEdges[i].vertexId1))->vertexId == par){
					if(f==0)	
					{
						printf("\nComponent No.: %d\n",cno);
						printf("-------------------------\n");
						f=1;
						cno++;
					}
					printf("edge no. %d:(%d %d) %d\n",i,minSpanningTreeEdges[i].vertexId1,minSpanningTreeEdges[i].vertexId2,minSpanningTreeEdges[i].weight);
				}
			}
			f=0;
		}	
		printf("\n");
		printf("\nCost of all components together is: %d",cost);
		printf("\n====================\n");
		if(j>=0){
			printf("\nExcluded edges are:\n");
			printf("====================\n");
			for(i=0;i<=j;i++)	
				printf("\nedge no. %d:(%d %d) %d\n",i,excludedEdges[i].vertexId1,excludedEdges[i].vertexId2,excludedEdges[i].weight);
		}
		else{
			printf("\nNo excluded egdes\n");
		}
		return 0;
	}													
}
