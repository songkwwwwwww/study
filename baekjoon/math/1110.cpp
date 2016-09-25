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
0보다 크거나 같고, 99보다 작거나 같은 정수를 두 자리로 쓴 후(10보다 작은 자연수는 앞에 0을 붙임)에 로 시작한다. 
두 자리수를 더한다. 
그럼, 처음 숫자의 가장 오른쪽 자리수와 앞에서 구한 합의 가장 오른쪽 자리수를 이어 붙이면 새로운 숫자를 만들 수 있다. 
이것을 계속 하다 보면, 원래 숫자를 얻을 수 있다. 다음 예를 보자.

26부터 시작한다. 2+6 = 8이다. 새로운 숫자는 68이다. 6+8 = 14이다. 새로운 숫자는 84이다. 8+4 = 12이다. 새로운 숫자는 42이다. 4+2 = 6이다. 새로운 숫자는 26이다.

위의 예는 4번만에 원래 숫자로 돌아올 수 있다. 따라서 26의 사이클의 길이는 4이다.

N이 주어졌을 때, N의 사이클의 길이를 구하는 프로그램을 작성하시오.

입력
첫째 줄에 N이 주어진다. N은 0보다 크거나 같고, 99보다 작거나 같은 정수이다.

출력
첫째 줄에 N의 사이클 길이를 출력한다.
*/


const int MAX_N = 99;


int main(){
    freopen("1110.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    scanf("%d", &N);
    int count = 0, prev, new_val = N;
    while(true){
        prev = new_val; // 26
        int a = prev / 10; // 2
        int b = prev % 10; // 6
        new_val = ((prev % 10) * 10) + ((a + b) % 10);
        count++;
        if(new_val == N) break;
    }
    printf("%d\n", count);
}