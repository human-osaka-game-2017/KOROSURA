#ifndef MATRIX_H
#define MATRIX_H

#include<vector>

using std::vector;

struct Matrix {

	std::vector<vector<double>> m_Mat;
	unsigned int m_Row, m_Column;

	Matrix() {};
	Matrix(const vector<vector<double>>&);
	Matrix(const Matrix&);

	Matrix(const unsigned int row, const unsigned int culumn, ...);

	// access grants
	const double&  operator () (unsigned int row, unsigned int col) const;
	int* Size(int *) const;
	double Max() const;
	int* Max(int index[]) const;
	void Transpose();//“]’u
	Matrix* Transpose(Matrix* pMat);
	void SetSize(unsigned int row, unsigned int column);
	void SetSize();
	void InitGaussDistribution(double avg = 0, double standardDeviation = 1);

	// assignment operators
	Matrix& operator *= (const Matrix&);
	Matrix& operator += (const Matrix&);
	Matrix& operator -= (const Matrix&);
	Matrix& operator *= (double);
	Matrix& operator /= (double);
	Matrix& operator += (double);
	Matrix& operator -= (double);

	Matrix& operator = (const Matrix&);

	// unary operators
	Matrix operator + () const;
	Matrix operator - () const;

	// binary operators
	Matrix operator * (const Matrix&) const;
	Matrix operator + (const Matrix&) const;
	Matrix operator - (const Matrix&) const;
	Matrix operator * (double) const;
	Matrix operator / (double) const;
	Matrix operator + (double) const;
	Matrix operator - (double) const;

	bool operator == (const Matrix&) const;
	bool operator != (const Matrix&) const;
};
#endif