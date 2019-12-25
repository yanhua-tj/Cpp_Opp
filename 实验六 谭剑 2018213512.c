#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***图的邻接矩阵存储结构***/
#define Max_Vertex_Num 128

typedef struct MGraph
{/*邻接矩阵*/
    char vexs[Max_Vertex_Num][5];          /*顶点向量*/
    int arcs[Max_Vertex_Num][Max_Vertex_Num];      /*邻接矩阵*/
    int vexnum,arcnum;              /*顶点数和边数*/
}MGraph;

int LocateVex(MGraph G,char u[]);/*返回顶点u在图中的位置(下标),如不存在则返回-1*/
void CreateAOVMGraph(MGraph *G);/*AOV网采用邻接矩阵表示法构造有向图G*/
void printMGraph(MGraph G);/*输出邻接矩阵*/
void TopologicalSort(MGraph G);/*对邻接矩阵存储的AOV网进行拓扑排序*/
void FindInDegree(MGraph G,int indegree[]);/*求顶点入度*/
void CreateAOEMGraph(MGraph *G);/*AOE网采用邻接矩阵表示法构造有向图G*/
void CriticalPath(MGraph G);/*求AOE网关键路径,关键路径长度*/

int LocateVex(MGraph G,char u[])
{/*返回顶点u在图中的位置(下标),如不存在则返回-1*/
    int i;
    for(i=0;i < G.vexnum;i++)
        if(strcmp(G.vexs[i],u)==0)
            return i;
    return -1;
}/*LocateVex*/

void CreateAOVMGraph(MGraph *G)
{/*采用邻接矩阵表示法构造有向图G*/
    int i,j,k;
    char v1[5],v2[5];     /*表示顶点*/
    printf("\n/******采用邻接矩阵表示法构造有向图******/\n");
    printf("请输入AOV网顶点数和边数:\n例如:11,16\n");
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));   /*输入顶点数和边数*/
    getchar();
    printf("请输入AOV网顶点信息:\n例如:C1 C2 C3 C4 C5\n");
    for(i=0;i<G->vexnum;i++)
		scanf("%s",G->vexs[i]);      /*输入顶点信息,构造顶点向量*/

    for(i=0;i<G->vexnum;i++)
        for(j=0;j<G->vexnum;j++)
            G->arcs[i][j]=0;            /*初始化邻接矩阵*/
    printf("请输入有向边对应的两个顶点:\n");
    printf("例如:A B\n");
    for(k=0;k<G->arcnum;k++)
    {
        scanf("%s%s",&v1,&v2);   /*输入arcnum条边建立邻接矩阵*/
        getchar();
        i=LocateVex(*G,v1);
        j=LocateVex(*G,v2);
        /*查找顶点V1,V2在图中的下标*/
        if((i==-1)||(j==-1))
        {
            printf("该对顶点不存在,请重新输入\n");
            k--;
        }
        else
        {
            printf("%s——%s边添加成功\n",v1,v2);
            G->arcs[i][j]=1;
        }
    }/*for*/
}/*CreateAOVMGraph*/

void printMGraph(MGraph G)
{/*输出邻接矩阵*/
    int i,j;
    for(i=0;i<G.vexnum;i++)
        printf("%s:%d  ",G.vexs[i],i);
    printf("\nAOV网有向图邻接矩阵如下:\n");
    printf("%5c",32);
    for(i=0;i<G.vexnum;i++)
        printf("%5s",G.vexs[i]);
    printf("\n\n");
    for(i=0;i<G.vexnum;i++)
    {
        printf("%5s",G.vexs[i]);
        for(j=0;j<G.vexnum;j++)
            printf("%5d",G.arcs[i][j]);
        printf("\n\n");
    }
}

void TopologicalSort(MGraph G)
{/*对邻接矩阵存储的AOV网进行拓扑排序*/
	int i,j,count,indegree[Max_Vertex_Num];
	int top;	/*栈顶指针*/
	char pint[Max_Vertex_Num][5];
	FindInDegree(G,&indegree);/*对各顶点求入度*/
	top = 0;/*初始化栈*/
	for(i=0;i<G.vexnum;i++)/*建0入度顶点栈*/
		if(indegree[i]==0)
		{
			indegree[i]=top;	/*将indegree中入度为0的单元作为链栈，用于存放顶点序号*/
			top = i+1;	/*修改栈顶指针*/

		}
	count = 0;	/*初始化计数器*/
	while(top!=0)	/*栈不空*/
	{
		i=top-1;	/*栈顶指针赋给i*/
		top = indegree[i];	/*取一入度为0的顶点i*/
		/*printf("%s,",G.vexs[i]);*/	/*输出i号顶点并计数*/
		strcpy(pint[count],G.vexs[i]);
		count++;
		for(j=0;j<G.vexnum;j++)
			if(G.arcs[i][j]==1)
			{
				indegree[j]--;
				if(indegree[j]==0)
				{
					indegree[j]=top;
					top=j+1;
				}
			}
	}
	if(count<G.vexnum)
		printf("此无向图有回路\n");
	else
    {
        printf("输出拓扑序列:\n");
        for(i=0;i<G.vexnum-1;i++)
            printf("%s,",pint[i]);
        printf("%s\n\n",pint[i]);
        printf("输出拓扑逆序列:\n");
        for(i=G.vexnum-1;i>0;i--)
            printf("%s,",pint[i]);
        printf("%s\n",pint[i]);
    }
}

void FindInDegree(MGraph G,int indegree[])
{/*求顶点入度*/
	int i,j;
	for(i=0;i<G.vexnum;i++)
		indegree[i]=0;
	for(i=0;i<G.vexnum;i++)
	{
		for(j=0;j<G.vexnum;j++)
		{
			if(G.arcs[i][j])
				indegree[j]++;
		}
	}
}

void CreateAOEMGraph(MGraph *G)
{/*采用邻接矩阵表示法构造有向图G*/
    int i,j,k,w;
    char v1[5],v2[5];     /*表示顶点*/
    printf("\n/******采用邻接矩阵表示法构造有向图******/\n");
    printf("请输入AOE网顶点数和边数:\n例如:9,12\n");
    scanf("%d,%d",&(G->vexnum),&(G->arcnum));   /*输入顶点数和边数*/
    getchar();
    printf("请输入AOE网顶点信息:\n例如:v1 v2 v3 v4 v5\n");
    for(i=0;i<G->vexnum;i++)
		scanf("%s",G->vexs[i]);      /*输入顶点信息,构造顶点向量*/

    for(i=0;i<G->vexnum;i++)
        for(j=0;j<G->vexnum;j++)
            G->arcs[i][j]=0;            /*初始化邻接矩阵*/
    printf("请输入有向边对应的两个顶点和权值:\n");
    printf("例如:v1 v2 6\n");
    for(k=0;k<G->arcnum;k++)
    {
        scanf("%s%s%d",&v1,&v2,&w);   /*输入arcnum条边建立邻接矩阵*/
        getchar();
        i=LocateVex(*G,v1);
        j=LocateVex(*G,v2);
        /*查找顶点V1,V2在图中的下标*/
        if((i==-1)||(j==-1))
        {
            printf("该对顶点不存在,请重新输入\n");
            k--;
        }
        else
        {
            printf("%s——%s边添加成功\n",v1,v2);
            G->arcs[i][j]=w;
        }
    }/*for*/
}/*CreateAOEMGraph*/

void CriticalPath(MGraph G)	/*G为邻接矩阵存储的AOE网*/
{/*求关键路径,关键路径长度*/
	int i,j,k,v,dut,indegree[Max_Vertex_Num];
	int top1=0,top2=0;	/*栈顶指针初始化*/
	int ve[Max_Vertex_Num],vl[Max_Vertex_Num];/*用于存放顶点的最早发生时间和最迟发生时间*/
	int ee,el,ans=0;
	FindInDegree(G,&indegree);	/*求各顶点入度*/
	for(i=0; i<G.vexnum; i++)
		ve[i]=0;	/*最早发生时间数组赋初值*/
	for(i=0; i<G.vexnum; i++)
		if(indegree[i]==0)
		{
			indegree[i]=top1;	/*入度为0的顶点入栈*/
			top1=i+1;
		}
	while(top1!=0)/*按拓扑排序次序计算ve*/
	{
		v = top1-1;
		top1 = indegree[v];	/*取栈顶元素*/
		indegree[v]=top2;	/*同时栈顶元素反向入栈,以便得到拓扑逆序*/
		top2=v+1;
		for(i=0;i<G.vexnum;i++)
		{
			if(G.arcs[v][i])
			{
				dut=G.arcs[v][i];
				if(ve[v]+dut > ve[i])
					ve[i]=ve[v]+dut;	/*计算ve[i]*/
				indegree[i]--;
				if(indegree[i]==0)/*邻接点入度减1,为0入栈*/
				{
					indegree[i]=top1;
					top1=i+1;
				}
			}/*if*/
		}/*for*/
	}/*while*/
	for(i=0;i<G.vexnum;i++)
		vl[i]=ve[top2-1];	/*最迟发生时间初始化*/
	while(top2!=0)/*按拓扑逆序计算vl的值*/
	{
		v=indegree[top2-1];	/*取栈顶元素*/
		top2 = v;	/*top2指向新的栈顶*/
		for(i=0;i<G.vexnum;i++)
		{
			if(G.arcs[v][i])
			{
				dut=G.arcs[v][i];
				if(vl[i]-dut < vl[v])
					vl[v]=vl[i]-dut;	/*计算vl[v]*/
			}/*if*/
		}/*for*/
	}/*while*/
	printf("该AOE网的关键路径:\n");
	for(i=0; i<G.vexnum; i++)/*ee,el和关键活动*/
	{
		for(j=0; j<G.vexnum; j++)
		{
			if(G.arcs[i][j])
			{
				dut=G.arcs[i][j];
				ee=ve[i];	/*ee等于vi的最早发生时间*/
				el=vl[j]-dut;	/*el等于vk的最迟时间减去弧<vi,vk>和权值*/
				if(ee == el)
                {
                    printf("边%s to %s:权值为:%d\n",G.vexs[i],G.vexs[j],dut);
                    ans+=dut;
                }
			}
		}/*for*/
	}/*for*/
	printf("关键路径长度:%d\n",ans);
}

int main()
{
    char flag='3';
    MGraph MG;
    while(1)
    {
        printf("1.AOV网邻接矩阵拓扑排序\n");
        printf("2.AOE网邻接矩阵关键路径\n");
        printf("3.退出程序\n");
        scanf("%c",&flag);
        getchar();
        if(flag == '3')
            break;
        switch(flag)
        {
            case '1': CreateAOVMGraph(&MG);
                      printMGraph(MG);
                      TopologicalSort(MG);
                      printf("按Enter键继续");
                      getchar();
                      system("cls");
                      break;
            case '2':   CreateAOEMGraph(&MG);
                        printMGraph(MG);
                        CriticalPath(MG);
                        printf("按Enter键继续");
                        getchar();
                        system("cls");
                        break;
            default: printf("输入命令无效,请重新输入\n");
                     printf("按Enter键继续");
                     getchar();
                     system("cls");
                     break;
        }
    }
    return 0;
}
