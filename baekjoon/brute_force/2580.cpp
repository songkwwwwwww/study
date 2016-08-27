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

int a[10][10];
bool c[10][10];
bool c2[10][10];
bool c3[10][10];
int n=9;
int square(int x, int y) {
    return (x/3)*3+(y/3);
}
bool go(vector<int>& empty, int index) {
    if (index == empty.size()) {
        for (int i=0; i < n; i++) {
            for (int j=0; j < n; j++) {
                cout << a[i][j] << ' ';
            }
            cout << '\n';
        }
        return true;
    }
    int x = empty[index] / n;
    int y = empty[index] % n;
 
        for (int i=1; i<=9; i++) {
            if (c[x][i] == 0 && c2[y][i] == 0 && c3[square(x,y)][i]==0) {
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = true;
                a[x][y] = i;
                if (go(empty, index + 1)) {
                    return true;
                }
                a[x][y] = 0;
                c[x][i] = c2[y][i] = c3[square(x,y)][i] = false;
            }
        }
    
    return false;
}
int main() {
    freopen("2580.txt", "r", stdin);
    vector<int> empty;
    empty.reserve(20);
    
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> a[i][j];
            if (a[i][j] != 0) {
                c[i][a[i][j]] = true;
                c2[j][a[i][j]] = true;
                c3[square(i,j)][a[i][j]] = true;
            }
            else{
                empty.push_back(i * n + j);
            }
        }
    }
    go(empty, 0);
    return 0;
}

/*
const int N = 9;

int a[N][N];

bool check(int r, int c, int num){
    // check row
    for(int i = 0; i < N; i++){
        //if(i == c) continue;
        if(num == a[r][i]) return false;
    }

    // check col
    for(int i = 0; i < N; i++){
        //if(i == c) continue;
        if(num == a[i][c]) return false;
    }
    
    // check 3 x 3 square
    int square_index = (r / 3) * 3 + (c / 3);
    int square_x = square_index / 3;
    int square_y = square_index % 3;
    int x = square_x * 3;
    int y = square_y * 3;
    for(int i = x; i < x + 3; i++){
        for(int j = y; j < y + 3; j++){
            if(num == a[i][j]) return false;
        }
    }
    return true;
}

void print(){
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
void go(vector<int>& empty, int index){
    if(index == empty.size()) {
        print();
        exit(0);
    }
    else{
        int x = empty[index] / N;
        int y = empty[index] % N;
        for(int i = 1; i <= 9; i++){
            if(check(x, y, i)){
                a[x][y] = i;
                go(empty, index + 1);
            }
        }
    }   
}

int main(){
    freopen("2580.txt", "r", stdin);
    vector<int> empty;
    empty.reserve(20);
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            scanf("%d", &a[i][j]);
            if(a[i][j] == 0) empty.push_back(i * N + j);
        }
    }
    go(empty, 0);
}
*/