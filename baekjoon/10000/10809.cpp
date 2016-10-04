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

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

/*

*/
char str[101];
int alpha[26];
int main(){
    freopen("10809.txt", "r", stdin);
    scanf("%s", str);
    memset(alpha, -1, sizeof(alpha));
    for(int i = 0; str[i]; i++){
        int pos = str[i] - 'a';
        if(alpha[pos] == -1)
            alpha[pos] = i;
    }
    for(int i = 0; i < 26; i++)
        printf("%d ", alpha[i]);
    printf("\n");
}