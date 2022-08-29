#include "RSA.h"
#include <stdlib.h>
#include <vector>
#include <string>
#include "boost/multiprecision/cpp_int.hpp"
#include "boost/multiprecision/random.hpp"
#include "boost/random/independent_bits.hpp"
#include "boost/random/mersenne_twister.hpp"
#include <boost/integer/mod_inverse.hpp>
#include "Windows.h"

/*
	Fuctions for enctyping and decrypting
*/

boost::multiprecision::uint1024_t modExp(boost::multiprecision::uint1024_t x, boost::multiprecision::uint1024_t y, boost::multiprecision::uint1024_t N)
{
	if (y == 0) return 1;
	boost::multiprecision::uint1024_t z = modExp(x, y / 2, N);
	if (y % 2 == 0)
		return (z * z) % N;
	else
		return (x * z * z) % N;
}

// Enctypt integer num with key (num ^ e)) % n
std::string encryptNum(char num, boost::multiprecision::uint1024_t e, boost::multiprecision::uint1024_t n) // num < n or its not OK
{
	std::string a = "\nKEKE\n";
	OutputDebugStringA(a.c_str());

	boost::multiprecision::uint1024_t newNum = (int)num;

	std::string result;

	result+=modExp(newNum, e, n).str() + ";";

	return result;
}

// Dectypt integer num with key (num ^ d) % n
char decryptNum(boost::multiprecision::uint1024_t num, boost::multiprecision::uint1024_t d, boost::multiprecision::uint1024_t n)
{
	char result;

	result = char((modExp(num, d, n)));

	return result;
}

// Dectypt the whole message
std::string decrypt(std::string message, boost::multiprecision::uint1024_t d, boost::multiprecision::uint1024_t n)
{
	std::string result;
	long long int count = 0;
	int index = 0;
	for (long long int i = 0; i < message.length(); i++)
	{
		if (message[i] == ';')
		{
			count++;
		}
	}

	for (long long int i = 0; i < count; i++)
	{
		index = message.find(';');
		result += decryptNum(boost::lexical_cast<boost::multiprecision::uint1024_t>(message.substr(0, index)), d, n);
		message = message.substr(index + 1);
	}

	return result;
}

// Encrypt the whole message
std::string encrypt(std::string message, boost::multiprecision::uint1024_t e, boost::multiprecision::uint1024_t n)
{
	std::string result;

	for (int i = 0; i < message.length(); i++)
	{
		result+=(encryptNum(message[i], e, n));
	}

	return result;
}


/*
	Functions for keys generation
*/

// 3 functions for miller proximity test
boost::multiprecision::uint1024_t modulo(boost::multiprecision::uint1024_t base, boost::multiprecision::uint1024_t exponent, boost::multiprecision::uint1024_t mod)

{

	boost::multiprecision::uint1024_t x = 1;

	boost::multiprecision::uint1024_t y = base;

	while (exponent > 0)

	{

		if (exponent % 2 == 1)

			x = (x * y) % mod;

		y = (y * y) % mod;

		exponent = exponent / 2;

	}

	return x % mod;

}
boost::multiprecision::uint1024_t mulmod(boost::multiprecision::uint1024_t a, boost::multiprecision::uint1024_t b, boost::multiprecision::uint1024_t mod)

{

	boost::multiprecision::uint1024_t x = 0, y = a % mod;

	while (b > 0)

	{

		if (b % 2 == 1)

		{

			x = (x + y) % mod;

		}

		y = (y * 2) % mod;

		b /= 2;

	}

	return x % mod;

}

bool millerPrimeTest(boost::multiprecision::uint1024_t p)

{
	if (p < 2)

	{

		return false;

	}

	if (p != 2 && p % 2 == 0)

	{

		return false;

	}

	boost::multiprecision::uint1024_t s = p - 1;

	while (s % 2 == 0)

	{
		s /= 2;
	}

	for (int i = 0; i < 50; i++)

	{

		boost::multiprecision::uint1024_t a = rand() % (p - 1) + 1, temp = s;

		boost::multiprecision::uint1024_t mod = modulo(a, temp, p);

		while (temp != p - 1 && mod != 1 && mod != p - 1)

		{

			mod = mulmod(mod, mod, p);

			temp *= 2;

		}

		if (mod != p - 1 && temp % 2 == 0)

		{

			return false;

		}

	}

	return true;

}

// Generate keys
std::vector<boost::multiprecision::uint1024_t> createKeys()
{	
	
	std::vector<boost::multiprecision::uint1024_t> result;
	boost::multiprecision::uint1024_t q;
	boost::multiprecision::uint1024_t p;
	boost::multiprecision::uint1024_t n;
	boost::multiprecision::uint1024_t eler;
	boost::multiprecision::uint1024_t e;
	boost::multiprecision::uint1024_t d;

	typedef boost::random::independent_bits_engine<boost::mt19937, 128, boost::multiprecision::uint128_t> generator128_type;
	generator128_type gen;
	gen.seed(time(NULL));

	q = gen();
	p = gen();

	while (!millerPrimeTest(q))
	{
		q = gen();
	}

	while (!millerPrimeTest(p))
	{
		p = gen();
	}
	n = p * q;
	eler = (p - 1) * (q - 1);

	e = gen();

	while (!((boost::integer::gcd(e, eler) == 1) && (e < eler) && millerPrimeTest(e)))
	{	
		e = gen();
	}

	d = boost::integer::mod_inverse(e, eler);



	result.push_back(e);
	result.push_back(n);
	result.push_back(d);

	return result;
}


/*
	a = "\nENC!!!\n char int  " + newNum.str();
	OutputDebugStringA(a.c_str());
*/