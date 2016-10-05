
// 짚더미 H의 부분 문자열로 바늘 N이 출현하는 시작 위치들을 모두 반환한다
vector<int> kmp_search(const string& H, const string& N){
    int n = H.size(), m = N.size();
    vector<int> ret;
    // pi[i] = N[..i] 의 접미사도 되고 접두사도 되는 문자열의 최대 길이
    vector<int> pi = get_partial_match(N);
    // begin = matched = 0 에서부터 시작하자
    int begin = 0, matched = 0;
    while(begin + m <= n){
        // 만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면
        if(matched < m && H[begin + matched] == N[matched]){
            matched++;
            // 결과적으로 m 글자가 모두 일치했다면 답에 추가한다
            if(matched == m)
                ret.push_back(begin);
        }
        else{
            // 예외 : matched가 0인 경우에는 다음 칸에서부터 계속
            if(matched == 0)
                begin++;
            else{
                begin += matched - pi[matched - 1];
                // begin을 옮겼다고 처음부터 다시 비교할 필요가 없다
                // 옮긴 후에도 pi[matched - 1] 만큼은 일치하기 때문이다
                matched = pi[matched - 1];
            }
        }
    }
    return ret;
}

// N에서 자기 자신을 찾으면서 나타내는 부분 일치를 이용해 pi[]를 계산한다
// pi[i] = N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이 
vector<int> get_partial_match(const string& N){
    int m = N.size();
    vector<int> pi(m, 0);
    // KMP로 자기 자신을 찾는다
    // N을 N에서 찾는다. begin = 0이면 자기 자신을 찾아버리니까 안됨!
    int begin = 1, matched = 0;
    while(begin + matched < m){
        if(N[begin + matched] == N[matched]){
            ++matched;
            pi[begin + matched - 1] = matched;
        }
        else{
            if(matched == 0)
                begin++;
            else{
                begin += matched - pi[matched - 1];
                matched = pi[matched - 1];
            }
        }
    }
    return pi;
}