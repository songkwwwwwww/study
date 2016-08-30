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
int main(){
    freopen("10820.txt", "r", stdin);
    char str[101], c;
    while(gets(str)){
        int lower = 0;
        int upper = 0;
        int digit = 0;
        int space = 0;
        for(int i = 0; str[i]; i++){
            c = str[i];
            if('a' <= c && c <= 'z')
                lower++;
            
            else if('A' <= c && c <= 'Z')
                upper++;
            
            else if('0' <= c && c <= '9')
                digit++;

            else if(c == ' ')
                space++;
        }
        printf("%d %d %d %d\n", lower, upper, digit, space);
    }
}