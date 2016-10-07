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
입력
첫 줄에 부등호 문자의 개수를 나타내는 정수 k가 주어진다. 
그 다음 줄에는 k개의 부등호 기호가 하나의 공백을 두고 한 줄에 모두 제시된다. 
k의 범위는 2<=k<=9 이다. 

출력
여러분은 제시된 부등호 관계를 만족하는 k+1 자리의 최대, 최소 정수를 첫째 줄과 둘째 줄에 각각 출력해야 한다. 
단 아래 예(1)과 같이 첫 자리가 0인 경우도 정수에 포함되어야 한다. 
모든 입력에 답은 항상 존재하며 출력 정수는 하나의 문자열이 되도록 해야 한다. 
*/


const int MAX_K = 9;
int K;

bool used[10];
char expression[MAX_K];
ll max_val, min_val;

void solve(int left_val, int index, ll num){
    if(index == K){
        //printf("Hello\n");
        max_val = max(max_val, num);
        min_val = min(min_val, num);
        return ;
    }
    used[left_val] = true;
    if(expression[index] == '<'){
        for(int i = left_val + 1; i <= 9; i++){
            if(!used[i]){
                solve(i, index + 1, num * 10 + i);
            }
        }
    }
    else{ // '>'
        for(int i = left_val - 1; i >= 0; i--){
            if(!used[i]){
                solve(i, index + 1, num * 10 + i);
            }
        }
    }
    used[left_val] = false;    
}

int main(){
    freopen("2529.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &K);
    for(int i = 0; i < K; i++)
        scanf(" %c", &expression[i]);

    max_val = -INF * 100LL;
    min_val = INF * 100LL;
    for(int i = 0; i <= 9; i++){
        solve(i, 0, i);
    }
    ll temp = min_val;
    int min_cnt = 0;
    while(temp){
        min_cnt++;
        temp /= 10;
    }
    temp = max_val;
    int max_cnt = 0;
    while(temp){
        max_cnt++;
        temp /= 10;
    }
    if(max_cnt == K && min_cnt == K){
        printf("0%lld\n0%lld\n", max_val, min_val);
    }
    else if(max_cnt == K)
        printf("0%lld\n%lld\n", max_val, min_val);
    else if(min_cnt == K)
        printf("%lld\n0%lld\n", max_val, min_val);
    else
        printf("%lld\n%lld\n", max_val, min_val);
       
}