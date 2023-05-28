/*Implement depth first search algorithm and Breadth First Search algorithm, Use an undirected 
graph and develop a recursive algorithm for searching all the vertices of a graph or tree data 
structure. */


#include<iostream>
#include<queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Tree {
    TreeNode* root;
public:
    Tree() {
        root = NULL;
    }

    void dfs_util(TreeNode* node) {
        if(node == NULL) {
            return;
        }
        cout << node->val << " ";
        dfs_util(node->left);
        dfs_util(node->right);
    }

    void dfs() {
        dfs_util(root);
    }

    void bfs() {
        if(root == NULL) {
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            cout << node->val << " ";
            if(node->left != NULL) {
                q.push(node->left);
            }
            if(node->right != NULL) {
                q.push(node->right);
            }
        }
    }

    void insert(int val) {
        TreeNode* new_node = new TreeNode(val);
        if(root == NULL) {
            root = new_node;
            return;
        }
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();
            if(node->left == NULL) {
                node->left = new_node;
                return;
            }
            else if(node->right == NULL) {
                node->right = new_node;
                return;
            }
            else {
                q.push(node->left);
                q.push(node->right);
            }
        }
    }
};

int main() {
    Tree t;
    int n;
    cout << "Enter the number of nodes in the tree: ";
    cin >> n;
    for(int i = 0; i < n; i++) {
        int val;
        cout << "Enter node " << i + 1 << " value: ";
        cin >> val;
        t.insert(val);
    }

    cout << "DFS Traversal: ";
    t.dfs();
    cout << endl;

    cout << "BFS Traversal: ";
    t.bfs();
    cout << endl;

    return 0;
}