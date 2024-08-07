#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    bool isThreaded;
};

Node* insert(Node* root, int key) {
    if (root == nullptr) {
        root = new Node;
        root->data = key;
        root->left = root->right = nullptr;
        root->isThreaded = false;
    } else if (key < root->data) {
        root->left = insert(root->left, key);
    } else if (key > root->data) {
        if (root->isThreaded) {
            root->right = insert(root->right, key);
            root->isThreaded = false;
        } else {
            Node* temp = new Node;
            temp->data = key;
            temp->left = nullptr;
            temp->right = root->right;
            temp->isThreaded = true;
            root->right = temp;
        }
    }
    return root;
}

Node* leftMost(Node* root) {
    if (root == nullptr) return nullptr;
    while (root->left != nullptr) {
        root = root->left;
    }
    return root;
}

Node* createTBT(Node* root) {
    if (root == nullptr) return nullptr;
    if (root->left == nullptr && root->right == nullptr) return root;
    if (root->left != nullptr) {
        Node* l = createTBT(root->left);
        l->right = root;
        l->isThreaded = true;
    }
    if (root->right == nullptr) return root;
    return createTBT(root->right);
}

void inorder(Node* root) {
    if (root == nullptr) return;
    Node* current = leftMost(root);
    while (current != nullptr) {
        cout << current->data << " ";
        if (current->isThreaded) {
            current = current->right;
        } else {
            current = leftMost(current->right);
        }
    }
}

void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->data << " ";
    if (!root->isThreaded) preorder(root->left);
    preorder(root->right);
}

void displayMenu() {
    cout << "Menu:\n";
    cout << "1. Insert a new node\n";
    cout << "2. Inorder traversal\n";
    cout << "3. Preorder traversal\n";
    cout << "4. Convert to threaded BST\n";
    cout << "5. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    Node* root = nullptr;
    int choice;
    int key;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> key;
                root = insert(root, key);
                break;
            case 2:
                cout << "Inorder Traversal: ";
                inorder(root);
                cout << endl;
                break;
            case 3:
                cout << "Preorder Traversal: ";
                preorder(root);
                cout << endl;
                break;
            case 4:
                createTBT(root);
                cout << "Tree converted to threaded BST.\n";
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please enter a valid option.\n";
                break;
        }
    } while (choice != 5);

    return 0;
}
