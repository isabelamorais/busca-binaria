#include<iostream>
using namespace std;

void selectionSort(int *vetor,int n){
	int menor, aux;
	for(int i=0;i<n-1;i++){
		menor = i;
		for(int j=i+i;j<n;j++){
			if(vetor[j]<vetor[menor])
				menor = j;
		}
		if(menor!=i){
			aux = vetor[menor];
			vetor[menor] = vetor[i];
			vetor[i] = aux;
		}
	}
}

int buscaBinaria(int *vetor,int n, int x){
	int aux=n/2,min=0,max=n-2;

	while(min!=max){
		if(x==vetor[aux])
			return aux;
		if(x>vetor[aux])
			min=aux;
		else
			max=aux;
		aux=(max+min)/2;		
	}
	if(x==vetor[aux+1])
		return aux+1;
	return -1;
}

int main(){
	int *vetor, n, elemento;
	
	cout<<"n = ";
	cin>>n;
	
	vetor = new int [n];
	
	for(int i=0;i<n;i++){
		cout<<"Posicao "<<i<<": ";
		cin>>vetor[i];
	}
	
	selectionSort(vetor,n);
	for(int i=0;i<n;i++){
		cout<<"\nPosicao "<<i<<": ";
		cout<<vetor[i];
	}
	
	cin>>elemento;
	cout<<"\n\nPosicao no vetor: "<<buscaBinaria(vetor,n,elemento)<<"\n";
	
	delete vetor;
}
