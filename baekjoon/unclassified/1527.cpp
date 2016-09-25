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
은민이는 4와 7을 좋아하고, 나머지 숫자는 싫어한다. 금민수는 어떤 수가 4와 7로만 이루어진 수를 말한다.

A와 B가 주어졌을 때, A보다 크거나 같고, B보다 작거나 같은 자연수 중에 금민수인 것의 개수를 출력하는 프로그램을 작성하시오.

입력
첫째 줄에 A와 B가 주어진다. A는 1보다 크거나 같고, 1,000,000,000보다 작거나 같은 자연수이다. 
B는 A보다 크거나 같고, 1,000,000,000보다 작거나 같은 자연수이다.

출력
첫째 줄에 A보다 크거나 같고, B보다 작거나 같은 자연수 중에 금민수인 것의 개수를 출력한다.
*/


const int MAX_N = 1000000;

int main(){
    freopen("1527.txt", "r", stdin);
    //setbuf(stdout, NULL);
    ll A, B;
    scanf("%lld %lld", &A, &B);
    qi q;
    q.push(4); q.push(7);
    int count = 0;
    while(!q.empty()){
        ll here = q.front(); q.pop();
        if(here * 10 + 4 <= B)
            q.push(here * 10 + 4);
        if(here * 10 + 7 <= B)
            q.push(here * 10 + 7);
        if(A <= here && here <= B) count++;
    }
    printf("%d\n", count);
}