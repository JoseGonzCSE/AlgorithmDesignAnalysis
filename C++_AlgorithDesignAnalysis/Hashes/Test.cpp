//
//  main.cpp
//  lab06
//
//  Created by Andres Rios on 3/15/19.
//  Copyright © 2019 Andres Rios. All rights reserved.
#include <iostream>
#include<list>
using namespace std;
//collaborated with cristian ortiz
int m;
//array of lists
//last edit at 8:17
void hashinsertion(list<int>T[],int k){
    
    int j=k%m;
    
  //taken from lecture notes
   
    T[j].push_front(k);
    
}

void hashsearch(list<int>T[], int k){
    
    list <int> :: iterator z;
    
    int i=0;
    bool found=false;
    int j=k%m;


    z = T[j].begin();
    while (z!=T[j].end()){
        if(*z==k){
            
            cout<<k<<":FOUND_AT"<<j<<","<< i<<";"<<endl;
            found=true;
            break;
        }else{
            cout<<k<<":NOT_FOUND;"<<endl;
            break;
        }
        i++;
        z++;
    }
}
    
/*
   for(z=T[j].begin();z!=T[j].end();z++){

        if(*z==k){
            
            T[i].erase(z);
            cout<<k<<":DELETED;"<<endl;
            found=true;
            break;
        }
        i++;
    }

    if(!found){
        cout<<k<<":DELETE_FAILED;"<<endl;
    }
}

*/


    /*
    for(it = T[j].begin(); it != T[j].end(); it++){
        //advance(it,j);
        if(*it==k){
            cout<<k<<":FOUND_AT"<<j<<","<< i<<";"<<endl;
            found=true;
        }i++;
    }if(!found){
        cout<<k<<":NOT_FOUND;"<<endl;
    }
*/

   // for(int i =0; i<m;i++){
    
   

    
    
    



void hashdelete(list<int>T[],int k){
    list <int> :: iterator it;
    int i=0;
    bool deleted=false;
    int j=k%m;
    
    it = T[j].begin();
    while (it!=T[j].end()){
        if(*it==k){
            
            T[i].erase(it);
            cout<<k<<":DELETED;"<<endl;
           deleted=true;
            break;
        }else{
             cout<<k<<":DELETE_FAILED;"<<endl;
             break;
        }
        i++;
        it++;
        
    }
    /*
    for(it = T[j].begin(); it != T[j].end(); ++it){
        //advance(it,j);
        if(*it==k){
            T[i].erase(it);
            cout<<k<<":DELETED;"<<endl;
            deleted=true;
            break;
            //break loop to help from deleting more than one if there are repeating numbers
        } i++;
    }if(!deleted){
        cout<<k<<":DELETE_FAILED;"<<endl;
    }
    */
}
void printtable(list<int>T[]){
    //help with iterators from https://en.cppreference.com/w/cpp/container/list
    list <int> :: iterator it;
    for(int i = 0; i<m;i++){
        cout<<i<<":";
        for(it = T[i].begin(); it != T[i].end(); ++it){
            cout<<*it<<"->";
        }
        cout<<";"<<endl;
    }
    

}

int main(int argc, const char * argv[]) {
    //collaborated with cristian ortiz for while loop
    cin>>m;
    char func;
    int k;
    list<int>T[m];
    
    while(m!=0){
        cin>>func;
         if(func=='i'){
            cin>>k;
            hashinsertion(T, k);
        }
        else if(func=='s'){
            cin>>k;
            hashsearch(T, k);
        }
        else if (func=='o'){
            printtable(T);
        }
        else if (func=='d'){
            cin>>k;
            hashdelete(T, k);
        }
        else if(func=='e'){
            break;
        }
        
    }
    return 0;
}