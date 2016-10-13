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
 
 
const int MAX_N = 1000000;
const int MAX_K = 10;
int N, K;
//int d[MAX_N + 1][MAX_K + 1];
//int d[MAX_N + 1];
 
int main(){
    freopen("1039.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &K);
     
    queue<string> q;
    q.push(to_string(N));
 
    // K 번 bfs
    for(int l = 0; l < K; l++){
        int q_size = q.size();
        // 중복 탐색을 방지하기 위해 set을 사용한다.
        set<string> found;
        // 각 레벨에서의 상태를 탐색한다
        for(int s = 0; s < q_size; s++){
            string here = q.front();
            q.pop();
 
            // 이미 방문한 상태면 건너뛴다
            if(found.count(here)) continue;
            // 아니라면 방문
            found.insert(here);
 
            // 각 원소를 교환
            int size = here.size();
            for(int i = 0; i < size - 1; i++){
                for(int j = i + 1; j < size; j++){
                    // i가 0이 아니면 무조건 방문한다.
                    // 아니라면 j가 가리키는 원소가 '0'이 아니어야 한다
                    if(0 < i || here[j] != '0'){
                        swap(here[i], here[j]);
                        q.push(here);
                        swap(here[i], here[j]);
                    }
                }
            }
        }
    } // end of bfs
 
    string result = "0";
    // 이제 큐에 남아있는 상태들은 K번 째에 방문한 상태들이다.
    // 여기서 최대값을 취한다.
    while(!q.empty()){
        result = max(result, q.front());
        q.pop();
    }
    if(result[0] == '0') printf("-1\n");
    else printf("%s\n", result.c_str());
}
 
/*
int solve(int n, int k){
    // base case
    if(k == K) return n;
 
    //int& ret = d[n][k];
    int& ret = d[n];
    if(ret != -1) return ret;
 
    ret = -INF;
    string here = to_string(n);
    int size = here.size();    
    for(int i = 0; i < size - 1; i++){
        for(int j = 1; j < size; j++){
            if(i > 0 || here[j] != '0'){
                swap(here[i], here[j]);
                ret = max(ret, solve(stoi(here), k + 1));
                swap(here[i], here[j]);
            }
        }
    }   
 
    return ret;
}
 
 
int main(){
    freopen("1039.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &K);
    memset(d, -1, sizeof(d));
    int ans = solve(N, 0);
    if(ans == -INF) printf("-1\n");
    else printf("%d\n", ans);
}
*/