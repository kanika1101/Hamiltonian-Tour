#include"main.h"


/*Allocate the memory and initialize the hash table.*/
void edgeHashInit(struct edgeHashTable *edgeHash)
{
	int i;
	for(i=0;i<MAXBUCKETS;i++)
	{
		edgeHash->buckets[i]=NULL;
	}
}

/*Use your own hash function to calculate the hash value*/
int calcEdgeHash( int ID1, int ID2)
{

	int hash = ( ID1 + ID2 ) * 33;
	return hash%97;

	
}



/*Search the given edge. If it is found return a pointer to the edge. If not found return NULL*/
struct edge * edgeHashSearch(struct edgeHashTable *edgeHash,struct edge *key)
{
    	char vertex1[30];
	char vertex2[30];
	int i=0;

	strcpy(vertex1,vertices[key->vertexId1]);
	strcpy(vertex2,vertices[key->vertexId2]);

	//int hashID= calcEdgeHash(vertex1,vertex2);
	int hashID= calcEdgeHash(key->vertexId1,key->vertexId2);
	struct llEdgeNode * ptr = edgeHash->buckets[hashID];
	
	struct edge* data;

	while(ptr != NULL)
	{
        	data = ptr->edgeInfo;
        	if(((data->vertexId1 == key->vertexId1) && (data->vertexId2 == key->vertexId2)) ||((data->vertexId1 == key->vertexId2) && (data->vertexId2 == key->vertexId1)))
       		 {
			//printf("found");
          	  	return ptr->edgeInfo;
        	}
        	ptr = ptr->next;
    	}
    return NULL;
	      
}

/*Insert the Type A edge in hash table. Return 0 on success and -1 on failure*/
int edgeHashInsert(struct edgeHashTable *edgeHash, struct edge *data)
{
	char vertex1[30];
	char vertex2[30];
	int i=0;
	struct edge *temp;

	strcpy(vertex1,vertices[data->vertexId1]);
	strcpy(vertex2,vertices[data->vertexId2]);

	
	int hashID = calcEdgeHash(data->vertexId1,data->vertexId2);
	
	temp=llGetEdge(edgeHash->buckets[hashID],data);
	

	if((edgeHashSearch(edgeHash,data) == NULL)&&(temp==NULL))
	{
		llEdgeInsert(&edgeHash->buckets[hashID],data);
		return 0;
		
	}
	else
	{
		struct edge* edg= edgeHashSearch(edgeHash,data);
		edg->weight = data->weight;
	}	
	return -1;
}

/*This function creates an array 'edges' of all the edge entries from the hash table. Return 0 on success and -1 on failure*/
int getArray(struct edgeHashTable *edgeHash,struct edge *edges);











