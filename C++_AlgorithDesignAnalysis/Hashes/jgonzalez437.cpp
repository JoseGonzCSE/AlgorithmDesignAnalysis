//lab 07 Hash

#include<iostream>
#include<string>
#include<sstream>
#include <vector>
#include <list>

using namespace std;
int m;

struct Node {
  int key;   // Value of the node
  Node *left;   // Pointer to the left node
  Node *right;  // Pointer to the right node
  Node *p; // Pointer to the parent node
};

void Search(list<int> T[], int k){
    list<int>::iterator z;

    bool correct=false;
    int i=0;
    int j=k%m;

    for(z=T[j].begin();z!=T[j].end();z++){
        if(*z==k){
            cout<<k<<":FOUND_AT"<<j<<","<< i<<";"<<endl;
            correct=true;
        }i++;
    }if(!correct){
        cout<<k<<":NOT_FOUND;"<<endl;
    }

}

void Insert(list<int> T[], int k){
    int j=k%m;
    T[j].push_front(k);
}

void Delete(list<int> T[], int k){
    list <int>::iterator z;

    bool correct=false;
    int i=0;
    int j=k%m;

    for(z=T[j].begin();z!=T[j].end();z++){

        if(*z==k){
            
            T[i].erase(z);
            cout<<k<<":DELETED;"<<endl;
            correct=true;
            break;
        }i++;
    }if(!correct){
        cout<<k<<":DELETE_FAILED;"<<endl;
    }
}

void Output(list<int> T[]){
    list <int>::iterator z;

    for(int i=0;i<m;i++){
        cout<<i<<":";
        for(z=T[i].begin();z!=T[i].end();z++){
            cout<<*z<<"->";
        }cout<<";"<<endl;
    }
}


int main(int argc, char const *argv[]) {
    

    int k;
    char test;
    cin>>m;
    list<int>*T=new list<int>[m];

    while(m!=0){
        cin>>test;

        if(test=='i'){
            cin>>k;
            Insert(T,k);
        }else if(test=='d'){
            cin>>k;
            Delete(T,k);
        }else if(test=='s'){
            cin>>k;
            Search(T,k);
        }else if(test=='o'){
            Output(T);
        }else if(test=='e'){
             break;
        }
    } 
    delete[] T;
   return 0;
}