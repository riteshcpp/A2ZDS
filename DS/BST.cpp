#include <iostream>
#include <queue>
#include <stack>

namespace DS::BST::C {
#include <iostream>
#include <queue>
#include <stack>

struct node {
    node* left = { nullptr };
    int data;
    node* right = { nullptr };
    node(int data) : data(data) {}
};

node* insert(node* root, int data) {
    if (root == nullptr) {
        root = new node(data);
        return root;
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    }
    else {
        root->right = insert(root->right, data);
    }
    return root;
}
node* insertI(node* root, int data) {
    node* newNode = new node(data);
    if (root == nullptr) {
        root = newNode;
        return root;
    }
    node* p = root;
    while (true) {
        if (data < p->data) {
            if (p->left == nullptr) {
                p->left = newNode;
                break;
            }
            p = p->left;
        }
        else {
            if (p->right == nullptr) {
                p->right = newNode;
                break;
            }
            p = p->right;
        }
    }
    return newNode;
}
void preOrder(node* root) {
    if (root != nullptr) {
        std::cout << root->data << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}
void inOrder(node* root) {
    if (root != nullptr) {
        inOrder(root->left);
        std::cout << root->data << " " ;
        inOrder(root->right);
    }
}
void postOrder(node* root) {
    if (root != nullptr) {
        postOrder(root->left);
        postOrder(root->right);
        std::cout << root->data << " ";
    }
}
void levelOrder(node* root) {
    if (!root) return;
    std::queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* p = q.front();
        q.pop();
        std::cout << p->data << " ";
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }
}
void spiral(node* root) {
    if (!root) return;
    std::stack<node*> s1, s2;
    s1.push(root);
    while (!s1.empty() || !s2.empty()) {
        while (!s1.empty()) {
            node* p = s1.top();
            s1.pop();
            std::cout << p->data << " ";
            if (p->right) s2.push(p->right);
            if (p->left) s2.push(p->left);
        }
        while (!s2.empty()) {
            node* p = s2.top();
            s2.pop();
            std::cout << p->data << " ";
            if (p->left) s1.push(p->left);
            if (p->right) s1.push(p->right);
        }
    }
}
int height(node* root) {
    if (!root)
        return 0;
    int x = height(root->left);
    int y = height(root->right);
    return x > y ? x + 1 : y + 1;
}
int noOfNodes(node* root) {
    if (!root)
        return 0;
    int x = noOfNodes(root->left);
    int y = noOfNodes(root->right);
    return x + y + 1;
}
int noOfLeafNodes(node* root) {
    if (!root)
        return 0;
    int x = noOfLeafNodes(root->left);
    int y = noOfLeafNodes(root->left);
    if (!root->left && !root->right)
        return x + y + 1;
    return x + y;
}
int noOfNonLeafNodes(node* root) {
    if (!root)
        return 0;
    int x = noOfNonLeafNodes(root->left);
    int y = noOfNonLeafNodes(root->left);
    if (root->left || root->right)
        return x + y + 1;
    return x + y;
}
node* inOrderPredecissor(node* root) {
    while (root && root->right)
        root = root->right;
    return root;
}
node* inOrderSuccessor(node* root) {
    while (root && root->left)
        root = root->left;
    return root;
}
node* deleteNode(node* root, int data) {
    if (root == nullptr)
        return nullptr;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    }
    else {
        int left = height(root->left);
        int right = height(root->right);
        if (left > right) {
            node* pre = inOrderPredecissor(root->left);
            root->data = pre->data;
            root->left = deleteNode(root->left, pre->data);
        }
        else if (right >= left && right) {
            node* succ = inOrderSuccessor(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
        else {
            delete root;
            root = nullptr;
        }
        return root;
    }
    return root;
}

void invertR(node* root) {
    if (!root) return;
    invertR(root->left);
    invertR(root->right);
    std::swap(root->left, root->right);
}

void inverI(node* root) {
    if (!root) return;
    std::queue<node*> q;
    q.push(root);
    while (!q.empty()) {
        node* p = q.front();
        q.pop();
        std::swap(p->left, p->right);
        if (p->left) q.push(p->left);
        if (p->right) q.push(p->right);
    }
}

int main() {
    node* root = nullptr;

    // Insert nodes
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 70);
    insert(root, 20);
    insert(root, 40);
    insert(root, 60);
    insert(root, 80);

    std::cout << "InOrder Traversal: ";
    inOrder(root);
    std::cout << "\n";

    std::cout << "PreOrder Traversal: ";
    preOrder(root);
    std::cout << "\n";

    std::cout << "PostOrder Traversal: ";
    postOrder(root);
    std::cout << "\n";

    std::cout << "LevelOrder Traversal: ";
    levelOrder(root);
    std::cout << "\n";

    std::cout << "Spiral Traversal: ";
    spiral(root);
    std::cout << "\n";

    std::cout << "Height of tree: " << height(root) << "\n";
    std::cout << "Number of nodes: " << noOfNodes(root) << "\n";
    std::cout << "Number of leaf nodes: " << noOfLeafNodes(root) << "\n";
    std::cout << "Number of non-leaf nodes: " << noOfNonLeafNodes(root) << "\n";

    std::cout << "Reverse/Invert/Mirror of Tree Recursive:\nInOrder After Invert: ";
    invertR(root);
    inOrder(root);
    std::cout << "\n";

    std::cout << "Reverse/Invert/Mirror of Tree Iterative:\nInOrder After Invert: ";
    inverI(root);
    inOrder(root);
    std::cout << "\n";

    // Delete node
    root = deleteNode(root, 70);
    std::cout << "InOrder after deleting 70: ";
    inOrder(root);
    std::cout << "\n";

    // Delete another node
    root = deleteNode(root, 30);
    std::cout << "InOrder after deleting 30: ";
    inOrder(root);
    std::cout << "\n";

    return 0;
}
} // namespace DS::BST::C

namespace DS::BST::CPP {
#include <iostream>
#include <queue>
#include <stack>

template <typename T>
struct Node {
    Node* left = nullptr;
    T data;
    Node* right = nullptr;
    Node(T data) : data(data) {}
};

template <typename T>
class BST {
public:
    Node<T>* root;

    BST() : root(nullptr) {}

    Node<T>* insert(Node<T>* root, T data) {
        if (root == nullptr) {
            return new Node<T>(data);
        }
        if (data < root->data) {
            root->left = insert(root->left, data);
        } else {
            root->right = insert(root->right, data);
        }
        return root;
    }

    Node<T>* insertIterative(Node<T>* root, T data) {
        Node<T>* newNode = new Node<T>(data);
        if (root == nullptr) return newNode;

        Node<T>* p = root;
        while (true) {
            if (data < p->data) {
                if (p->left == nullptr) {
                    p->left = newNode;
                    break;
                }
                p = p->left;
            } else {
                if (p->right == nullptr) {
                    p->right = newNode;
                    break;
                }
                p = p->right;
            }
        }
        return newNode;
    }

    void preOrder(Node<T>* root) {
        if (root) {
            std::cout << root->data << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }

    void inOrder(Node<T>* root) {
        if (root) {
            inOrder(root->left);
            std::cout << root->data << " ";
            inOrder(root->right);
        }
    }

    void postOrder(Node<T>* root) {
        if (root) {
            postOrder(root->left);
            postOrder(root->right);
            std::cout << root->data << " ";
        }
    }

    void levelOrder(Node<T>* root) {
        if (!root) return;
        std::queue<Node<T>*> q;
        q.push(root);
        while (!q.empty()) {
            Node<T>* p = q.front();
            q.pop();
            std::cout << p->data << " ";
            if (p->left) q.push(p->left);
            if (p->right) q.push(p->right);
        }
    }

    void spiral(Node<T>* root) {
        if (!root) return;
        std::stack<Node<T>*> s1, s2;
        s1.push(root);
        while (!s1.empty() || !s2.empty()) {
            while (!s1.empty()) {
                Node<T>* p = s1.top(); s1.pop();
                std::cout << p->data << " ";
                if (p->right) s2.push(p->right);
                if (p->left) s2.push(p->left);
            }
            while (!s2.empty()) {
                Node<T>* p = s2.top(); s2.pop();
                std::cout << p->data << " ";
                if (p->left) s1.push(p->left);
                if (p->right) s1.push(p->right);
            }
        }
    }

    int height(Node<T>* root) {
        if (!root) return 0;
        int x = height(root->left);
        int y = height(root->right);
        return (x > y ? x + 1 : y + 1);
    }

    Node<T>* inOrderPredecessor(Node<T>* root) {
        while (root && root->right) root = root->right;
        return root;
    }

    Node<T>* inOrderSuccessor(Node<T>* root) {
        while (root && root->left) root = root->left;
        return root;
    }

    Node<T>* deleteNode(Node<T>* root, T data) {
        if (root == nullptr) return nullptr;

        if (data < root->data) {
            root->left = deleteNode(root->left, data);
        } else if (data > root->data) {
            root->right = deleteNode(root->right, data);
        } else {
            int left = height(root->left);
            int right = height(root->right);
            if (left > right) {
                Node<T>* pre = inOrderPredecessor(root->left);
                root->data = pre->data;
                root->left = deleteNode(root->left, pre->data);
            } else if (right >= left && right) {
                Node<T>* succ = inOrderSuccessor(root->right);
                root->data = succ->data;
                root->right = deleteNode(root->right, succ->data);
            } else {
                delete root;
                root = nullptr;
            }
        }
        return root;
    }
};
} // namespace DS::BST::CPP