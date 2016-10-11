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


const int MAX_N = 10000;



int main(){
    freopen("9020.txt", "r", stdin);
    //setbuf(stdout, NULL);
    vb prime(MAX_N + 1, true);
    prime[0] = prime[1] = false;
    for(int i = 2; i * i <= MAX_N; i++){
        if(prime[i]){
            
            for(int j = i * i; j <= MAX_N; j += i){
                prime[j] = false;
            }
        }
    }
    int TC; scanf("%d", &TC);
    while(TC--){
        int N, a, b;
        scanf("%d", &N);
        if(N == 4){
            a = b = 2;
        }
        else{
            for(int i = 3; 2 * i <= N; i += 2){
                if(prime[i] && prime[N - i]){
                    a = i;
                    b = N - i;
                }
            }
        }
        printf("%d %d\n", a, b);
    }
}