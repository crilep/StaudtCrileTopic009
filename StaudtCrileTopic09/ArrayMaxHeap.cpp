
#include "ArrayMaxHeap.h"
#include<iostream>

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap() {
    itemCount = 0;
    items = std::vector<ItemType>();
    maxItems = DEFAULT_CAPACITY;
}

template<class ItemType>
ArrayMaxHeap<ItemType>::ArrayMaxHeap(const std::vector<ItemType> someArray, const int arraySize) {
    items = someArray;
    itemCount = arraySize;
}

template<class ItemType>
ArrayMaxHeap<ItemType>::~ArrayMaxHeap() {
    clear();
}

// Returns the array index of the left child (if it exists).
template<class ItemType>
int ArrayMaxHeap<ItemType>::getLeftChildIndex(const int nodeIndex) const {
    int left = 2 * nodeIndex + 1;
    if (left < items.size())
        return left;
    else
        return -1;
}

// Returns the array index of the right child (if it exists).
template<class ItemType>
int ArrayMaxHeap<ItemType>::getRightChildIndex(const int nodeIndex) const {
    int right = 2 * nodeIndex + 2;
    if (right < items.size())
        return right;
    else
        return -1;
}

// Returns the array index of the parent node.
template<class ItemType>
int ArrayMaxHeap<ItemType>::getParentIndex(const int child) const {

    int parent = (child - 1) / 2;
    if (child == 0)
        return -1;
    else
        return parent;
}

// Tests whether this node is a leaf.
template<class ItemType>
bool ArrayMaxHeap<ItemType>::isLeaf(int nodeIndex) const {
    return (getLeftChildIndex(nodeIndex) == -1 && getRightChildIndex(nodeIndex) == -1);
}


// Converts a semiheap to a heap.
template<class ItemType>
void ArrayMaxHeap<ItemType>::heapRebuild(int nodeIndex) {

    int left = getLeftChildIndex(nodeIndex);
    int right = getRightChildIndex(nodeIndex);
    int largest = nodeIndex;

    // Compare the element at nodeIndex with its left child
    if (left < items.size() && items[left] > items[largest])
        largest = left;

    // Compare the element at nodeIndex with its right child
    if (right < items.size() && items[right] > items[largest])
        largest = right;

    // If the largest element is not the current node, swap them and recursively rebuild
    if (largest != nodeIndex) {
        std::swap(items[nodeIndex], items[largest]);
        heapRebuild(largest);
    }
}

// Creates a heap from an unordered array.
template<class ItemType>
void ArrayMaxHeap<ItemType>::heapCreate() {

    int n = items.size();

    // Starting from the back of the vector, loop until all items are heapified
    for (int i = n / 2 - 1; i >= 0; i--) {

        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // If the left child is bigger than the largest value, set the largest equal to the left child
        if (left < n && items[left] > items[largest])
            largest = left;

        // If the right child is bigger than the largest value, set the largest equal to the right child
        if (right < n && items[right] > items[largest])
            largest = right;

        // If the largest value has been changed, swap and recurse
        if (largest != i) {
            std::swap(items[i], items[largest]);
            heapCreate();
        }
    }

}

// Returns if the heap is empty or not
template<class ItemType>
bool ArrayMaxHeap<ItemType>::isEmpty() const {
    return items.size() == 0;
}

// Returns the number of nodes in the heap
template<class ItemType>
int ArrayMaxHeap<ItemType>::getNumberOfNodes() const {
    return items.size();
}

// Returns the height of the heap
template<class ItemType>
int ArrayMaxHeap<ItemType>::getHeight() const {

    // The heap has no height if its empty
    if (items.empty())
        return 0;
    else {

        int levels = 0;
        int itemsCount = items.size();
        /*
        Since a heap is complete, we can determine the height by dividing by two for each progressing level
        (e.g. 6 nodes would have a height of 3 as 6 / 2 = 3 => 3 / 2 = 1 => 1/2 = 0, giving three levels)
        */
        while (itemsCount > 0) {
            itemsCount = itemsCount / 2;
            levels++;
        }

    }

}

// Returns the max item in the heap
template<class ItemType>
ItemType ArrayMaxHeap<ItemType>::peekTop() const throw(PrecondViolatedExcept) {

    // If the heap is not empty
    if (items.size() != 0)
        return items.at(0);
    else
        throw new PrecondViolatedExcept("The heap is empty");
}

// Adds an item to the heap
template<class ItemType>
bool ArrayMaxHeap<ItemType>::add(const ItemType& newData) {

    // Check if a task was given
    if (newData.task.empty()) {
        std::cout << "\nYou failed to enter a task, no item was added...\n";
        return false;
    }

    // Add the new element at the end of the array
    items.push_back(newData);

    // Get the index of the newly added element
    int i = items.size() - 1;

    // Restore the max heap property
    while (i != 0 && items[getParentIndex(i)] < items[i]) {
        std::swap(items[i], items[getParentIndex(i)]);
        i = getParentIndex(i);
    }
    
    heapRebuild(0);

    return true; // Indicate that the element was successfully added
}

// Removes an item from the heap
template<class ItemType>
bool ArrayMaxHeap<ItemType>::remove() {

    if (items.size() == 0) {
        std::cout << "\nHeap is Empty\n";
        return false;
    }

    // Set the root of the heap to a different value and then reheafify the heap
    items[0] = items.at(items.size() - 1);
    items.pop_back();
    heapRebuild(0);
    std::cout << "\nElement Deleted\n";

    return true;
}

// Clears the heap
template<class ItemType>
void ArrayMaxHeap<ItemType>::clear() {
    items.clear();
}

// Traverses the heap
template<class ItemType>
void ArrayMaxHeap<ItemType>::traverseHeap() {
    
    for (int i = 0; i < items.size(); i++) {
        std::cout << "Task: " << items[i].task << " Priority: " << items[i].priority << "\n";
    }

}

