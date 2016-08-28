
// recursive-find
int Find(int x){
	if(x == p[x]){ // x == parent[x]
		return x;
	}
	else{
		return p[x] = find(p[x]);
	}
}

int Union(int x, int y){
	x = Find(x);
	y = Find(y);
	p[y] = x;
}
