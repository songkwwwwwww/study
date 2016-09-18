
// recursive-find
int Find(int x){
	if(x == p[x]){ // x == parent[x]
		return x;
	}
	else{
		return p[x] = Find(p[x]);
	}
}

int Union(int x, int y){
	x = Find(x);
	y = Find(y);
	p[y] = x;
}


/*
	CS 97SI Stanford University

*/
int find(vector<int> &C, int x) { 
	return (C[x] == x) ? x : C[x] = find(C, C[x]); 
}
void merge(vector<int> &C, int x, int y) { 
	C[find(C, x)] = find(C, y); 
}



/*
	kks227

*/

int find(int n){
	if(p[n] < 0) return n;
	else return p[n] = find(p[n]);
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	p[b] = a;
}

void merge(int a, int b){
	a = find(a);
	b = find(b);
	if(a == b) return;
	p[a] += p[b];
	p[b] = a;
}

