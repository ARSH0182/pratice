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
bool check(binarytree<int>*root,int min=INT_MIN,int max=INT_MAX)
{
    if(root==NULL)
    {
        return true;
    }
    if(root->data<min || root->data>max)
    {
        return false;
    }
    bool isleftok=check(root->left,min,root->data-1);
    bool isrightok=check(root->right,root->data,max);
    return isleftok && isrightok;
}
int main()
{
    binarytree<int>*root=takeinput();
    bool ch=check(root);
    if(ch)
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"fALSE"<<endl;
    }
}