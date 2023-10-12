// Jose gonzalez Lab 5

#include <iostream>

using namespace std;

class record{  // to store each row using this class. 
  public:
    int key[11]; // for simplicity, we use indices 1-10. 

  record()
  {
    for(int i=1;i<=10;i++)
    key[i] = 0;
  }
};


int Length=0;
int Size=0;

void length(int length){
    Length= length-1;
    Size=length;
}

/*-------------------------------------------------------*/
 int InsertionSort(int Array[],int size){
 for(int j=1;j<size;j++){

        int key=Array[j]; // main number we are looking at
        int left=j-1; // The number to the left 
        
        // While loop will swap(shift) left to the right if it is greater than the subject we are looking at
        
        while(left>=0 && Array[left]>key){
            Array[left+1]=Array[left];
            left=left-1;
        }
        Array[left+1]=key;
    }
 }
/*-------------------------------------------------------*/

/*
COUNTINGSORT 
int CountingSort(int Array[],int ArrayB[],int k){
  int *ArrayC;
  ArrayC=new int [k];

  for (int i=0;i<k;i++){
    ArrayC[i]=0;
  }
  for (int j=0; j<Length;j++){
    ArrayC[Array[j]]=ArrayC[Array[j]]+1;
  }

  for (int i=0;i<k;i++){
    ArrayC[i]= ArrayC[i]+ ArrayC[i-1];
  }
  for (int j=Length;j>0;j--){
    ArrayB[ArrayC[Array[j]]]=Array[j];
    ArrayC[Array[j]]=ArrayC[Array[j]]-1;
  }
}
*/

// Global variables that can be accessed anywhere. Not recommend for serious programming. 

record* A;
int arraySize;

 int RadixSort(record A,int d){
     for(int i=1;i<d;i++){
          
     }
 }



int main(int argc,char **argv) {

  // Get the size of the sequence
  cin >> arraySize;
  length(arraySize);
  A = new record[arraySize+1];

  // Continue reading sequences until there is no more
  for(int i=1;i<=arraySize;i++)
  {
    for(int j=1;j<=10;j++)
    {
       cin >> A[i].key[j];
    }
  } 
  // Free allocated space
  delete[] A;

  return 1;
}





/*
int main(int argc,char **argv){
    
    
    int *Array;
    int size=1;
    cin>>size;
    
    Array=new int[size];
    for (int i=0;i<size;i++){
        cin>>Array[i];
    }

    
   
   for (int k=0;k<size;k++){
        cout<< Array[k]<<";";
    }

    delete[] Array;
    
}
*/