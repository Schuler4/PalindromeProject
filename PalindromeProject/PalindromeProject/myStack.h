//***********************************************************************
//
//   Used to list variables and function prototypes for myStack.h
//   Used for implementation for myStack class
//
//   **Normally you would seperate prototypes from implementaion, but I 
//     was getting errors I was unable to resolve**
//
//**********************************************************************

#ifndef H_StackType
#define H_StackType


#include <cassert>
#include "stackADT.h"
#include <iostream>
using namespace std;



template <class Type>
class stackType : public stackADT<Type>   //inherits from StackADT.h
{
public:
	
	//Overridden Function from StackADT.h to initialize the stack to an empty state.
	void initializeStack();
	
	
	//Overridden Function from StackADT.h to determine whether the stack is empty.
	bool isEmptyStack() const;
	
	
	//Overridden Function from StackADT.h to determine whether the stack is full.
	bool isFullStack() const;
	

	//Overridden Function from StackADT.h to add newItem to the stack.
	void push(const Type& newItem);
	
	
	//Overridden Function from StackADT.h to return the top element of the stack.
	Type top() const;
	

	//Overridden Function from StackADT.h to remove the top element of the stack.
	void pop();
	

	//Constructor
	//Creates an array of the size stackSize is to hold
	stackType(int stackSize = 100);
	 
	
	//Destructor- Removes elements from stack
	~stackType();
	
	

private:
	int maxStackSize; //variable to store the maximum stack size
	int stackTop;     //variable to point to the top of the stack
	Type *list; //pointer to the array that holds the stack elements


	
	
};


//Initalizes StackTop;
template <class Type>
void stackType<Type>::initializeStack()
{
	stackTop = 0;
}


//Determines if Stack is empty
template <class Type>
bool stackType<Type>::isEmptyStack() const
{
	return(stackTop == 0);
}



//Determines if stack is full
template <class Type>
bool stackType<Type>::isFullStack() const
{
	return(stackTop == maxStackSize);
} 



//Pushes a new item onto the stack
//First checks to see if it is full or not
template <class Type>
void stackType<Type>::push(const Type& newItem)
{
	if (!isFullStack())
	{
		list[stackTop] = newItem;   
									
		stackTop++; 
	}
	else
		cout << "Cannot add to a full stack." << endl;
}



// Returns top of the stack
// If there is nothing on the stack the program stops
template <class Type>
Type stackType<Type>::top() const
{
	assert(stackTop != 0);          
									
	return list[stackTop - 1];      
									
}


//Takes an element off the stack
//First checks to see if stack is empty
template <class Type>
void stackType<Type>::pop()
{
	if (!isEmptyStack())
		stackTop--;                  
	else
		cout << "Cannot remove from an empty stack." << endl;
}


//Constructor
//Lets user enter the Stack size they would like
//If they enter a negative number it is automatically initialized to 100
//set stackTop to 0
//create the array to hold the stack elements
template <class Type>
stackType<Type>::stackType(int stackSize)
{
	if (stackSize <= 0)
	{
		cout << "Size of the array to hold the stack must "
			<< "be positive." << endl;
		cout << "Creating an array of size 100." << endl;

		maxStackSize = 100;
	}
	else
		maxStackSize = stackSize;   

	stackTop = 0;                   
	list = new Type[maxStackSize]; 
}


//destructor
//deallocates the memory occupied by the array
template <class Type>
stackType<Type>::~stackType() 
{
	delete[] list; 
}


#endif
