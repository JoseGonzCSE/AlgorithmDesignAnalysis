// lab 05 

#include <iostream>
#include <string.h>
#include <vector>

using namespace std;
void CountingSort(vector<int>** Array, int A2, int size){

	int i = 0;
	int j = 1;
	int m = 0;
	int k = size-1;

	int *Array1 = new int[size];
	vector<int>* Array2 = new vector<int>[size];

	int Num [10];
	memset(Num, 0, 10*sizeof(int));


	while(i < size){
		Num [(*Array)[i][A2]]+=1;
		i++;
	}
	

	while(j < 10){
		Num [j] += Num [j-1];
		j++;
	}


	while(k>=0){
		Array1 [Num[(*Array)[k][A2]]-1] = k;
		Num[(*Array)[k][A2]]--;
		k--;
	}


	while(m<size){
		Array2[m] = (*Array)[Array1[m]];
		m++;
	}
}




void Radix_Sort(vector<int>** Vec, int size){
	for (int i = 9; i >= 0; i--){	
		CountingSort(Vec, i, size);
	}
}

int main(){

int size;
cin>>size;
vector<int>* Vec = new vector<int>[size];

int input;
int i = 0;

while(i<size){
	int j = 0;
	while(j<10){
		cin>>input;
		Vec[i].push_back(input);
		j++;
		}
		i++;
	}

Radix_Sort(&Vec, size);

int k = 0;
while( k < size){
	
	for (auto yeet = Vec[k].begin(); yeet != Vec[k].end(); yeet++){
		cout << *yeet << ';';	
		}

		k++;
		cout << endl;
		
	}

return 0;
}

