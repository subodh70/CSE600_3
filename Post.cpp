#include <iostream>

class QSTNode {
public:
    int key;
    QSTNode* left;
    QSTNode* second;
    QSTNode* third;
    QSTNode* right;

    QSTNode(int k) {
        key = k;
        left = nullptr;
        second = nullptr;
        third = nullptr;
        right = nullptr;
    }
};

class QuaternarySearchTree {
private:
    QSTNode* root;

public:
    QuaternarySearchTree() {
        root = nullptr;
    }

    void insert(int key) {
        root = insertRecursive(root, key);
    }

    QSTNode* insertRecursive(QSTNode* node, int key) {
        if (node == nullptr) {
            return new QSTNode(key);
        }

        if (key < node->key / 2) {
            node->left = insertRecursive(node->left, key);
        }
        else if (key >= node->key / 2 && key < node->key) {
            node->second = insertRecursive(node->second, key);
        }
        else if (key >= node->key && key < 2 * node->key) {
            node->third = insertRecursive(node->third, key);
        }
        else {
            node->right = insertRecursive(node->right, key);
        }

        return node;
    }

    void preorderTraversal(QSTNode* node) {
        if (node == nullptr) {
            return;
        }

        std::cout << node->key << " ";
        preorderTraversal(node->left);
        preorderTraversal(node->second);
        preorderTraversal(node->third);
        preorderTraversal(node->right);
    }

    void postorderTraversal(QSTNode* node) {
        if (node == nullptr) {
            return;
        }

        postorderTraversal(node->left);
        postorderTraversal(node->second);
        postorderTraversal(node->third);
        postorderTraversal(node->right);
        std::cout << node->key << " ";
    }

    void performPreorderTraversal() {
        std::cout << "Preorder traversal: ";
        preorderTraversal(root);
        std::cout << std::endl;
    }

    void performPostorderTraversal() {
        std::cout << "Postorder traversal: ";
        postorderTraversal(root);
        std::cout << std::endl;
    }
};

int main() {
    QuaternarySearchTree qst;
    int key;

    while (true) {
        std::cout << "Enter a value to insert (or -1 to exit): ";
        std::cin >> key;

        if (key == -1) {
            break;
        }

        qst.insert(key);
    }

    qst.performPreorderTraversal();
    qst.performPostorderTraversal();

    return 0;
}


