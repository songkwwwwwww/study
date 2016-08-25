#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm> // max, min, sort
#include <cmath> // abs

using namespace std;
typedef long long ll;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

char command[10];

int main(){
    freopen("11723.txt", "r", stdin);
    int TC, x, s;
    scanf("%d", &TC);
    for(int tc = 0; tc < TC; tc++){
        scanf("%s", command);
        if(!strcmp(command, "add")){
            scanf("%d", &x); x--;
            s = (s | (1 << x));
        }
        else if(!strcmp(command, "remove")){
            scanf("%d", &x); x--;
            s = (s & ~(1 << x));
        }
        else if(!strcmp(command, "check")){
            scanf("%d", &x); x--;
            int res = (s & (1 << x));
            if(res) printf("1\n");
            else printf("0\n");
        }
        else if(!strcmp(command, "toggle")){
            scanf("%d", &x); x--;
            s = (s ^ (1 << x));
        }
        else if(!strcmp(command, "all")){
            s = (1 << 20) - 1;
        }
        else if(!strcmp(command, "empty")){
            s = 0;
        }
    }
}