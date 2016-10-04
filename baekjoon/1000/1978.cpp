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
int a[100];
bool is_prime[1001];
int main(){
    freopen("1978.txt", "r", stdin);
    int N; scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &a[i]);
    
    memset(is_prime, true, sizeof(is_prime));
    
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i <= 1000; i++)
        if(is_prime[i] == true)
            for(int j = i * 2; j <= 1000; j += i)
                is_prime[j] = false;
        
    
    int count = 0;
    for(int i = 0; i < N; i++){
        if(is_prime[a[i]] == true)
            count++;
    }
    printf("%d\n", count);
}