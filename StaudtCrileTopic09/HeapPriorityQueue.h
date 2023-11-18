/** ADT priority queue: Heap-based implementation.
 @file HeapPriorityQueue.h */

#pragma once
#include "ArrayMaxHeap.h"
#include "PriorityQueueInterface.h"

template<class ItemType>
class HeapPriorityQueue : public PriorityQueueInterface<ItemType>, private ArrayMaxHeap<ItemType>{
public:
    HeapPriorityQueue();
    bool isEmpty() const;
    bool enqueue(const ItemType newEntry);
    bool dequeue();

    void traverse();

    /** @pre The priority queue is not empty. */
    ItemType peekFront() const throw(PrecondViolatedExcept);
}; // end HeapPriorityQueue
