// Jose Gonzalez Lab 03 Finding Max
//O(nlogn)
#include <iostream>

using namespace std;
//Max for use of infinite in the psudocode
#define MAX_INT 2147483647

// not void because we are returning numbers 
int Find_Max_Cross_SubArr(int A[],int low, int mid,int high){
    // returns indices of a max subarray that crosses the mid point and the sum of the values in Max Array

    //initializers 

    int left_sum=-MAX_INT;
    int sum=0;
    int maxLeft=0;
    int maxRight=0;
    int rightSum=0;

    //cut Array from Mid point
    // Find the sum for left of mid and the Max # of left
    for(int i=mid; i>=low; i--){ 
        sum=sum+A[i];
        if (sum>left_sum){
            left_sum=sum;
            maxLeft=i;
        }
    }

    //resets sum and go again
    rightSum=-MAX_INT;
    sum=0;
    // This time for the Right of Mid
    for (int j=mid+1; j<=high; j++){ 
        sum=sum+A[j];
        if(sum>rightSum){
            rightSum=sum;
            maxRight=j;
        }
    }
    //returns multiple variables, but most importantly the compplete Sum
    return (maxLeft,maxRight,left_sum+rightSum);
}

//Finding the Max number given Values in an Array
int Find_Max_SubArr(int Array[],int low,int high){
    
    //Initializers
    int leftLow=0;
    int leftHigh=0;
    int leftSum=0;

    int rightLow=0;
    int rightHigh=0;
    int rightSum=0;

    int crossLow=0;
    int crossHigh=0;
    int crossSum=0;



    //base case, One element array
    if(high==low){
        return (low,high,Array[low]);
    }
    //find mid point
    int mid= (low+high)/2;
    //Find Max of left of mid
    (leftLow,leftHigh,leftSum)=Find_Max_SubArr(Array,low,mid);
    //Find Max of right of mid
    (rightLow,rightHigh,rightSum)=Find_Max_SubArr(Array,mid+1,high);
    //Find Max of combination
    (crossLow,crossHigh,crossSum)=Find_Max_Cross_SubArr(Array,low,mid,high);

    // If Left contains the Max of Array, returns sum
    if(leftSum>=rightSum && leftSum>=crossSum){
        return (leftLow,leftHigh,leftSum);
    }
    //If Right contains the Max of Array, returns sum
    else if(rightSum>=leftSum && rightSum>=crossSum){
        return (rightLow,rightHigh,rightSum);
    }
    //Max uses both, Returns sum.
    else
        return (crossLow,crossHigh,crossSum);

}




int main(int argc,char **argv){
    
    //setting up the array 
    int *Array;
    int size=1;
    cin>>size;
    Array=new int[size];
    for (int i=0;i<size;i++){
        cin>>Array[i];
    }

    //assignment
    cout<< Find_Max_SubArr(Array,0,size-1);
   
   
    delete[] Array;
    
}