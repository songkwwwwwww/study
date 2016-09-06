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
#include <utility> // std::pair

#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;


/*
문제
kriii는 1부터 N까지의 수로 이루어진 순열을 파일로 저장해 놓았다. 
모든 숫자는 10진수로 이루어져 있고, 모두 공백으로 분리되어 있다.

그런데 sujin이 그 파일의 모든 공백을 지워버렸다!

kriii가 순열을 복구하도록 도와주자.

입력
첫 줄에 공백이 사라진 kriii의 수열이 주어진다.

kriii의 수열은 최소 1개 최대 50개의 숫자로 이루어져 있다.

출력
복구된 수열을 출력한다. 공백을 잊으면 안된다.

복구한 수열의 경우가 여러가지 일 경우, 그 중 하나를 출력한다.
*/
const int MAX = 50;

char cstr[200];
bool flag = false;
bool used[51];

int solve(string& str, string ans, int index){
    // base case;
    // 1    
    if(flag) return 0;
    // 2
    if(index == str.size()){
        printf("%s\n", ans.c_str() + 1);
        flag = true;
        return 0;
    }
    // 3
    if(str[index] == '0') return 0;

    char cur = str[index];
    int n1 = str[index] - '0';
    if(!used[n1]){
        used[n1] = true;
        solve(str, ans + " " + cur, index + 1);
        used[n1] = false;
    }

    if(index < str.size() - 1){
        int n2 = n1 * 10 + (str[index + 1] - '0');
        if(n2 <= MAX && !used[n2]){
            used[n2] = true;
            solve(str, ans + " " + cur + str[index + 1], index + 2);
            used[n2] = false;
        }
    }
    return 0;
}

int main(){
    freopen("10597.txt", "r", stdin);
    scanf("%s", cstr);
    string str(cstr);
    string ans = "";
    solve(str, ans, 0);
}