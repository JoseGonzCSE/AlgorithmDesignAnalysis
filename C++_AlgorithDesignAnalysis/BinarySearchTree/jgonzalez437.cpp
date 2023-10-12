//lab06 Binary Search Tree

#include <iostream>
#include <sstream>
#include <stdlib.h>
#include<string>
#include<cstdlib>

using namespace std;

struct Node {
  int key;   // Value of the node
  Node *left;   // Pointer to the left node
  Node *right;  // Pointer to the right node
  Node *p; // Pointer to the parent node
  Node *root;

};
//x=root
//correct
void InOrder(struct Node* x){
    if (x!=nullptr){
        InOrder(x->left);
        cout<<x->key<<endl;
        InOrder(x->right);
    }
}
//correct
void Postorder(struct Node* x){
    if(x!=nullptr){
        Postorder(x->left);
        Postorder(x->right);
        cout<< x->key<<endl;
    }
}
//correct
void Preorder(struct Node* x){
    if(x!=nullptr){
        cout<< x->key<<endl; 
        Preorder(x->left);
        Preorder(x->right);
    }
}

Node* convert(int Key){
    struct Node* temp= new Node;
    temp->key=Key;
    temp->right=nullptr;
    temp->left=nullptr;
    return temp;
}


Node* convert2(int Key){
    struct Node* temp= new Node;
    temp->key=Key;
    temp->right=nullptr;
    temp->left=nullptr;
    return temp;
}
//correct
Node* Insert(struct Node* T, int key){
    struct Node* z=convert(key);
    struct Node* y=nullptr;
    struct Node* x = T; 
    while (x!=nullptr){
        y=x;
        if(z->key<x->key){
            x=x->left;
        }else{
            x=x->right;
        }
    }z->p=y;
    if(y==nullptr){
        T=z; // Another T.root
    }else if(z->key<y->key){
        y->left=z;
    }else{
        y->right=z;
    }return T;
}



void Transplant(struct Node* T,struct Node*u,struct Node*v){
    if(u->p==nullptr){
        T=v; // Another T.root
    }else if(u==u->p->left){
        u->p->left=v;
    }else{
        u->p->right=v;
    }if(v!=nullptr){
        v->p=u->p;
    }
}
//Also required for TreeDelete 
struct Node* TreeMinimum(struct Node* x){
    while(x->left!=nullptr){
        x=x->left;
    }return x;
}




struct Node* TreeDelete( Node* T,int Key){
    struct Node* z=convert2(Key);

    if(z->left==nullptr){
        Transplant(T,z,z->right);
    }else if(z->right==nullptr){
        Transplant(T,z,z->left);
    }else{
        struct Node* y = TreeMinimum(z->right);
        
        if(y->p !=z){
            Transplant(T,y,y->right);
            y->right=z->right;
            y->right->p=y;
        }
        Transplant(T,z,y);
        y->left=z->left;
        y->left->p=y;
    }
    return T;
}




int main(int argc,char **argv) {
    Node *root = NULL; 
    int key;
    string str;

    while (1){
        cin >> str;

        if (str[0] =='e'){
            return 1;
        }

        if (str[0] =='o'){

            if (str.substr(0, 3) =="oin"){
                InOrder(root);
            }else if (str.substr(0, 4) =="opre"){
                Preorder(root);
            }else if (str.substr(0, 5) =="opost"){ 
                Postorder(root);
            }
        }else {

            string sen= str.substr(1);
            stringstream convert_stm(sen);
            convert_stm >> key;

            if (str.substr(0, 1) =="i") {
                root = Insert(root, key);
            }         

            else if (str.substr(0, 1) =="d") {
                root = TreeDelete(root, key);
            }
        }
    }
    return 0;
}