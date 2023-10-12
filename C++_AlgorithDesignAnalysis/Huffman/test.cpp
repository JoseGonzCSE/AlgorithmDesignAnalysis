#include<iostream>
#include <deque>
#include<map>
#include<queue>
#include<string>
using namespace std;

map<char, string>C;
struct  Node {
    char letter;
    int freq;
    Node* left;
    Node* right;
   
    
};
struct comparenodes {
    // weak collaboration
   // bool operator ()(const Node& left, const Node& right) {
    bool operator()(Node* left, Node* right){
        //help from http://www.cplusplus.com/reference/algorithm/sort/ for the bool operator
        //discussed comparison type with cristian ortiz
        return (left->freq > right->freq);
    }
};

priority_queue<Node *, deque<Node *>, comparenodes> Q;
//priority queue was instructed by the book
//priority_queue <Type, vector<Type>, ComparisonType > min_heap;
// disscused using a priority queue with cristisn ortiz
Node* Getnew(char letter, int freq){
    Node* newnode= new Node();
    newnode->freq=freq;
    newnode->letter=letter;
    return newnode;
    
}


static void encoding(Node *Q, string enc, int i) {
    //weak collaboration
    char letters[]={'A','B','C','D','E','F'};
    
    if (Q==NULL) {
        return;
    }
    
    if (Q->letter == letters[i]) {
        C.insert(make_pair (letters[i],enc));
    }else {
    encoding(Q->left, enc + "0", i);
    //adds on to the string
    encoding(Q->right, enc + "1", i);
    }
};

void huffmantree(){
   Node* x= new Node();
    //establish new nodes
    Node* y= new Node();
    //establish new nodes
   
   //establish new nodes
    for(int p=6; p!=1;p--){
        Node* z= new Node();
        x = Q.top();
        //x = extractmin(Q)
        //gets new min
        Q.pop();
        //min element gets removed
        y = Q.top();
        Q.pop();
        z = Getnew(' ', (x->freq + y->freq));
        // gets our addition of both nodes being added based on the frequency
        z->left = x;
        //makes left child off of the x min
        z->right = y;
        //makes right child off of the y min

        Q.push(z);
    }
}


int main(){
    int freq;
    
    for(int i=0;i<6;i++){
      
        cin>>freq;
        if (i==0){

            Q.push(Getnew('A', freq));
        }
        if (i==1){
            Q.push(Getnew('B', freq));

        }
        if (i==2){
            Q.push(Getnew('C', freq));

        }
        if (i==3){
            Q.push(Getnew('D', freq));

        }
        if (i==4){
            Q.push(Getnew('E', freq));

        }
        
        if (i==5){
            Q.push(Getnew('F', freq));

        }
    }
       
    huffmantree();
    for (int i = 0; i < 6; i++) {
                encoding(Q.top(), "",i);
    }
    //prints out our encoded letters

     map<char, string>::iterator it = C.begin();
        while(it != C.end()){
                    //
        cout<<it->first<<":"<<it->second<<endl;
                    it++;
        
         }
}