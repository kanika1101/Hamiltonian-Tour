#include"main.h"
int checkTriangleInequality(struct edge **sortedEdgeList,struct edgeHashTable *edgeHash)
{

	int i,j,u,v,w,A,B,sort;
	
	//If vertices are less than 3.
	if(numVertices < 3)
	{
	printf("\nVertices less than 3, so no triangles can be formed.");
	return (-1);
	}
	
	//If no Type A edges.
	if(edgcount == 0)
	{
	printf("\nAll edges are Type B; So Triangle Inequality will be satisfied for all possiible triangles as they are Equilateral. ");
	return (-1);
	}
	
	//To check if input array is sorted.
	sort = isSorted(edges , edgcount);
	if(sort==0)
	{
		printf("\nEdges array unsorted.");
		return (-1);
	}
	

//Taking the sorted list of edges and checking for all possible combinations of triangles with each edge.
for(i=0;i<edgcount;i++)
{


	u=sortedEdgeList[i]->vertexId1;
	v=sortedEdgeList[i]->vertexId2;
	w=sortedEdgeList[i]->weight;

	for(j=0;j<numVertices;j++) //Checking for all possible vertices in the graph.
	{
		if(j!=u && j!=v)
		{
		A=fetchWeight(u,j,edgeHash);
		B=fetchWeight(v,j,edgeHash);

		if(!(((A+B)>w)&&((A+w)>B)&&((w+B)>A))) //Condition for Triangle Inequality
		{
		printf("\nThe edges (%d ,%d) : %d, (%d ,%d) : %d and (%d ,%d) : %d do not satisfy triangle inequality.\n",u,j,A,v,j,B,u,v,w);
		return 1;
		}

		}
	}
}
return 0;
}



int fetchWeight(int x,int y,struct edgeHashTable *edgeHash)
{
	struct edge * foundEdge = (struct edge *) malloc (sizeof(struct edge));
	struct edge * key = (struct edge *) malloc (sizeof(struct edge)); 
	key->vertexId1 = x;
	key->vertexId2 = y;
	foundEdge = edgeHashSearch(edgeHash,key); //Searching if an edge exists in the Edge Hash Table
	if ( foundEdge != NULL)
	{
		return(foundEdge->weight); //If found return weight
	}
	else
	return(weightb); // Else return bweight
			
}

