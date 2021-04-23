class Solution {
public:
    
    int min(int l, int r) {
        return l < r ? r : l;
    }
    
    int minDistance(string word1, string word2) {
        vector < vector <int> > dp(word1.size() + 3,vector <int>(word2.size() + 3, 0));
        int l = word1.size();
        int r = word2.size();
        for (int i = 1; i <= l; i++) {
            dp[i][0] = i;
        }
        
        for (int j = 1; j <= r; j++) {
            dp[0][j] = j;
        }
        
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= r; j++) {
                int m = std::min(dp[i - 1][j], dp[i][j - 1]) + 1;
                int n = dp[i - 1][j - 1] + (word1[i - 1] == word2[j - 1]  ? 0 : 1);
                dp[i][j] = std::min(m, n);
            }
        }
        return dp[l][r];
    }
};
