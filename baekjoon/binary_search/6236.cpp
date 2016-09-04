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
Line 1: Two space-separated integers: N and M 
Lines 2..N+1: Line i+1 contains the number of dollars Farmer John spends on the ith day
(1 ≤ moneyi ≤ 10,000) 
(1 ≤ N ≤ 100,000) 
(1 ≤ M ≤ N)  

출력
Line 1: The smallest possible monthly limit Farmer John can afford to live with.
*/
int N, M;
int a[100000];


bool check(int mid){
    int limit = 1, sum = 0;
    for(int i = 0; i < N; i++){
        if(a[i] > mid) return false;
        sum += a[i];
        if(sum > mid){
            limit++;
            sum = a[i];
        }
    }
    return limit <= M ? true : false;
}

int main(){
    freopen("6236.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    int l = 1, r = 0, m, ans = -1;
    for(int i = 0; i < N; i++){
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