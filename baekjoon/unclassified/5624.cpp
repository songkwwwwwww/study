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
정수 N개로 이루어진 수열 A가 있다. 
이 때, i번째 수가 그 앞에 있는 수 세 개의 합으로 나타낼 수 있을 때, 그 수를 좋다고 한다. 
(같은 위치에 있는 수를 여러번 더해도 된다)

수열이 주어졌을 때, 총 몇 개의 수가 좋은 수 일까?

입력
첫째 줄에 수열 A의 크기 N이 주어진다. (1 ≤ N ≤ 5000) 
둘째 줄에는 수열 A의 각 숫자가 공백으로 구분되어 주어진다. (-100,000 ≤ Ai ≤ 100,000)

출력
첫째 줄에 좋은 수의 개수를 출력한다.
*/


const int MAX_N = 5000;
const int MAX_SUM = 200000;

int N;
int a[MAX_N];

int main(){
    freopen("5624.txt", "r", stdin);
    scanf("%d", &N);
    vb sum(2 * MAX_SUM + 1);
    
    int count = 0;
    for(int i = 0; i < N; i++){
        scanf("%d", &a[i]);
        for(int j = 0; j < i; j++){
            if( sum[a[i] - a[j] + MAX_SUM] ){
                count++;
                break;
            }
        }
        for(int j = 0; j <= i; j++){
            sum[ a[i] + a[j] + MAX_SUM ] = true;            
        }
    }
    //for(int i = 0; i < N; i++){
        
    //}
    printf("%d\n", count);
}