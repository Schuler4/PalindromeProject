//***********************************************************************
//
//   Used to list variables and function prototypes for queueAsArray.h
//   Used for implementation for queueAsArray.h
//
//   **Normally you would seperate prototypes from implementaion, but I 
//     was getting errors I was unable to resolve**
//
//***********************************************************************

#ifndef H_QueueAsArray
#define H_QueueAsArray


#include <cassert>
#include "queueADT.h"
#include <iostream>
using namespace std;


template <class Type>
class queueType : public queueADT<Type> //inherits from queueADT
{
public:

	//Overrding function from queueADT.h to determine whether the queue is empty.
	bool isEmptyQueue() const;

	//Overriding Function from queueADT.h to determine whether the queue is full.
	bool isFullQueue() const;
	
	//Overriding Function from queueADT.h to initialize the queue to an empty state.
	void initializeQueue();
	
	//Overriding Function from queue.h to return the first element of the queue.
	Type front() const;
	 
	//Overriding Function from queue.h to return the last element of the queue.
	Type back() const;
	
	//Overriding Function from queue.h to add queueElement to the queue.
	void addQueue(const Type& queueElement);
	
	//Overriding Function from queue.h to remove the first element of the queue.
	void deleteQueue();
	
	//Constructor
	queueType(int queueSize = 100);

	//Destructor
	~queueType();


private:
	int maxQueueSize; //variable to store the maximum queue size
	int count;        //variable to store the number of elements in the queue
	int queueFront;   //variable to point to the first element of the queue
	int queueRear;    //variable to point to the last element of the queue
	Type *list;       //pointer to the array that holds the queue elements 
};



//returns true if queue is empty
template <class Type>
bool queueType<Type>::isEmptyQueue() const
{
	return (count == 0);
} 


//returns true if queue is full
template <class Type>
bool queueType<Type>::isFullQueue() const
{
	return (count == maxQueueSize);
} 



//Initalizes the queue
template <class Type>
void queueType<Type>::initializeQueue()
{
	queueFront = 0;
	queueRear = maxQueueSize - 1;
	count = 0;
} 


//returns the front of the queue
//If there is nothing in the queue, it stops the program
template <class Type>
Type queueType<Type>::front() const
{
	assert(!isEmptyQueue());
	return list[queueFront];
} 



//returns the back of the queue
//If there is nothing in the queue, it stops the program
template <class Type>
Type queueType<Type>::back() const
{
	assert(!isEmptyQueue());
	return list[queueRear];
} 



//Adds new element to the queue
template <class Type>
void queueType<Type>::addQueue(const Type& newElement)
{
	
	//tests to make sure queue is not full
	if (!isFullQueue())
	{
		queueRear = (queueRear + 1) % maxQueueSize; //use mod operator to advance queueRear
													//because the array is circular
													
		count++;
		list[queueRear] = newElement;
	}
	else
		cout << "Cannot add to a full queue." << endl;
} 


//Adds new element to the queue
template <class Type>
void queueType<Type>::deleteQueue()
{
	
	//tests to make sure queue is not empty
	if (!isEmptyQueue())
	{
		count--;
		queueFront = (queueFront + 1) % maxQueueSize; //use the
													  //mod operator to advance queueFront 
													  //because the array is circular 
	}
	else
		cout << "Cannot remove from an empty queue" << endl;
} 



//Constructor
template <class Type>
queueType<Type>::queueType(int queueSize)
{
	
	//makes sure queue size is positive
	if (queueSize <= 0)
	{
		cout << "Size of the array to hold the queue must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;

		maxQueueSize = 100;
	}
	else
		maxQueueSize = queueSize;   //sets the max size of the queue

	queueFront = 0;                 //initialize front to queue
	queueRear = maxQueueSize - 1;   //initialize back of queue
	count = 0;
	list = new Type[maxQueueSize];  //create the array to hold the queue elements
} 

//Destructor
//Deletes the queue
template <class Type>
queueType<Type>::~queueType()
{
	delete[] list;
} 


#endif