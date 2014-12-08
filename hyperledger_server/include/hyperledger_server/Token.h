#ifndef TOKENS_H
#define TOKENS_H

namespace utility
{
	enum TokenType //TODO Dynamic token types
	{
		tokenType1,
		tokenType2,
		tokenType3,
		tokenType4
	};

	struct Token
	{
		double amount;
		TokenType tokenType;

		Token() : Token(0.0, tokenType1) {};
		Token(double amount, TokenType tokenType);

		friend Token operator+(const Token& c1, const Token& c2);
		friend Token operator-(const Token& c1, const Token& c2);

		friend Token operator+(const Token& c1, double c2);
		friend Token operator-(const Token& c1, double c2);

		friend Token operator+(double c1, const Token& c2);
		friend Token operator-(double c1, const Token& c2);

		friend Token operator*(const Token& c1, double c2);
		friend Token operator/(const Token& c1, double c2);

		friend bool operator==(const Token& c1, const Token& c2);
		friend bool operator!=(const Token& c1, const Token& c2);
		friend bool operator<(const Token& c1, const Token& c2);
		friend bool operator>(const Token& c1, const Token& c2);
		friend bool operator>=(const Token& c1, const Token& c2);
		friend bool operator<=(const Token& c1, const Token& c2);
	};
}

#endif