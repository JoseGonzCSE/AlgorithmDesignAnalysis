// Jose gonzalez Lab 04-1

//heaps and stuff 

#include <iostream>
using namespace std;

int Length=0;
int Size=0;

//gets the length to use in Maxheap in main
void length(int length){
    Length= length-1;
    Size=length;
}

// makes sure heap is max, meaning that the parent node is greater than those below it.
void MaxHeap(int Array[], int i){
    
    int max;
    int r= 2*i+1;
    int l= 2*i;
    int Switch;
    

    // checks if the parent is greater than child
    if(l<Size && Array[l]>Array[i]){
        max=l;
    }else{
        max=i;
    }
    if(r<Size && Array[r]>Array[max]){
        max=r;
    }

    // if max isn't = i, swap max with current i and go again with max 
    if(max!=i){
        Switch=Array[i];
        Array[i]=Array[max];
        Array[max]= Switch;
        MaxHeap(Array,max);
    }

}

// i= parent, creates heap that we will then be able to sort
void BuildMaxHeap(int Array[]){
    for(int i=(Length/2); i>=0;i--){
        MaxHeap(Array,i);
    }
}

//sorting
void HeapSort(int Array[]){
   
    int Switch;
    BuildMaxHeap(Array);
    
    for(int i=Length;i>=1;i--){
        Switch=Array[0];
        Array[0]=Array[i];
        Array[i]=Switch;
        Size=Size-1;
        MaxHeap(Array,0);
    }
}


int main(int argc,char **argv){
    
    //setting up the array for Merge sort
    int *Array;
    int size=1;
    cin>>size;
    length(size);
    Array=new int[size];
    for (int i=0;i<size;i++){
        cin>>Array[i];
    }
   
   HeapSort(Array);
    
    //print results
    for (int k=0;k<size;k++){
        cout<< Array[k]<<";";
    }

    delete[] Array;
    
}