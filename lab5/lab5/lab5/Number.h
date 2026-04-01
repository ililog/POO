#pragma once
class Number
{
	char* value;
	int base;

	void CopyString(const char* str);
	void TransformFromBase10(int nr, int newbase);
	int TranformToBase10() const;
public:
	Number(const char* value, int base); //constructor cu un sir de caractere
	Number(int value); //constructor cu un int
	~Number();

	Number(const Number& toCopy); //copy constructor
	Number(Number&& toMove); //move constructor

	//assignment operators
	Number& operator=(const Number& other);
	Number& operator=(int value);
	Number& operator=(const char* value);

	Number& operator+=(const Number& other);

	Number& operator--(); //prefix
	Number operator--(int); //postfix

	char operator[](int index) const; //index operator

	void SwitchBase(int newBase);
	void Print() const;
	int  GetDigitsCount() const; // returns the number of digits for the current number
								 // pun const fiindca nu modifica nimic in Number
	int  GetBase() const; // returns the current base

	friend Number operator+(const Number& n1, const Number& n2);
	friend Number operator-(const Number& n1, const Number& n2);

	friend bool operator>(const Number& n1, const Number& n2);
	friend bool operator<(const Number& n1, const Number& n2);
	friend bool operator>=(const Number& n1, const Number& n2);
	friend bool operator<=(const Number& n1, const Number& n2);
	friend bool operator==(const Number& n1, const Number& n2);
	friend bool operator!=(const Number& n1, const Number& n2);
};