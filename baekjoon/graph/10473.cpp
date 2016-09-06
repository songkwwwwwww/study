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

#include <functional> // greater, less
#include <limits> // std::numeric_limits<double>::max()

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

const int INF = 987654321;
const int MAX_V = 20000;

const int dx[4] = {0, 0, 1, -1}; // E W S N;
const int dy[4] = {1, -1, 0, 0}; // E W S N;

/*
입력
입력은 한 개의 길찾기 문제를 표현한다. 
첫 줄에는 두 개의 실수가 입력되며 각각은 당신이 현재 위치한 X, Y좌표이다. 
두 번째 줄에는 목적지의 X, Y좌표가 실수로 입력된다. 이어지는 줄에는 대포의 숫자 정수 n이 주어진다. 
남은 n줄에는 한 줄에 대포 하나의 위치 정보가 주어지며, 이는 실수로 주어지는 X, Y 좌표이다. 
모든 좌표는 미터로 측정되었으며 n의 값은 0 이상 100 이하이다.

출력
한 줄에 걸쳐 목적지에 다다르기 위해 가장 빠른 시간을 출력하라. 실제 답과 0.001초 미만의 차이는 정답으로 인정한다.
*/

class Point{
    double x, y;

public:
    Point(){}
    Point(int nx, int ny):x(nx), y(ny) {}
};

double SX, SY, EX, EY;
int N;

vector< pair<double, double> > po

double get_distance(Point a, Point b){
    return sqrt( ((a.x - b.x) * (a.x - b.x)) + ( (a.y - b.y) * (a.y - b.y) ) );
}

int main(){
    freopen("10473.txt", "r", stdin);

}