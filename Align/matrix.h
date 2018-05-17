#ifndef MATRIX_H
#define MATRIX_H

#include<iostream>
#include<vector>
#include"exceptions.h"
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

	bool isSameDim(const Matrix<T> & n)
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

	Matrix<T> operator + (const Matrix<T> & other)
	{
		if (!isSameDim(other)) { throw E("Dimensions not suitable for Matrix addition\n"); }
		Matrix<T> result(row, col);
		for (int r = 0; r< row; r++)
		{
			for (int c = 0; c<col; c++)
			{
				result[r][c] = data[r][c] + other.data[r][c];
			} 
		}
		return result; 
		
	}; //operator +

	Matrix<T> operator - (const Matrix<T> & other)
	{
		if (!isSameDim(other)) { throw E(" Dimensions not suitable for Matrix subtraction \n"); }

			Matrix<T> result(row, col);
			for (int r = 0; r< row; r++)
			{
				for (int c = 0; c<col; c++)
				{
					result[r][c] = data[r][c] - other.data[r][c];
				}
			}
			return result;
	}; //operator -

	Matrix<T> operator * (const Matrix<T> & other)
	{
		if (col != other.row) { throw E(" Dimensions not suitable for Matrix multiplication \n"); }
		Matrix<T> result(row, other.col);
		for (int r = 0; r < result.row; r++)
			{
				for (int c = 0; c < result.col; c++)
				{   
					for (int i = 0; i < col; i++)
					{
						result[r][c] += data[r][i] * other.data[i][c];
					}
					
				}
			}
		return result;
	} // operator*
};




#endif // !MATRIX_H

