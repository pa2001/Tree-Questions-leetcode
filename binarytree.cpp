#include<bits/stdc++.h>
using namespace std;
class node
{
  public:
  int val;
  node* left,*right;
};
node* head=NULL;
int choice=0,v,chl=0,chr=0,key;
void create(int k,node* leaf)
{
  if(k<leaf->val)
  {
    if(leaf->left!=NULL)
    create(k,leaf->left);
    else
    {
      leaf->left=new node();
      leaf->left->val=k;
      leaf->left->left=NULL;
      leaf->left->right=NULL;
    }
  }
  else if(k>leaf->val)
  {
    if(leaf->right!=NULL)
    create(k,leaf->right);
    else
    {
      leaf->right=new node();
      leaf->right->val=k;
      leaf->right->left=NULL;
      leaf->right->right=NULL;
    }
  }
}
void insert()
{
  cout<<"Enter value-";
  cin>>v;
  if(head!=NULL)
  create(v,head);
  else
  {
    head=new node();
    head->val=v;
    head->left=NULL;
    head->right=NULL;
  }
}
void search(int k,node*head)
{ 
  if(k==head->val)
  cout<<"Found"<<endl;
  else if(k<head->val)
  search(k,head->left);
  else if(k>head->val)
  search(k,head->right);
  else
  cout<<"Not found"<<endl;
}
void preorder(node* root)
{
  if(root==NULL)
  return;
  cout<<root->val<<" ";
  preorder(root->left);
  preorder(root->right);
}
void preorder()
{
  preorder(head);
}
void inorder(node* root)
{
  if(root==NULL)
  return;
  inorder(root->left);
  cout<<root->val<<" ";
  inorder(root->right);
}
void inorder()
{
  inorder(head);
}
void postorder(node* root)
{
  if(root==NULL)
  return;
  postorder(root->left);
  postorder(root->right);
  cout<<root->val<<" ";
}
void postorder()
{
  postorder(head);
}
void search()
{
  cout<<"Enter value to be seached-";
  cin>>key;
  search(key,head);
}
void destroy(node* head)
{
  if(head!=NULL)
  {
    destroy(head->left);
    destroy(head->right);
    delete(head);
  }
}
void destroy()
{
  destroy(head);
}
int main()
{
  cout<<"Press 1 to insert\nPress 2 to delete\nPress 3 to preorder display\nPress 4 to inorder display\nPress 5 to postorder display\nPress 6 to search";
  while(choice!=7)
  {
    cout<<"\nEnter choice-";
    cin>>choice;
    switch(choice)
    {
      case 1:
      insert();
      break;
      case 2:
      destroy();
      break;
      case 3:
      preorder();
      break;
      case 4:
      inorder();
      break;
      case 5:
      postorder();
      break;
      case 6:
      search();
      break;
    }
  }
}
