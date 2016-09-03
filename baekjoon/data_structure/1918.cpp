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

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*
입력
첫째 줄에 중위 표기식이 주어진다. 
단 이 수식의 피연산자는 A~Z의 문자로 이루어지며 수식에서 한 번씩만 등장한다. 
그리고 -A+B와 같이 -가 가장 앞에 오거나 AB와 같이 *가 생략되는 등의 수식은 주어지지 않는다. 
표기식은 알파벳 대문자와 +, -, *, /, (, )로만 이루어져 있다.

출력
첫째 줄에 후위표기식으로 바뀐 식을 출력하시오
*/

int p = 0;
char cur, str[101], result[101];


int get_prior(char op){
    if(op == '(' || op == ')') 
        return 0;
    else if(op == '+' || op == '-') 
        return 1;
    else if(op == '*' || op == '/') 
        return 2;
    else 
        return -1;
}

int main(){
    freopen("1918.txt", "r", stdin);
    scanf("%s", str);
    stack<char> s;

    for(int i = 0; str[i]; i++){
        cur = str[i];        
        // +, -, *, / 와 같은 사칙연산 일 경우
        if(cur == '+' || cur == '-' || cur == '*' || cur == '/'){
            while(!s.empty() && (get_prior(s.top()) >= get_prior(cur))){
                result[p++] = s.top(); 
                s.pop();
            }
            s.push(cur);
        }
        
        // '(' 를 스택에 push 한다
        else if(cur == '('){
            s.push(cur);
        }

        // ')' 일 경우 '(' 를 만날 때까지 스택을 pop 한다.
        else if(cur == ')'){
            while(s.top() != '('){
                result[p++] = s.top();
                s.pop();
            }
            s.pop();
        }
        // 피연산자이면 출력한다.
        else{
            result[p++] = cur;
        }
        
    }
    
    while(!s.empty()){
        result[p++] = s.top(); s.pop();
    }
    printf("%s\n", result);
}