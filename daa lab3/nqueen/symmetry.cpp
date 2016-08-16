#include <stdio.h>
#include <math.h>
#define true 1
#define false 0

int numberSol = 0;

int allsol[100000][100];

void print(int *sol, int n) {
	int i, j, q;
	for(i = 0; i < n; i++) {
		q = sol[i];
		for(j = 0; j < n; j++) {
			if(j == q) {
				printf("Q ");
			} else {
				printf(". ");
			}
		}
		printf("\n");
	}
	printf("\n");
	
/*	for (i = 0; i < n; i++) {
		printf("%d\t", sol[i]);
	}
	printf("\n");*/

}
int xSymmetric(int * x, int *y, int n) {
	int i;
	 for(i = 0; i < n; i++) {
	 	if(x[i] != n - 1 - y[i]) {
	 		return false;
	 	}
	 }
	 return true;
}

int ySymmetric(int *x, int *y, int n) {
	int i;
	for(i = 0; i < n; i++) {
		if(x[i] != y[n - 1 - i]) {
			return false;
		}
	}
	return true;
}
int isRotation(int *x, int *y, int n) {
	int i;
	int isRotation90, isRotation180, isRotation270;

	isRotation270 = isRotation180 = isRotation90 = true;

	for(i = 0; i < n; i++) {
		if(y[x[i]] != n - 1 - i) {
			isRotation90 = false;
		}
	}

	for(i = 0; i < n; i++) {
		if(y[n - 1 - i] != n - 1 - x[i]) {
			isRotation180 = false;
		}
	}

	for(i = 0; i < n; i++) {
		if(y[n - 1 - x[i]] != i) {
			isRotation270 = false;
		}
	}

	if(isRotation90 || isRotation180 || isRotation270) {
		return true;
	} else {
		return false;
	}
}
int isTranspose(int *x, int *y, int n) {
	int i;
	for(i = 0; i < n; i++) {
		if(y[x[i]] != i) {
			return false;
		}
	}
	return true;
}
int isSymmetric(int n, int allsol[][100], int * sol){
	int i, j, k, l;
	if(numberSol == 0) return false;
	int symmetric[numberSol];
	for(k = 0; k < numberSol; k++) {
		if(xSymmetric(allsol[k], sol, n)) {
			return true;
		}
		if(ySymmetric(allsol[k], sol, n)) {
			return true;
		}
		if(isRotation(allsol[k], sol, n)) {
			return true;
		}
		int mirrorImage[n];
		for(i = 0; i < n; i++) {
			mirrorImage[i] = n - 1 - allsol[k][i];
		}
		if(xSymmetric(mirrorImage, sol, n)) {
			return true;
		}
		if(ySymmetric(mirrorImage, sol, n)) {
			return true;
		}
		if(isRotation(mirrorImage, sol, n)) {
			return true;
		}
	}

	return false;
}

void add(int n, int allsol[][100], int *sol) {
	int i = numberSol;
	int j;
	for(j = 0; j < n; j++) {
		allsol[i][j] = sol[j];
	}
	numberSol++;
}

int check(int *sol, int n, int current) {
	int i;
	int valid = true;
	for(i = 0; i < current; i++) {
		if(sol[current] == sol[i]) {
			valid = false;
		}
		if(fabs(sol[current] - sol[i]) == fabs(current - i)) {
			valid = false;
		}
	}
	return valid;
}

void nQueens(int n, int allsol[][100], int * sol, int level) {
	if(level == n + 1) {
//		print(sol, n);

		if(!isSymmetric(n, allsol, sol)) {
	//		printf("numberSol = %d\n", numberSol);
		 	add(n, allsol, sol);
		}

		return;
	}
	int i, j;
	for(i = 0; i < n; i++) {
		int valid = true;
		int current = level - 1;
		sol[current] = i;

		if(level > 1) {
			valid = check(sol, n, current);
		}

		if(valid) {
			nQueens(n, allsol, sol, level + 1);
		}

	}

}

int main() {
	int n;
	//FILE *ifile = fopen("in.txt", "r");
	//fscanf(ifile, "%d", &n);
	scanf("%d", &n);

	int sol[n];

	nQueens(n, allsol, sol, 1);

	int i, j, q;

	printf("No. of distinct solutions: %d\n", numberSol);
	/* for(i = 0; i < numberSol; i++) {
	 	for(j = 0; j < n; j++) {
	 		printf("%d ", allsol[i][j]);
	 	}
	 	printf("\n");
	 }*/
	// printf("\n");

/*	 for(i = 0; i< numberSol; i++) {
	 	print(allsol[i], n);
	 }
*/
	return 0;
}



