#include "linkedList.h"
using namespace std;

//this linked stack is using the linkedlist class discussed from the udemy videos as its backbone 
template<class T>
class LinkedStack{
	protected:
		LinkedList<T> list;
	public:
		LinkedStack(){
		}

	//adds element to the top of the stack
	void push(const T& element){
		list.insertFirst(element);
	}
	
	//returns and deletes the top element of the stack
	T pop(){
		T poppedItem = list.front();
		list.deleteNode(list.front());
		return poppedItem;
	}
	
	//returns the top element of the stack (but doesnt remove it)
	T peak(){
		T peakedItem = list.front();
		return peakedItem;
	}
	
	//returns the bottom element of the stack (the first one pushed on)
	T bottom(){
		T bottomItem = list.back();
		return bottomItem;
	}
	
	//prints out the elements of the stack
	void print(){
		list.print();
	}
};
