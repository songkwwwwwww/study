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
//#include <unordered_map> // c++11

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

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
문제
세준이는 N*N크기의 배열을 만들었다. (배열의 방 번호는 1부터 시작한다.)

그 배열을 A라고 했을 때, 배열에 들어가는 수는 A[i][j] = i*j 이다.

세준이는 이 수를 일차원 배열 B에 넣으려고 한다. 

그렇게 되면, B의 크기는 N*N이 될 것이다. 

그러고 난 후에, B를 정렬해서 k번째 원소를 구하려고 한다.

N이 주어졌을 때, k번째 원소를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 배열의 크기 N이 주어진다. N은 10^5보다 작거나 같은 자연수이다. 
둘째 줄에 k가 주어진다. k는 min(10^9, n^2)보다 작거나 같은 자연수이다.

출력
k번째 원소를 출력한다.
*/

const int MAX_N = 100000;
int N, K;
int main(){
    freopen("1300.txt", "r", stdin);
    scanf("%d %d", &N, &K);
    if(K == 1){
        printf("1\n");
    }
    else{
        int lo = 0, hi = min(1LL *N * N, 1000000000LL);
        while(lo <= hi){
            int mid = (lo + hi) / 2, cnt = 0;
            for(int i = 1; i <= N; i++)
                cnt += min(mid / i, N);
            if(cnt < K)
                lo = mid + 1;
            else
                hi = mid - 1;
        }
        printf("%d\n", lo);
    }
}