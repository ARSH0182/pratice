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
bool identical(treenode<int>*root1,treenode<int>*root2)
{
    if(root1->data!=root2->data)
    {
        return false;
    }
    for(int i=0;i<root1->children.size();i++)
    {
        bool ans=identical(root1->children[i],root2->children[i]);
        if(ans==false)
        {
            return false;
        }

    }
    return true;

}
int main()
{
    treenode<int>*root1=takeinput();
    treenode<int>*root2=takeinput();
    //print(root1);
    bool ans=identical(root1,root2);
    if(ans)
    cout<<"true"<<endl;
    else
    cout<<"false"<<endl;
}