#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;
typedef long long ll;

// N : 아이들의 수, M : 놀이 기구의 수
// 1 <= N <= 20,0000,0000
// 1 <= M <= 1,0000
int N, M;

int a[10000];

int main(){
    freopen("1561.txt", "r", stdin);
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++) scanf("%d", &a[i]);

    ll l = 0, r = 2000000000LL * 10000LL, m;
    ll begin, end;
    while(l <= r){
        m = (l + r) / 2;
        end = M;
        // mid 분까지 탄 학생의 수는 몇 명인가?
        for(int i = 0; i < M; i++){
            end += m/a[i];
        }
        begin = end;
        for (int i = 0; i < M; i++) {
            if (m % a[i] == 0) { // mid 분에 a[i] 놀이기구에 새로 탑승했다면
                begin -= 1; // 뺀다.
            }
        }
        // mid 분 이전까지는 begin 명이었으나
        // mid 분에 탑승한 인원을 포함하면 end 명이 된다.
        // mid 분에 빈 놀이 기구 중 첫 번째 사람이 들어간다.
        begin++;
        if(N < begin) // N 번째 사람은 mid분 이전에 탑승했다.
            r = m - 1;
        else if (N > end) // N 번째 사람은 mid분 이후에 탑승했다.
            l = m + 1;
        else{ // N 번째 사람은 mid 분에 탑승했다.
            // 그럼 몇 번째 놀이기구에 탔는가?
            for(int i = 0; i < M; i++) {
                if(m % a[i] == 0){ // mid 분에 i 번째 놀이기구가 비었다면
                    
                    if( N == begin){
                        printf("%d\n", i + 1);
                        return 0;
                    }
                    else
                        begin++;

                } // end if
            } // end if
        } // end else
    }// end while
}