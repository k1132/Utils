#ifndef C_QUEUE_H
#define C_QUEUE_H
#include "lock_utils.h"

#define null 0 

typedef int status;
typedef void* elem;

typedef struct cqueuenode_s{
	elem data;
	struct cqueuenode_s *next;
}cqueuenode;
typedef struct
{
	cqueuenode *front;
	cqueuenode *rear;
	int size;
	CMtx lock;
}cqueue;

#ifdef __cplusplus
extern "C"{
#endif

void cqueue_init(cqueue *p);
//将释放节点数据内存
void cqueue_clear(cqueue *q);
//将释放节点数据内存
status cqueue_destory(cqueue *q);
status cqueue_is_empty(cqueue *q);
//外部mallco节点结构
status cqueue_enqueue(cqueue *q, elem e);
//需要手动删除节点
elem cqueue_dequeue(cqueue *q);
elem cqueue_gethead(cqueue *q);
int cqueue_size(cqueue *q);


typedef struct
{
	void*	base;
	int		max;			// 数组的元素个数
	int		node_size;		// 每个元素的大小

	int		front;
	int 	tail;
	CMtx 	lock;
}array_queue;

array_queue* array_queue_create(int max, int node_size);
void array_queue_clear(array_queue *q);
void array_queue_destory(array_queue *q);
int array_queue_is_empty(array_queue *q);
int array_queue_is_full(array_queue *q);
int array_queue_push(array_queue *q, void* e);
int array_queue_pop(array_queue *q, void* e);
int array_queue_front(array_queue *q, void* e);
int array_queue_post(array_queue *q);
int array_queue_get(array_queue *q, int i, void* e);
int array_queue_remaid(array_queue *q);

#ifdef __cplusplus
}
#endif

#endif
