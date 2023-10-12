// Jose Gonzalez Lab 02 MergeSort
#include <iostream>

using namespace std;
#define MAX_INT 2147483647

// function to merge multiple arrays, crazy huh?
void Merge(int Array[],int left,int mid, int right){
    // p= left, q=mid, r= right (psudocode note)

    // n1=left, n2=right max of that side
    int n1=mid-left+1;
    int n2= right-mid;

    //create 2 new arrays for each side using above variables

    int *lArray=new int[n1+1]; 
    int *rArray=new int [n2+1];  

    //copies contents of the main array into the temp array respectfully 
    for(int i=left;i<=mid;i++){ 
        lArray[i-left]=Array[i];
    } 
    for(int j=mid+1;j<=right;j++){ 
        rArray[j-1-mid]=Array[j];
    }
    
    /* set sental values to simplify code and avoid while loops
    These act as a stopping point, dont need to check if we reached
    the end of each array.
    */

    lArray[1+mid-left]=MAX_INT;
    rArray[right-mid]=MAX_INT;

    //Initializers for the upcoming loops
    int a=0;
    int b=0;

    //for the whole array
    for(int k=left;k<=right;k++){
        //puts the lowest in comparasion to Left and Right into the main array.
        if(lArray[a]<=rArray[b]){
            Array[k]=lArray[a];
            a=a+1;
        }
        else{
            Array[k]=rArray[b];
            b=b+1;
        }
    }
    delete[] lArray;
    delete[] rArray;
}

//Recursion use for merge sort.
void MergeSort(int Array[], int start, int last){
    //base case: one num in array, do nothing

    //Find Mid point, Merge sort left then right side of array
    //combines results using merge.
    if(start+1<last){
        int mid= start+(last-start)/2;
        MergeSort(Array,start,mid);
        MergeSort(Array,mid+1,last);
        Merge(Array,start,mid,last);
    }
}

int main(int argc,char **argv){
    
    //setting up the array for Merge sort
    int *Array;
    int size=1;
    cin>>size;
    Array=new int[size];
    for (int i=0;i<size;i++){
        cin>>Array[i];
    }
   
    MergeSort(Array,0,size-1);
    
    //print results
    for (int k=0;k<size;k++){
        cout<< Array[k]<<";";
    }

    delete[] Array;
    
}