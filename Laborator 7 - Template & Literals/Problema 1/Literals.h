#pragma once

float operator"" _Kelvin(long double k) // din kelvin in celsius
{
	long double Celsius = k - 273.15;
	return Celsius;
}

float operator"" _Kelvin(unsigned long long int k) // din kelvin in celsius
{
	long double Celsius = k - 273.15;
	return Celsius;
}

float operator"" _Fahrenheit(unsigned long long int f) // din fahrenheit in celsius
{
	long double Celsius = (f - 32) / 1.8;
	return Celsius;
}

float operator"" _Fahrenheit(long double f) // din fahrenheit in celsius
{
	long double Celsius = (f - 32) / 1.8;
	return Celsius;
}

