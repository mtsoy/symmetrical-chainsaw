#include <iostream>
#include <vector>

//PRODUCT
class Product{
	protected:
		char* name;
		float price;
		float weight;
	
	public:
		Product();
		Product(char*, float, float);
		
		void Set_Name(char*);
		void Set_Price(float);
		void Set_Weight(float);
		
		char* Get_Name();
		float Get_Price();
		float Get_Weight();
};

//constructors
Product::Product()
{
	name = "untitled";
	price = 0.0;
	weight = 0.0;
}

Product::Product(char *Name, float Price, float Weight)
{
	name = Name;
	price = Price;
	weight = Weight;
}

//set-methods
void Product::Set_Name(char* Name)
{
	name = Name;
}

void Product::Set_Price(float Price)
{
	price = Price;
}

void Product::Set_Weight(float Weight)
{
	weight = Weight;
}

//get-methods
char* Product::Get_Name()
{
	return name;
}

float Product::Get_Price()
{
	return price;
}

float Product::Get_Weight()
{
	return weight;
}


//BUY
class Buy : public Product{
	protected:
		int number;
		float all_price;
		float all_weight;
		
	public:
		Buy();
		Buy(char*, float, float, int);
		
		void Set_Number(int);
		void Set_All_Price(float);
		void Set_All_Weight(float);
		
		int Get_Number();
		float Get_All_Price();
		float Get_All_Weight();
};

//constructors
Buy::Buy():Product()
{ 
	number = 0;
	all_price = 0.0;
	all_weight = 0.0;
}

Buy::Buy(char *Name, float Price, float Weight, int Number = 1):Product(Name, Price, Weight)
{
	number = Number;
	all_price = price * number;
	all_weight = weight * number;
}

//set-methods
void Buy::Set_Number(int Number)
{
	number = Number;
}

void Buy::Set_All_Price(float All_price)
{
	all_price = All_price;
}

void Buy::Set_All_Weight(float All_weight)
{
	all_weight = All_weight;
}

//get-methods
int Buy::Get_Number()
{
	return number;
}

float Buy::Get_All_Price()
{
	return all_price;
}

float Buy::Get_All_Weight()
{
	return all_weight;
}


//CHECK
class Check : public Buy{
	public:
		Check();
		Check(Buy);
		Check(char*, float, float, int);
	
		void Print_Info();
};

//constructors
Check::Check():Buy() { }

Check::Check(Buy A):Buy(A.Get_Name(), A.Get_Price(), A.Get_Weight(), A.Get_Number()) { }

Check::Check(char *Name, float Price, float Weight, int Number = 1):Buy(Name, Price, Weight, Number) { }


void Check::Print_Info()
{
	std::cout << "Name: " << Get_Name() << "\n";
	std::cout << "Price: " << Get_Price() << "\n";
	std::cout << "Weight: " << Get_Weight() << "\n";
	std::cout << "Number: " << Get_Number() << "\n";
	std::cout << "All Price: " << Get_All_Price() << "\n";
	std::cout << "All Weight: " << Get_All_Weight() << "\n";
}


int main()
{
	Buy a;
	Buy b("qqq", 2.5, 9.8);
	Buy c("www", 2.5, 9.8, 5);
	
	std::cout << a.Get_Name() << a.Get_All_Price() << std::endl;
	std::cout << b.Get_Name() << b.Get_All_Price() << std::endl;
	std::cout << c.Get_Name() << c.Get_All_Price() << std::endl;
	
	Check E("www", 2.5, 9.8, 5);
	E.Print_Info();
	
	
	return 0;
}
