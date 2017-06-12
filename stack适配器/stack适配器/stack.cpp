#include <iostream>
#include <list>
#include <stack>
#include <string>
#include <cmath>
#include <algorithm>
#include <stdexcept>

using namespace std;

inline size_t precedence(const char op)
{
	if (op == '+' || op == '-')
	{
		return 1;
	}
	if (op == '*' || op == '/')
	{
		return 2;
	}
	if (op == '^')
	{
		return 3;
	}
	throw runtime_error{ string{"invalid operator: "} + op };
}

double execute(stack<char>& ops,stack<double>& operands)
{
	double result{};
	double rhs{ operands.top() };//前操作数
	operands.pop();
	double lhs{ operands.top() };//后操作数
	operands.pop();
	switch (ops.top())
	{
	case '+':
		result = lhs + rhs;
		break;
	case '-':
		result = lhs - rhs;
		break;
	case '*':
		result = lhs * rhs;
		break;
	case '/':
		result = lhs / rhs;
		break;
	case '^':
		result = pow(lhs,rhs);
		break;
	default:
		throw runtime_error{ string{"invalid operator: "} +ops.top() };
	}
	ops.pop();
	operands.push(result);
	return result;
}

int main()
{
	//创建
	stack<string> words;
	//可自行指定下层容器
	stack<string, list<string>> fruit;
	//初始化
	list<string> city{ "cd","cq","bj" };
	stack<string, list<string>> cities( city );

	/**************************************** stack实现计算器*********************************************/
	stack<double> operands;
	stack<char> operators;
	string exp;
	cout << "An arithmetic expression can include the operators +,-,*,/ and ^ for exponentiation. " << endl;
	try
	{
		while (true)
		{
			cout << "Enter an arithmetic expression and press Enter - enter an empty line to end: " << endl;
			getline(cin, exp, '\n');
			if (exp.empty()) break;

			exp.erase(remove(begin(exp), end(exp), ' '), end(exp));//移除空格
			size_t index{};//字符串位置,并统计字符串长度

			operands.push(stod(exp, &index));//入栈第一个数字，stod将以float分割字符串，并返回一个double型，同时index会自动偏移相应位数

			while (true)
			{
				operators.push(exp[index++]);//入栈算符

				size_t i{};//字符串位置
				operands.push(stod(exp.substr(index), &i));//入栈第二个算数
				index += i;//指向算数后的运算符
				
				if (index == exp.length())//公式结尾
				{
					while (!operators.empty())//当算符非空时
						execute(operators, operands);
					break;
				}

				//当i位置运算符优先级高于栈顶时，执行优先运算（只运算一步）
				while (!operators.empty() && precedence(exp[index]) <= precedence(operators.top()))
					execute(operators, operands);
			}
			cout << "result == " << operands.top() << endl;
		}
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << "Calculator ending..." << endl;


	system("pause");
	return 0;
}