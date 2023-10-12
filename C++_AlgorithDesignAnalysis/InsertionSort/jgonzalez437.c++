// Jose Gonzalez Lab 01 Insertion sort
#include <iostream>

using namespace std;


int main(int argc,char **argv){
    //setting up the array for insertion sort
    int *Array;
    int size=1;
    cin>>size;
    Array=new int[size];
    for (int i=0;i<size;i++){
        cin>>Array[i];
    }
    //Array is now created with input
    
    //Insertion Sort start:

    int pyramid=1;// used in order to produce the desired output for the Lab
    for(int j=1;j<size;j++){

        int key=Array[j]; // main number we are looking at
        int left=j-1; // The number to the left 
        
        // While loop will swap(shift) left to the right if it is greater than the subject we are looking at
        
        while(left>=0 && Array[left]>key){
            Array[left+1]=Array[left];
            left=left-1;
        }
        //updates with new key + increases pyramid size
        Array[left+1]=key;
        pyramid=pyramid+1;

        //for loop to produce output after each itteration
       
       for(int k=0;k<pyramid;k++){
            cout<< Array[k]<<";";
            }
            cout<<endl;  
    }
    delete[] Array;
}