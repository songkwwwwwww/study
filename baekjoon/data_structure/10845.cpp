#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <stack>
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*
명령은 총 여섯 가지이다.

push X: 정수 X를 큐에 넣는 연산이다.
pop: 큐에서 가장 앞에 있는 정수를 빼고, 그 수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 큐에 들어있는 정수의 개수를 출력한다.
empty: 큐가 비어있으면 1, 아니면 0을 출력한다.
front: 큐의 가장 앞에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
back: 큐의 가장 뒤에 있는 정수를 출력한다. 만약 큐에 들어있는 정수가 없는 경우에는 -1을 출력한다.
*/

struct my_queue{
    int arr[10000];
    int head;
    int tail;
    int count;
    my_queue(){
        head = 0;
        tail = 0;
        count = 0;
    }
    void push(int x){
        if(count == 10000)
            return;
        arr[tail] = x;
        tail = (tail + 1) % 10000;
        count++;
    }
    int pop(){
        if(count == 0)
            return -1;
        int previous = head;
        head = (head + 1) % 10000;
        count--;
        return arr[previous];
    }

    int size(){
        return count;
    }

    int empty(){
        return count == 0 ? 1 : 0;
    }

    int front(){
        if(count == 0) return -1;
        else return arr[head]; 
    }

    int back(){
        if(count == 0) return -1;
        else return arr[tail -1];
    }
};

int main(){
    freopen("10845.txt", "r", stdin);
    my_queue q;
    int TC; scanf("%d", &TC);
    char command[6];
    while(TC--){
        scanf("%s", command);
        if(strcmp(command, "push") == 0){
            int n;
            scanf("%d", &n);
            q.push(n);
        }
        else if(strcmp(command, "pop") == 0){
            printf("%d\n", q.pop());
        }
        else if(strcmp(command, "size") == 0){
            printf("%d\n", q.size());
        }
        else if(strcmp(command, "empty") == 0){
            printf("%d\n", q.empty());
        }
        else if(strcmp(command, "front") == 0){
            printf("%d\n", q.front());
        }
        else { // back
            printf("%d\n", q.back());
        }
    }
}