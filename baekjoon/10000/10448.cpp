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

/*
Tn = 1 + 2 + 3 + ... + n = n(n+1)/2

처리과정
 1. 모든 삼각수를 구한다.
 2. 삼각수로 만들수 있는 값을 해당 배열에 저장한다.
 3. 숫자를 입력받는다.
 4. 해당 숫자 인덱스에 값을 출력한다.
 5. 끝낸다.
*/
int T[46];
int isTrue[1000];
int main(){
    freopen("10448.txt", "r", stdin);
    for(int i = 1; i < 46; i++)
        T[i] = (i * (i + 1)) / 2;
    int n;
    for(int i = 1; i < 46;i++){
        for(int j = 1; j < 46 ; j++){
            for(int k = 1; k < 46; k++){
                n = T[i] + T[j] + T[k];
                if(n <= 1000)
                    isTrue[n] = 1;
            }
        }
    }
    int TC;
    scanf("%d",&TC);
    for(int tc = 1; tc <= TC; tc++){
        scanf("%d", &n);
        printf("%d\n", isTrue[n]);
    }
}