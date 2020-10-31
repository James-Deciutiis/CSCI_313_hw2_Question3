using namespace std;

template<class T>
class ArrayStack{
	protected:
		T *list;
		int count = 0;
	public:
		ArrayStack(){
			list = new T[100000000];
		}
	
	//adds an element to the top of the stack
	void push(const T& element){
		list[count] = element;
		count++;
	}

	//removes and returns the top element of the stack
	T pop(){
		T poppedItem = list[count-1];
		count--;
		return poppedItem;
	}
	
	//returns the top element of the stack (but doesnt remove it)
	T peak(){
		T peakedItem = list[count-1];
		return peakedItem;
	}
	
	//returns the last element of the stack (first one pushed on)
	T bottom(){
		T bottomItem = list[0];
		return bottomItem;
	}

	//prints out the stacks elements from top to bottom
	void print(){
		for(int i = count - 1; i >= 0; i--){
			cout<< list[i] <<endl;
		}
	}
	
	//returns the amount of elements in the stack
	int getCount(){
		return count;
	}
};
