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


const int MAX_L = 100;
//char a[MAX_L + 1];
//char b[MAX_L + 1];


int main(){
    freopen("3778.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; 
    //scanf("%d", &TC);
    cin >> TC;
    string temp;
    getline(cin, temp);

    for(int tc = 1; tc <= TC; tc++){
        string a, b;
        getline(cin, a);
        getline(cin, b);
        int a_len = 0, b_len = 0;
        vi check_a(256);
        vi check_b(256);
        //printf("case : %d\n", tc);
        //printf("a : %s\n", a.c_str());
        //printf("b : %s\n", b.c_str());
        for(int i = 0; i < a.size(); i++){
            check_a[a[i]]++;
        }
        for(int i = 0; i < b.size(); i++){
            check_b[b[i]]++;
        }
        int ans = 0;
        for(int i = 0; i < 256; i++){
            ans += abs(check_a[i] - check_b[i]);
        }
        printf("Case #%d: %d\n", tc, ans);
    }
}