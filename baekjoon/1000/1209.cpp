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

typedef pair<int, int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
문제
음이 아닌 정수로 이루어진 수열 A1, A2, …, AN이 있다. 
단조수열 B1, B2, …, BN을 만들어서 |A1-B1| + |A2-B2| + … + |AN-BN|을 최소로 하는 프로그램을 작성하시오.

단조수열이란 B1≤B2≤…≤BN을 만족하거나 B1≥B2≥…≥BN를 만족하는 수열을 말한다.

입력
첫째 줄에 수열의 길이 N이 주어진다. (1≤N≤2,000) 
이어서 둘째 줄부터 N개의 줄에 걸쳐 A1, A2, …, AN이 순서대로 주어진다. (0≤Ai≤1,000,000,000)

출력
첫째 줄에 절대값의 합의 최소값을 출력한다.
*/


/*
    koosaga님 코드
*/
const int MAX_N = 2000;

int main(){
    freopen("1209.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    vi a(N);
	for(int i = 0; i < N; i++)
        scanf("%d", &a[i]);
    
	int ans = INF;
    // 단조 증가, 단조 감소 
    // 총 두번
	for(int i = 0; i < 2; i++){
		int ret = 0;
        // priority_queue를 통해
        // a[0] ~ a[i] 까지의 값들을 기억
        priority_queue<int> pq;
        for(int j = 0; j < N; j++){
			if(!pq.empty() && pq.top() > a[j]){
                // A[j]까지의 의 최대 값과 비교하여 차를 계산
				ret += pq.top() - a[j];
				pq.pop();
				pq.push(a[j]);
			}
			pq.push(a[j]);
		}

		ans = min(ans, ret);
		reverse(a.begin(), a.end());
	}
	printf("%d\n", ans);
}