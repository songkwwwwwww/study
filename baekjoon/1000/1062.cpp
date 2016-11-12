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


const int MAX_N = 50;
const int MAX_K = 26;
int N, K;
vector<string> dic;
//int dic[MAX_N][26];
int solve(int checked, int index, int k){
    if(checked & (1 << index) ){
        return solve(checked, index + 1, k);
    }
    // base case
    if(index == 26){
        if(k == 0){
            int result = 0;
            for(int i = 0; i < N; i++){
                bool flag = true;
                for(int j = 0; j < dic[i].size(); j++){
                    if(!(checked & 1 << (dic[i][j] - 'a'))){
                        flag = false;
                        break;
                    }
                }
                if(flag)
                    result++;
            }
            return result;
        }
        else
            return 0;
    }
    // 현재 단어를 사용하지 않을 경우와 사용할 경우
    return max( solve(checked, index + 1, k), solve(checked | (1 << index) , index + 1, k - 1) );

}

int main(){
    freopen("1062.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d %d", &N, &K);
    int ans = 0;
    // anta ~ tica
    // a, c, n, t, i
    // 다섯 가지의 글자는 기본적으로 알고 있어야 한다.
    if(5 <= K){
        dic.reserve(N);
        for(int i = 0; i < N; i++){
            string s;
            cin >> s;
            dic.push_back(s);  
        }
        int checked = 0;
        checked |= (1 << ('a' - 'a'));
        checked |= (1 << ('c' - 'a'));
        checked |= (1 << ('n' - 'a'));
        checked |= (1 << ('t' - 'a'));
        checked |= (1 << ('i' - 'a'));
        ans = solve(checked, 0, K - 5);
    }
    printf("%d\n", ans);
    return 0;
}