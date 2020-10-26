#include "linkedList.h"
using namespace std;

template<class T>
class LinkedStack{
	protected:
		LinkedList<T> list;
	public:
		LinkedStack(){
		}

	void push(const T& element){
		list.insertFirst(element);
	}

	T pop(){
		T poppedItem = list.front();
		list.deleteNode(list.front());
		return poppedItem;
	}
	
	T peak(){
		T peakedItem = list.front();
		return peakedItem;
	}
	
	T bottom(){
		T bottomItem = list.back();
		return bottomItem;
	}

	void print(){
		list.print();
	}
};
