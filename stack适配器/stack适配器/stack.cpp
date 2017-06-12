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
	double rhs{ operands.top() };//ǰ������
	operands.pop();
	double lhs{ operands.top() };//�������
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
	//����
	stack<string> words;
	//������ָ���²�����
	stack<string, list<string>> fruit;
	//��ʼ��
	list<string> city{ "cd","cq","bj" };
	stack<string, list<string>> cities( city );

	/**************************************** stackʵ�ּ�����*********************************************/
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

			exp.erase(remove(begin(exp), end(exp), ' '), end(exp));//�Ƴ��ո�
			size_t index{};//�ַ���λ��,��ͳ���ַ�������

			operands.push(stod(exp, &index));//��ջ��һ�����֣�stod����float�ָ��ַ�����������һ��double�ͣ�ͬʱindex���Զ�ƫ����Ӧλ��

			while (true)
			{
				operators.push(exp[index++]);//��ջ���

				size_t i{};//�ַ���λ��
				operands.push(stod(exp.substr(index), &i));//��ջ�ڶ�������
				index += i;//ָ��������������
				
				if (index == exp.length())//��ʽ��β
				{
					while (!operators.empty())//������ǿ�ʱ
						execute(operators, operands);
					break;
				}

				//��iλ����������ȼ�����ջ��ʱ��ִ���������㣨ֻ����һ����
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