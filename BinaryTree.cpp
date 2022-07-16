#include<iostream>
#include "bits/stdc++.h"
using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int x){
        left=NULL;
        right=NULL;
        data=x;
    }
};
/*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
                   \
                    1
*/

void preorder(struct node* root){ //preorder traversal
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void inorder(struct node* root){ //inorder traversal
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}


void postorder(struct node* root){ //postorder traversal
    if(root==NULL){
        return;
    }
   
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}


int countnode(node *p){

if(p==NULL){
    return 0;
}
return countnode(p->left) + countnode(p->right) + 1;



return 0;
}

int countnodeofdegree2(node *p){
int x, y;

if(p!=NULL)
{x=countnodeofdegree2(p->left);
y=countnodeofdegree2(p->right);
if(p->left && p->right)
    return x+y+1;
else 
    return x+y;
}

return 0;
}

int sumTree(node *p){
int x, y;

if(p!=NULL)
{
x=sumTree(p->left);
y=sumTree(p->right);
return x+y+p->data;
}

return 0;
}


int heightTree(node *p){
int x, y;

if(p!=NULL)
{x=heightTree(p->left);
y=heightTree(p->right);
if(x>y)
    return x+1;
else 
    return y+1;
}

return 0;
}



int SumAtK(node* root, int k){
    if(root==NULL)
        return -1;
    queue<node*> q;

    q.push(root);
    q.push(NULL);
    int sum=0;
    int level=0;

    while(!q.empty()){
    node* top= q.front();
    q.pop();
    if(top!=NULL){
        if(level==k){
            sum+=top->data;
        }
        if(top->left)
            q.push(top->left);
        if(top->right)
            q.push(top->right);
    }
    else if(!q.empty()){
        level++;
        q.push(NULL);
    }
    }
    return sum;
}



void levelorderprint(node* p){
if(p==NULL)
    return;
queue<node*> q;

q.push(p);
q.push(NULL);
while(!q.empty()){
    node* top= q.front();
    q.pop();
    if(top!=NULL){
        cout<<top->data<<" ";
        if(top->left)
            q.push(top->left);
        if(top->right)
            q.push(top->right);
    }
    else if(!q.empty()){
        q.push(NULL);
    }
}

}




int diameterOfTree(node* p, int &maxi){ //imp understand again
if(p==NULL)
    return 0;

int lh, rh;
lh= diameterOfTree(p->left, maxi);
rh= diameterOfTree(p->right, maxi);

maxi = max(maxi, lh+rh);

return 1+max(lh,rh);

}



void sumreplace(node* p){   // O(n)
    if(p==NULL){
        return;
    }
    sumreplace(p->left);
    sumreplace(p->right);

    if(p->left!=NULL){
        p->data+=p->left->data;
    }
    if(p->right!=NULL){
        p->data+=p->right->data;
    }
    
}




bool IsBalanced(node* p){ //O(n^2)
    
    if(p==NULL)
        return true;
    
    if(IsBalanced(p->left) == false){
        return false;
    }
    if(IsBalanced(p->right) == false){
        return false;
    }

    int lh= heightTree(p->left);
    int rh= heightTree(p->right);
    if(abs(lh-rh)<=1){
        return true;
    }
    else    
        return false;
}



void RightView(node* p){  //o(n)
if(p==NULL)
    return;
queue<node*> q;

q.push(p);

while(!q.empty()){
    int n = q.size();
    for(int i=0; i<n; i++){
        node* curr = q.front();
        q.pop();
        if(i==n-1)
            cout<<curr->data<<" ";
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);


    }
    
}
}



void LeftView(node* p){  //o(n)
if(p==NULL)
    return;
queue<node*> q;

q.push(p);

while(!q.empty()){
    int n = q.size();
    for(int i=0; i<n; i++){
        node* curr = q.front();
        if(i==0)
            cout<<curr->data<<" ";
        q.pop();
        if(curr->left!=NULL)
            q.push(curr->left);
        if(curr->right!=NULL)
            q.push(curr->right);

    }
    
}
}



int main(){
    int maxi=0;
    struct node* root=new node(1);
    root->left=new node(2);
    root->right=new node(3);
    root->left->left=new node(4);
    root->left->right=new node(5);
    root->right->left=new node(6);
    root->right->right=new node(7);
    root->right->right->right=new node(1);
    // preorder(root);
    // inorder(root);
    // postorder(root);

    cout<<countnode(root)<<endl;
    cout<<countnodeofdegree2(root)<<endl;
    cout<<sumTree(root)<<endl;
    cout<<heightTree(root)<<endl;
    levelorderprint(root);
    cout<<endl;
    cout<<SumAtK(root, 1)<<endl;
    int m= diameterOfTree(root, maxi);
    cout<<max(maxi, m)<<endl;

    sumreplace(root);
    preorder(root);
    cout<<endl;
    cout<<IsBalanced(root);
    cout<<endl;

    RightView(root);
       cout<<endl;
    LeftView(root);


return 0;
}

