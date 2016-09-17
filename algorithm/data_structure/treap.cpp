
typedef int key_type;

// 트립의 한 노드를 저장한다.
struct node{
    // 노드에 저장된 원소
    key_type key;
    // 이 노드의 우선 순위(priority)
    // 이 노드를 루트로 하는 서브 트리의 크기(size)
    int priority, size;
    // 두 자식 노드의 포인터
    Node* left;
    Node* right;

    // 생성자에서 난수 우선 순위를 생성하고, size와 left/ right를 초기화한다.
    Node(const key_type& _key) : key(_key), priority(rand()), size(1), left(NULL), right(NULL){}

    void set_left(node* new_left){left = new_left; calc_size();}
    void set_right(node* new_right){right = new_right; calc_size();}

    // size 멤버를 갱신한다.
    void calc_size(){
        szie = 1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
}

typedef pair< node*, node* > node_pair;

// root를 루트로 하는 트립을 key 미만과 이상의 가ㅄ을 갖는 두개의 트립으로 분리한다.
node_pair split(node* root, key_type key){
    if(root == NULL) return node_pair(NULL, NULL);
    // 루트가 key 미만이면 오른쪽 서브트리를 쪼갠다.
    if(root->key < key){
        node_pair rs = split(root->right, key);
        root->set_right(rs.first);
        return node_pair(root, rs.first);
    }

    node_pair ls = split(root->left, key);
    root->set_left(ls.second);
    return node_pair(ls.first, root);
}

// root를 루트로 하는 트립에 새 노드 node를 삽입한 뒤 결과 트립의 루트를 반환한다.
// 트립의 루트를 가리키는 포인터 root가 있을 때, 새 가ㅄ value를 다음과 같이 추가할 수 있다.
// root = insert(root, new node(value));
node* insert(node* root, node* node){
    if(root == NULL) return node;
    // node가 루트를 대체해야 한다. 해당 서브트리를 반으로 잘라 각각 자손으로 한다.
    if(root->priority < node->priority){
        node_pair splitted = split(root, node->key);
        node->set_left(splitted.first);
        node->set_right(splitted.second);
        return node;
    }
    else if(node->key < root->key){
        root->set_left(insert(root->left, node));
    }
    else{ // node->key > root->key
        root->set_right(insert(node->right, node));
    }
    return root;
}

// a와 b가 트립이고,  max(a) < min(b) 일 때, 이 둘을 합친다.
node* merge(node* a, node* b){
    if(a == NULL) return b;
    if(b == NULL) return a;
    if(a->priority < b->priority){
        b->set_left(merge(a, b->left));
        return b;
    }
    else{
        a->set_right(merge(a->right, b));
        return a;
    }
}

// root를 루트로 하는 트립에서 key를 지우고 결과 트립의 루트를 반환한다.
node* erase(node* root, key_type key){
    if(root == NULL) return root;
    // root를 지우고 양 서브트리를 합친 뒤 반환한다.
    if(root->key == key){
        node* ret = merge(root->left, root->right);
        delete root;
        return ret;
    }
    if(key < root->key)
        root->set_left(erase(root->left, key));
    else
        root->set_right(erase(root->right, key));
    return root;
}