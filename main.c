#include "main.h"

int main()
                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       {
	struct vertexHashTable* vertexhash = (struct vertexHashTable*)malloc(sizeof(struct vertexHashTable));
	struct edgeHashTable* edgeHash = (struct edgeHashTable*)malloc(sizeof(struct edgeHashTable));
	char *inputFileName;
	int f=0,heapReturn,a;
	int ch = 0;
	int choice;
	int MSTResult;
	int temp = 0;
	int triIneq;

	do
	{
		inputFileName=(char*)malloc(100);
		printf("\nEnter the input file path: ");
		scanf("%s",inputFileName);
		printf("\nChecking for input file: %s",inputFileName);

        temp=TestCase("C:\\Users\\Getene\\Documents\\hamiltonianTour\\Triangle-1.txt");
		if(temp==0)
		{
			printf("\n****Parsing done successfully****\n");
		}
	 	else
		{      
			printf("\n****Parsing done unsuccessfully****\n");  
			do{
			printf("\n*****Do you want to exit ?  Enter 1 to exit.... or Enter 0 to enter new file name..(0/1)\n");
			scanf("%d",&ch);
			}while(ch<0 || ch>1);
			
			//printf("Do you want to exit ? (y/n)\n");
		}
	}while(temp !=0 && (ch == 0));

	if(ch == 1)
	{
        return 0;
	}

    f=parseInputDescription("C:\\Users\\Getene\\Documents\\hamiltonianTour\\Triangle-1.txt",vertexhash,edgeHash);
	if(f==-1){
		printf("\n*****Incorrect input file specification**** \nEXITING \n");
	}
	else{
	struct edge* minEdges;

	do
	{
		printf("\n\n\n--------------MENU-------------");
		printf("\nEnter 1 for HeapSort.\nEnter 2 for MST.\nEnter 3 for Triangle Inequality.\nEnter 4 to exit.\n");
		printf("\nEnter Choice (1-4): ");		
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				if(edgcount != 0)
				{
					heapReturn = heapsort(edges,edgcount);
					a = 0;
					printf("\n----------------Edge hash table sorted by weights------------------- \n");
	
					while(a<edgcount)
					{
						printf("(%d %d) %d  ",edges[a]->vertexId1,edges[a]->vertexId2,edges[a]->weight);
						a++;
					}
				}
				else
				{
					printf("\n*****No type A edges.... Heapsort not required..*****\n");
				}
	
				
				break;

			case 2:
				if(edgcount != 0)
				{
					heapsort(edges,edgcount);
					minEdges=NULL;
					minEdges= (struct edge*)malloc(sizeof(struct edge)*(vCount));
					MSTResult=buildMinSpanningTree(edges,minEdges,edgcount,vCount);
					printf("\nPrinting MST in main");
					int i;
					for(i=0;i<vCount;i++){
						printf("edge no. %d:(%d %d) %d\n",i,minEdges[i].vertexId1,minEdges[i].vertexId2,minEdges[i].weight);
					}
					printf("\nCalling dfs in main");
					dfs(minEdges,vCount);
				}
				else
				{
					printf("\n*****No type A edges.... MST not required..*****\n");
				}
				break;
			case 3:
				printf("\n------------------Checking for Triangle Inequality----------------");
				heapsort(edges,edgcount);	
				triIneq =  checkTriangleInequality(edges,edgeHash);
				if(triIneq == 0)
				printf("\nAll triangles possible satisfy triangle inequality.\n");
				if(triIneq == 1)
				printf("\nTriangle inequality failed.\n");
				break;
			case 4:
                return 0;
			
			default:
				printf("Invalid choice.");
		}
	}while(choice != 4);
	}
		

 }
