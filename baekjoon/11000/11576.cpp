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

/* 입력
입력의 첫 줄에는 미래세계에서 사용하는 진법 A와 정이가 사용하는 진법 B가 공백을 구분으로 주어진다. 
A와 B는 모두 2이상 30이하의 자연수다.

입력의 두 번째 줄에는 A진법으로 나타낸 숫자의 자리수의 개수 m(1 ≤ m ≤ 25)이 주어진다. 

세 번째 줄에는 A진법을 이루고 있는 숫자 m개가 공백을 구분으로 높은 자릿수부터 차례대로 주어진다. 
각 숫자는 0이상 A미만임이 보장된다. 또한 수가 0으로 시작하는 경우는 존재하지 않는다.

A진법으로 나타낸 수를 10진법으로 변환하였을 때의 값은 양의 정수이며 220보다 작다.

EX1)
17 8
2
2 16
*/

/* 출력
입력으로 주어진 A진법으로 나타낸 수를 B진법으로 변환하여 출력한다.

EX1)
6 2
*/

int a[25];

int main(){
    freopen("11576.txt", "r", stdin);
    int A, B; // 2 <= A, B <= 30
    scanf("%d %d", &A, &B);
    int m; // 1 <= m <= 25
    scanf("%d", &m);
    for(int i = 0; i < m; i++) scanf("%d", &a[i]);

    int decimal = 0;
    for(int i = 0; i < m; i++){
        decimal = 
    }        
}