// Huffman
#include<iostream>
#include<string>
#include<queue>
#include<map>

using namespace std;
map<char,string>Z;
#define MAX_INT 2147483647

struct Node {
  int key;  // Value of the node
  char symbol;
  int frequency;
  Node *left;   // Pointer to the left node
  Node *right;  // Pointer to the right node
  Node *p; // Pointer to the parent node
};


struct compare{
    bool operator()(Node *left, Node*right){
        return left->frequency>right->frequency;
    }
};

Node* update(char Symbol,int Frequency){
    Node* x=new Node();
    x->symbol=Symbol;
    x->frequency=Frequency;

    return x;
}
priority_queue<Node *, deque<Node *>, compare> test;
//n=6 since letters are up to F only.
void Huffman(){
    Node* x=new Node();
    Node* y=new Node();
   
    //min priority que

    for(int i=6;i!=1;i--){
        Node* z=new Node();
        
        x=test.top();
        test.pop();
        y=test.top();
        test.pop();
        z=update(' ',(x->frequency+y->frequency));
        z->right=y;
        z->left=x;
        test.push(z);
    }
}

void code(Node* test,string x,int i){
    char alphabet[]={'A','B','C','D','E','F','G'};

    //base case
    if (test==nullptr){
        return;
    }

    if(test->symbol==alphabet[i]){
        Z.insert(make_pair(alphabet[i],x));
    }else{
        code(test->left,x+"0",i);
        code(test->right,x+"1",i);
    }


}

int main(int argc, const char*argvp[]){
    
    int frequency;

    for(int i=0;i<6;i++){
        cin>>frequency;
        if(i==0){
            test.push(update('A',frequency));
        }else if (i==1){
            test.push(update('B',frequency));
        }else if (i==2){
            test.push(update('C',frequency));
        }else if (i==3){
            test.push(update('D',frequency));
        }else if (i==4){
            test.push(update('E',frequency));
        }else if (i==5){
            test.push(update('F',frequency));
        }
    }Huffman();
    for(int i=0;i<6;i++){
        code(test.top(),"",i);
        
    } map<char, string>::iterator y = Z.begin();
    while(y != Z.end()){
        cout<<y->first<<":"<<y->second<<endl;
        y++;
    }
    return 0;
}