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

typedef pair<int, int> pii;
typedef pair<double, double> pdd;

typedef vector<int> vi;
typedef vector<vi> vvi;

typedef vector<double> vd;
typedef vector<vd> vvd;

typedef vector<long long> vl;
typedef vector<vl> vvl;

typedef vector<bool> vb;
typedef vector<vb> vvb;

typedef queue<int> qi;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

const int INF = 987654321;

/*

*/


const int MAX_N = 8;
const int MAX_M = 8;

void swap(char* a, char* b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

void my_reverse(char* str){
    char* end = str;
    if(str){
        while(*end)
            end++;
        end--;

        while(str < end){
            swap(str, end);
            str++;
            end--;
        }
    }
}

int main(){
    //freopen(".txt", "r", stdin);
    //setbuf(stdout, NULL);
    char s[2][100] = {
        {"Hello world!"},
        {"song ki won"},
    };
    printf("before\n");
    for(int i = 0; i < 2; i++)
        printf("%s\n", s[i]);
    
    for(int i = 0; i < 2; i++)
        my_reverse(s[i]);

    printf("after\n");
    for(int i = 0; i < 2; i++)
        printf("%s\n", s[i]);
}