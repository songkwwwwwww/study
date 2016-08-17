/*

	http://www.codeforces.com/problemset/problem/698/A

*/

#include <cstdio>

int MAX(int a, int b){
	return a > b ? a : b;
}

int days[101];
int d[101][3];

int main(){
	//freopen("699C.txt", "r", stdin);
	int n, max, today, temp; // 1 <= n <= 100
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &days[i]);
	
	for(int i = 1; i <= n; i++){
		today = days[i];
		temp = d[i-1][0] > d[i-1][1] ? d[i-1][0] : d[i-1][1];
		d[i][0] = temp > d[i-1][2] ? temp : d[i-1][2];


		if(today == 0){
			d[i][1] = d[i-1][1]; 
			d[i][2] = d[i-1][2];
		}
		else if(today == 1){ // The gym is closed and the contest is carried out
			d[i][1] = MAX(d[i-1][0] + 1, d[i-1][2] + 1);
			d[i][2] = d[i-1][2];	
		}

		else if(today == 2){ // The gym is open and the contest is not carried out
			d[i][1] = d[i-1][1]; 
			d[i][2] = MAX(d[i-1][0] + 1, d[i-1][1] + 1);
		}
		// is the gym open
		else { // today == 4, The gym is open and the contest is carried out
			d[i][1] = MAX(d[i-1][0] + 1, d[i-1][2] + 1);
			d[i][2] = MAX(d[i-1][0] + 1, d[i-1][1] + 1);
		}
	}
	
	temp = d[n][0] > d[n][1] ? d[n][0] : d[n][1];
	max = temp > d[n][2] ? temp : d[n][2];
	printf("%d\n", n - max);	

}
