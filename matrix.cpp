#include <iostream>

using namespace std;

class User_Matrix{
	public:
		User_Matrix(int i = 1, int m = 1);
		User_Matrix(const User_Matrix&);
		~User_Matrix() {delete[] matrix;}
		
		User_Matrix& operator= (const User_Matrix&);
		float& operator()(int i, int j) {return *(matrix + i*m + j);}
		float operator()(int i, int j) const {return *(matrix + i*m + j);}
		User_Matrix operator+ (const User_Matrix&);
		User_Matrix operator- (const User_Matrix&);
		User_Matrix operator* (const User_Matrix&);
		
		friend ostream& operator<< (ostream&, const User_Matrix&);
		friend istream& operator>> (istream&, User_Matrix&);
		
	private:
		int m, n;
		float *matrix;
};

User_Matrix::User_Matrix(int i, int j)
{
	m = i;
	n = j;
	matrix = new float[m*n];
	for(int k = 0; k < (m*n); ++k)
		*(matrix + k) = 0.0;
}

User_Matrix::User_Matrix(const User_Matrix& A)
{
	m = A.m;
	n = A.n;
	matrix = new float[m*n];
	for(int k = 0; k < (m*n); ++k)
		matrix[k] = A.matrix[k];
}

User_Matrix& User_Matrix::operator= (const User_Matrix& A)
{
	if(this == &A)
		return *this;
	if(m*n != A.m * A.n)
	{
		delete[] matrix;
		matrix = new float[A.m * A.n];
	}
	
	m = A.m;
	n = A.n;
	for(int k = 0; k < (m*n); ++k)
		matrix[k] = A.matrix[k];
		
	return *this;
}


User_Matrix User_Matrix::operator+ (const User_Matrix& A)
{
	User_Matrix sum(*this);
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			sum(i, j) += A(i, j);
			
	return sum;
}

User_Matrix User_Matrix::operator- (const User_Matrix& A)
{
	User_Matrix div(*this);
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			(div(i, j)) -= (A(i, j));
			
	return div;
}

User_Matrix User_Matrix::operator* (const User_Matrix& A)
{
	User_Matrix Result(m, A.n);
	
	float tmp;
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < A.n; ++j)
		{
			tmp = 0.0;
			for(int k = 0; k < m; ++k)
				tmp += (*this)(i, k) * A(k, j);
			
			Result(i, j) = tmp;
		}
		
		return Result;
}

ostream& operator<< (ostream& stream, const User_Matrix& A)
{
	for(int i = 0; i < A.m; ++i)
	{
		for(int j = 0; j < A.n; ++j)
			stream << A(i, j) << " ";
			
		stream << endl;
	}
	
	return stream;
}

istream& operator>> (istream& stream, User_Matrix& A)
{
	cout << "Please, enter the matrix size" << endl; 
	stream >> A.m >> A.n;
	
	cout << "Please, enter the matrix elements" << endl; 
	for(int i = 0; i < A.m; ++i)
		for(int j = 0; j < A.n; ++j)
			stream >> A(i, j);
	
	return stream;
}

int main()
{
	User_Matrix A;
	cin >> A;
	
	User_Matrix B;
	B = (A + A);
	cout << B;
	
	A = (A * B);
	cout << A;
	
	return 0;
}
