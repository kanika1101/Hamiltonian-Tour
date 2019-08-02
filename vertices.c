#include"main.h"
/*Allocate the memory and initialize the hash table.*/
void vertexHashInit(struct vertexHashTable *vertexHash){
	int i;
	for(i=0;i<MAXBUCKETS;i++)
		vertexHash->buckets[i]=NULL;
}

/*Use your own hash function to calculate the hash value*/
int calcVertexHash(char *vertexName){
	int index = 0;
	int i=0;
	while(vertexName[i] != '\0'){
		index = index + vertexName[i];
		i++;
	}
	return index%97;
}
/*Insert the Type A edge in hash table. Return 0 on success and -1 on failure*/
int vertexHashInsert(struct vertexHashTable *vertexHash, struct vertex *vertex){
	
	int index,f;
	index = calcVertexHash(vertex->vertexName);
	struct vertex *temp;
	temp=llGetVertex(vertexHash->buckets[index],vertex->vertexName);
	if(temp==NULL)
	{
		f=llVertexInsert(&vertexHash->buckets[index],vertex);
		return f;
	}
	else 
		return -1;
}

/*For the given vertex name calculate the hash value and return the corresponding vertex id from hashtable. Return -1 if vertex name not found*/
int getVertexId(struct vertexHashTable *vertexHash,char *Name){
	struct vertex *v1;	
	int index,vertexId;
	int flag;
	struct llVertexNode *q;
	index = calcVertexHash(Name);
	flag=0;
	q=vertexHash->buckets[index];
	while((q!=NULL) && (flag!=1)){
		v1=q->vertexInfo;
		if(strcmp((v1->vertexName),Name) == 0){
			flag=1;
			vertexId=(q->vertexInfo)->vertexId;
		}
		q=q->next;
	}
	if(flag==0)
		return -1;
	else
		return vertexId;
}


/*For the given vertex id return vertexname from array. Return NULL if vertex id is invalid*/
char * getVertexName(char **vertices,int vertexId,int length){
if((vertexId>length)||(vertexId<0))
return NULL;
else
return vertices[vertexId];
}
