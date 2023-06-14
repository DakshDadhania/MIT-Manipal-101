// Program to implement Binary Tree
#include <iostream>
#include <queue>
#include <stack>
using namespace std;

struct Node
{
    int data;
    Node *lc, *rc;
};

class Tree
{

private:
    Node *root;

protected:
    Node *createTree()
    {
        int val;
        cout << ">";
        cin >> val;
        if (val == -1)
            return NULL;
        Node *temp = new Node;
        temp->data = val;
        cout << "Left child of " << val << endl;
        temp->lc = createTree();
        cout << "Right child of " << val << endl;
        temp->rc = createTree();
    }

public:
    Tree()
    {
        root = NULL;
    }

    void create()
    {
        cout << "Use -1 to break" << endl;
        cout << "Enter root" << endl;
        root = createTree();
    }
    void iterativeLevelorder() 
    {
        queue<Node *> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            if (temp == NULL)
            {
                cout << endl;
                if (!q.empty())
                {
                    q.push(NULL);
                }
            }
            else
            {
                cout << temp->data;
                
                if (temp->lc)
                {
                    q.push(temp->lc);
                }
                if (temp->rc)
                {
                    q.push(temp->rc);
                }
            }
        }
    }
    void iterativePreorder() const
    {
        cout << "Iterative Preorder Traversal >>";
        if (root == NULL)
            return;
        stack<Node *> S;
        Node *curr = root;
        S.push(curr);
        while (!S.empty())
        {
            curr = S.top();
            S.pop();
            cout << curr->data << ' ';
            if (curr->rc)
                S.push(curr->rc);
            if (curr->lc)
                S.push(curr->lc);
        }
        cout << endl;
    }

    void iterativeInorder() const
    {
        cout << "Iterative Inorder Traversal >>";
        if (root == NULL)
            return;
        stack<Node *> S;
        Node *curr = root;
        while (curr != NULL || !S.empty())
        {
            while (curr != NULL)
            {
                S.push(curr);
                curr = curr->lc;
            }
            curr = S.top();
            S.pop();
            cout << curr->data << ' ';
            curr = curr->rc;
        }
        cout << endl;
    }

    void iterativePostorder() const
    {
        cout << "Iterative Postorder Traversal >>";
        if (root == NULL)
            return;
        stack<Node *> S;
        Node *curr = root;
        do
        {
            while (curr)
            {
                if (curr->rc)
                    S.push(curr->rc);
                S.push(curr);
                curr = curr->lc;
            }
            curr = S.top();
            S.pop();
            if (curr->rc && S.top() == curr->rc)
            {
                S.pop();
                S.push(curr);
                curr = curr->rc;
            }
            else
            {
                cout << curr->data << ' ';
                curr = NULL;
            }
        } while (!S.empty());
        cout << endl;
    }

    bool searchParent(Node *curr, int elem) const
    {
        if (curr->lc)
        {
            if (curr->lc->data == elem)
            {
                cout << "Parent is " << curr->data << endl;
                return true;
            }
            else
                searchParent(curr->lc, elem);
        }
        if (curr->rc)
        {
            if (curr->rc->data == elem)
            {
                cout << "Parent is " << curr->data << endl;
                return true;
            }
            else
                searchParent(curr->rc, elem);
        }
        return false;
    }

    void parent(int elem) const
    {
        if (root->data == elem)
        {
            cout << "Root has no parent" << endl;
            return;
        }
        else
        {
            if (!searchParent(root, elem))
                cout << "Element does not exist in the tree" << endl;
        }
    }

    int counter(Node *node) const
    {
        if (node == NULL)
            return 0;
        int lDepth = counter(node->lc);
        int rDepth = counter(node->rc);
        // Return larger of both plus one for root
        if (lDepth > rDepth)
            return (lDepth + 1);
        else
            return (rDepth + 1);
    }

    void level() const
    {
        int v = counter(root);
        cout << "Total Depth is:" << v << endl;
    }

    bool searchAncestor(Node *node, int elem) const
    {
        if (node == NULL)
            return false;
        else if (node->data == elem)
            return true;
        else if (searchAncestor(node->lc, elem) || searchAncestor(node->rc, elem))
        {
            cout << node->data << " ";
            return true;
        }
        return false;
    }

    void ancestors(int elem) const
    {
        if (root->data == elem)
            cout << "Root element has no ancestor" << endl;
        else
        {
            if (!searchAncestor(root, elem))
                cout << "Element does not exist in the tree" << endl;
        }
        cout << endl;
    }

    int leafcount(Node *node)
    {
        if (node == NULL)
            return 0;
        else if (!node->lc && !node->rc)
            return 1;
        else
            return leafcount(node->lc) + leafcount(node->rc);
    }

    void leafs()
    {
        cout << "Leafs present:" << leafcount(root) << endl;
    }
};

int main()
{
    Tree T;
    T.create();
    int choice, loc, elem;
    cout << "THE FOLLOWING OPEARTIONS CAN BE PERFORMED ON THE BINARY TREE:" << endl;
    cout << "1.Inorder Traversal" << endl;
    cout << "2.Postorder Traversal" << endl;
    cout << "3.Preorder Traversal" << endl;
    cout << "4.Print parent of given element" << endl;
    cout << "5.Print Depth of tree" << endl;
    cout << "6.Print ancestors of given element" << endl;
    cout << "7.Count the no of leaf nodes in binary tree" << endl;
    cout << "8.Level Order traversal" << endl;
    cout << "9.Exit" << endl;
    while (true)
    {
        cout << ">";
        cin >> choice;
        switch (choice)
        {
        case 1:
            T.iterativeInorder();
            break;
        case 3:
            T.iterativePreorder();
            break;
        case 2:
            T.iterativePostorder();
            break;
        case 4:
            int n;
            cout << "Find parent of?";
            cin >> n;
            T.parent(n);
            break;
        case 5:
            T.level();
            break;
        case 6:
            cout << "Find ancestor of?";
            cin >> n;
            T.ancestors(n);
            break;
        case 7:
            T.leafs();
            break;
        case 8:
            T.iterativeLevelorder();
            break;
        case 9:
            return 0;
        default:
            cout << "Invalid Choice" << endl;
        }
    }
}

// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1