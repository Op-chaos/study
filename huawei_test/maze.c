// #include<stdio.h>
// struct node{
// 	int x; //x坐标 
// 	int y; //y坐标 
// 	int pre; //来到此点的出发点 
// };
// int book[6][6];  //用来记录点是否访问过
// int map[6][6];   //记录图
// struct node queue[20]; //存储路径的队列
// void print(struct node a) //实现路径输出的函数
// {
// 	if(a.pre==-1)  
// 	{
// 		printf("(%d, %d)\n",a.x,a.y);
// 		return ;
// 	}
// 	else
// 	{
// 		print(queue[a.pre]);
// 		printf("(%d, %d)\n",a.x,a.y);
// 	}
// }
// int main()
// {
// 	int i,j,k,m,n,x,y,hang,lie;
// 	int head,tail;
//     scanf("%d %d",&hang,&lie);

// 	for(i=0;i<hang;i++)
// 	{
// 		for(j=0;j<lie;j++)
// 		{
// 			scanf("%d",&map[i][j]);
// 		}
// 	}
// 	head=0;
// 	tail=0;
// 	queue[tail].x=0;
// 	queue[tail].y=0;
// 	queue[tail].pre=-1;
// 	book[0][0]=1;
// 	tail++;
// 	while(head<tail) //当队列为空时跳出，说明搜索没有找到可行路径
// 	{
// 		int next[4][2]={{0,1},{0,-1},{1,0},{-1,0}}; //定义出四个方向
// 		int flag=0;
// 		for(i=0;i<4;i++)  //从当前点往四周探索
// 		{
// 			int nextx=queue[head].x+next[i][0];
// 			int nexty=queue[head].y+next[i][1]; //实现移动
// 			if(nextx<0||nextx>5||nexty<0||nexty>5) //超出了边界则跳出
// 			{
// 				continue;
// 			}
// 			if(book[nextx][nexty]==0&&map[nextx][nexty]==0) //当点未被访问过且是可行点才入队
// 			{
// 				book[nextx][nexty]=1;
// 				queue[tail].x=nextx;
// 				queue[tail].y=nexty;
// 				queue[tail].pre=head;
// 				tail++;
// 			}
// 			if(nextx==4&&nexty==4) //到达了目的地，毫无疑问地跳出结束循环
// 			{
// 				flag=1;
// 				break;
// 			}
// 		}
// 		if(flag) //到达目的地后调用函数输出路径
// 		{
// 			print(queue[tail-1]);
// 			break;
// 		}
// 		head++; //出队
// 	}
// 	for ( i= 0; i<20;i++){
// 		printf("%d %d %d\n",queue[i].x,queue[i].y,queue[i].pre);
// 	}
// 	return 0;
// }
#include<stdio.h>
struct node{
	int x; //x坐标 
	int y; //y坐标 
	int pre; //来到此点的出发点 
};
int book[6][6];  //用来记录点是否访问过
int map[6][6];   //记录图
struct node queue[20]; //存储路径的队列
void print(struct node a) //实现路径输出的函数
{
	if(a.pre==-1)  
	{
		printf("(%d, %d)\n",a.x,a.y);
		return ;
	}
	else
	{
		print(queue[a.pre]);
		printf("(%d, %d)\n",a.x,a.y);
	}
}
int main()
{
	int i,j,k,m,n,x,y,hang,lie;
	int head,tail;
    scanf("%d %d",&hang,&lie);

	for(i=0;i<hang;i++)
	{
		for(j=0;j<lie;j++)
		{
			scanf("%d",&map[i][j]);
		}
	}
	head=0;
	tail=0;
	queue[tail].x=0;
	queue[tail].y=0;
	queue[tail].pre=-1;
	book[0][0]=1;
	tail++;
	while(head<tail) //当队列为空时跳出，说明搜索没有找到可行路径
	{
		int next[4][2] ={{-1,0},{1,0},{0,-1},{0,1}};
		int flag=0;
		for (i=0;i<4;i++)
		{
			int nextx = queue[head].x + next[i][0];
			int nexty = queue[head].y + next[i][1];
			if(nextx > 5 || nextx<0 || nexty > 5 || nexty<0) {
				continue;
			}
			if (book[nextx][nexty] == 0 && map[nextx][nexty] == 0) {
				book[nextx][nexty] = 1;
				queue[tail].x=nextx;
				queue[tail].y=nexty;
				queue[tail].pre=head;
				tail++;
			}
			if(nextx == 4 && nexty == 4){
				flag =1;
				break;
			}
		}
		if(flag == 1){
			print(queue[tail-1]);
			break;
		}
		head ++;
	}
	// for ( i= 0; i<20;i++){
	// 	printf("%d %d %d\n",queue[i].x,queue[i].y,queue[i].pre);
	// }
	return 0;
}
