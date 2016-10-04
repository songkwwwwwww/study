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
int main(){
    freopen("11655.txt", "r", stdin);
    gets(str);

    for(int temp, i = 0; str[i]; i++){
        char& c = str[i];
        if('a' <= c && c <= 'z'){
            c = ((c - 'a' + 13) % 26 ) + 'a';        
        }
        else if( 'A' <= c && c <= 'Z'){
            c = ((c - 'A' + 13) % 26 ) + 'A';
        }
    }
    printf("%s\n", str);
}