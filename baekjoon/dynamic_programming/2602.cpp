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

/*
입력
첫째 줄에는 마법의 두루마리에 적힌 문자열(R, I, N, G, S 로만 구성된)이 주어진다. 
이 문자열의 길이는 최소 1, 최대 20 이다. 
그 다음 줄에는 각각 <악마의 돌다리>와 <천사의 돌다리>를 나타내는 같은 길이의 문자열이 주어진다. 
그 길이는 1 이상, 100 이하이다.

출력
마법의 두루마리에 적힌 문자열의 순서대로 다리를 건너갈 수 있는 방법의 수를 출력한다. 
그러한 방법이 없으면 0을 출력한다.

모든 테스트 데이터에 대한 출력결과는 2^31 - 1 이하이다.
*/

char str[22];
char a[2][102];
int d[2][120][30];


/*
현재 위치는 dol_type과 dol_index 이고
밟아야 할 문자가 str[index] 일 때의 경우의 수
*/
int solve(int dol_type, int dol_index, int str_index){
    // base case;
    if(str[str_index] == '\0') return 1;

    int& ret = d[dol_type][dol_index][str_index];
    if(ret != -1) return ret;

    ret = 0;
    for(int i = dol_index; a[1 - dol_type][i] != '\0'; i++){
        if(a[1 - dol_type][i] == str[str_index])
            ret += solve(1 - dol_type, i + 1, str_index + 1); 
    }
    return ret;
}

int main(){
    freopen("2602.txt", "r", stdin);
    scanf("%s", str);
    scanf("%s", a[0]);
    scanf("%s", a[1]);
    memset(d, -1, sizeof(d));
    printf("%d\n", solve(0, 0, 0) + solve(1, 0, 0));
}