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


const int MAX_L = 100000;

int solve(string& A, string& B){
    int N = A.size();
    int M = B.size();
    if(N != M)
        return -1;
    vi a, b; 
    a.reserve(N);
    b.reserve(N);
    for(int i = 0; i < N; i++){
        if(A[i] == 'a')
            a.push_back(i);
        if(B[i] == 'a')
            b.push_back(i);
    }
    if(a.size() != b.size())
        return -1;
            
    int ans = 0;
    for(int i = 0; i < a.size(); i++){
        ans += abs(b[i] - a[i]);
    }
            
    return ans;
}

int main(){
    freopen("10453.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){        
        string A, B;
        cin >> A >> B;
        printf("%d\n", solve(A, B));
    }
}