#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm> // max, min, sort, swap
#include <cmath> // abs

using namespace std;
typedef long long ll;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

// 0 <= N <= 50,0000, 이동하려는 채널
// 0 <= M <= 10, 망가진 버튼의 개수
int N, M; 
bool button_state[10];

// 채널 c로 이동이 가능한지 여부를 반환
// 불가능하면 0, 가능하면 채널의 길이를 리턴
int possible(int c){
    if(c == 0){
        return button_state[0] ? 0 : 1;
    }
    int len = 0;
    // c 채널에 속하는 수 중 부서진 버튼이 포함되어있는지의 여부 확인
    while(c > 0){        
        if(button_state[c % 10]) return 0;
        len++;
        c /= 10;
    }
    return len;
}

int main(){
    freopen("1107.txt", "r", stdin);
    scanf("%d", &N);
    scanf("%d", &M);
    for(int i = 0; i < M; i++){
        int button;
        scanf("%d", &button);
        button_state[button] = true;
    }
    // 현재 보고 있는 채널 : 100
    int ans = N - 100;
    if(ans < 0) ans = -ans;

    for(int i = 0; i <= 1000000; i++){
        int c = i;
        int len = possible(c);
        if(len > 0){
            int press = c - N;
            if(press < 0) press = -press;
            if(ans > len + press) ans = len + press;
        }
    }
    printf("%d\n", ans);
    
}