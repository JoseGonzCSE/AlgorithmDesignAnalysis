// Lab 08 Rods and stuff

#include<iostream>
#include<string>
#include<sstream>

using namespace std;
#define MAX_INT 2147483647

int ExtendedBottomUpCut(int p[], int n){
    int *r=new int[n+1]; // doesnt work for 2nd example if just n???
    int *s=new int[n+1];
    r[0]=0;
    for (int j=1;j<=n;j++){
        int q=-MAX_INT;
        for(int i=1;i<=j;i++){ 
            if(q<(p[i]+r[j-i])){
                q=(p[i]+r[j-i]);
                s[j]=i;
            }
        }r[j]=q;
    }//return r[n]; // changed
    cout<< r[n]<<endl;
    while(n>0){
        cout<<s[n]<<" ";
        n=n-s[n];
    }
    return -1;

} 


int main(int argc, const char*argvp[]){
    int length;
    cin>> length;
    int *temp=new int[length+1]; // needs length+1
    temp[0]=0;
    for(int i=1;i<length+1;i++){
        cin>>temp[i];
    }
    cout<<ExtendedBottomUpCut(temp,length)<<endl;
    

    return 0;
}