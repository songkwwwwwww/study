/*
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
//#include <unordered_map> // c++11

#include <utility> // std::pair

#include <functional> // greater, less
#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;


const int MAX_L = 1000000;
char str[MAX_L + 1];
char buf[MAX_L + 1];
int main(){
    freopen("5397.txt", "r", stdin);
    int TC; scanf("%d", &TC);
    char c;
    while(TC--){
        scanf("%s", str);
        list<char> l;
        list<char>::iterator it = l.begin();
        int shift = 0, p = 0;
        for(int i = 0; str[i]; i++){
           c = str[i];

           if( ('A' <= c && c <='Z') || ('a' <= c && c <= 'z') ){
               if(shift == 0){
                   l.insert(it, c);
               }
               else{
                   list<char>::iterator temp = it;
                   int n_iter = (shift > 0 ? shift : -shift);
                   if(shift < 0){
                       n_iter = min(n_iter, l.size());
                       for(int i = 0; i < shift; i++)
                           temp--;
                       l.insert(temp, c);
                   }
                   else{ // shift > 0
                       for(int i = 0; i < shift; i++)
                           temp--;
                   }
                   shift = 0;
               }
           }
           else if(c == '-'){
               l.erase(it);
               //p--;
           }
           else if(c == '<'){
               shift--;
           }
           else if(c == '>'){
               shift++;
           }
        }
    }
}
*/