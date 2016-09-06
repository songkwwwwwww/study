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

#include <functional> // greater, less
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
문제
N(1≤N≤31)자리의 이진수가 있다. 
이러한 이진수들 중에서, L(1≤L≤N)개 이하의 비트들만 1인 것들을 크기 순으로 나열했을 때, 
I번째로 나오는 이진수를 구해내는 프로그램을 작성하시오. 
이진수는 0으로 시작할 수도 있다.

입력
첫째 줄에 세 정수 N, L, I가 주어진다. I는 범위 안에 있도록 주어진다.

출력
첫째 줄에 답을 출력한다.
*/

int N, L;
ll I;

int d[32][32];

int binary(int n, int m){
    // base case
    if(n == 0 || m == 0) return 1;

    int& ret = d[n][m];
    if(ret != -1) return ret;

    return ret = binary(n - 1, m) + binary(n - 1, m - 1);
}

char result[32];

void skip(int n, int m, int k, int p){
    if(n == 0) return;
    if(m == 0){
        for(int i = 0; i < n; i++)
            result[p + i] = '0';
        return ;
    }

    int pivot = binary(n - 1, m);
    if(k < pivot){
        result[p] = '0';
        skip(n - 1, m, k, p + 1);
    }
    else{
        result[p] = '1';
        skip(n - 1, m - 1, k - pivot, p + 1);
    }
}

int main(){
    freopen("2248.txt", "r", stdin);
    scanf("%d %d %lld", &N, &L, &I);
    memset(d, -1, sizeof(d));
    skip(N, L, I - 1, 0);
    result[N] = '\0';
    printf("%s\n", result);
}