#include <iostream>
#include<queue>
using namespace std;
class Node
{
public:
    int data;
    Node *lc;
    Node *rc;
    Node()
    {
        this->data = 0;
        this->lc = 0;
        this->rc = 0;
    }
    Node(int d)
    {
        this->data = d;
        this->lc = NULL;
        this->rc = NULL;
    }
};
class tree
{
public:
    Node *root;
    tree()
    {
        root = NULL;
    }
    void create()
    {
        cout << "Enter -1 to break";
        cout << "Enter root";
        root = createtree(root);
    }
    void search(){
        cout<<"Element to be searched? ";
        int elem;
        cin>>elem;
        searching(root,elem)?cout<<"Yes found":cout<<"No not found";
    }
    void print()
    {
        printtree(root);
    }
    void levelbuild(){
        buildfromlevel(root);
    }
    void counterleaf(){
        int count=0;
        countleaf(count,root);
        cout<<"No of leaf nodes "<<count;
    }
    void height(){
        cout<<"Height of the given tree ";
        cout<<countheight(root);

    }
    int mini(Node* root){
        cout<<"Minimum data is ";
        int min=root->data;
        minimum(root,min);
       return min;
    }
    int maxi(Node* root){
        cout<<"Minimum data is ";
        int max=root->data;
        minimum(root,max);
        return max;
    }
    void balance(){
        checkbalanced(root)?cout<<"Yes balanced":cout<<"No not balanced";
    }

    void equality(tree t4){
        bool a= equaltrees(root,t4.root);
        if(a){
            cout<<"Yes equal";
        }
        else{
            cout<<"No not equal";
        }
    }
    void deletebst(){
        cout<<"Enter element to delete from BST ";
        int val;
        cin>>val;
        root=deletefromBST(root,val);
        
    }

protected:
    // Node *createtree(Node *root)
    // {
    //     cout << ">";
    //     int val;
    //     cin >> val;
    //     if (val == -1)
    //     {
    //         return NULL;
    //     }
    //     Node *temp = new Node();
    //     temp->data = val;
    //     cout << "Enter left node of " << val << "\n";
    //     temp->lc = createtree(temp->lc);
    //     cout << "Enter right node of " << val << "\n";
    //     temp->rc = createtree(temp->rc);

    //     return temp;
    // }
    bool searching(Node* root,int elem){
        if(root==NULL){
            return false;
        }
        
        if(root->data==elem){
            return true;
        }
        bool left=searching(root->lc,elem);
        bool right=searching(root->rc,elem);
        if(left || right){
            return true;
        }
    }
    void minimum(Node*root,int &min){
        if(root==NULL){
            return;
        }
        if(root->data<min){
            min=root->data;
        }
        minimum(root->lc,min);
        minimum(root->rc,min);


    }
    void maximun(Node*root,int &min){
        if(root==NULL){
            return;
        }
        if(root->data>min){
            min=root->data;
        }
        minimum(root->lc,min);
        minimum(root->rc,min);


    }
    void buildfromlevel(Node* &root){
        queue<Node*> q;
        int d;
        cin>>d;
        root=new Node(d);
        q.push(root);
        while(!q.empty()){
            Node* temp=q.front();
            q.pop();
            cout<<"Enter left of "<<temp->data<<endl;
            int ld;
            cin>>ld;
            if(ld!=-1){
                temp->lc=new Node(ld);
                q.push(temp->lc);

            }
            cout<<"Enter right of "<<temp->data<<endl;
            int rd;
            cin>>rd;
            if(rd!=-1){
                temp->rc=new Node(rd);
                q.push(temp->rc);

            }

        }
    }
    int countheight(Node*root){
        if(root==NULL){
            return 0;
        }
        int leftheight=countheight(root->lc);
        int rightheight=countheight(root->rc);


        if(leftheight>rightheight){
            return (leftheight+1);
        }
        else{
            return (rightheight+1);
        }

    }
    Node *createtree(Node *root)
    {
        cout << ">";
        int val;
        cin >> val;
        if (val == -1)
        {
            return NULL;
        }
        Node *temp = new Node();
        temp->data = val;
        cout << "Enter left node of " << val << "\n";
        temp->lc = createtree(temp->lc);
        cout << "Enter right node of " << val << "\n";
        temp->rc = createtree(temp->rc);

        return temp;
    }
    // void printtree(Node* node){
    //     if(node==NULL){
    //         return;
    //     }
    //     printtree(node->lc);
    //     cout<<node->data<<" ";
    //     printtree(node->rc);

    // }
    void countleaf(int &count,Node* root){
        if(root==NULL){
            return;

        }
        countleaf(count,root->lc);
        if(root->lc==NULL && root->rc==NULL){
            count+=1;
        }
        countleaf(count,root->rc);
    }
    bool checkbalanced(Node* root){
      
        if(root==NULL){
            return true;
        }
        bool left=checkbalanced(root->lc);
        bool right=checkbalanced(root->rc);
        bool selfbalance= abs(countheight(root->lc)-countheight(root->rc))<=1;
        if(left && right && selfbalance){
            return 1;
        }
        else{
            return false;
        }
    }
    bool equaltrees(Node* r1,Node*r2){
        if(r1==NULL && r2==NULL){
            return true;
        }
        if(r1!=NULL && r2==NULL){
            return false;
        }
        if(r1==NULL && r2!=NULL){
            return false;
        }
        bool self= r1->data==r2->data;
        bool left=equaltrees(r1->lc,r2->lc);
        bool right=equaltrees(r1->rc,r2->rc);
        if(self && left && right){
            return true;
        }
        else {
            return false;
        }
    }
    Node* deletefromBST(Node* root, int val){
        if(root=NULL){
            return root;
        }
        if(root->data==val){
            //0 child
            if(root->rc==NULL && root->lc==NULL){
                delete root;
                return NULL;
            }

            //1 child 
            if(root->lc!=NULL && root->rc==NULL){
                Node* temp=root->lc;
                delete root;
                return temp;
            }
            if(root->rc!=NULL && root->lc==NULL){
                Node* temp=root->rc;
                delete root;
                return temp;
            }

            //2 child
            if(root->lc!=NULL && root->rc!=NULL){
                int minimum=mini(root->rc);
                root->data=minimum;
                root->rc=deletefromBST(root->rc,minimum);
                return root;

            }
        }
        else if(root->data>val){
            root->lc=deletefromBST(root->lc,val);
            return root;
        }
        else{
            root->rc=deletefromBST(root->rc,val);
            return root;

        }
    }

    void printtree(Node *node)
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
                
                cout << temp->data<<" ";
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

};
int main()
{
    tree t1;
    // t1.create();
    // t1.print();
    t1.levelbuild();
    t1.deletebst();
    // tree t2;
    // cout<<"Root of t2"<<endl;
    // t2.levelbuild();
    // t1.search();
   
    // t1.print();
    // t1.equality(t2);
    // t1.counterleaf();
    
    cout<<endl;
    t1.height();
    cout<<endl;
    t1.balance();
    cout<<endl;
}