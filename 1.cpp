#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define NAME 100   //名称长度
#define NUM 100   //景点个数
#define LEIJIA 5050   //景点累加数

struct info    //景点信息
{
	char name[NAME];    //景点名称
	int num[NUM];    //相连的景点序号
	int total;    //相连的景点总数
	int luning[LEIJIA];    //包含的路径序号
}jingdian[NUM];

float length[NUM][NUM];    //两景点间的路程

struct jiedian    //节点信息
{
	int ceng;    //层次
	int include[NUM];    //包含节点
	int nexttotal;    //下方节点总数
	int next[NUM];    //下方节点序号
	int jingdian;    //代表景点序号
	float lujing;    //节点路径长度
}jiedian[LEIJIA];

int jiediantotal;    //节点总数

int mojiediantotal;    //末节点总数(终点)
int mojiedian[LEIJIA];    //末节点序号

int a,b;    //起点、终点
int zzzz;

void buildnextjiedian(int aaa)    //新建下方节点(本节点)
{
int aa,bb,cc=0;
jiedian[aaa].nexttotal=0;
for(aa=0;aa<jingdian[jiedian[aaa].jingdian].total;aa++)
{
cc=0;
	for(bb=0;bb<jiedian[aaa].ceng-1;bb++)
	{
		if (jingdian[jiedian[aaa].jingdian].num[aa]==jiedian[jiedian[aaa].include[bb]].jingdian) cc=1;
	}
	if (cc==0)
	{
		jiedian[jiediantotal]=jiedian[aaa];

		jiedian[jiediantotal].include[jiedian[jiediantotal].ceng]=jiediantotal;
		jiedian[jiediantotal].ceng++;
		jiedian[jiediantotal].jingdian =jingdian[jiedian[aaa].jingdian].num[aa];

		jiedian[aaa].next[jiedian[aaa].nexttotal]=jiediantotal;
		jiedian[aaa].nexttotal++;

		jiediantotal++;
	}
}


}

void disposejiedian(int benjiedian)    //处理节点(本节点序号)
{int aaa;

if (jiedian[benjiedian].jingdian==b)
{

mojiedian[mojiediantotal]=benjiedian;
mojiediantotal++;
	goto loop;
}
else
{

aaa=benjiedian;
buildnextjiedian(aaa);
}

if (jiedian[benjiedian].nexttotal==0) 
{

	goto loop;
}

int dd;

for (dd=0;dd<jiedian[benjiedian].nexttotal;dd++)
{aaa=benjiedian;
disposejiedian(jiedian[aaa].next[dd]);
}

loop:zzzz=1;
}








void main()
{

length[1][2]=40;length[2][1]=40;
length[1][3]=7;length[3][1]=7;
length[2][9]=4;length[9][2]=4;
length[3][4]=8;length[4][3]=8;
length[3][5]=6;length[5][3]=6;
length[4][5]=7;length[5][4]=7;
length[5][6]=5;length[6][5]=5;
length[5][7]=20;length[7][5]=20;
length[6][7]=1;length[7][6]=1;
length[7][8]=4;length[8][7]=4;
length[7][9]=10;length[9][7]=10;
length[8][10]=5;length[10][8]=5;
length[9][10]=2;length[10][9]=2;

jingdian[1].total =2;
jingdian[1].num[0]=2; 
jingdian[1].num[1]=3; 
jingdian[2].total =2;
jingdian[2].num[0]=1; 
jingdian[2].num[1]=9;
jingdian[3].total =3;
jingdian[3].num[0]=1; 
jingdian[3].num[1]=4;
jingdian[3].num[2]=5;
jingdian[4].total =2;
jingdian[4].num[0]=3; 
jingdian[4].num[1]=5;
jingdian[5].total =4;
jingdian[5].num[0]=3; 
jingdian[5].num[1]=4;
jingdian[5].num[2]=6;
jingdian[5].num[3]=7;
jingdian[6].total =2;
jingdian[6].num[0]=5; 
jingdian[6].num[1]=7;
jingdian[7].total =4;
jingdian[7].num[0]=5; 
jingdian[7].num[1]=6;
jingdian[7].num[2]=8;
jingdian[7].num[3]=9;
jingdian[8].total =2;
jingdian[8].num[0]=7; 
jingdian[8].num[1]=10;
jingdian[9].total =3;
jingdian[9].num[0]=2; 
jingdian[9].num[1]=7;
jingdian[9].num[2]=10;
jingdian[10].total =2;
jingdian[10].num[0]=8; 
jingdian[10].num[1]=9;







	printf("请输入起点序号：");
	scanf("%d",&a);
	printf("请输入终点序号：");
	scanf("%d",&b);

mojiediantotal=0;
jiediantotal=0;

jiedian[0].ceng =1;
jiedian[0].include[0]=0;
jiedian[0].jingdian =a;
jiediantotal++;

jiedian[0].lujing=0;

disposejiedian(0);



int ee,ff;
for (ee=0;ee<mojiediantotal;ee++)
{
jiedian[mojiedian[ee]].lujing=0;
for (ff=0;ff<jiedian[mojiedian[ee]].ceng-1;ff++)
{
jiedian[mojiedian[ee]].lujing+=length[jiedian[jiedian[mojiedian[ee]].include[ff]].jingdian][jiedian[jiedian[mojiedian[ee]].include[ff+1]].jingdian];
}
}

int bbb=0;
float ccc=jiedian[mojiedian[0]].lujing;
for (ee=0;ee<mojiediantotal;ee++)
{
if (jiedian[mojiedian[ee]].lujing<ccc)
{
bbb=ee;
ccc=jiedian[mojiedian[ee]].lujing;
}
}

printf("\n路径为：");
for (ff=0;ff<jiedian[mojiedian[bbb]].ceng-1;ff++)
{
printf("\n%d    %d",jiedian[jiedian[mojiedian[bbb]].include[ff]].jingdian,jiedian[jiedian[mojiedian[bbb]].include[ff+1]].jingdian);
}

printf("\n路径最短为：%f\n",ccc);

}







