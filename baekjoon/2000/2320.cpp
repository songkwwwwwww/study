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
백승환와 이석원은 한 팀이 되어 English 끝말대회에 출전했다. 
앞단어의 마지막 글자가 뒷단어의 처음 글자와 같도록 단어를 차례대로 늘어놓는 게임 말이다. 
단어는 주어지는 사전에 나와 있는 단어만 사용해야 하며 (영혼이 맑아질 만한 사실을 한 가지 가르쳐 주자면) 
사전의 단어들은 모두 모음(A, E, I, O, U)으로만 이루어져있다는 것이다. 
단어의 시작은 어떤 단어이든지 상관이 없고 같은 단어가 두 번 이상 사용되며 안 되며 게임에 사용된 단어의 길이의 합이 그 팀의 점수가 된다.

점수가 최대가 되도록 끝말잇기 규칙에 맞게 단어를 늘어놓는 프로그램을 만들어 승환이와 석원이를 도와주도록 하자.

입력
첫 줄에 사전에 포함된 단어 개수 N이 입력된다. (N ≤ 16)
  두 번째 줄부터 N+1번째 줄까지 사전에 포함된 단어들이 한 줄에 하나씩 입력된다. 단어는 대문자 A, E, I, O, U로만 이루어져 있고 하나의 단어는 그 길이가 100을 넘지 않는다.

출력
한 줄에 단어를 잘 늘어 놨을 때 얻을 수 있는 최대 점수를 출력한다.
*/


const int MAX_N = 16;
const int MAX_LEN = 100;
int N;
string words[MAX_N];

//int d[MAX_N][1 << MAX_N];
//vi d;
vvi d;
int solve(int index, int state){
    // base case
    if(state == (1 << N) - 1) return 0;

    int& ret = d[index][state];
    if(ret != -1) return ret;

    int len = words[index].length();
    ret = 0;
    for(int i = 0; i < N; i++){
        if( !(state & (1 << i) ) &&  words[index][len-1] == words[i][0]){
            ret = max(ret, solve(i, state | (1 << i)) + (int)words[i].length() );
        }
    }
    return ret;
}

int main(){
    freopen("2320.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%d", &N);
    d = vvi(N, vi(1 << N, -1)); 
    //d = vi(N, -1);
    char str[MAX_LEN + 1];
    for(int i = 0; i < N; i++){
        scanf("%s", str);
        words[i] = string(str);    
    }
    int result = 0;
    for(int i = 0; i < N; i++){
        result = max(result, solve(i, 1 << i) + (int)words[i].length());
        //fill(d.begin(), d.end(), -1);
    }
    printf("%d\n", result);
}