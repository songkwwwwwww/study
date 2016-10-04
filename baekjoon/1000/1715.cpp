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

#include <functional>
#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*
입력
첫째 줄에 N이 주어진다. (1≤N≤100,000)
이어서 N개의 줄에 걸쳐 숫자 카드 묶음의 각각의 크기가 주어진다.

출력
첫째 줄에 최소 비교 횟수를 출력한다. (21억 이하)
*/

int N;

int cmp(int a, int b){
    if(a < b)
        return true;
    else
        return false;
}

int main(){
    freopen("1715.txt", "r", stdin);
    scanf("%d", &N);
    priority_queue<int, vector<int>, greater<int> > pq;
    for(int i = 0; i < N; i++){
        int n;
        scanf("%d", &n);
        pq.push(n);
    }
    int ans = 0;
    while(pq.size() >= 2){
        int a, b;
        a = pq.top(); pq.pop();
        b = pq.top(); pq.pop();
        ans += a + b;
        pq.push(a + b);
    }
    printf("%d\n", ans);
}