#include <iostream>
#include <vector>
#include <algorithm> // std::max, std::min, std::sort, std::swap
#include <string> // std::string, std::stoi
#include <queue> // std::queue
#include <deque> // std::deque
#include <list> // std::list
#include <set>
#include <map>

#include <utility> // std::pair

#include <cstdio>
#include <cstring> // memset
#include <cmath> // std::abs

using namespace std;

#define MAX(x, y) ((x) > (y) ? (x) : (y))
#define MIN(x, y) ((x) < (y) ? (x) : (y))

typedef long long ll;

struct Node{
    int val;
    Node* left;
    Node* right;
    Node(){
        val = 0;
        left = NULL;
        right = NULL;
    }
    Node(int v){
        val = v;
        left = NULL;
        right = NULL;
    }
};

string preorder(Node* root){
    string ans = "";
    ans += "V";
    if(root->left){
        ans += "L";
        ans += preorder(root->left);
        ans += "l";
    }
    if(root->right){
        ans += "R";
        ans += preorder(root->right);
        ans += "r";
    }
    ans += "v";
    return ans;
    
}

void remove(Node* root){
    if(root->left)
        remove(root->left);
    if(root->right)
        remove(root->right);
    delete root;
}

int main(){
    freopen("12767.txt", "r", stdin);
    // (1 <= n <= 50), (1 <= k <= 20)
    int n, k;
    scanf("%d %d", &n, &k);
    set<string> s;
    for(int i = 0; i < n; i++){
        vector<int> a(k);
        for(int j = 0; j < k; j++) cin >> a[j];

        Node* root = new Node;
        root->val = a[0];

        for(int j = 1; j < k; j++){
            Node* cur = root;
            while(true){
                if(cur->val > a[j]){ // left
                    if(cur->left == NULL){
                        cur->left = new Node(a[j]);
                        //cur->left = new Node;
                        //cur->left->val = a[i];
                        break;
                    }
                    else{
                        cur = cur->left;
                    }
                }
                else if(cur->val < a[j]){ // right
                    if(cur->right == NULL){
                        cur->right = new Node(a[j]);
                        //cur->right = new Node;
                        //cur->right->val = a[i];
                        break;
                    }
                    else{
                        cur = cur->right;
                    }
                }
                else{
                    break;
                }
            }
        }
        s.insert(preorder(root));
        remove(root);
    }
    cout << s.size() << '\n';

}
