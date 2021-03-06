/*
참조 : 
    알고리즘 문제 해결 전략(종만북)
*/
/*
    탐색 방법 선택하기

문제에 따른 적절한 탐색 방법을 선택하려면 각 탐색 방법의 장단점을 이해하고 있어야 한다.
1. 상태 공간에서의 최단 경로를 찾는 경우, 너비 우선 탐색을 최우선적으로 고려한다.
    너비 우선 탐색은 직관적이고 구현하기도 간단하기 때문.
    탐색의 깊이 한계가 정해져 잇지 않거나 너무 깊어서 메모리 사용량이 너무 크지 않은지 확인
2. 상태 공간에서의 최단 경로를 찾는데, 탐색의 최대 깊이가 정해져 있고 너비 우선 탐색을 하기에는
    메모리와 시간이 부족할 경우 양방향 탐색을 고려한다.
    단 이 경우 목표 상태에서 역방향으로 움직이기가 쉬워야 한다.
3. 두 탐색이 모두 너무 메모리를 많이 사용하거나 너무 느린 경우,
    최적화를 할 거리가 더 많은 점점 깊어지는 탐색을 사용할 수밖에 없다.
*/