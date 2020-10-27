#pragma once
class Number
{
public:
	char* value = nullptr;
	int base = 0;
	static int convertToDecimal(const Number&);//data meber
	void convertToAnotherBase(int, int);
public:
	Number();
	Number(int);
	Number(const Number&);
	Number(Number&&); //move constructor
	Number(const char* value, int base);
	Number(const char*);
	Number& operator=(const Number&);
	Number& operator=(Number&&); //move assignment operator
	~Number();
	char operator[](const int index) const;
	bool operator>(const Number&);
	bool operator<=(const Number&);
	bool operator<(const Number&);
	bool operator>=(const Number&);
	bool operator==(const Number&);
	bool operator!=(const Number&);
	Number& operator--();
	Number operator--(int);
	Number operator-();
	friend Number operator+(const Number&, const Number&);
	friend Number& operator+=(Number&, const Number&);
	friend Number operator-(const Number&, const Number&);
	friend Number& operator-=(Number&, const Number&);
	void SwitchBase(int newBase);
	void Print();
	int GetDigitsCount();
	int GetBase();
};
