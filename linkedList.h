#include <iostream>
#include <string>
#include <cassert>
#include "node.h"
using namespace std;

template<class T>
class LinkedList{
	protected:
		int count;
		node<T>* first;
		node<T>* last;
	public:
		LinkedList(){
			first = last = nullptr;
			count = 0;
		}
	
	void print(){
		node<T>* current;
		current = first;

		while(current != nullptr){
			cout << current->data << endl;
			current = current->link;
		}
	}
	
	int length(){
		return count;
	}
	
	T front(){
		assert(first != nullptr);
		return first->data;
	}
	
	T back(){
		asster(last != nullptr);
		return last->data;
	}

	void destroyList(){
		node<T>* temp;

		while(first != nullptr){
			temp = first;
			first = first->link;
			delete temp;
		}

		last = nullptr;
		count = 0;
	}

	void initializeList(){
		destroyList();
	}

	bool isEmpty() const{
		return (first == nullptr);
	}

	void copyList(const LinkedList<T>& otherlst){
		node<T>* newNode;
		node<T>* current;

		if(first != nullptr){
			destroyList();
		}

		if(otherlst.first == nullptr){
			first = last = nullptr;
			count = 0;
		}
		else{
			current = otherlst.first;
			count = otherlst.count;

			first = new node<T>;
			first->data = current->data;
			first->link = nullptr;

			last = first;

			current = current->link;

			while(current != nullptr){
				newNode = new node<T>;
				newNode->data = current->data;
				newNode->link = nullptr;

				last->link = newNode;
				last = newNode;

				current = current->link;
			}
		}
	}

	~LinkedList(){
		destroyList();
	}

	LinkedList(const LinkedList<T>& otherlst){
		first = nullptr;
		copyList(otherlst);
	}

	const LinkedList<T>& operator=(const LinkedList<T>& otherlst){
		if(this != &otherlst){
			copyList(otherlst);
		}

		return *this;
	}

	bool search(const T& searchItem) const{
		node<T>* current;
		bool found = false;

		current = first;
		while(current != nullptr){
			if(current->data == searchItem){
				return true;
			}

			current = current->link;
		}

		return false;
	}

	void insertFirst(const T& newItem){
		node<T>* newNode;
		newNode = new node<T>;
		newNode->data = newItem;

		newNode->link = first;
		first = newNode;
		count++;

		if(last == nullptr){
			last = newNode;
		}
	}

	void insertLast(const T& newItem){
		node<T>* newNode;
		newNode = new node<T>;
		newNode->data = newItem;
		newNode->link = nullptr;
		
		if(first == nullptr){
			first = last = newNode;
			count++;
		}
		else{
			last->link;
			last = newNode;
			count++;
		}
	}

	void deleteNode(const T& deleteItem){
		node<T>* current;
		node<T>* trailCurrent;
		bool found;

		if(first == nullptr){
			cout<<"list is already empty"<<endl;
		}
		else{
			if(first->data == deleteItem){
				current = first;
				first = first->link;
				count--;

				if(first == nullptr){
					last = nullptr;
					delete current;
				}

			}
			else{
				found = false;
				trailCurrent = first;

				current = first->link;

				while(current != nullptr && !found){
					if(current->data != deleteItem){
						trailCurrent = current;
						current = current->link;
					}
					else{
						found = true;
					}
				}

				if(found){
					trailCurrent->link = current->link;
					count--;

					if(last == current){
						last = trailCurrent;
						delete current;
					}
				}
				else{
					cout<<"Item no found"<<endl;
				}
			}
		}
	}
};
	
