#include <stdio.h>
#include <stdlib.h>
typedef struct FifoQueue
{/* FIFO for Turn Angle Add */
    int size; /* Queue size */
    int front; /* Queue head */
    int rear; /* Queue tail */
    int count; /* Queue count */
    int data[5];
}FifoQueue_t;

FifoQueue_t queue;


int QueueInit(FifoQueue_t *Queue, int size);
int QueueIn(FifoQueue_t *Queue, int* in_data);  //数据进入队列
int QueueOut(FifoQueue_t *Queue, int *out_data);


int cycle(int size, int *number)      // 相当于TC
{
    FifoQueue_t *Queue = &queue;
    int data;
    QueueInit( Queue, size);
    QueueIn(Queue,  number);
    QueueOut(Queue,  &data);
    for(int i=0;i<size;i++)
    {
        printf("%d ", queue.data[i]);
    }
    printf("\n ");
}


int main()     // 相当于 TC.c 的调用函数
{
	int number;
    int size=5;
    do{
		scanf("%d",&number);
		if(number !=-1){
			cycle(size, &number);
		}
	} while(number !=-1);
	// print all data in linked-list
	return 0;
}

int QueueInit(FifoQueue_t *Queue, int size)
{
    if (size <= 0) {
        printf("FIFO size error: size = %d", size);
        return -1;
    }

    Queue->front = Queue->rear;/* 初始化时队列头队列首相连 */
    Queue->count = 0;   /* 队列计数初始为0 */
    Queue->size = size;/* 确定队列最大长度 */

    return 0;
}

int QueueIn(FifoQueue_t *Queue, int* in_data) //数据进入队列
{
    if((Queue->front == Queue->rear) && (Queue->count == Queue->size)) {
        /* 判断如果队列满了 */
        return -1;/* 返回队列满的标志 */
    } else {
        /* else 将成员加入队列 */
        Queue->data[Queue->rear] = *in_data;
        Queue->rear = (Queue->rear + 1) % Queue->size;
        Queue->count = Queue->count + 1;
        return 0;
    }
}

int QueueOut(FifoQueue_t *Queue, int *out_data)
{
    if((Queue->front == Queue->rear) && (Queue->count == 0)) {
        /* 判断如果队列为空 */
        return -1;/* 返回对列为空标志 */
    } else {
        /* else 删除队首成员 */
        *out_data = Queue->data[Queue->front];
        Queue->front = (Queue->front + 1) % Queue->size;
        Queue->count = Queue->count - 1;
        return 0;
    }
}
