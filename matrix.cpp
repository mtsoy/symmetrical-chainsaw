#include <iostream>

using namespace std;

//matrix
class User_Matrix{
	public:
		User_Matrix(int columns = 1, int strings = 1);
		User_Matrix(int M, int N, float **Matrix);
		User_Matrix(const User_Matrix&);
		~User_Matrix();
		
		float& operator()(int i, int j) {return matrix[i][j];}
		float operator()(int i, int j) const {return matrix[i][j];}
		
		User_Matrix& operator= (const User_Matrix&);
		User_Matrix operator+ (const User_Matrix&) const;
		User_Matrix operator- (const User_Matrix&) const;
		User_Matrix operator* (const User_Matrix&) const;
		User_Matrix operator* (const float) const;
		
		friend float det(const User_Matrix&);
		
		friend ostream& operator<< (ostream&, const User_Matrix&);
		friend istream& operator>> (istream&, User_Matrix&);
		
	private:
		int m, n;
		float **matrix;
};


//Constructors
User_Matrix::User_Matrix(int columns, int strings)
{
	m = columns;
	n = strings;
	
	matrix = new float*[m];
	for(int i = 0; i < m; ++i)
		matrix[i] = new float[n];
	
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			matrix[i][j] = 0.0;
}

User_Matrix::User_Matrix(int M, int N, float **Matrix)
{
	m = M;
	n = N;
	
	matrix = new float*[m];
	for(int i = 0; i < m; ++i)
		matrix[i] = new float[n];
	
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			matrix[i][j] = Matrix[i][j];
}

User_Matrix::User_Matrix(const User_Matrix& A)
{
	m = A.m;
	n = A.n;
	
	matrix = new float*[m];
	for(int i = 0; i < m; ++i)
		matrix[i] = new float[n];
	
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			(this -> matrix)[i][j] = A(i, j);
}


//Destuctor
User_Matrix::~User_Matrix()
{
	for(int i = 0; i < n; ++i)
		delete[] matrix[i];
		
	delete[] matrix;
}


//Arithmetic operators
User_Matrix& User_Matrix::operator= (const User_Matrix& A)
{
	if(this == &A)
		return *this;

	if((m != A.m) || (n != A.n))
	{
		for(int i = 0; i < n; ++i)
			delete[] matrix[i];
		
		delete[] matrix;
		
		matrix = new float*[A.m];
		for(int i = 0; i < A.m; ++i)
			matrix[i] = new float[A.n];
	}
	
	m = A.m;
	n = A.n;
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			(this -> matrix)[i][j] = A(i, j);
		
	return *this;
}

User_Matrix User_Matrix::operator+ (const User_Matrix& A) const
{
	User_Matrix sum(*this);
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			sum(i, j) += A(i, j);
			
	return sum;
}

User_Matrix User_Matrix::operator- (const User_Matrix& A) const
{
	User_Matrix div(*this);
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			(div(i, j)) -= (A(i, j));
			
	return div;
}

User_Matrix User_Matrix::operator* (const User_Matrix& A) const
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

User_Matrix User_Matrix::operator* (const float a) const
{
	User_Matrix Result(m, n);
	
	for(int i = 0; i < m; ++i)
		for(int j = 0; j < n; ++j)
			Result(i, j) = (*this)(i, j) * a;
		
	return Result;
}


//determinant
float det(const User_Matrix& A)
{
	if(A.m != A.n)
		return -1.0;
	
	int s = A.m;
	if(s == 1)
		return A(0, 0);
		
	float result = 0.0;
	for(int k = 0; k < s; ++k)
	{
		if(A(k, 0) == 0)
			continue;
		
		User_Matrix Minor((s - 1), (s - 1));
		
		for(int i = 0; i < k; ++i)
			for(int j = 1; j < s; ++j)
				Minor(i, (j - 1)) = A(i, j);
				
		for(int i = k + 1; i < s; ++i)
			for(int j = 1; j < s; ++j)
				Minor((i - 1), (j - 1)) = A(i, j);
		
		if((k % 2) == 1)
			Minor = Minor * (-1);
				
		result += A(k, 0) * det(Minor);
	}
	
	return result;
}


//Input and output
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
	cout << "Please, enter the matrix elements" << endl; 
	for(int i = 0; i < A.m; ++i)
		for(int j = 0; j < A.n; ++j)
			stream >> A(i, j);
	
	return stream;
}


//main
int main()
{
	User_Matrix A(3, 3);
	cin >> A;
	
	cout << det(A) << endl; 
	
	A*5;
	
	return 0;
}
