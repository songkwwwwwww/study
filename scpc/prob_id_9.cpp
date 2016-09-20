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
const int MOD = 1000000007;

/*

*/

char table[114][3] = {  
        "H", "He", "Li", "Be", "B", "C", "N", "O", "F", "Ne", 
        "Na", "Mg", "Al", "Si", "P", "S", "Cl", "Ar", "K", "Ca", 
        "Sc", "Ti", "V", "Cr", "Mn", "Fe","Co", "Ni", "Cu", "Zn", 
        "Ga", "Ge", "As", "Se", "Br", "Kr", "Rb", "Sr", "Y","Zr", 
        "Nb", "Mo", "Tc", "Ru", "Rh", "Pd", "Ag", "Cd", "In", "Sn", 
        "Sb", "Te", "I", "Xe", "Cs", "Ba", "Hf", "Ta", "W", "Re", 
        "Os", "Ir", "Pt", "Au", "Hg", "Tl", "Pb", "Bi", "Po", "At", 
        "Rn", "Fr", "Ra", "Rf", "Db", "Sg", "Bh", "Hs", "Mt", "Ds", 
        "Rg", "Cn", "Fl", "Lv", "La", "Ce", "Pr", "Nd", "Pm", "Sm", 
        "Eu", "Gd", "Tb", "Dy", "Ho", "Er", "Tm", "Yb", "Lu", "Ac",
        "Th", "Pa", "U", "Np", "Pu", "Am", "Cm", "Bk", "Cf", "Es", 
        "Fm", "Md",  "No", "Lr"};

bool check_one[26], check_two[26][26];

const int MAX_N = 50000;
char str[MAX_N + 2];
int d[3];

int solve(){
    int i;
    d[0] = 1;
    for(i = 1; str[i]; i++){
        d[i % 3] = 0;
        if(str[i] < 97) str[i] += 32;

        if(check_one[str[i] - 97]) 
            d[i % 3] |= d[(i - 1) % 3];

        if(str[i - 1] != 0 && check_two[str[i - 1] - 97][str[i] - 97]) 
            d[i % 3] |= d[(i - 2) % 3];
            
        //if(d[i] == 0) return 0;
    }
    if(d[(i - 1) % 3]) return 1;
    else return 0;
    //return 1;
}

void make_check_table();

int main(){
    freopen("prob_id_9.txt", "r", stdin);
    setbuf(stdout, NULL);
    int TC; scanf("%d", &TC);
    make_check_table();
    
    for(int tc = 1; tc <= TC; tc++){
        scanf("%s", str + 1);
        
        if(solve() == 1) printf("Case #%d\nYES\n", tc);
        else printf("Case #%d\nNO\n", tc);
    }
}



// A = 65, a = 97
void make_check_table(){
    for(int i = 0; i < 114; i++){
        // 한 글자
        if(table[i][1] == '\0'){
            // 대문자면 소문자로
            if(table[i][0] < 97) table[i][0] += 32;
            check_one[table[i][0] - 97] = true;
        }
        // 두 글자
        else{
            // 대문자면 소문자로
            if(table[i][0] < 97) table[i][0] += 32;
            if(table[i][1] < 97) table[i][1] += 32;            
            check_two[table[i][0] - 97][table[i][1] - 97] = true;
        }
    }
}