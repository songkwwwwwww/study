template <typename T>
class my_queue{
    T data[MAX_QUEUE_SIZE];
    int size, front, rear;
public:
    my_queue(): size(0), front(0), rear(0){}
    void init(){
	size = front = rear = 0;
    }
    bool empty(){
	if(front == rear) return true;
	else return false;
    }
    bool full(){
	if((rear + 1) % MAX_QUEUE_SIZE == front) return true;
	else return false;
    }

    int push(T item){
	if(full()) return -1;
	else{
	    rear = (rear + 1) % MAX_QUEUE_SIZE;
	    data[rear] = item;
	    return 0;
	}
    }

    T pop(){
	if(!empty()){
	    front = (front + 1) % MAX_QUEUE_SIZE;
	    return data[front];
	}
    }
}
