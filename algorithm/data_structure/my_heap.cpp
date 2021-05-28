struct node{
    int dist;
    int here;
};


template <typename T>
class my_heap{
    int size;
    T data[MAX_HEAP_SIZE];
public:
    my_heap(): size(0){}
    void init(){
	size = 0;
    }
    bool empty(){
	if(size == 0) return true;
	else return false;
    }
    int push(T n)
	if(size + 1 > MAX_HEAP_SIZE)
	    return INF;
	
        data[size] = n;
	int cur = size++;

	while(cur > 0 && data[cur] < data[(cur - 1) / 2]){
	    swap(data[cur], data[(cur - 1) / 2]);
	    cur = (cur - 1) / 2
	}
    }
    T pop(){
	if(empty())
	    return INF;
	size--;
	T ret = data[0];
	data[0] = data[size];
	int cur = 0;
	while(cur * 2 + 1 < size){ // 자식이 최소 하나라도  있다면
	    int child;
	    if(cur * 2 + 2 == size){ // 자식이 하나일 때
		child = cur * 2 + 1;
	    }
	    else{
		child = data[cur * 2 + 1] < data[cur * 2 + 2] ? cur * 2 + 1 : cur * 2 + 2;
	    }
	    if(data[cur] < data[child])
		break;

	    swap(data[cur], data[child])
	    cur = child;
	}
	return ret;
    }
}
