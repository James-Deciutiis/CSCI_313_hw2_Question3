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
	
	void push(const T& element){
		list[count] = element;
		count++;
	}

	T pop(){
		T poppedItem = list[count-1];
		list[count-1] = 0;
		count--;
		return poppedItem;
	}
	
	T peak(){
		T peakedItem = list[count];
		return peakedItem;
	}
	
	T bottom(){
		T bottomItem = list[0];
		return bottomItem;
	}

	void print(){
		for(int i = count - 1; i >= 0; i--){
			cout<< list[i] <<endl;
		}
	}
};
