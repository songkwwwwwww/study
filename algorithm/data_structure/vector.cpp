class vector{
    int size, cap;
    int* arr;

    vector(){
	size = 0;
	cap = 4;
	arr = new int[4];
    }

    void push_back(int x){
	if(size == cap){
	    cap *= 2;
	    int* temp = new int[cap];
	    for(int i = 0; i < size; i++){
		temp[i] = arr[i];
	    }
	    delete[] arr;
	    arr = temp;
	}
	arr[size++] = x;
    }

    void clear(){
	delete[] arr;
	arr = new int[4];
	size = 0;
	cap = 4;
    }
};
