#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

vector< pair<int,int> > a[10001];
bool visited[10001];
int start, end;
// N : 섬의 개수
// 1 <= N <= 1,0000
// 1 <= M <= 10,0000
int N, M; 


bool go(int current_position, int weight){
    if(visited[current_position]) return false;
    visited[current_position] = true;
    if(current_position == end) return true;
    for(int i = 0; i < a[current_position].size(); i++){
        int next = a[current_position][i].first;
        int limit = a[current_position][i].second;
        if(weight <= limit && go(next, weight))
                return true;            
        
    }
    return false;
}

int main(){
    freopen("1939.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    // A, B : 섬,    C : 중량제한
    // 1 <= A, B <= N
    // 1 <= C <= 10,0000,0000
    int A, B, C;
    for(int i = 0; i < M; i++){
        scanf("%d %d %d", &A, &B, &C);
        a[A].push_back(make_pair(B, C));
        a[B].push_back(make_pair(A, C));
    }
    scanf("%d %d", &start, &end);
    int l = 1, r = 1000000000, m, ans = 0;
    while(l <= r){
        memset(visited, false, sizeof(visited));
        m = (l + r) / 2;
        if(go(start, m)){
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }
    printf("%d\n", ans);
    
}