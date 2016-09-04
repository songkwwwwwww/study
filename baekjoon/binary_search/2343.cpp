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
첫째 줄에 레슨의 수 N (1 ≤ N ≤ 100,000)과 M (1 ≤ M ≤ N)이 주어진다. 
다음 줄에는 강토의 기타 레슨의 길이가 레슨 순서대로 분 단위로(자연수)로 주어진다. 
각 레슨의 길이는 10,000분을 넘지 않는다.

출력
첫째 줄에 가능한 블루레이 크기중 최소를 출력한다.
*/
int N, M;
int a[100001];

bool check(int mid){
    int n_basket = 1, sum = 0;
    for(int i = 0; i < N; i++){
        if(a[i] > mid) return false;
        sum += a[i];
        if(sum > mid){
            n_basket++;
            sum = a[i];
        }
    }
    return n_basket <= M ? true : false;
}

int main(){
    freopen("2343.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    
    int l = 1, r = 0, m, ans = -1;
    
    for(int i = 0; i < N; i++) {
        scanf("%d", &a[i]);
        r += a[i];
    }
    while(l <= r){
        m = (l + r) / 2;
        if(check(m)){
            ans = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    printf("%d\n", ans);
}
