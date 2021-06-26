// Matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>

using namespace std;

class Matrix {
private:
	vector<vector<int>> M;
	int _rows{ 1 }, _cols{ 1 };
public:
	Matrix(int rows = 1, int cols = 1) :_rows{ rows }, _cols{ cols } {
		M.resize(_rows);
		for (int i = 0; i < _rows; i++) {
			M[i].resize(_cols);
			for (int j = 0; j < _cols; j++)
			{
				M[i][j] = 0;
			}
		}
	}
	Matrix(const Matrix& matrix) : Matrix(matrix._rows, matrix._cols) {
		for (int i = 0; i < _rows; i++) {
			for (int j = 0; j < _cols; j++)
			{
				M[i][j] = matrix.M[i][j];
			}
		}
	}
	///////////////////////////////////////
	void add(int r, int c, int value); 
	int get(int r, int c);
	void trans();

	void show(); 
	////////////////////////////////////////
	friend Matrix operator+ (Matrix m1, Matrix m2);
	friend Matrix operator* (Matrix m1, Matrix m2);
};

void Matrix::add(int r, int c, int value) {
	if (r >= 0 & r < _rows & c >= 0 & c < _cols) {
		M[r][c] = value;
	}
}

int Matrix::get(int r, int c) {
	if (r >= 0 & r < _rows & c >= 0 & c < _cols) {
		return M[r][c];
	}
	else
		return 0;
}

void Matrix::trans() {
	vector<vector<int>> Mtr;
	Mtr.resize(_rows);
	for (int i = 0; i < _rows; i++) {
		Mtr[i].resize(_cols);
		for (int j = 0; j < _cols; j++)
		{
			Mtr[i][j] = M[j][i];
		}
	}

	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++)
		{
			M[i][j] = Mtr[i][j];
		}
	}

	for (int i = 0; i < _rows; i++) {
		Mtr[i].clear();
	}
	Mtr.clear();

}

void Matrix::show() {
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _cols; j++) {
			cout << M[i][j] << "\t";
		}
		cout << "\n";
	}
}

 Matrix operator+ (Matrix m1, Matrix m2) {
	 Matrix m3(m1._rows,m1._cols);
	 if ((m1._cols == m2._cols) & (m1._rows == m2._rows)) {
		 for (int r = 0; r < m1._rows; r++) {
			 for (int c = 0; c < m1._cols; c++) {
				 m3.add(r, c, m1.M[r][c]+m2.M[r][c]);
			 }
		 }
	 }

	 return m3;
}

 Matrix operator* (Matrix m1, Matrix m2) {
	 Matrix m3(m1._rows, m1._cols);
	 if ((m1._cols == m2._cols) & (m1._rows == m2._rows)) {
		 for (int r = 0; r < m1._rows; r++) {
			 for (int c = 0; c < m1._cols; c++) {
				 m3.add(r, c, m1.M[r][c] * m2.M[r][c]);
			 }
		 }
	 }

	 return m3;
 }


int main()
{
	const int ROWS = 5;
	const int COLS = 5;

	Matrix matrix(ROWS, COLS);

	for (int r = 0; r < ROWS; r++) {
		for (int c = 0; c < COLS; c++) {
			matrix.add(r, c, r * 10 + c);
		}
	}

	Matrix matrix2 = matrix;

	matrix.show();

	matrix2.show();

	matrix2.trans();

	matrix2.show();
	cout << endl;

	Matrix m3 = matrix + matrix2;
	Matrix m4 = matrix * matrix2;
	m3.show();
	cout << endl;
	m4.show();
}


