#define _CRT_SECURE_NO_WARNINGS
#include "Math.h"
#include <cstdarg>
#include<string.h>
#include <malloc.h>
#include <xlocinfo>




int Math::Add(int a, int b)
{
	return a+b;
}

int Math::Add(int a, int b, int c)
{
	return a+b+c;
}

int Math::Add(double a, double b)
{
	return (double)(a+b);
}

int Math::Add(double a, double b, double c)
{
	return (double)(a + b + c);
}

int Math::Mul(int a, int b)
{
	return a*b;
}

int Math::Mul(int a, int b, int c)
{
	return a *b *c;
}

int Math::Mul(double a, double b)
{
	return (double)(a * b );
}

int Math::Mul(double a, double b, double c)
{
	return (double)(a * b * c);
}

int Math::Add(int count, ...)
{
	int val = 0;
	va_list ap;
	int i;

	va_start(ap, count);
	for (i = 0; i < count; i++) {
		val += va_arg(ap, int);
	}
	va_end(ap);

	return val;
}

char* Math::Add(const char* c1, const char* c2)
{

	int m, n;
	int sum;
	char* sumstr;
	sumstr = (char*)malloc(sizeof(char) * (strlen(c1) + strlen(c2) + 1));

	if (c1 == NULL || c2 == NULL) {
		return nullptr;
	}
	else
	{
		m = atof (c1);
		n = atof (c2);
		sum = m + n;
		sprintf(sumstr, "%f", sum);
	}
	return sumstr;
}

