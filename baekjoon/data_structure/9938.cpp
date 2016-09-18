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

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*
입력

첫째 줄에 N과 L이 주어진다. (1 ≤ N, L ≤ 300,000)
다음 N개 줄에는 Ai와 Bi가 주어진다. (1 ≤ Ai, Bi ≤ L, Ai ≠ Bi)


출력

1번 술부터 N번 술까지 순서대로 보관할 수 있는지, 그 자리에서 먹어야 하는지를 출력한다.
보관할 수 있는 경우에는 "LADICA"를, 먹어버려야 하는 경우에는 "SMECE"를 출력한다.
*/


const int MAX_N = 300000;
const int MAX_L = 300000;
int N, L;
int p[MAX_L + 1];
bool filled[MAX_L + 1];

int find(int n){
    if(p[n] == 0) return n;
    else return p[n] = find(p[n]);
}

void merge(int a, int b){
    a = find(a);
    b = find(b);
    if(a == b) return ;
    p[b] = a;
}

int main(){
    freopen("9938.txt", "r", stdin);
    scanf("%d %d", &N, &L);

    for(int i = 0; i < N; i++){
        int A, B;
        scanf("%d %d", &A, &B);
    
        if(!filled[A]){
            printf("LADICA\n");
            filled[A] = true;
            merge(B, A);
        }
        else if(!filled[B]){
            printf("LADICA\n");
            filled[B] = true;
            merge(A, B);
        }
        else if(!filled[find(A)]){
            printf("LADICA\n");
            filled[p[A]] = true;
            merge(B, A);            
        }
        else if(!filled[find(B)]){
            printf("LADICA\n");
            filled[p[B]] = true;            
            merge(A, B);
        }
        else{
            printf("SMECE\n");
        }
    }
}