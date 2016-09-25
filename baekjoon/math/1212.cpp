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
8진수가 주어졌을 때, 2진수로 변환하는 프로그램을 작성하시오.

입력
첫째 줄에 8진수가 주어진다. 주어지는 수의 길이는 333,334을 넘지 않는다.

출력
첫째 줄에 주어진 수를 2진수로 변환하여 출력한다. 수가 0인 경우를 제외하고는 반드시 1로 시작해야 한다.
*/


const int MAX_N = 333334;

int main(){
    freopen("1212.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int n, p = 0;
    char str[MAX_N + 1];
    char result[MAX_N * 3 + 1];    
    scanf("%s", str);
    if(str[0] == 0){
        printf("0\n");
        return 0;
    }
    for(int i = 0; str[i]; i++){
        n = str[i] - '0';
        result[p] = n & (1 << 2) ? '1' : '0';
        result[p + 1] = n & (1 << 1) ? '1' : '0';
        result[p + 2] = n & 1 ? '1' : '0';
        p += 3;
    }
    result[p] = '\0';
    p = 0;
    while(result[p] != '1'){
        p++;
    }
    printf("%s\n", result + p);
}