//***********************************************************************
//
//   Driver class used to test program
//
//***********************************************************************

#include <iostream>
#include <string>
#include "queueAsArray.h"
#include "myStack.h"

using namespace std;

int main()
{
	queueType<char> queue;
	stackType<char> stack;

	string text;//Used to enter a sentence
	char letter;//Used to hold a letter
	bool result = true;//sets result to true
	int quit;//Used to quit program (Really used to keep screen up)


	cout << "Enter a sentence=>";
	getline(cin, text);//reads whole line

	cout << "\nTesting: " << text << endl;

	//Adds letters to queue and stack
	for (int i = 0; i < text.length(); i++)
	{
		letter = text[i];
		if (letter != ' ')
		{
			queue.addQueue(toupper(letter));  //Letters are added to queue, learn about toUpper
			stack.push(toupper(letter));   //Letters are pushed onto stack
		}

	}

	cout << "\nTestsing some functions of the Stack" << endl;
	cout << "------------------------------------"<< endl;
	cout << "Is the stack empty?";
	if (stack.isEmptyStack())
		cout << " Yes" << endl;
	else
		cout << " No" << endl;
	
	cout << "Top of the Stack: " << stack.top() << endl << endl;

	
	
	cout << "\nTesting some unctions of the Queue" << endl;
	cout << "----------------------------------" << endl;
	cout << "Is the queue empty? ";
	if (queue.isEmptyQueue())
		cout << " Yes" << endl;
	else
		cout << " No" << endl;
	cout << "Front of the queue: " << queue.front() << endl;
	cout << "Back of queue: " << queue.back() << endl << endl;
	cout << "And for the grand finale....." << endl;
	
	//While loop, while the queue is not empty
	while (!queue.isEmptyQueue())  
	{


		//if the first letter in the queue (first letter of word) doesn't equal
		//top letter in stack (end of word) make result false and its not a palindrome
		if (queue.front() != stack.top())  
		{
			result = false;
			break;
		}
		
		//else remove letters from queue and stack to compare next letters
		else
		{
			queue.deleteQueue();
			stack.pop();
		}
	}




	//When finished, if result is still true, its a palindrome, 
	//if false, not palindrome
	if (result == true)
		cout << "\nIt's a palindrome!" << endl;

	else
		cout << "\nIt's not a palindorme" << endl;

	
	
	
	cin.get();//keeps screen up
	
	
	return 0;
}

