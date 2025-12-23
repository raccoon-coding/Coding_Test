#include <iostream>
#include <vector>

using namespace std;

struct Node {
    vector<int> seq;  // 이 노드가 가지는 수열
    Node* left;
    Node* right;
    Node() : left(nullptr), right(nullptr) {}
};

Node* buildTree(int H, vector<int>& P, int depth) {
    Node* node = new Node();

    if (depth == H) {
        node->seq = P;  // 리프는 P 그대로
        return node;
    }

    node->left = buildTree(H, P, depth + 1);
    node->right = buildTree(H, P, depth + 1);

    // 규칙: 부모의 seq는 (왼쪽 seq + 오른쪽 seq)
    node->seq.reserve(node->left->seq.size() + node->right->seq.size());
    node->seq.insert(node->seq.end(), node->left->seq.begin(), node->left->seq.end());
    node->seq.insert(node->end(), node->right->seq.begin(), node->right->seq.end());

    return node;
}

int main() {
    int H = 4;
    vector<int> P = {2, 3, 1};

    Node* root = buildTree(H, P, 1);

    // 출력 (루트는 길이 24의 seq를 가짐)
    cout << "root size = " << root->seq.size() << endl;
}