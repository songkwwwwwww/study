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
char a[MAX_L + 1];
char b[MAX_L + 1];


int main(){
    freopen("6996.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    while(TC--){
        scanf("%s", a);
        scanf("%s", b);
        int a_len = 0, b_len = 0;
        vi check_a(256);
        vi check_b(256);
        for(a_len = 0; a[a_len]; a_len++){
            check_a[a[a_len]]++;
        }
        for(b_len = 0; b[b_len]; b_len++){
            check_b[b[b_len]]++;           
        }
        bool same = true;
        if(a_len != b_len){
            same = false;
        }
        else{
            for(int i = 0; i < 256; i++){
                if(check_a[i] != check_b[i]){
                    same = false;
                    break;
                }
            }
        }
        if(same)
            printf("%s & %s are anagrams.\n", a, b);
        else
            printf("%s & %s are NOT anagrams.\n", a, b);
    }
}