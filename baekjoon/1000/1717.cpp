#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

int p[1000001];

int Find(int x){
    if(x == p[x]){
        return x;
    }
    else{
        return p[x] = Find(p[x]);
    }
}

int Union(int x, int y){
    x = Find(x);
    y = Find(y);
    p[y] = x;
}

int main(){
    freopen("1717.txt", "r", stdin);
    // 초기에 {0}, {1}, {2}, ... {n} 이 각각 n+1개의 집합을 이루고 있다 
    // n ( 1 <= n <= 100,0000)
    // 입력으로 주어지는 연산의 개수 m ( 1 <= m <= 10,0000)
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= n; i++)
        p[i] = i;

    for(int i = 0; i < m; i++){
        int c, a, b;
        scanf("%d %d %d", &c, &a, &b);
        if(c == 0){ // 집합 합치기
            Union(a, b);
        }
        else if(c == 1){ // 동일한 집합인지 아닌지 확인
            if(Find(a) == Find(b))
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
}