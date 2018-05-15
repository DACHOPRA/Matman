#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<vector>
using namespace std;

template <typename T>
struct Matrix
{
	int row, col;
	std::vector<vector<T>> data;
	Matrix(int r, int c): row(r),col(c),data(row, std::vector<T>(col)) {};
	std::vector<T> & operator[](int i)
	{
		return data[i];
	};// operator[] overload

	bool isSameDim(Matrix<T> & n)
	{
		if ((row == n.row) && (col == n.col)) { return true; }
		else { return false; }
	};//isSameDim

	void read()
	{
		for (int r = 0; r< row; r++)
		{
			for (int c = 0; c<col; c++)
			{
				cin >> data[r][c];
			}
		}
	}; // read()

	void print()
	{
		for (int r = 0; r< row; r++)
		{
			for (int c = 0; c<col; c++)
			{
				cout <<data[r][c] << " ";
			} cout << endl;
		}
	}; //print()
};




#endif // !MATRIX_H

