// Jose gonzalez Lab 04-2

#include <iostream>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
using namespace std;

// partisions an array using the last int as a pivot point, causeing the left to be less than and the right to be more than the pivot

//r=pivot point
int Partition(int Array[],int p,int r){
    
    int x= Array[r];//pivot point.
    int i= p-1;//left?
    int temp;

    for (int j=p;j<=r-1;j++){
        if(Array[j]<=x){
            i=i+1;
            temp=Array[i];
            Array[i]=Array[j];
            Array[j]=temp;
        }
    }
    int temp2=Array[i+1];
    Array[i+1]=Array[r];
    Array[r]=temp2;
    return i+1;
}





int Randomized_Partition(int Array[],int p,int r){

    int temp;
    int min=p;
    int max=r;

    int i= rand()%(max-min+1)+min;

    temp= Array[r];
    Array[r]=Array[i];
    Array[i]=temp;

    return Partition(Array,p,r);

}


void RandomQuickSort(int Array[],int p, int r){
    if (p<r){
        int q=Randomized_Partition(Array,p,r);
        RandomQuickSort(Array,p,q-1);
        RandomQuickSort(Array,q+1,r);
    }
}




int main(int argc,char **argv){
    
    srand (time(NULL));
    //setting up the array for Merge sort
    int *Array;
    int size=1;
    cin>>size;
    
    Array=new int[size];
    for (int i=0;i<size;i++){
        cin>>Array[i];
    }

    RandomQuickSort(Array,0,size-1);
   
   for (int k=0;k<size;k++){
        cout<< Array[k]<<";";
    }

    delete[] Array;
    
}