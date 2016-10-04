#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
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
명령은 총 다섯 가지이다.

push X: 정수 X를 스택에 넣는 연산이다.
pop: 스택에서 가장 위에 있는 정수를 빼고, 그 수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.
size: 스택에 들어있는 정수의 개수를 출력한다.
empty: 스택이 비어있으면 1, 아니면 0을 출력한다.
top: 스택의 가장 위에 있는 정수를 출력한다. 만약 스택에 들어있는 정수가 없는 경우에는 -1을 출력한다.

14
push 1
push 2
top
size
empty
pop
pop
pop
size
empty
pop
push 3
empty
top
*/

struct my_stack {
    int count;
    int val[10000];

    my_stack(){
        count = 0;
    }

    void push(int x){
        if(count == 10000)
            return ;
        val[++count] = x;
    }
    int pop(){
        if(count == 0){
            return -1;
        }
        return val[count--];
    }
    int size(){
        return count;
    }
    int empty(){
        return count == 0 ? 1 : 0;
    }
    int top(){
        if(count == 0) return -1;
        else return val[count];
    }
};

int main(){
    freopen("10828.txt", "r", stdin);
    int N; scanf("%d", &N);
    my_stack s;
    while(N--){
        string command;
        cin >> command;
        if(command == "push"){
            int n;
            cin >> n;
            s.push(n);
        }
        else if(command == "pop"){
            cout << s.pop() << endl;
        }
        else if(command == "size"){
            cout << s.size() << endl;
        }
        else if(command == "empty"){
            cout << s.empty() << endl;
        }
        else{ // top
            cout << s.top() << endl;
        }
    }
}