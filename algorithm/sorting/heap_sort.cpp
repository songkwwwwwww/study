#include <stdio.h>



// max heap
template <typename T>
class priority_queue{
    private:
	int size, length;

	T* a;

	void swap(T& a, T& b){
	    T temp = a;
	    a = b;
	    b = temp;
	}

	void MAX_HEAPIFY(int i){
	    int l = 2 * i;
	    int r = 2 * i + 1;
	    int largest = i;
	    if(l <= size && a[l] >= a[i]){
		largest = l;
	    }
	    if(r <= size && a[r] >= a[largest]){
		largest = r;
	    }
	    if(largest != i){
		swap(a[i], a[largest]);
		MAX_HEAPIFY(largest);
	    }
	}


    public:
	priority_queue(int length = 100){
	    a = new T[length];
	    size = 0;
	};

	T top(){
	    return a[1];
	}

	T pop(){
	    //if(size < 1)
		// error
	   
	    T ret = a[1];
	    a[1] = a[size];
	    size--;
	    MAX_HEAPIFY(1);
	    return ret;
	}

	void push(T n){
	    size++;
	    int i = size;
	    a[i] = n;
	    while(i > 1 && a[i / 2] < a[i]){
		swap(a[i / 2], a[i]);
		i = i >> 1;
	    }
	}
};


int main(){
    int a[10] = {5, 3, 2, 6, 8, 4, 1, 9, 10, 7};
    priority_queue<int> h;
    for(int i = 0; i < 10; i++){
	h.push(a[i]);
    }
    for(int i = 0; i < 10; i++){
	printf("%d\n", h.pop());
    }
}
