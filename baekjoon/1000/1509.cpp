#include <cstdio>

const int MAX_N = 2500;
char str[MAX_N + 1];
// str[i, j] 가 팰린드롬인지
bool c[MAX_N + 1][MAX_N + 1];
// str[i] 까지의 팰린드롬 분할 개수의 최소값
int d[MAX_N + 1];

int main(){
    freopen("1509.txt", "r", stdin);
    //setbuf(stdout, NULL);
    scanf("%s", str);
    int N = 0;
    // 길이가 1인 경우
    for(int i = 0; str[i]; i++) {
        c[i][i] = true;
        N++;
    }
    
    // 길이가 2인 경우
    for(int i = 1; i < N; i++)
        if(str[i - 1] == str[i])
            c[i - 1][i] = true;
    
    // 길이가 3인 경우 ~
    for(int k = 3; k <= N; k++){
        for(int i = 0; i + k - 1 < N; i++){
            int j = i + k - 1;
            if(str[i] == str[j] && c[i + 1][j - 1])
                c[i][j] = true;
        }
    }
    d[0] = 0;
    for(int i = 1; i <= N; i++){
        d[i] = -1;
        for(int j = 1; j <= i; j++){
            if(c[j - 1][i - 1]){
                if(d[i] == -1 || d[i] > d[j - 1] + 1){
                    d[i] = d[j - 1] + 1;
                }
            }
        }
    }
    printf("%d\n", d[N]);
}