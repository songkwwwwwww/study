

// factorials[i] = i;
int factorials[12];

/*

*/
int get_indeex(const vector<int>& X){
	int ret = 0;
	for(int i = 0; i < X.size(); i++){
		int less = 0;
		// find # of value less than X[i]
		for(int j = i + 1; j < X.size(); j++)
			if(X[j] < X[i])
				less++;
		
		ret += factorials[X.size() - 1 - i] * less;
	}
	return ret;
}

