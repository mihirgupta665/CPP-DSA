/*
Input 3 :
5
2
-1
-1
7
-1
-1
Output 3 :
Postorder Traversal: 2 7 5 
Sum of all nodes: 14
*/
#include<iostream>
using namespace std;
struct treenode {
    int value;
    treenode* left;
    treenode* right;
    treenode(int data) : value(data), left(nullptr), right(nullptr) {}
};
treenode* buildtree(){
    int value;
    cin>>value;
    if(value==-1){
        return nullptr;
    }
    treenode* node= new treenode(value);
    node->left=buildtree();
    node->right=buildtree();
    return node;
}
void postorder(treenode* root){
    if(root==nullptr){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->value<<" ";
}
int sumnode(treenode* node){
    if(node==nullptr){
        return 0;
    }
    return node->value + sumnode(node->left) + sumnode(node->right);
}
int main(){
    treenode* root= buildtree();
    cout<<"Postorder transversal : ";
    postorder(root);
    cout<<endl;
    int sum =sumnode(root);
    cout<<"Sum of all the nodes : "<<sum<<endl;
    return 0;
}