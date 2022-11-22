#include<iostream>
#include<queue>
#include "basic.h"
using namespace std;
 

treenode<int>*takeinput()
{
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    treenode<int>*root=new treenode<int>(rootdata);
    queue<treenode<int>*>pending;
    pending.push(root);
    while(pending.size()!=0)
    {
        treenode<int>*front=pending.front();
        pending.pop();
        int n;
        cout<<"enter the number of child of"<<front->data<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int childdata;
            cout<<"enter the"<<i<<"th child"<<endl;
            cin>>childdata;
            treenode<int>*child=new treenode<int>(childdata);
            front->children.push_back(child);
            pending.push(child);
        }
    }
    return root;
}
void print(treenode<int>*root)
{
    queue<treenode<int>*>pendingnodes;
    pendingnodes.push(root);
    pendingnodes.push(NULL);

    while(pendingnodes.size()!=0)
    {
        treenode<int>*front=pendingnodes.front();
        pendingnodes.pop();
        if(front==NULL)
        {
            if(pendingnodes.empty())
            {
                break;
            }
            else
            {
                pendingnodes.push(NULL);
            }
        }
        else{
        cout<<front->data<<" :";
        for(int i=0;i<front->children.size();i++)
        {
            cout<<front->children[i]->data<<",";
            pendingnodes.push(front->children[i]);
        }
        cout<<endl;
        }

    }
}
treenode<int>* nextlarger(treenode<int>*root,int x)
{
    treenode<int>*ans;
    if(root->data>x)
    {
        ans=root;
    }
    else
    {
        ans=NULL;
    }
    for(int i=0;i<root->children.size();i++)
    {
        treenode<int>*temp=nextlarger(root->children[i],x);
        if(ans==NULL)
        {
            ans=temp;
        }
        else if(temp<ans)
        {
            ans=temp;
        }
    }
    return ans;
}
int main()
{
    treenode<int>*root=takeinput();
    print(root);
    //cout<<height(root)<<endl;
    treenode<int>*x=nextlarger(root,5);
    cout<<x->data<<endl;
}