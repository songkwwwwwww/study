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
문제
얼마전에 후위표기식에 관한 프로그래밍을 한 적이 있다. 
이제 후위 표기식과 각 피 연산자에 대응하는 값들이 주어져 있을 때, 
그 식을 계산하는 프로그램을 작성하시오.

입력
첫째 줄에 피 연산자의 개수(1<=N<=26) 가 주어진다. 
그리고 둘째 줄에는 후위표기식이 주어진다.
 (여기서 피연산자는 A~Z의 영대문자이며, A부터 순서대로 N개의 영대문자만이 사용된다.) 
 그리고 셋째 줄부터 3+N줄까지는 각 피 연산자에 대응하는 값이 주어진다. 
 (3번째 줄에는 A에 해당하는 값, 4번째 줄에는 B에 해당하는값 , 5번째 줄에는 C ...이 주어진다, 
 그리고 피 연산자에 대응 하는 값은 정수이다)

출력
계산 결과를 출력한다. (계산 결과를 소숫점 둘째 자리까지 출력하시오)
*/
int N;
char str[100];
int a[27];

double calculate(double a, double b, char op){
    if(op == '*'){
        return a * b;
    }
    else if(op == '/'){
        return a / b;
    }
    else if(op == '+'){
        return a + b;
    }
    else if(op == '-'){
        return a - b;
    }
    else
        return 987654321;
}

int main(){
    freopen("1935.txt", "r", stdin);
    scanf("%d", &N);
    scanf("%s", str);
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
    } 

    int p = 0;
    stack<double> s;
    for(int i = 0; str[i]; i++){
        char cur = str[i];

        // 후위 표기식에는 사칙연산 혹은 피연산자만 있다.
        // 만약 현재 문자가 사칙연산이면 스택에서 피연산자를 두 개 꺼내서 연산.
        if(cur == '*' || cur == '/' || cur == '+' || cur == '-'){
            double b = s.top(); s.pop();
            double a = s.top(); s.pop();
            s.push(calculate(a, b, cur));
        }
        // 사칙연산이 아니면 피연산자니 스택에 넣는다.
        else{
            s.push(a[cur - 'A']);
        }
    }
    printf("%.2lf\n", s.top());
}