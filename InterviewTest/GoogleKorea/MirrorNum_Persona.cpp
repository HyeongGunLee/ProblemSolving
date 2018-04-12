#include <stdio.h>

int cand[5] = {0,1,6, 8, 9};

void printarr(int arr[100], int index){
	int i;
	for(i=0; i<index; i++){
		printf("%d", arr[i]);
	}
}

void printarr_rev(int arr[100], int index){
	int i;
	for(i=index-1; i>=0; i--){
		if(arr[i] == 6) printf("%d", 9);
		else if(arr[i] == 9) printf("%d", 6);
		else printf("%d", arr[i]);
	}
	printf("\n");
}

void solve(int n, int arr[100], int index){

	if(n % 2 == 0 && index == n/2){
		
		printarr(arr, index);
		printarr_rev(arr, index);
		return;
	}
	else if(n%2 != 0 && index == n/2){
		printarr(arr, index);
		printf("0");
		printarr_rev(arr, index);

		printarr(arr, index);
		printf("1");
		printarr_rev(arr, index);

		printarr(arr, index);
		printf("8");
		printarr_rev(arr, index);
		return;
	}

	if(index == 0){
		int i;
		for(i=1; i<5; i++){
			arr[index] = cand[i];
			solve(n, arr, index+1);
		}
	} 
	else{
		int i;
		for(i=0; i<5; i++){
			arr[index] = cand[i];
			solve(n, arr, index+1);
		}
	}

}

int main(){

	int n;
	scanf("%d", &n);

	int arr[100];
	solve(n, arr, 0);

}
