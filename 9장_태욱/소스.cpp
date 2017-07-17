#include <stdio.h>

void show(int(*Mat1)[3], int(*Mat2)[3]);

int main() {
	int Mat1[3][3] = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	int Mat2[3][3] = {
		{ 7,8,9 },
		{ 4,5,6 },
		{ 1,2,3 }
	};
	show(Mat1, Mat2);
}

//2.1
void show(int(*Mat1)[3], int(*Mat2)[3]) {
	
	//2.2
	int result[3][3] = { 0 };

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			int temp = 0;
			//result[i][j] // 2.3.1
			for (int k = 0; k < 3; k++) {
				temp += Mat1[i][k] * Mat2[k][j];
				//2.3.2	
			}
			result[i][j] = temp;
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; ++j)
			printf("%3d ", result[i][j]);
		printf("\n");
	}
}