#include<bits/stdc++.h>
#include<queue>
#include<stack>
using namespace std;
template<typename T>
class binarytree{
    public:
    int data;
    binarytree<int>*left;
    binarytree<int>*right;
    binarytree(T data)
    {
        this->data=data;
        left=NULL;
        right=NULL;
    }
    ~binarytree()
    {
        delete left;
        delete right;
    }
};
binarytree<int>* takeinput()
{
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    if(rootdata==-1)
    {
        return NULL;
    }
    binarytree<int>*root=new binarytree<int>(rootdata);
    queue<binarytree<int>*>pending;
    pending.push(root);
    while(pending.size()!=0)
    {
        binarytree<int>*front=pending.front();
        pending.pop();
        int leftroot;
        cout<<"enter the left root of"<<front->data<<endl;
        cin>>leftroot;
        if(leftroot!=-1)
        {
            binarytree<int>*node1=new binarytree<int>(leftroot);
            front->left=node1;
            pending.push(node1);
        }
        int rightroot;
        cout<<"enter the right root of"<<front->data<<endl;
        cin>>rightroot;
        if(rightroot!=-1)
        {
            binarytree<int>*node2=new binarytree<int>(rightroot);
            front->right=node2;
            pending.push(node2);
        }
    
    }
    return root;
}
void print(binarytree<int>*root)
{
    queue<binarytree<int>*>pending;
    pending.push(root);
    pending.push(NULL);
    while(pending.size()!=0)
    {
        binarytree<int>*front=pending.front();
        pending.pop();
        if(front==NULL)
        {
            if(pending.empty())
            {
                break;
            }
            else
            {
                pending.push(NULL);
            }
        }
        else
        {
            cout<<front->data<<":";
            if(front->left!=NULL)
            {
                cout<<"L"<<front->left->data<<",";
                pending.push(front->left);
            }
            else
            {
                cout<<"L"<<-1<<",";
            }
            if(front->right!=NULL)
            {
                cout<<"R"<<front->right->data<<",";
                pending.push(front->right);
            }
            else
            {
                cout<<"R"<<-1<<",";
            }
        }
        cout<<endl;
    }
}
class node{
    public:
    node*next;
    int data;
    node(int data)
    {
        this->data=data;
        next=NULL;
    }
};
class Pair{
    public:
    node*head;
    node*tail;
};
Pair bst(binarytree<int>*root)
{
    if(root==NULL)
    {
        Pair ans;
        ans.head=NULL;
        ans.tail=NULL;
        return ans;
    }
    node*n=new node(root->data);
    Pair leftans=bst(root->left);
    Pair rightans=bst(root->right);

    Pair ans;
    if(leftans.head==NULL && rightans.head==NULL)
    {
        ans.head=n;
        ans.tail=n;
    }
    else if((!leftans.head && rightans.head))
    {
        ans.head=n;
        n->next=rightans.head;
        ans.tail=rightans.tail;
    }
    else if(leftans.head && rightans.head==NULL)
    {
        ans.head=leftans.head;
        leftans.tail->next=n;
        ans.tail=n;
    }
    else{
        ans.head=leftans.head;
        ans.tail=rightans.tail;
        leftans.tail->next=n;
        n->next=rightans.head;
    }

return ans;
}
int main()
{
    binarytree<int>*root=takeinput();
    Pair p=bst(root);
    node*head=p.head;
    while(head!=NULL)
    {
        cout<<head->data<<endl;
        head=head->next;
    }

}