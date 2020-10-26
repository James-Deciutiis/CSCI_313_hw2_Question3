#include <iostream>
#include "timeTrial.h"
using namespace std;

int main(){
	TimeTrial trial;
	
	LinkedStack<int> linkedStack;
	ArrayStack<int> arrayStack;

	trial.start(arrayStack, linkedStack);

	return 0;
}
