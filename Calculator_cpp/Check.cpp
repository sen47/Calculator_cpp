#include"Check.h"

std::string checkInput(const char* out, std::int16_t& lBrakets, std::int16_t& operations)
{
	std::string input;
	while (true)
	{
		std::cout << out;
		std::cout << "\nEnter: ";
		std::getline(std::cin, input);
		system("cls");
		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << "Error, try again!\n";
		}
		else if (!isAllowedSymbols(input))
		{
			std::cout << "I think you use unvaliable symbol, try again!\n";
		}
		else if (!isBracketsEquals(input, lBrakets))
		{
			std::cout << "I think you forgot bracket, try again!\n";
		}
		else if (!isSpace(input))
		{
			std::cout << "I think you use space, try again!\n";
		}
		else if (input.empty())
		{
			std::cout << "I think you forgot print example, try again!\n";
		}
		else
			return input;
	}
}

bool isBracketsEquals(const std::string example, std::int16_t& lBrakets)
{
	std::int16_t left(0), right(0);
	for (const char el : example)
	{
		if (el == '(')
			++left;
		else if (el == ')')
			++right;
	}
	lBrakets = left;
	return left == right;
}

bool isOperationsEquals(const std::string example, std::int16_t& operations)
{
	for(const char el:example)
		if (el == '+' || el == '-' || el == '*' || el == '/')
			++operations;
	return false;
}

bool isAllowedSymbols(const std::string example)
{
	for (const char exampSymbol : example)
	{
		bool isThere = false;
		for(const char allowedSymbol:allowedSymbols)
			if (exampSymbol == allowedSymbol)
			{
				isThere = true;
				break;
			 }
		if (!isThere)
			return false;
	}
	return true;
}

bool isSpace(const std::string example)
{
	for (const char el : example)
	{
		if (el == ' ')
			return false;
	}
}
