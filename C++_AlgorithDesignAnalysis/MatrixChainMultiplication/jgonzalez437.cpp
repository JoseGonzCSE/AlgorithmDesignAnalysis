// Lab 09 Matrix Chain Multiplication

#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<limits.h>
//use vectors


using namespace std;

#define MAX_INT 2147483647
vector<vector<int>>x;

void Print(vector<vector<int>>s, int i, int j){

    if (i==j){
        cout<< "A"<<i-1; // << i-1;?
    }else{
        cout<<"(";
        Print(s,i,s[i][j]);
        Print(s,s[i][j]+1,j);
        cout<<")";
    }
}

int MatrixChain(int n,int p[]){
   /* Doesn't work 
    int** m = new int*[n+1];
    for(int i = 0; i < n; i++)
    m[i] = new int[n]; 
    */
    int m[n+1][n];
    x.resize(n,vector<int>(n+1));
    //from the book correct
    for(int i=1;i<=n;i++){
        m[i][i]=0;
    }
    for(int l=2;l<=n;l++){
        for (int i=1;i<=n-l+1;i++){
            int j=i+l-1;
            m[i][j]=MAX_INT;
            for(int k=i;k<=j-1;k++){
                int q= m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];//+ p shits
                if(q<m[i][j]){
                    m[i][j]=q;
                    x[i][j]=k;
                }
            }
        }
    }
    cout<<m[1][n]<<endl;
    Print(x,1,n);
    return m[1][n];
}

int main(int argc, const char*argvp[]){
    
    int length;
    cin>> length;
    int *temp=new int[length+1]; // needs length+1
    //temp[0]=0;

    for(int i=0;i<=length;i++){
        cin>>temp[i];
    }
    MatrixChain(length,temp);
    cout<< endl;
    

    return 0;
}