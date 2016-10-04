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
입력은 여러 개의 테스트 케이스로 이루어져 있다. 
각 테스트 케이스는 한 줄로 이루어져 있고, L, P, V를 순서대로 포함하고 있다. 
모든 입력 정수는 int범위이다. 마지막 줄에는 0이 3개 주어진다. (1 < L < P < V)

출력
각 테스트 케이스에 대해서, 
강산이가 캠핑장을 최대 몇 일동안 사용할 수 있는지 예제 출력처럼 출력한다.
*/
int L, P, V;
int main(){
    freopen("4796.txt", "r", stdin);
    int count = 1;
    while(true){
        scanf("%d %d %d", &L, &P, &V);
        if(L == 0 && P == 0 && V == 0) break;
        int quotient = V / P;
        int remainder = V % P;
        if(remainder > L)
            remainder = L;
    
        printf("Case %d: %d\n", count++, quotient * L + remainder);
    }
}