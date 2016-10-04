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


const int MAX_N = 1000000;


int main(){
    freopen("1816.txt", "r", stdin);
    //setbuf(stdout, NULL);

    vb is_prime(MAX_N + 1, true);
    vi prime; prime.reserve(MAX_N);

    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= MAX_N; i++){
        if(is_prime[i]){
            prime.push_back(i);
            for(int j = 2 * i; j <= MAX_N; j += i)
                is_prime[j] = false;
        }
    }


    int TC; scanf("%d", &TC);
    while(TC--){
        ll num;
        scanf("%lld", &num);
        int flag = true;
        for(int i = 0; i < prime.size(); i++){
            if(num % prime[i] == 0){
                flag = false;
                break;
            }
        }
        if(flag) printf("YES\n");
        else printf("NO\n");
    }
}