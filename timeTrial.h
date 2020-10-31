#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <ctime>
#include <chrono>
#include "linkedStack.h"
#include "arrayStack.h"
using namespace std;

class TimeTrial
{
private:
	int _trials;
public:
	//default constructor
	TimeTrial(){_trials = 10; cout<<"initialized with default constructor"<<endl;}
	//parameter contructor
	TimeTrial(int t) : _trials(t){}
	
	//tests the time it takes to do basic stack operations and prints out time taken in milliseconds. 
	void start(ArrayStack<int> a, LinkedStack<int> l){
		cout<<"<--------------------- PUSHING: ----------------------->"<<endl;
		cout<<"Filling array based stack with 10,000,000 random numbers"<<endl;
		auto start = chrono::steady_clock::now();
		for(int i = 0; i <_trials; i++){
			for(int j = 0; j < 10000000; j++){
				a.push(rand());
			}
		}
		auto end = chrono::steady_clock::now();
		auto elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)/_trials;
		cout << "It took on average " << elapsed.count() << " milliseconds. over " << _trials << " trials" << endl;
		
		
		cout<<"Filling linked list based stack with 10,000,000 random numbers"<<endl;
		start = chrono::steady_clock::now();
		for(int i = 0; i <_trials; i++){
			for(int j = 0; j < 10000000; j++){
				l.push(rand());
			}
		}
		end = chrono::steady_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)/_trials;
		cout << "It took on average " << elapsed.count() << " milliseconds. over " << _trials << " trials" << endl;
		
		cout<<"<--------------------- POPPING: ----------------------->"<<endl;
		cout<<"popping off array based stack's 10,000,000 random numbers"<<endl;
		start = chrono::steady_clock::now();
		for(int i = 0; i <_trials; i++){
			for(int j = 0; j < 10000000; j++){
				a.pop();
			}
		}
		end = chrono::steady_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)/_trials;
		cout << "It took on average " << elapsed.count() << " milliseconds. over " << _trials << " trials" << endl;
		
		cout<<"popping off linked list based stack's 10,000,000 random numbers"<<endl;
		start = chrono::steady_clock::now();
		for(int i = 0; i <_trials; i++){
			for(int j = 0; j < 10000000; j++){
				l.pop();
			}
		}
		end = chrono::steady_clock::now();
		elapsed = std::chrono::duration_cast<std::chrono::milliseconds>(end - start)/_trials;
		cout << "It took on average " << elapsed.count() << " milliseconds. over " << _trials << " trials" << endl;
	}
};

