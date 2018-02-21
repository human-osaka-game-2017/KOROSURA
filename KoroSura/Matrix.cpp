#include "Matrix.h"
#include<random>
#include<Windows.h>

Matrix::Matrix(const vector<vector<double>>& mat) {
	m_Column = mat[0].size();
	m_Row = mat.size();
	for (unsigned int i = 0; i < m_Row; ++i) {
		if (m_Column != mat[i].size()) {
			MessageBox(0, "ñ≥å¯Ç»çsóÒÇ™ì¸óÕÇ≥ÇÍÇ‹ÇµÇΩ", "", MB_OK);
		}
	}
	m_Mat = mat;
}

Matrix::Matrix(const Matrix& mat) {
	m_Mat = mat.m_Mat;
	m_Row = mat.m_Row;
	m_Column = mat.m_Column;
}

Matrix::Matrix(const unsigned int row, const unsigned int column, ...) {

	m_Mat = vector<vector<double>>(row, vector<double>(column));
	m_Row = row;
	m_Column = column;

	va_list list;
	va_start(list, column);

	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			m_Mat[i][j] = va_arg(list, double);
		}
	}

	va_end(list);
}

const double& Matrix::operator () (unsigned int row, unsigned int col) const {
	return m_Mat[col][row];
}

int* Matrix::Size(int* pSize) const{
	pSize[0] = m_Row;
	pSize[1] = m_Column;
	return pSize;
}

double Matrix::Max() const{
	double retMax = m_Mat[0][0];
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			if (retMax < m_Mat[i][j]) {
				retMax = m_Mat[i][j];
			}
		}
	}

	return retMax;
}

int* Matrix::Max(int index[]) const {
	double max = m_Mat[0][0];
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			if (max < m_Mat[i][j]) {
				max = m_Mat[i][j];
				index[0] = i;
				index[1] = j;
			}
		}
	}

	return index;
}

void Matrix::Transpose() {
	vector<vector<double>> tmpMat = vector<vector<double>>(m_Column, vector<double>(m_Row));
	for (int i = 0; i < m_Row; ++i) {
		for (int j = 0; j < m_Column; ++j) {
			tmpMat[j][i] = m_Mat[i][j];
		}
	}

	unsigned int tmp = m_Row;
	m_Row = m_Column;
	m_Column = tmp;
	m_Mat = tmpMat;
}

Matrix* Matrix::Transpose(Matrix* pMat) {
	vector<vector<double>> tmp = vector<vector<double>>(m_Column, vector<double>(m_Row));
	for (int i = 0; i < m_Row; ++i) {
		for (int j = 0; j < m_Column; ++j) {
			tmp[j][i] = m_Mat[i][j];
		}
	}

	pMat->m_Mat = tmp;
	pMat->m_Column = m_Row;
	pMat->m_Row = m_Column;
	return pMat;
}

void Matrix::SetSize(unsigned int row, unsigned int column) {
	m_Row = row;
	m_Column = column;
}

void Matrix::SetSize() {
	m_Column = m_Mat[0].size();
	m_Row = m_Mat.size();
}

void Matrix::InitGaussDistribution(double avg,double standardDeviation) {
	std::random_device seed_gen;
	std::default_random_engine engine(seed_gen());

	// ïΩãœ0.0ÅAïWèÄïŒç∑1.0Ç≈ï™ïzÇ≥ÇπÇÈ
	std::normal_distribution<> dist(avg, standardDeviation);

	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			// ê≥ãKï™ïzÇ≈óêêîÇê∂ê¨Ç∑ÇÈ
			m_Mat[i][j] = dist(engine);
		}
	}
}

Matrix& Matrix::operator *= (const Matrix& mat) {
	*this = *this * mat;
	return *this;
}

Matrix& Matrix::operator += (const Matrix& mat) {
	*this = *this + mat;
	return *this;
}

Matrix& Matrix::operator -= (const Matrix& mat) {
	*this = *this - mat;
	return *this;
}

Matrix& Matrix::operator *= (double c) {
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			m_Mat[i][j] *= c;
		}
	}

	return *this;
}

Matrix& Matrix::operator /= (double c) {
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			m_Mat[i][j] /= c;
		}
	}

	return *this;
}

Matrix& Matrix::operator += (double c) {
	*this = *this + c;
	return *this;
}

Matrix& Matrix::operator -= (double c) {
	*this = *this - c;
	return *this;
}

Matrix Matrix::operator + () const {
	return *this;
}

Matrix Matrix::operator - () const {
	Matrix tmp;
	tmp.m_Mat= vector<vector<double>>(m_Row, vector<double>(m_Column));
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			tmp.m_Mat[i][j] = m_Mat[i][j] * -1.0;
		}
	}

	return tmp;
}

Matrix Matrix::operator * (const Matrix& mat) const {

	if (m_Column != mat.m_Row) {
		MessageBox(0, "Ç±ÇÃçsóÒä|éZÇÕñ≥å¯Ç≈Ç∑", "", MB_OK);
	}

	vector<vector<double>> returnMat;
	returnMat = vector<vector<double>>(m_Row, vector<double>(mat.m_Column));

	double tmp = 0.0;
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < mat.m_Column; ++j) {
			for (unsigned int k = 0; k < m_Column; ++k) {
				tmp += m_Mat[i][k] * mat.m_Mat[k][j];
			}
			returnMat[i][j] = tmp;
			tmp = 0.0;
		}
	}

	return Matrix(returnMat);
}

Matrix Matrix::operator + (const Matrix& mat) const {

	if (m_Column != mat.m_Column || m_Row!=mat.m_Row) {
		MessageBox(0, "Ç±ÇÃçsóÒë´ÇµéZÇÕñ≥å¯Ç≈Ç∑", "", MB_OK);
	}

	vector<vector<double>> returnMat;
	returnMat = vector<vector<double>>(m_Row, vector<double>(m_Column));
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			returnMat[i][j] = m_Mat[i][j] + mat.m_Mat[i][j];
		}
	}

	return Matrix(returnMat);
}

Matrix Matrix::operator - (const Matrix& mat) const {

	if (m_Column != mat.m_Column || m_Row != mat.m_Row) {
		MessageBox(0, "Ç±ÇÃçsóÒà¯Ç´éZÇÕñ≥å¯Ç≈Ç∑", "", MB_OK);
	}

	vector<vector<double>> returnMat;
	returnMat = vector<vector<double>>(m_Row, vector<double>(m_Column));
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			returnMat[i][j] = m_Mat[i][j] - mat.m_Mat[i][j];
		}
	}

	return Matrix(returnMat);
}

Matrix Matrix::operator * (double c) const {
	vector<vector<double>> returnMat;
	returnMat = vector<vector<double>>(m_Row, vector<double>(m_Column));
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			returnMat[i][j] = m_Mat[i][j] * c;
		}
	}

	return Matrix(returnMat);
}

Matrix Matrix::operator / (double c) const {
	vector<vector<double>> returnMat;
	returnMat = vector<vector<double>>(m_Row, vector<double>(m_Column));
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			returnMat[i][j] = m_Mat[i][j] / c;
		}
	}

	return Matrix(returnMat);
}

Matrix Matrix::operator + (double c) const {
	vector<vector<double>> returnMat;
	returnMat = vector<vector<double>>(m_Row, vector<double>(m_Column));
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			returnMat[i][j] = m_Mat[i][j] + c;
		}
	}

	return Matrix(returnMat);
}

Matrix Matrix::operator - (double c) const {
	vector<vector<double>> returnMat;
	returnMat = vector<vector<double>>(m_Row, vector<double>(m_Column));
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			returnMat[i][j] = m_Mat[i][j] - c;
		}
	}

	return Matrix(returnMat);
}

bool Matrix::operator == (const Matrix& mat) const {
	vector<vector<double>> returnMat;
	returnMat = vector<vector<double>>(m_Row, vector<double>(m_Column));
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			if (m_Mat[i][j] != mat.m_Mat[i][j]) {
				return false;
			}
		}
	}

	return true;
}

bool Matrix::operator != (const Matrix& mat) const {
	vector<vector<double>> returnMat;
	returnMat = vector<vector<double>>(m_Row, vector<double>(m_Column));
	for (unsigned int i = 0; i < m_Row; ++i) {
		for (unsigned int j = 0; j < m_Column; ++j) {
			if (m_Mat[i][j] == mat.m_Mat[i][j]) {
				return false;
			}
		}
	}

	return true;
}

Matrix& Matrix::operator = (const Matrix& mat) {
	this->m_Mat = mat.m_Mat;
	this->m_Column = mat.m_Column;
	this->m_Row = mat.m_Row;
	return *this;
}