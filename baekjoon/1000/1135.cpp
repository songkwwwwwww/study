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

*/


const int MAX_N = 50;
int N;
vi child[MAX_N];

/*
    here 에서부터 모든 자식들에게 연락했을 때의 최대 소요 시간 반환
*/
int solve(int here){
    vi v; v.reserve(child[here].size());
    int ret = 0;
    // 각 자식들의 최대 소요시간 검사
    for(int i = 0; i < child[here].size(); i++)
        v.push_back(1 + solve(child[here][i]));
    
    // 걸리는 시간 순서대로 정렬한다.
    sort(v.begin(), v.end());
    if(!v.empty()){ // 자식이 있다면
        int time = 0;
        for(int i = 0; i < v.size(); i++){
            // 가장 오랜 시간을 필요로 하는 자식부터 연락한다.
            ret = max(ret, v[(int)v.size() - 1 - i] + time);
            time++;
        }
    }
    return ret;
}

int main(){
    freopen("1135.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    for(int i = 0; i < N; i++){
        int p;
        scanf("%d", &p);
        if(p != -1)
            child[p].push_back(i);
    }
    printf("%d\n", solve(0));
}