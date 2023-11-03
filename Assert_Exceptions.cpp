#include <iostream>
#include <cassert>
#include <set>

using namespace std;

class DuplicateValueException : public exception {
public:
    const char* what() const noexcept {
        return "Duplicate value. Please insert a unique value.";
    }
};

class UndefinedOptionException : public exception {
public:
    const char* what() const noexcept {
        return "Undefined option. Please select a valid option.";
    }
};

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
    set<int> insertedValues;

public:
    QuaternarySearchTree() {
        root = nullptr;
    }

    void insert(int key) {
        assert(key >= 0);

        if (insertedValues.count(key) > 0) {
            throw DuplicateValueException();
        }

        root = insertRecursive(root, key);
        insertedValues.insert(key);
    }

    QSTNode* insertRecursive(QSTNode* node, int key) {
        if (node == nullptr) {
            return new QSTNode(key);
        }

        if (key < node->key / 2) {
            node->left = insertRecursive(node->left, key);
        } else if (key >= node->key / 2 && key < node->key) {
            node->second = insertRecursive(node->second, key);
        } else if (key >= node->key && key < 2 * node->key) {
            node->third = insertRecursive(node->third, key);
        } else {
            node->right = insertRecursive(node->right, key);
        }

        return node;
    }

    void preorderTraversal(QSTNode* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->key << " ";
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
        cout << node->key << " ";
    }

    void performPreorderTraversal() {
        cout << "Preorder traversal: ";
        preorderTraversal(root);
        cout << endl;
    }

    void performPostorderTraversal() {
        cout << "Postorder traversal: ";
        postorderTraversal(root);
        cout << endl;
    }
};

int main() {
    QuaternarySearchTree qst;
    int key;
    int option;

    while (true) {
        try {
            cout << "\nMenu:\n";
            cout << "1. Insert a value\n";
            cout << "2. Perform Preorder Traversal\n";
            cout << "3. Perform Postorder Traversal\n";
            cout << "4. Exit\n";
            cout << "Select an option: ";
            cin >> option;

            if (option == 1) {
                cout << "Enter a non-negative integer to insert: ";
                cin >> key;
                qst.insert(key);
            } else if (option == 2) {
                qst.performPreorderTraversal();
            } else if (option == 3) {
                qst.performPostorderTraversal();
            } else if (option == 4) {
                break;
            } else {
                throw UndefinedOptionException();
            }
        } catch (DuplicateValueException& e) {
            cout << "Error: " << e.what() << endl;
        } catch (UndefinedOptionException& e) {
            cout << "Error: " << e.what() << endl;
        }
    }

    return 0;
}
