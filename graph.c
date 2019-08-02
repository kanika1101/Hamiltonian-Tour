#include"main.h"

void printVertex(struct vertexHashTable *vertexHash){
	int i;
	printf("\n------------------Vertex Hash Table:-----------------------\n");
	
	struct llVertexNode* q;
	for(i=0;i<MAXBUCKETS;i++){
		q=vertexHash->buckets[i];
		while(q != NULL){	
			printf("%s: \t",q->vertexInfo->vertexName);	
			printf(" %d\n",q->vertexInfo->vertexId);
				
			q=q->next;
		}
	}
}

void printEdge(struct edgeHashTable* edgHashTable)
{
	printf("\n");printf("\n");
	printf("--------------------Edge Hash Table:--------------------------------");
	int i=0,count=0;
	struct llEdgeNode* node = (struct llEdgeNode*)malloc(sizeof(struct llEdgeNode));
	printf("\n\n");
	while(i<MAXBUCKETS)
	{
		
		node=edgHashTable->buckets[i];
		if(node==NULL)
		{
			i++;
			continue;
		}
		

		while(node!=NULL)
		{
			printf("(%d  ",node->edgeInfo->vertexId1);
			printf("%d) weight: %d    ",node->edgeInfo->vertexId2,node->edgeInfo->weight);
			node=node->next;
			count++;
		}
		printf("\n");
		i++;
	}
	printf("\nNo of Type A edges: %d",count);printf("\n");printf("\n");
	printf("---------------------------------------------------------\n");

}


int TestCase(char *inputFileName)                             // Function for checking input file.
{
FILE *f1;

f1=fopen("C:\\Users\\Getene\\Documents\\hamiltonianTour\\Triangle-1.txt","r");

int n=0,numv;                                                // n contains number of lines in file.

char *tok ,c;
char eachLine[100];

if(f1==NULL)
{
	printf("\n**** Error Msg :: No such file Exists!! ****\n");
	return -1;
}
	if(fgets(eachLine,100, f1)==NULL)
	{
		printf("\n**** Error Msg :: File is Empty!!****\n");
		fclose(f1);
		return -1;
	}
		else
	 	{
		rewind(f1);
			while(fgets(eachLine, 100, f1)!=NULL)                            //total number of lines
			n++;
			//printf("Total Number of lines is : %d", n);
			rewind(f1);

		
		fgets(eachLine,100,f1);                                                  // Checking first line.
		tok=strtok(eachLine, "'() .:;-");
		numv=atoi(strtok(NULL,"'() .:;-"));
		
		
		if (strcmp(tok, "num_vertices") != 0)
		{
			printf("\n**** Error Msg :: First line missing!!****\n");
			return -1;
		}		
		else if (numv==0) 
		{
			printf("\n**** Error Msg ::Number of vertices not given!!****\n"); 
			return -1;
		}
		
		}

		
		
		

		fgets(eachLine, 100, f1);                                                 //move to 2nd line
		//printf("%d", strlen(eachLine));
		while(strlen(eachLine)==1)
			fgets(eachLine, 100, f1);
		tok=strtok(eachLine, "'() .:;-");
		//("%s", tok);
		//printf("%s",tok);
		
         	


		if((strcmp(tok,"type"))==0)
		{
                        printf("\n****Error Msg :: There are no Type A edges!!****\n");
			return 0;
		}
		rewind(f1);
		
		fgets(eachLine, 100, f1);
				
		while(fgets(eachLine, 100, f1)!=NULL)                           // Checking each line
		{

			tok=NULL;
			tok=strtok(eachLine, "'() .:;-");
			
			if(strcmp(tok, "type")==0)
			{
				tok=strtok(NULL, "'() .:;-");
				weightb=atoi(strtok(NULL, "'() .:;"));
				
				if(weightb<=0)
				{
					printf("\n****Error Msg :: Please check the Weight b ***\n");
					return -1;
				}
				
				fclose(f1);
				return 0;
			}
			else
			{
				if(tok!=NULL)                                              //here tok holds first vertex name
					tok=strtok(NULL,"'() .:;-");                       //now if first vertex is not null then tok gets second vertex
				if(tok!=NULL)                                              //if second vertex is not null then
				{
					tok=strtok(NULL,"'() .:;");
					if(tok!=NULL)
					{
						int weight=atoi(tok);
						if(weight<=0)                              //get the weight of edge and if that weight is 0
						{	
							printf("\n**** Error Msg :: Please check the Weight A****\n");
							return -1;
						}
					}
					else
					{
						printf("\n**** Error Msg :: Only one vertex is specified in type A edge****\n");
						return -1;
					}
				}
			}
		}
 
if(weightb==0)                                               //Check if last line is given or not..
{
	printf("\n**** Error Msg :: Line giving Type B weight not specified in input****\n");
	return -1;
}
fclose(f1);
}

int parseInputDescription(char *inputFileName,struct vertexHashTable *vertexHash,struct edgeHashTable *edgeHash)
{
	
	int flag,bVertexAppend;
	struct vertex* node;
	//struct edge* minEdges= (struct edge*)malloc(sizeof(struct edge)*(vCount-1));
	

	FILE *input;

	char vertexName1[30]={"\0"},vertexName2[30]={"\0"},bvertexName[30]={"\0"},c,bVertex[6],eachLine[100];

	char *tok;
	
	int count,i,j,weight,vertexId1, vertexId2;
	char* v;

	strcpy(bVertex,"User_");

	//Initialising vertexhash
	vertexHashInit(vertexHash);
	edgeHashInit(edgeHash);

	input=fopen(inputFileName,"r");


	fgets(eachLine,100,input);                           //Collect numvertices
	tok=strtok(eachLine,"'() ;:-");
	numVertices=atoi(strtok(NULL," ();:-"));

	
	
	vertices=(char**)malloc(numVertices*sizeof(char *));
	edges = (struct edge**)malloc((numVertices*(numVertices - 1)/2)*sizeof(struct edge));

	//while((c = fgetc(input))!='\n');
	count=-1;
	printf("\nVertex\t\t    Vertex\t\tWeight");
	while(c!=EOF)
	{
		
		if((c = fgetc(input))=='('){
			i=0;
			while((c = fgetc(input))!=' ')
			{
				vertexName1[i]=c;
				i++;
			}
			vertexName1[i]='\0';
			printf("\n%-20s",vertexName1);
			
			
			if(getVertexId(vertexHash,vertexName1)==-1)
			{
				count++;
				if(count<numVertices){
					node = (struct vertex*)malloc(sizeof(struct vertex));
					vertices[count]=(char*)malloc(sizeof(vertexName1));
					strcpy(vertices[count],vertexName1);
					node->vertexId=count;
					strcpy(node->vertexName,vertexName1);
					vertexHashInsert(vertexHash,node);
				}
				else{
					printf("\nExplicit vertices are more than the vertices required\n");
					return -1;
				}
			}
	
			i=0;
			while((c = fgetc(input))!=')')
			{

				if(c==' '){
					printf("\n*****Error Msg :: extra space....file not in actual format******\n");
					return -1;}
				vertexName2[i]=c;
				i++;
			}	
			vertexName2[i]='\0';
			printf("%-20s",vertexName2);
			if(getVertexId(vertexHash,vertexName2)==-1)
			{
				count++;
				if(count<numVertices){
					vertices[count]=(char*)malloc(sizeof(vertexName1));
					strcpy(vertices[count],vertexName2);
					node = (struct vertex*)malloc(sizeof(struct vertex));
					node->vertexId=(count);
					strcpy(node->vertexName,vertexName2);
					vertexHashInsert(vertexHash,node);
				}
				else{
					printf("\nExplicit vertices are more than the vertices required");
					return -1;
				}
			}

			//while((c = fgetc(input))==' ');
			fscanf(input,"%d",&weight);
			printf("%d",weight);

			while((c = fgetc(input))!='\n');
		
			}

if(strlen(vertexName1)>1&&strlen(vertexName2)>1)
{
			struct edge* edg = (struct edge*)malloc(sizeof(struct edge));
			edg->vertexId1=getVertexId(vertexHash,vertexName1);
			edg->vertexId2=getVertexId(vertexHash,vertexName2);
			edg->weight=weight;
			

			if(edgeHashSearch(edgeHash,edg) == NULL)
			{
				edgeHashInsert(edgeHash,edg);
				edges[edgcount++] = edg;
			}
			else
			{
				struct edge* edg1= edgeHashSearch(edgeHash,edg);
				edg1->weight = edg->weight;
			}
}



	}
	printf("\n");	
	printf("---------------------------------------------------------");
	vCount=count;
	printf("\nNumber of explicitly specified vertices is: %d\n",count+1);
	printf("\nTotal Number of vertices: %d\n",numVertices);
	printf("-----------------------------------------------------------");
	//Adding implicit vertices
	    if(count<numVertices-1){
		    bVertexAppend=1;
		    while(count<numVertices-1){        
		        flag=0;
		        sprintf(bvertexName, "%s%d", bVertex,bVertexAppend);
		        while(flag==0){
		            if(getVertexId(vertexHash,bvertexName)==-1){
		                flag=1;
		            }
		            else{
		                bVertexAppend++;
		                sprintf(bvertexName, "%s%d", bVertex,bVertexAppend);                        
		            }
		        }
		        node = (struct vertex*)malloc(sizeof(struct vertex));
		        node->vertexId=(++count);
		        strcpy(node->vertexName,bvertexName);
		        vertices[count]=(char*)malloc(sizeof(vertexName1));
		        strcpy(vertices[count],bvertexName);
		        vertexHashInsert(vertexHash,node);
		    }
	    }
	printVertex(vertexHash);
	printEdge(edgeHash);
	int a=0;

	printf("\n***************Array of vertices********************\n");

	while(a<numVertices)
	{
		
		printf("%s  ",vertices[a]);
		a++;
	}
	fclose(input);
return 1;
}
