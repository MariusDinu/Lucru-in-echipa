#include "Number.h"
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
Number::Number()
{
}
Number::Number(int number)
{
	Number nr1("256");
	Number nr2("0");
	int copyOfNumber = number;
	unsigned int numberOfDigits = 0;
	this->base = 10;
	unsigned int counter = 1;
	while (number != 0)
	{
		number = number / 10;
		numberOfDigits++;
	}
	if (copyOfNumber > 0)
	{
		value = new char[numberOfDigits + 1];
		value[numberOfDigits] = '\0';
		while (copyOfNumber != 0)
		{
			value[numberOfDigits - counter] = (char)(copyOfNumber % 10) + '0';
			copyOfNumber /= 10;
			counter++;
		}
	}
	else if (copyOfNumber < 0)
	{
		++numberOfDigits;
		value = new char[numberOfDigits + 1];
		value[0] = '-';
		value[numberOfDigits] = '\0';
		copyOfNumber = -copyOfNumber;
		while (copyOfNumber != 0)
		{
			value[numberOfDigits - counter] = (char)(copyOfNumber % 10) + '0';
			copyOfNumber /= 10;
			counter++;
		}
	}
	else if (copyOfNumber == 0)
	{
		value = new char[2];
		value[0] = '0';
		value[1] = '\0';
	}
	if ((*this) < nr1 && (*this)>nr2)
		SwitchBase(2);
}
Number::Number(const Number& nr)
{
	this->base = nr.base;
	this->value = new char[strlen(nr.value)+1];
	for (unsigned int index = 0; index < strlen(nr.value); index++)
		this->value[index] = nr.value[index];
	this->value[strlen(nr.value)] = '\0';
}
Number::Number(Number&& nr)
{
	this->value = nr.value;
	nr.value = nullptr;
	this->base = nr.base;
}
Number& Number::operator=(Number&& nr)
{
	this->value = nr.value;
	nr.value = nullptr;
	this->base = nr.base;
	return (*this);
}
Number::Number(const char* value, int base)
{
	this->base = base;
	this->value = new char[strlen(value)+1];
	memcpy(this->value, value, strlen(value)+1);
}
Number::Number(const char* nr)
{
	this->base = 10;
	this->value = new char[strlen(nr) + 1];
	for (unsigned int index = 0; index < strlen(nr); index++)
		this->value[index] = nr[index];
	this->value[strlen(nr)] = '\0';
}
Number::~Number()
{
	delete value;
	value = nullptr;
}
void Number::Print()
{
	for (unsigned int index = 0; index < strlen(this->value); index++)
		cout << value[index];
	cout << endl;
}
int Number::convertToDecimal(const Number& number)
{
	int decimalNumber = 0;
	short int sign = 1;
	unsigned int p = 1;
	if (number.value[0] != '-' && number.value[0] != '+')
	{
		for (int index = strlen(number.value) - 1; index >= 0; index--)
		{
			if (number.value[index] >= '0' && number.value[index] <= '9')
			{
				decimalNumber += (number.value[index] - '0') * p;
			}
			else if (number.value[index] >= 'A' && number.value[index] <= 'Z')
			{
				decimalNumber = decimalNumber + ((number.value[index] - 'A') + 10) * p;
			}
			p = p * (number.base);
		}
	}
	else if (number.value[0] == '-')
	{
		sign = -1;
		for (int index = strlen(number.value) - 1; index >= 1; index--)
		{
			if (number.value[index] >= '0' && number.value[index] <= '9')
			{
				decimalNumber += (number.value[index] - '0') * p;
			}
			else if (number.value[index] >= 'A' && number.value[index] <= 'Z')
			{
				decimalNumber = decimalNumber + ((number.value[index] - 'A') + 10) * p;
			}
			p = p * (number.base);
		}
	}
	else if (number.value[0] == '+')
	{
		for (int index = strlen(number.value) - 1; index >= 1; index--)
		{
			if (number.value[index] >= '0' && number.value[index] <= '9')
			{
				decimalNumber += (number.value[index] - '0') * p;
			}
			else if (number.value[index] >= 'A' && number.value[index] <= 'Z')
			{
				decimalNumber = decimalNumber + ((number.value[index] - 'A') + 10) * p;
			}
			p = p * (number.base);
		}
	}
	return decimalNumber*sign;
}
void Number::convertToAnotherBase(int decimalNumber, int newBase)
{
	delete value;
	value = nullptr;
	int remainder;
	int numberOfDigits;
	if (decimalNumber > 0)
	{
		numberOfDigits = (int)(log(decimalNumber) / log(newBase)) + 1;
		value = new char[numberOfDigits + 1];
	}
	else if (decimalNumber < 0)
	{
		numberOfDigits = (int)(log(-decimalNumber) / log(newBase)) + 2;
		value = new char[numberOfDigits + 2];
		value[0] = '-';
	}
	else
	{
		numberOfDigits = 1;
		value = new char[2];
	}
	int counter = 0;
	if (decimalNumber < 0)
	{
		decimalNumber = -decimalNumber;
		while (decimalNumber != 0)
		{
			remainder = decimalNumber % newBase;
			counter++;
			if (remainder < 10)
				value[numberOfDigits - counter] = remainder + '0';
			else if (remainder >= 10)
				value[numberOfDigits - counter] = remainder - 10 + 'A';
			decimalNumber /= newBase;
		}
		value[numberOfDigits] = '\0';
	}
	else if(decimalNumber==0)
	{
		value[0] = '0';
		value[1] = '\0';
	}
	else if (decimalNumber > 0)
	{
		while (decimalNumber != 0)
		{
			remainder = decimalNumber % newBase;
			counter++;
			if (remainder < 10)
				value[numberOfDigits - counter] = remainder + '0';
			else if (remainder >= 10)
				value[numberOfDigits - counter] = remainder - 10 + 'A';
			decimalNumber /= newBase;
		}
		value[numberOfDigits] = '\0';
	}
}
void Number::SwitchBase(int newBase)
{
	int decimalNumber = convertToDecimal(*this);
	convertToAnotherBase(decimalNumber, newBase);
	this->base = newBase;
}
char Number::operator[](const int index) const
{
	return this->value[index];
}
Number& Number::operator=(const Number& nr)
{
	if (this == &nr) return *this;
	if (value) delete value;
	value = nullptr;
	this->value = new char[strlen(nr.value)+1];
	this->base = nr.base;
	for (unsigned int index = 0; index < strlen(nr.value); index++)
		this->value[index] = nr.value[index];
	this->value[strlen(nr.value)] = '\0';
	return *this;
}
bool Number::operator>(const Number& nr)
{
	int nr1Decimal = convertToDecimal(*this);
	int nr2Decimal = convertToDecimal(nr);
	if (nr1Decimal > nr2Decimal) return true;
	else return false;
}
bool Number::operator<=(const Number& nr)
{
	return !(*this > nr);
}
bool Number::operator<(const Number& nr)
{
	int nr1Decimal = convertToDecimal(*this);
	int nr2Decimal = convertToDecimal(nr);
	if (nr1Decimal < nr2Decimal)
		return true;
	else
		return false;
}
bool Number::operator>=(const Number& nr)
{
	return !(*this < nr);
}
bool Number::operator==(const Number& nr)
{
	int nr1Decimal = convertToDecimal(*this);
	int nr2Decimal = convertToDecimal(nr);
	return (nr1Decimal == nr2Decimal);
}
bool Number::operator!=(const Number& nr)
{
	return !(*this == nr);
}
Number& Number::operator--()
{
	char* temp = nullptr;
	temp = new char[strlen(this->value)+1];
	for (unsigned int index = 0; index < strlen(this->value); index++)
		temp[index] = value[index];
	temp[strlen(this->value)] = '\0';
	delete value;
	value = nullptr;
	value = new char[strlen(temp)];
	for (unsigned int index = 1; index < strlen(temp); index++)
		value[index - 1] = temp[index];
	value[strlen(temp) - 1] = '\0';
	delete []temp;
	return *this;
}
Number Number::operator--(int fictiv)
{
	char* temp = nullptr;
	temp = new char[strlen(this->value) + 1];
	for (unsigned int index = 0; index < strlen(this->value); index++)
		temp[index] = value[index];
	temp[strlen(this->value)] = '\0';
	delete value;
	value = nullptr;
	value = new char[strlen(temp)];
	for (unsigned int index = 0; index < strlen(temp)-1; index++)
		value[index] = temp[index];
	value[strlen(temp) - 1] = '\0';
	delete[] temp;
	temp = nullptr;
	return *this;
}
int Number::GetDigitsCount()
{
	return strlen(value);
}
int Number::GetBase()
{
	return base;
}
Number Number::operator-()
{
	Number temp;
	if (this->value[0] != '-' && this->value[0] !='+')
	{
		temp.value = new char[strlen(value) + 2];
		temp.value[0] = '-';
		for (unsigned int index = 0; index < strlen(this->value); index++)
			temp.value[index + 1] = this->value[index];
		temp.value[strlen(this->value) + 1] = '\0';
	}
	if (this->value[0] == '+')
	{
		temp.value = new char[strlen(value) + 1];
		temp.value[0] = '-';
		for (unsigned int index = 1; index < strlen(this->value); index++)
			temp.value[index] = this->value[index];
		temp.value[strlen(this->value)] = '\0';
	}
	if (this->value[0] == '-')
	{
		temp.value = new char[strlen(value)];
		for (unsigned int index = 1; index < strlen(this->value); index++)
			temp.value[index - 1] = this->value[index];
		temp.value[strlen(this->value) - 1] = '\0';
	}
	return temp;
}
Number operator+(const Number& nr1, const Number& nr2)
{
	int nr1Decimal = Number::convertToDecimal(nr1);
	int nr2Decimal = Number::convertToDecimal(nr2);
	int biggestBase;
	if (nr1.base > nr2.base)
		biggestBase = nr1.base;
	else
		biggestBase = nr2.base;
	int sum = nr1Decimal + nr2Decimal;
	Number newNumber(sum);
	newNumber.SwitchBase(biggestBase);
	return newNumber;
}
Number operator-(const Number& nr1, const Number& nr2)
{
	int nr1Decimal = Number::convertToDecimal(nr1);
	int nr2Decimal = Number::convertToDecimal(nr2);
	int biggestBase;
	if (nr1.base > nr2.base)
		biggestBase = nr1.base;
	else
		biggestBase = nr2.base;
	int subt = nr1Decimal - nr2Decimal;
	Number newNumber(subt);
	newNumber.SwitchBase(biggestBase);
	return newNumber;
}
Number& operator+=(Number& nr1, const Number& nr2)
{
	int nr1Decimal = Number::convertToDecimal(nr1);
	int nr2Decimal = Number::convertToDecimal(nr2);
	int biggestBase;
	if (nr1.base > nr2.base)
		biggestBase = nr1.base;
	else
		biggestBase = nr2.base;
	int sum = nr1Decimal + nr2Decimal;
	nr1 = sum;
	nr1.SwitchBase(biggestBase);
	return nr1;
}
Number& operator-=(Number& nr1, const Number& nr2)
{
	int nr1Decimal = Number::convertToDecimal(nr1);
	int nr2Decimal = Number::convertToDecimal(nr2);
	int biggestBase;
	if (nr1.base > nr2.base)
		biggestBase = nr1.base;
	else
		biggestBase = nr2.base;
	int subt = nr1Decimal - nr2Decimal;
	nr1 = subt;
	nr1.SwitchBase(biggestBase);
	return nr1;
}
