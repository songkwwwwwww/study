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
 처리과정
 1.여는 괄호가 나오면 스택에 넣는다
 2.닫는 괄호가 나오면 스택에서 뺀다
    2.1 pair가 차이가 1일때 레이져이다.
        2.1.1 이때 남아 있는 스택의 크기만큼 더한다
    2.2 pair가 차이가 1이 아닐때
        2.2.1 종료되는 파이프 개수이 1개를 더한다
*/
char str[100001];
int main(){
    freopen("10799.txt", "r", stdin);
    scanf("%s", str);
    int c = 0, result = 0;
    for(int i = 0; str[i]; i++){
        if(str[i] == '('){
            c++;
        }
        else{ // ')'
            c--;
            if(str[i - 1] == '('){
                result += c;
            }
            else{
                result++;
            }
        }
    }
    printf("%d\n", result);
}