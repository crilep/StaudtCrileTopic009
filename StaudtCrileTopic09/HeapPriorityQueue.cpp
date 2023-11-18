/** Heap-based implementation of the ADT priority queue.
 @file HeapPriorityQueue.cpp */

#include "HeapPriorityQueue.h"

template class HeapPriorityQueue<toDo>;

template<class ItemType>
HeapPriorityQueue<ItemType>::HeapPriorityQueue()
{
    ArrayMaxHeap<ItemType>(); // This is commented out because it's implied.
} // end constructor

template<class ItemType>
bool HeapPriorityQueue<ItemType>::isEmpty() const
{
    return ArrayMaxHeap<ItemType>::isEmpty();
} // end isEmpty

template<class ItemType>
bool HeapPriorityQueue<ItemType>::enqueue(const ItemType newEntry)
{
    return ArrayMaxHeap<ItemType>::add(newEntry);
} // end enqueue

template<class ItemType>
bool HeapPriorityQueue<ItemType>::dequeue()
{
    return ArrayMaxHeap<ItemType>::remove();
} // end dequeue

template<class ItemType>
ItemType HeapPriorityQueue<ItemType>::peekFront() const throw(PrecondViolatedExcept)
{
    try
    {
        return ArrayMaxHeap<ItemType>::peekTop();
    }
    catch (PrecondViolatedExcept e)
    {
        throw PrecondViolatedExcept("Attempted peek into an empty priority queue.");
    }
} // end peekFront

template<class ItemType>
void HeapPriorityQueue<ItemType>::traverse() {

    ArrayMaxHeap<ItemType>::traverseHeap();


}