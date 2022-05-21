#include <cstdlib>
#include <iostream>

using namespace std;
struct tree
{
  int val,fix,weight,size;
  tree *left,*right;
};
int resize(tree *tr)
{
  if (tr==NULL) return 0;
  else return tr->size;
}
void turnleft(tree *&x)
{
   tree *y=x->right;
   x->right=y->left;
   y->left=x;
   x=y;
   y=x->left;
   y->size=resize(y->right)+resize(y->left)+y->weight;
   x->size=resize(x->left)+resize(x->right)+x->weight;
}
void turnright(tree *&x)
{
   tree *y=x->left;
   x->left=y->right;
   y->right=x;
   x=y;
   y=x->right;
   y->size=resize(y->right)+resize(y->left)+y->weight;
   x->size=resize(x->left)+resize(x->right)+x->weight;
}
void insert(tree *&head,int item)
{
   if (head==NULL)
   {
     head=new tree;
     head->val=item;
     head->right=NULL;
     head->left=NULL;
     head->weight=1;
     head->fix=rand();
     head->size=1;
   }
   else   if (item<head->val) 
          { 
          insert(head->left,item);
          head->size++;
          if (head->left->fix<head->fix) turnright(head);
          }
   else   if (item>head->val) 
          {
          insert(head->right,item);          
          head->size++;
          if (head->right->fix<head->fix) turnleft(head);
          }
   else if (item==head->val) {head->weight++;head->size++;}
}
void print(tree *head)
{
  if (head!=NULL)
  {
    print(head->left);
    cout<<head->val<<" ";
    print(head->right);
  }
}
void del(tree *&head)
{
     if (head->left==NULL || head->right==NULL)
     {
       if (head->left==NULL) head=head->right;
       else head=head->left;
     }
     else if (head->left->fix<head->right->fix) {turnright(head);del(head);} 
     else if (head->left->fix>head->right->fix) {turnleft(head);del(head);}
}
void del_find(tree *&head,int item)
{
     if (head!=NULL)
     {
       if (item<head->val) del_find(head->left,item);
       else if (item>head->val) del_find(head->right,item);
       else if (item==head->val) del(head);
     }
}
int k_find(tree *&head,int k)
{
    if (k<=resize(head->left)) return k_find(head->left,k);
    else if (k>resize(head->left) && k<=resize(head->left)+head->weight) return head->val;
    else return k_find(head->right,k-(resize(head->left)+head->weight));
}
int main(int argc, char *argv[])
{
    int n;
    tree *tr=NULL;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
      int l;
      cin>>l;
      insert(tr,l);
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}
