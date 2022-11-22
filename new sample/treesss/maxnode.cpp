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
int maxe(treenode<int>* root)
{
    int max=INT_MIN;
    for(int i=0;i<root->children.size();i++)
    {
        int max1=maxe(root->children[i]);
        if(max<max1)
        max=max1;
    }
    if(max<root->data)
    max=root->data;
        return max;
}

int main()
{
    treenode<int>*root=takeinput();
    print(root);
    cout<<"maximum element is"<<maxe(root)<<endl;
}