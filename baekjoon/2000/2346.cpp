// boj 2346
#include <iostream>
#include <cstdio>

using namespace std;


const int MAX_N = 100000;
int N;

class node{
public:
    node* m_prev;
    node* m_next;
    int m_index, m_value;

    node(int index, int value):m_index(index), m_value(value){
	m_prev = m_next = NULL;
    }

    node(int index, int value, node* prev, node* next):m_index(index), m_value(value), m_prev(prev), m_next(next){

    }


private:
};


#ifdef SONG_TEST
void print_array(node* it, char* msg){
    node* head = it;
    printf("\n%s\n", msg);
    printf("\n==========\n");
    for( ; it->m_next != head; it = it->m_next ) {
	printf("cur : %p, m_prev = %p, m_next = %p, m_index = %d, m_value = %d\n", it, it->m_prev, it->m_next, it->m_index, it->m_value);
    }
    printf("cur : %p, m_prev = %p, m_next = %p, m_index = %d, m_value = %d\n", it, it->m_prev, it->m_next, it->m_index, it->m_value);
    printf("\n==========\n");
}
#endif

int main(){
#ifdef SONG_TEST
    freopen("input.txt", "r", stdin);
#endif

    int TC = 1, a;
    for(int tc = 1; tc <= TC; tc++){
	//	scanf("%d", &N);
	cin >> N;

	//	scanf("%d", &a);
	cin >> a;
	node* head = new node(1, a); 
	node* tail = head;

	for (int i = 2; i <= N; i++) {
	    //    scanf("%d", &a);
	    cin >> a;
	    tail = new node(i, a, tail, head);
	    tail->m_prev->m_next = tail;
	    head->m_prev = tail;
	}

#ifdef SONG_TEST
	print_array(head, "initial state");
#endif
	int count = N;
	while (1 < count) {
	    printf("%d ", head->m_index);
	    node* temp = head;
	    int val = head->m_value;
	    int abs_val = 0 < val ? val : -val;
	    if(0 < val)
		head = head->m_next;
	    else
		head = head->m_prev;
	    
	    abs_val--;
	    count--;

	    temp->m_prev->m_next = temp->m_next;
	    temp->m_next->m_prev = temp->m_prev;
	    delete temp;

	    if (0 < val) {
		for(int i = 0; i < abs_val; i++){
		    head = head->m_next;
		}
	    }
	    else {
		for(int i = 0; i < abs_val; i++){
		    head = head->m_prev;
		}
	    }
	    
#ifdef SONG_TEST
	    print_array(head, "after state");
#endif
	}

	printf("%d", head->m_index);
	printf("\n");
    }
}
