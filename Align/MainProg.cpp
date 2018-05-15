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
		cout << "\n The input Matrix is" << endl;
		arr[i].print();
	};
	
	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (arr[i].isSameDim(arr[j])) {
				cout << " Matrix " << i + 1 << " and matrix " << j + 1 << " have the same dimension"<<endl;
			}
		}
	 }
	return 0;
}