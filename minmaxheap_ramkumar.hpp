/*
Author: Samyukta Ramkumar

Date: 03/18/2024

Description: This is the header file for implementing a min and max heap. The heap has 2 major functions - Adding elements, and removing the
highest priority element from the heap. Both the heaps have been implemented using a template.
*/

#ifndef MINMAXHEAP_RAMKUMAR_HPP_
#define MINMAXHEAP_RAMKUMAR_HPP_

#include <stdexcept>

//Code for Minheap starting with declaring the required template.
template <typename T>
class MinHeap {
private:
    T *array;
    int capacity;
    int size;

    //Swap two variables in the heap using a temp variable.
    void swap(int a, int b) {
        T temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }

    //This method maintains the heap's properties. This method ensures that the value of a node is less than or equal to its children. Thus,
    //satisfying the properties of the min heap.
    void MinHeapify(int index) {
        int smallest = index;
        //The left child's index with respect to the parent index
        int left = 2 * index + 1;
        //The right child's index with respect to the parent index
        int right = 2 * index + 2;

        //If the value of the left child is smaller than the smallest item in the array, then the new smallest node is the left child
        if (left < size && array[left] < array[smallest]) {
            smallest = left;
        }

        //If the value of the right child is smaller than the smallest item in the array, then the new smallest node is the right child
        if (right < size && array[right] < array[smallest]) {
            smallest = right;
        }

        //If the smallest item in the array is not equal to the value of the current index, the smallest element is swapped with the current item.
        if (smallest != index) {
            swap(index, smallest);
            MinHeapify(smallest);
        }
    }

public:
    //Default contructor
    MinHeap(int capacity) : capacity(capacity), size(0) {
        array = new T[capacity];
    }

    //MinHeap() : MinHeap(10) {}

    //Destructor
    ~MinHeap() {
        delete[] array;
    }

    //The enqueue method adds items to the queue
    void enqueue(const T& item) {
    	//If the size of the heap is equal to or greater than its capacity, the programs gives an output indicating that the heap is full
        if (size >= capacity) {
            throw std::runtime_error("Heap is full");
        }

        int current = size++;
        //The new item is placed at the next available position in the heap
        array[current] = item;
        //This loop ensures that the parent node's value is larger than the value of the newly inserteditem
        while (current != 0 && array[(current - 1) / 2] > array[current]) {
        	//If the parent node is greater, the items are swapped
            swap((current - 1) / 2, current);
            current = (current - 1) / 2;
        }
    }

    //The dequeue method removes the smallest value from the MinHeap
    void dequeue() {
        if (size == 0) {
            throw std::runtime_error("Heap is empty");
        }
        array[0] = array[--size];
        MinHeapify(0);
    }

    T peek() { //Returns the smallest value in the heap
        if (size == 0) {
            throw std::runtime_error("Heap is empty");
        }
        return array[0];
    }

    int getSize() { //Returns the size of the MinHeap(number of items)
        return size;
    }

    int getCapacity() { //Returns the capacity of the MinHeap
        return capacity;
    }

    bool isEmpty() { //Checks if the queue is empty
        return size == 0;
    }
};

template <typename T>
class MaxHeap {
private:
    T *array;
    int capacity;
    int size;

    void swap(int a, int b) {
        T temp = array[a];
        array[a] = array[b];
        array[b] = temp;
    }

    void MaxHeapify(int index) {
        int largest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && array[left] > array[largest]) {
            largest = left;
        }
        if (right < size && array[right] > array[largest]) {
            largest = right;
        }
        if (largest != index) {
            swap(index, largest);
            MaxHeapify(largest);
        }
    }

public:
    MaxHeap(int capacity) : capacity(capacity), size(0) {
        array = new T[capacity];
    }

    ~MaxHeap() {
        delete[] array;
    }

    void enqueue(const T& item) {
        if (size >= capacity) {
            throw std::runtime_error("Heap is full");
        }
        int current = size++;
        array[current] = item;
        while (current != 0 && array[(current - 1) / 2] < array[current]) {
            swap((current - 1) / 2, current);
            current = (current - 1) / 2;
        }
    }

    void dequeue() {
        if (size == 0) {
            throw std::runtime_error("Heap is empty");
        }
        array[0] = array[--size];
        MaxHeapify(0);
    }

    T peek() {
        if (size == 0) {
            throw std::runtime_error("Heap is empty");
        }
        return array[0];
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }

    bool isEmpty() {
        return size == 0;
    }
};

#endif /* MINMAXHEAP_RAMKUMAR_HPP_ */
