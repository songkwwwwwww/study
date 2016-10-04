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
첫째 줄에 정수 N(1≤N≤500,000)이 주어진다.

출력
첫째 줄에 남게 되는 카드의 번호를 출력한다.
*/

int N;
int main(){
    freopen("2164.txt", "r", stdin);
    queue<int> q;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) q.push(i);
    while(q.size() >= 2){
        q.pop();
        int next = q.front(); q.pop();
        q.push(next);
    }
    printf("%d\n", q.front());
}