#include "matrix.h"

int main() {
	//code
	int n, rows, columns;
	cin >> n;
	vector<Matrix<int>> arr;
	for (int i = 0; i < n; i++)
	{
		cin >> rows >> columns;
		Matrix<int> A(rows, columns);
		A.read();
		arr.push_back(A);
		printf("\nThe input Matrix number %d is\n", i);
		arr[i].print();
	};
	
	for (int i = 0; i < n; i++)
	{
		for (int j = n-1; j >i; j--)
		{
			if (arr[i].isSameDim(arr[j])) {
				cout << "\nMatrix " << i + 1 << " and matrix " << j + 1 << " have the same dimension" << endl;
			}
				try {
					Matrix<int> temp(arr[i].row, arr[i].col);
					temp = arr[i] + arr[j];
					arr.push_back(temp);
					printf("\nThe addition of matrix %d and %d reuslts in the following matrix saved as %d th element in vector \n", i + 1, j + 1, arr.end() - arr.begin());
					arr.back().print();
									}
				catch (exception &e)
				{
					printf("\nFor matrix %d and %d : %s",i+1, j+1, e.what());
				}

				try {
					arr.push_back(arr[i] * arr[j]);
					printf("\nThe multiplication of matrix %d and %d reuslts in the following matrix saved as %d th element in vector \n", i + 1, j + 1, arr.end() - arr.begin());
					arr.back().print();
				}
				catch (exception &e)
				{
					printf("\nFor Matrix %d and %d :%s",i+1, j+1, e.what());
				}
			//}
		}
	 }
	
	
	return 0;
}