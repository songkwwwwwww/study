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

*/
char S[1002];
int d[1001][1001];
int main(){
    freopen("1254.txt", "r", stdin);
    scanf("%s", S + 1);
    int n;
    for(n = 0; S[n + 1]; n++);

    for(int t = 2; t <= n; t++){
        for(int i = 1, j = t; j <= n; i++, j++){
            if(S[i] == S[j])
                d[i][j] = d[i+1][j-1];
            else // S[i] != S[j]
                d[i][j] = 1 + MIN(d[i+1][j], d[i][j-1]);
        }
    }
    printf("%d\n", n + d[1][n]);
}

/*
char S[1002];
char rS[1002];
int d[1001][1001];
int main(){
    freopen("1254.txt", "r", stdin);
    scanf("%s", S);
    int len = 0;
    //printf("%d\n", n + d[1][n]);
    for(len = 0; S[len]; len++);
    for(int i = 1; i <= len; i++)
        rS[i-1] = S[len - i];
    rS[len] = '\0';
    
    for(int i = 1; i <= len; i++){
        for(int j = 1; j <= len; j++){
            if(S[i - 1] == rS[j - 1]){
                d[i][j] = d[i - 1][j - 1] + 1;
            }
            else{
                d[i][j] = MAX(d[i-1][j], d[i][j - 1]);
            }
        }
    }
    int lcs =  d[len][len];

    //printf("%d\n", d[len][len]);
    printf("%d\n", 2 * len - lcs);
}
*/