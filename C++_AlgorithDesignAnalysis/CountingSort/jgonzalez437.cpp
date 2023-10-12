//lab05
#include <iostream>
#include <string.h>
#include <vector>

using namespace std;

void CountingSort(vector<int>** Array, int A2, int size){
	
	int *Array2 = new int[size];
	vector<int> *Array3 = new vector<int>[size];
	int Num[10];
	memset(Num,0,sizeof(int)*10);
	
	for (int i=0;i<size;i++){
		Num[ (*Array)[i][A2] ]++;
	}

	for(int j=1;j<10;j++){
		Num[j] += Num[j-1];
	}

	for(int k=size-1;k>=0;k--){
		Array2 [Num[(*Array)[k][A2]]-1 ] = k;
		Num[ (*Array)[k][A2] ] --;
	}

	for(int m=0;m<size;m++){
		Array3[m] = (*Array)[Array2[m]];
	}
	*Array = Array3;
}

void RadixSort(vector<int>** Vector, int size){
	
	for (int i = 9; i >= 0; i--){	
		CountingSort(Vector, i, size);
	}

}

int main(){
	
	int user;
	int size;
	cin>>size;
	vector<int>* Vector = new vector<int>[size];

	for(int i=0;i<size;i++){
		for(int j=0;j<10;j++){
			cin>>user;
			Vector[i].push_back(user);
		}
	}
	
	RadixSort(&Vector, size);

	
	for(int i=0;i<size;i++){
		for(auto j=Vector[i].begin();j!=Vector[i].end();j++ ){
			cout<< *j<<';';
		}
		cout<<endl;
	}
	return 0;
}

