#ifndef MEMPOOL_H
#define MEMPOOL_H

#include <stddef.h>

//struct mempool;
typedef struct _mempool *mempool;
typedef struct _mempool{
	unsigned int used, size;
	void* (*malloc)(size_t);
	void (*free)(void*);
	struct _mempool *next;
}*mempool;

LIQ_PRIVATE void* mempool_create(mempool *mptr, unsigned int size, unsigned int capacity, void* (*malloc)(size_t), void (*free)(void*));
LIQ_PRIVATE void* mempool_alloc(mempool *mptr, unsigned int size, unsigned int capacity);
LIQ_PRIVATE void mempool_destroy(mempool m);

#endif
