#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <semaphore.h>
#include <pthread.h>

#define msleep(x) usleep(x * 1000) // 延时
#define PRODUCT_SPEED 200  // 生产速度
#define COUSUM_SPEED  400  // 消费速度
#define INIT_NUM  3        // 仓库初始库存
#define TOTAL_NUM 10       // 仓库总库存

struct HANDLE
{
	sem_t p_sem; // 生产信号量
	sem_t c_sem; // 消费信号量
	sem_t sh_sem;// 出库入库信号量

	pthread_t p_tid; // 生产者线程
	pthread_t c_tid; // 消费着线程
	
	int num; // 仓库库存
};

/* 生产延时 */
void productDelay(void)
{
	msleep(PRODUCT_SPEED * 10);
}

/* 消费延时延时 */
void consumerDelay(void)
{
	msleep(COUSUM_SPEED * 10);
}

/* 消费出库 */
void sub_to_work(struct HANDLE *handle)
{
	sem_wait(&(handle->sh_sem));
	handle->num--;
	msleep(300);
	sem_post(&(handle->sh_sem));
}

/* 生产入库 */
void add_to_work(struct HANDLE *handle)
{
	sem_wait(&(handle->sh_sem));
	handle->num++;
	msleep(300);
	sem_post(&(handle->sh_sem));
}

/* 生产线程 */
void *product(void *arg)
{
	struct HANDLE *handle = (struct HANDLE *)arg;
	int num = 0;
	while(1)
	{
		sem_wait(&(handle->p_sem));
		productDelay();
		add_to_work(handle);
		printf("生产 num = %d\n", handle->num);
		sem_post(&(handle->c_sem));
	}
	return NULL;
}

/* 消费线程 */
void *consumer(void *arg)
{
	struct HANDLE *handle = (struct HANDLE *)arg;
	int num = 0;
	while(1)
	{
		sem_wait(&(handle->c_sem));
		sub_to_work(handle);
		printf("消费 num = %d\n", handle->num);
		sem_post(&(handle->p_sem));
		consumerDelay();
	}
	return NULL;
}

int main(int argc, char *argv[])
{
	struct HANDLE handle;
	memset(&handle, 0x00, sizeof(struct HANDLE));
	handle.num = INIT_NUM;

	sem_init(&handle.p_sem,  0, TOTAL_NUM - INIT_NUM);
	sem_init(&handle.c_sem,  0, INIT_NUM);
	sem_init(&handle.sh_sem, 0, 1);

	pthread_create(&(handle.p_tid), NULL, product,  (void *)(&handle));
	pthread_create(&(handle.c_tid), NULL, consumer, (void *)(&handle));

	pthread_join(handle.p_tid, NULL);
	pthread_join(handle.c_tid, NULL);
	
	return 0;
}
