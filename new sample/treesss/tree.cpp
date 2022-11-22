#include<iostream>
#include<queue>
#include "basic.h"
using namespace std;


treenode<int>* takeinput()
{
    int rootdata;
    cout<<"enter root data"<<endl;
    cin>>rootdata;
    treenode<int>*root=new treenode<int>(rootdata);
    queue<treenode<int>*> pendingnodes;
    pendingnodes.push(root);
    while(pendingnodes.size()!=0)
    {
        treenode<int>*first=pendingnodes.front();
        pendingnodes.pop();
        int n;
        cout<<"enter the no. of children of "<<first->data<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            int childdata;
            cout<<"enter the child data of"<<i<<"th node"<<endl;
            cin>>childdata;
            treenode<int>*child=new treenode<int>(childdata);
            pendingnodes.push(child);
            first->children.push_back(child);
        }

    }
    return root;
}

// void print(treenode<int>*root)
// {
//     if(root==NULL)
//     {
//         return;
//     }
//     cout<<root->data <<"  :";
//     for(int i=0;i<root->children.size();i++)
//     {
//         cout<<root->children[i]->data<<",";
//     }
//     cout<<endl;
//     for(int i=0;i<root->children.size();i++)
//     {
//         print(root->children[i]);
//     }
// }
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
        }

    }
}
int main()
{
    treenode<int>*root=takeinput();
    print(root);
}
