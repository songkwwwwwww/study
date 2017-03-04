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
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<double> vd;
typedef vector<vd> vvd;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 8;
const int MAX_M = 8;


struct MAX_FLOW{
    // 총 노드의 개수
    int n;

    vvi c, f;
    vi dad; // 증가 경로에서 이전 노드를 기억해두기 위한 변수
    vi q; // 배열로 사용하는 queue

    MAX_FLOW(int nn): n(nn), c(nn, vi(nn)), f(nn, vi(nn)), dad(nn), q(nn) {
    }

    void add_edge(int from, int to, int cap){
	this->c[from][to] += cap;
    }

    int get_flow(int s, int t){
	fill(dad.begin(), dad.end(), -1); // dad 변수 초기화
	dad[s] = -2;

	int head = 0, tail = 0;
	q[tail++] = s; // q.push(s)
	
	while(head < tail){
	    int here = q[head++]; // q.pop();
	    for(int there = 0; there < n; there++){
		if(dad[there] == -1 && c[here][there] - f[here][there] > 0){
		    dad[there] = here;
		    q[tail++] = there;
		}
	    }
	}

	if(dad[t] == -1) return 0;

	int total_flow = 0;
	for(int i = 0; i < n; i++){
	    if(dad[i] == -1) continue;

	    int amount = c[i][t] - f[i][t];
	    for(int j = i; amount && (j != s); j = dad[j]){
		amount = min(amount, c[dad[j]][j] - f[dad[j]][j]);
	    }
	    if(amount == 0) continue;
	    f[i][t] += amount;
	    f[t][i] -= amount;

	    for(int j = i; j != s; j = dad[j]){
		f[dad[j]][j] += amount;
		f[j][dad[j]] -= amount;
	    }
	    total_flow += amount;
	}
	return total_flow;
    }

    int get_max_flow(int s, int t){
	int total_flow = 0;
	while(int flow = get_flow(s, t)){
	    total_flow += flow;
	}
	return total_flow;
    }

};

int get_num(char c){
    if('A' <= c && c <= 'Z'){
	return c - 'A';
    }
    else if('a' <= c && c <= 'z'){
	return c - 'a' + 26;
    }
    else{
	return -1; // error
    }
}

int main(){
    freopen("6086.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    //printf("N : %d\n", N);
    MAX_FLOW m(52);

    for(int i = 0; i < N; i++){
	char cu, cv;
	int u, v, cap;
	
	scanf(" %c %c %d", &cu, &cv, &cap);
	//printf("%d : %c %c %d\n", i, cu, cv, cap);

	u = get_num(cu);
	v = get_num(cv);
	//printf("u = %d, v = %d, cap = %d\n", u, v, cap);
	m.add_edge(u, v, cap);
    }
    int ans = m.get_max_flow(0, 25);
    printf("%d\n", ans);
}
