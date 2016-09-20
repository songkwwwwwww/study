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
#define PI 3.14159265

typedef long long ll;

typedef pair<int, int> pii;

typedef vector<int> vi;
typedef vector<vi> vvi;

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
int score[20] = { 6, 13, 4, 18, 1, 20, 5, 12, 9, 14, 11, 8, 16, 7, 19, 3, 17, 2, 15, 10 };
/*
// 360 / 40 = 9
int score[40] = { 9, 13, 13, 4, 4, 18, 18, 1, 1 // 9
        , 20, 20, 5, 5, 12, 12, 9, 9, 14, 14 // 10
        , 11, 11, 8, 8, 16, 16, 7, 7, 19, 19 // 10
        , 3, 3, 17, 17, 2, 2, 15, 15, 10, 10, 9}; // 11
*/
int main(){
    freopen("prob_id_4.txt", "r", stdin);
    setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    for(int tc = 1; tc <= TC; tc++){
        int b_e; // bull end
        int t_s, t_e; // triple start, end
        int d_s, d_e; // double start, end
        //scanf("%lf %lf %lf %lf %lf", &be, &t_s, &t_e, &d_s, &d_e);
        scanf("%d %d %d %d %d", &b_e, &t_s, &t_e, &d_s, &d_e);
        
        int N, total = 0;
        scanf("%d", &N);
        for(int i = 0; i < N; i++){
            int x, y, distance, current = 0;
            scanf("%d %d", &x, &y);
            distance = x * x + y * y;
            if(distance < b_e * b_e){
                current = 50;
            }
            else if(d_e * d_e < distance){
                current = 0;
            }
            else{
                int multiply = 1;
                // triple
                if(t_s * t_s < distance && distance < t_e * t_e){
                    multiply = 3;
                }
                // double
                else if(d_s * d_s < distance && distance < d_e * d_e){
                    multiply = 2;
                }
                double degree = atan2(y, x) * 180 / 3.14159265358979 + 9;
                if(degree < 0) degree += 360;
                //current = score[(int)(degree / 9)] * multiply;
                current = score[(int)(degree / 18)] * multiply;
                
            }
            total += current;
        }       
        printf("Case #%d\n%d\n", tc, total);
    }
}