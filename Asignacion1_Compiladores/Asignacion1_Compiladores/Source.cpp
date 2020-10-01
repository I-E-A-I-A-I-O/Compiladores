#include <iostream>
#include <string>
#include <ctype.h>
#include <list>
using namespace std;

bool CheckExpression(string ex);
bool IsOperator(char check);

int main() 
{
	string expression;
	cout << "Inserte la expresion a evaluar.\n>>";
	getline(cin, expression);
	string result = CheckExpression(expression) ? "Valido!" : "Invalido!";
	cout << "\n" << result;
	return 0;
}

bool CheckExpression(string ex)
{
	int temp, openCount = 0, closeCount = 0;
	bool result = true, equalsFlag = false, digitFlag = false, operatorFlag = false,
		parenthesisFlag = false, firstNumberFlag = false, firstOperatorFlag = false,
		secondNumberFlag = false;

	for (int i = 0; i < ex.size(); i++)
	{
		if (isalpha(ex[i]))
		{
			if (!equalsFlag)
			{
				if (isupper(ex[i]))
				{
					cout << "\n" << "ERROR: Letra mayuscula en la posicion " << i;
					if (result) result = false;
					continue;
				}
			}
			else
			{
				cout << "\n" << "ERROR: Caracter invalido en la posicion " << i;
			}
		}
		else if (!isspace(ex[i]))
		{
			if (ex[i] == '=')
			{
				if (!equalsFlag)
				{
					equalsFlag = true;
				}
				else if (equalsFlag)
				{
					cout << "\n" << "ERROR: Caracter invalido en la posicion " << i;
					if (result) result = false;
					continue;
				}
			}
			else if (isdigit(ex[i]))
			{
				if (!equalsFlag)
				{
					cout << "\n" << "ERROR: Caracter invalido en la posicion " << i << ". Nombre de variable invalido.";
					if (result) result = false;
					continue;
				}
				else
				{
					digitFlag = true;
					if (parenthesisFlag) parenthesisFlag = false;
					if (!firstOperatorFlag && !firstNumberFlag) firstNumberFlag = true;
					if (firstOperatorFlag && !secondNumberFlag) secondNumberFlag = true;
				}
			}
			else if (IsOperator(ex[i]))
			{
				if (!equalsFlag)
				{
					cout << "\n" << "ERROR: Expresion invalida en la posicion " << i << ". Nombre de variable invalido";
					if (result) result = false;
					continue;
				}
				else
				{
					if (parenthesisFlag)
					{
						cout << "\n" << "ERROR: Expresion invalida en la posicion " << i;
						if (result) result = false;
						continue;
					}
					else if (digitFlag)
					{
						firstOperatorFlag = true;
						digitFlag = false;
					}
					else if (!digitFlag)
					{
						cout << "\n" << "ERROR: Expresion invalida en la posicion " << i;
						if (result) result = false;
						continue;
					}
				}
			}
			else if (ex[i] == '(')
			{
				parenthesisFlag = true;
				openCount++;
				if (!equalsFlag)
				{
					cout << "\n" << "ERROR: Nombre de variable invalido en la posicion " << i;
					if (result) result = false;
					continue;
				}
			}
			else if (ex[i] == ')')
			{
				closeCount++;
				if (!equalsFlag)
				{
					cout << "\n" << "ERROR: Nombre de variable invalido en la posicion " << i;
					if (result) result = false;
					continue;
				}
				else if (!digitFlag)
				{
					cout << "\n" << "ERROR: Expresion invalida en la posicion " << i;
					if (result) result = false;
					continue;
				}
			}
		}
	}
	if (openCount != closeCount)
	{
		cout << "\n" << "ERROR: Uno o mas parentesis no fueron cerrados correctamente.";
		if (result) result = false;
	}
	else if (!equalsFlag || !firstNumberFlag || !firstOperatorFlag || !secondNumberFlag)
	{
		cout << "\n" << "ERROR: Expresion incompleta.";
		if (result) result = false;
	}
	return result;
}

bool IsOperator(char check)
{
	if (check == '+' || check == '-' || check == '/' || check == '*') return true;
	else return false;
}