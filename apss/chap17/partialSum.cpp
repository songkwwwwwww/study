



vector<int> partialSum(const vector<int>& a){
	vector<int> ret(a.size());
	ret[0] = a[0];
	for(int i = 1; i < a.size(); ++i)
		ret[i] = ret[i - 1] + a[i];
	
	return ret;
}

int rangeSum(const vector<int>& psum, int a, int b){
	if(a == 0) return psum[b];
	return psum[b] - psum[a - 1];
}

double variance(const vector<int>& spqsum, const vector<int>& psum, int a, int b){
	double mean = rangeSum(psum, a, b) / double(b - a + 1);
	double ret = rangeSum(sqpsum, a, b) - 2 * mean * rangeSum(psum, a, b) + (b - a + 1) * mean * mean
	return ret / (b - a + 1);

}

int gridSum(const vector<vector<int>>& psum, int y1, int x1, int y2, int x2){
	int ret = psum[y2][x2];
	if(y1 > 0) ret -= psum[y1-1][x2];
	if(x1 > 0) ret -= psum[y2][x1-1];
	if(y1 > 0 && x1 > 0) ret += psum[y1-1][x1-1];
	return ret;
}
