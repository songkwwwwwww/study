


// 프로그래밍 콘테스트 챌린지, 216p

struct segment_tree{
    // Range Minimum Query(RMQ)
    int MAX_N;
    // 세그먼트 트리를 가진 전역 변수
    int n;
    std::vector<int> data;

    segment_tree(){
        MAX_N = 1 << 17;
        data = std::vector<int>(2 * MAX_N - 1);
    }

    // 초기화
    void init(int n_){
        // 간단하게 하기 위해서, 요소 수를 2의 멱승으로
        n = 1;
        while(n < n_)
            n *= 2;
        
        // 모든 값을 INT_MAX에
        for(int i = 0; i < 2 * n - 1; i++)
            data[i] = INF;
    }

    // k 번째 값(0-indexed)을 a로 변경
    void update(int k, int a){
        // 노드의 절점
        k += n - 1;
        data[k] = a;
        // 올라가면서 갱신
        while(k > 0){
            k = (k - 1) / 2;
            data[k] = min(data[k * 2 + 1], data[k * 2 + 2]);
        }
    }

    // [a, b]의 최소 값을 구한다
    // 뒤 쪽의 인수는, 계산을 간단하게 하기 위한 인수
    // k는 노드의 번호, l, r,은 그 노드가 [l, r]에 대응하고 있다는 것을 나타낸다.
    // 따라서 외부에서는 query(a, b, 0, 0, n)을 호출한다.
    int query(int a, int b, int k, int l, int r){
        // [a, b]와 [l, r]이 교차하지 않는다면, INT_MAX
        if(r <= a || b <= l) return INF;
        // [a, b]이 [l, r]을 완전히 포함하고 있다면, 이 노드의 값
        if(a <= l && r <= b) return data[k];
        else{
            // 그렇지 않다면 2개 자식의 최소 값
            int vl = query(a, b, k * 2 + 1, l, (l + r) / 2);
            int vr = query(a, b, k * 2 + 2, (l + r) / 2, r);
            return min(vl, vr);        
        }
    }
};
