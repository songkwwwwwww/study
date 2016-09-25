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
입력
첫째 줄에 파일 이름의 개수 N이 주어진다. 
둘째 줄부터 N개의 줄에는 파일 이름이 주어진다. 
N은 50보다 작거나 같은 자연수이고 파일 이름의 길이는 모두 같고 길이는 최대 50이다. 
파일이름은 알파벳과 "." 그리고 "?"로만 이루어져 있다.

출력
첫째줄에 패턴을 출력하면 된다.
*/


const int MAX_N = 50;

int main(){
    freopen("1032.txt", "r", stdin);
    //setbuf(stdout, NULL);
    int N;
    char str[MAX_N + 1];

    scanf("%d", &N);
    string s[N];
    for(int i = 0; i < N; i++){
        scanf("%s", str);
        s[i] = string(str);
    }
    /*for(int i = 0; i < N; i++){
        cout << s[i] << endl;
    }*/
    int i;
    for(i = 0; i < s[0].length(); i++){
        char cur = s[0][i];
        bool flag = true;
        for(int j = 1; j < N; j++){
            if(cur != s[j][i]){
                flag = false;
                break;
            }
        }
        if(flag){
            str[i] = cur;
        }
        else{
            str[i] = '?';
        }
    }
    str[i] = '\0';
    printf("%s\n", str);
}