#include "stdafx.h"
#include "Token.h"


utility::Token::Token(double amount, TokenType tokenType)
{
	this->amount = amount;
	this->tokenType = tokenType;
}

utility::Token utility::operator+(const utility::Token& t1, const utility::Token& t2)
{
	if (t1.tokenType != t2.tokenType)
		throw std::logic_error("Cannot perform action on two different types of utility");
	return utility::Token(t1.amount + t2.amount, t1.tokenType);
}


utility::Token utility::operator-(const utility::Token& t1, const utility::Token& t2)
{
	if (t1.tokenType != t2.tokenType)
		throw std::logic_error("Cannot perform action on two different types of utility");
	return utility::Token(t1.amount - t2.amount, t1.tokenType);
}

utility::Token utility::operator+(const utility::Token& t1, double t2)
{
	return utility::Token(t1.amount + t2, t1.tokenType);
}

utility::Token utility::operator-(const utility::Token& t1, double t2)
{
	return utility::Token(t1.amount - t2, t1.tokenType);
}


utility::Token utility::operator+(double t1, const utility::Token& t2)
{
	return utility::Token(t1 + t2.amount, t2.tokenType);
}


utility::Token utility::operator-(double t1, const utility::Token& t2)
{
	return utility::Token(t1 - t2.amount, t2.tokenType);
}


utility::Token utility::operator*(const utility::Token& t1, double t2)
{
	return utility::Token(t1.amount * t2, t1.tokenType);
}


utility::Token utility::operator/(const utility::Token& t1, double t2)
{
	return utility::Token(t1.amount / t2, t1.tokenType);
}

bool utility::operator==(const utility::Token& t1, const utility::Token& t2)
{
	if (t1.tokenType != t2.tokenType)
		throw std::logic_error("Cannot perform action on two different types of utility");
	if (t1.amount == t2.amount)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool utility::operator!=(const utility::Token& t1, const utility::Token& t2)
{
	return !utility::operator==(t1, t2);
}


bool utility::operator<(const  utility::Token& t1, const utility::Token& t2)
{
	if (t1.tokenType != t2.tokenType)
		throw std::logic_error("Cannot perform action on two different types of utility");
	if (t1.amount<t2.amount)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool utility::operator>(const  utility::Token& t1, const utility::Token& t2)
{
	if (t1.tokenType != t2.tokenType)
		throw std::logic_error("Cannot perform action on two different types of utility");
	if (t1.amount > t2.amount)
	{
		return true;
	}
	else
	{
		return false;
	}
}


bool utility::operator>=(const utility::Token& t1, const utility::Token& t2)
{
	return !utility::operator<(t1, t2);
}


bool utility::operator<=(const utility::Token& t1, const utility::Token& t2)
{
	return !utility::operator>(t1, t2);
}