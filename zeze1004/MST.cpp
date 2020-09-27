/*
1. 처음에는 자기 자신을 부모노드로 초기화
2. 노드의 가중치를 오름차순으로 sort
3. 가중치 적은 노드끼리 연결
    1. 같은 부모면 싸이클이 되니 
        부모를 먼저 찾음, find()
    2. 서로 다른 부모인지 판단하는 함수
    3. 서로 다른 부모일 시, 두 노드 연결 union()

*/

// 1. 부모를 찾는 find()
int findParent(int x) {   // 노드 x의 부모를 찾는 함수
    if(parent[x]==x) return x;
    else return parent[x] = findParent(parent[x]);    
    // x의 부모가 y면 find() 에서 y 도출
}

// 2. 서로 같은 부모인지 판단하는 함수
bool sameParent(int x, int y) {
    x = find(x);    //노드 x의 부모 찾기
    y = find(y);    // 노드 y의 보모 찾기
    if(x==y) 
        return true;
    else
        return false;
}

// 3. sameParent() true 값 나왔을 경우, 두 노드 합쳐주는 union 함수
void union(int x, int y) {
    x = findParent; // x 부모를 찾고
    y = findParent; // y 부모를 찾고
    if( x! = y ){   // 두 노드의 부모가 다르다면
        parent[y] = x;  // 어는 한 쪽 노드의 부모를 연결되는 다른 한쪽 노드로 설정
    }                   // 이 과정을 통해 노드 x,y의 부모가 x로 같아짐   
    // 같지 않으면 그냥 끝
}

    
}
