#include "Vector.hpp"
#include "Complex.hpp"

//check
int main()
{
	User_Vector a(5);
	User_Vector c(5);
	std::cin >> a >> c;
	
	Complex<User_Vector> B(a, c);
	Complex<User_Vector> D(c, c);
	
	std::cout << B << std::endl;
	
	return 0;
}
