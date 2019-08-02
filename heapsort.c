#include"main.h"


int heapSize=0;

int left(int i)
{
	return 2*i;
}

int right(int i)
{
	return (2*i+1);
}

int isSorted(struct edge **edges , int numEdges)
{
	int isSorted = 0,i=0;
	
	for(i=0;i<numEdges-1;i++)
	{
		if(edges[i]->weight >= edges[i+1]->weight)
		{
			isSorted = 1;
		}
		else
			isSorted = 0;
			
	}
	return isSorted;

}

void max_heapify(struct edge **edges , int index)
{
	int l = left(index);
	int r = right(index);

	int largest;

	if(l<=heapSize && (edges[l]->weight < edges[index]->weight))
	{
		largest = l;
	}
	else
	{
		largest = index;
	}

	if(r<=heapSize && (edges[r]->weight < edges[largest]->weight))
	{
		largest = r;
	}
	

	if(largest != index)
	{
	 	struct edge* temp = edges[index];
		edges[index] = edges[largest];
		edges[largest] = temp;
		max_heapify(edges,largest);
	}
}

/* Function to build the  heap*/ 
void build_max_heap(struct edge **edges , int numEdges)
{
	int i=0;
	
	for(i=heapSize/2 ; i>=0 ; i--)
	{
		max_heapify(edges,i);
	}
}

/*Function to perform heap sort i.e call heapify and recreate_heap from here . 
   edges - pointer to array of edges
Return 0 on success and -1 on failure*/
int heapsort(struct edge **edges , int numEdges)
{
	

	int i,j;	

	heapSize = numEdges-1;
	build_max_heap(edges,numEdges);

	for(i=numEdges-1 ; i>=1 ; i--)
	{
		struct edge* temp = edges[0];
		edges[0] = edges[i];
		edges[i] = temp;
		heapSize--; 
		max_heapify(edges,0);
	}

	j = isSorted(edges , numEdges);

	if(j==0 && edgcount!=0)
	{
		printf("\n\nEdges array unsorted.");
		return 0;
	}
	else
	{
		printf("\n\nEdges array sorted correctly by Heapsort.");
		return 1;
	}

}
