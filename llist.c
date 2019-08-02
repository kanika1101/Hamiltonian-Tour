#include"main.h"
/*Insert the Type A edge in linked list. Return 0 on success and -1 on failure*/
int llEdgeInsert(struct llEdgeNode **head,struct edge *edgeData)
{
	struct llEdgeNode* node = (struct llEdgeNode*)malloc(sizeof(struct llEdgeNode));
	node->edgeInfo=edgeData;
	node->next=(*head);
	(*head)=node;
	return 1;
}
/*Return the node of the linked list containing the key. If not fonud, return NULL*/
struct edge * llGetEdge(struct llEdgeNode *head,struct edge *key)
{
	struct llEdgeNode *temp1;
		temp1=head;
		while(temp1!=NULL)
		{
		if((temp1->edgeInfo->vertexId1==key->vertexId1)&&(temp1->edgeInfo->vertexId2==key->vertexId2))
			return temp1->edgeInfo;
		temp1=temp1->next;
		}
		return NULL;	


}


/*Insert the Type A edge in linked list. Return 0 on success and -1 on failure*/
int llVertexInsert(struct llVertexNode **head,struct vertex *vertexData){
	struct llVertexNode *node;
	node=(struct llVertexNode*)malloc(sizeof(struct llVertexNode));
	node->vertexInfo = vertexData;
	node->next=(*head);
	(*head)=node;
	return 1;
}	
/*Return the node of the linked list containing the key. If not fonud, return NULL*/
struct vertex * llGetVertex(struct llVertexNode *head,char *vertexName)
{
	struct llVertexNode *temp1;
		temp1=head;
		while(temp1!=NULL)
		{
		if(strcmp(temp1->vertexInfo->vertexName,vertexName)==0)
			return temp1->vertexInfo;			
		temp1=temp1->next;
		}
		return NULL;
		

}

