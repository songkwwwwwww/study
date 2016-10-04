#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list

#include <map>
#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

// 일반 문자열 str, 1 <= |str| <= 100,0000
// 폭발 문자열 boom, 1 <= |boom| <= 36
// 두 문자는 모두 알파벳 소문자와 대문자, 숫자 0, 1, ... , 9 로만 이루어져 있다.
char str[1000001], boom[37], result[1000001];


/*
참조 :
https://www.acmicpc.net/source/2426222 
작성자 :
cubelover
*/
int main(){
    freopen("9935.txt", "r", stdin);
    scanf("%s %s", str, boom);
    int n = strlen(boom);
    int i, j, m=0;
    for(i = 0; str[i]; i++){
        result[m++] = str[i];
        if(m >= n){
            for(j = 0; j < n; j++) if(result[m - n + j] != boom[j]) break;
            if(j == n) m -= n;
        } 
    }
    result[m] = '\0';
    if(m == 0)
        cout << "FRULA" << endl;
    else
        cout << result << endl; 
}