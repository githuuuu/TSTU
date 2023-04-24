#include<iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
# define M_PI           3.14159265358979323846
# define M_E	2.71828182845904523536
using namespace std;
enum toktype { num, negnum, power, mult, divide, add, sub, leftpar, rightpar, func, negfunc };
class tok {
public:
	toktype type{};
	string content;
	/*выводит токены с их типом, проверяет работу токенизатора*/
	void disp(){
		if (type == 2) std::cout << '^' << "[" << type << "]" << " ";
		if (type == 3) std::cout << '*' << "[" << type << "]" << " ";
		if (type == 4) std::cout << '/' << "[" << type << "]" << " ";
		if (type == 5) std::cout << '+' << "[" << type << "]" << " ";
		if (type == 6) std::cout << '-' << "[" << type << "]" << " ";
		if (type<power || type>sub) std::cout << content << "[" << type << "]" << " ";
	}
	/*выводит токенизированное выражение*/
	void disp2() {
		if (type == 2) std::cout << '^' << " ";
		if (type == 3) std::cout << '*' << " ";
		if (type == 4) std::cout << '/' << " ";
		if (type == 5) std::cout << '+' << " ";
		if (type == 6) std::cout << '-' << " ";
		if (type<power || type>sub) std::cout << content << " ";
	}
};
int main() {
	string expression;
	vector<tok> inp;
	vector<tok> out;
	vector<tok> oper;
	vector<double> calc;
	tok buf1;
	std::cout << endl << "Enter the expression: ";
	getline(cin, expression);
	std::cout << "Your expression: " << expression << endl << endl;
	int i = 0;
/*токенизатор*/
	while (i < expression.length()) {
		while (expression[i] == ' ') {
			i++;
		}
		switch (expression[i]) {
		case'-':
			if (i == 0 || expression[i - 1] == '(') {
				buf1.content.clear();
				buf1.content = "-";
				i++;
				while ((48 <= int(expression[i]) && int(expression[i]) <= 57) || expression[i] == '.' || expression[i] == ',') {
					buf1.type = negnum;
					buf1.content += expression[i];
					i++;
				}
				while ((65 <= int(expression[i]) && int(expression[i]) <= 90) || (97 <= int(expression[i]) && int(expression[i]) <= 122)) {
					buf1.type = negfunc;
					buf1.content += expression[i];
					i++;
				}
				break;
			}
			else {
				buf1.type = sub;
				buf1.content = "3";
				i++;
			}
			break;
		case'(':
			buf1.type = leftpar;
			buf1.content = expression[i];
			i++;
			break;
		case')':
			buf1.type = rightpar;
			buf1.content = expression[i];
			i++;
			break;
		case'+':
			buf1.type = add;
			buf1.content = "3";
			i++;
			break;
		case'*':
			buf1.type = mult;
			buf1.content = "2";
			i++;
			break;
		case'/':
			buf1.type = divide;
			buf1.content = "2";
			i++;
			break;
		case'^':
			buf1.type = power;
			buf1.content = "1";
			i++;
			break;
		default:
			buf1.content.clear();
			while ((65 <= int(expression[i]) && int(expression[i]) <= 90) || (97 <= int(expression[i]) && int(expression[i]) <= 122)) {
				buf1.type = func;
				buf1.content += expression[i];
				i++;
			}
			while ((48 <= int(expression[i]) && int(expression[i]) <= 57) || expression[i] == '.' || expression[i] == ',') {
				buf1.type = num;
				buf1.content += expression[i];
				i++;
			}
			break;
		}
		inp.push_back(buf1);

	}
	/*убирает скобки вокруг отрицательных чисел*/
	for (int j = 1; j < inp.size() - 1; j++) {
		if (inp[j].type == negnum) {
			if (inp[j - 1].type == leftpar) {
				if (inp[j + 1].type == rightpar) {
					inp.erase(inp.begin() + j + 1);
					inp.erase(inp.begin() + j - 1);
				}
			}
		}
	}
	/*меняет константные функции на их числовое значение*/
	for (int j = 0; j < inp.size(); j++) {
		if (inp[j].type == func) {
			if (inp[j].content == "pi") {
				buf1.content = std::to_string(M_PI);
				buf1.type = num;
				inp[j] = buf1;
			}
			if (inp[j].content == "e") {
				buf1.content = std::to_string(M_E);
				buf1.type = num;
				inp[j] = buf1;
			}
		}
		if (inp[j].type == negfunc) {
			if (inp[j].content == "-pi") {
				buf1.content = std::to_string(0-M_PI);
				std::cout << buf1.content;
				buf1.type = num;
				inp[j] = buf1;
			}
			if (inp[j].content == "-e") {
				buf1.content = std::to_string(M_E);
				buf1.type = num;
				inp[j] = buf1;
			}
		}
	}
	/*for (int i = 0; i < inp.size(); i++) {
		inp[i].disp();
	}*/

	/*~~~~~~~~~~Алгоритм сортировочной станции~~~~~~~~~~~~*/
	for (int i = 0; i < inp.size(); i++) {
		buf1 = inp[i];
		//cout << endl << endl << buf1.content << endl << buf1.type << endl;
		if (buf1.type == num || buf1.type == negnum) {
			out.push_back(buf1);
		}
		if (buf1.type == func || buf1.type == negfunc) {
			oper.push_back(buf1);
		}
		if (buf1.type >= power && buf1.type <= sub) {
			if (oper.empty() == false) {
				while ((oper.back().type >= power && oper.back().type <= sub) && ((stoi(oper.back().content) < stoi(buf1.content) || (stoi(oper.back().content) == stoi(buf1.content) && buf1.type != power)))) {
					out.push_back(oper.back());
					oper.pop_back();
					if (oper.empty()) break;
				}
			}
			oper.push_back(buf1);
		}
		if (buf1.type == leftpar) {
			oper.push_back(buf1);
		}
		if (buf1.type == rightpar) {
			if (oper.empty() == false) {
				while (oper.back().type != leftpar) {
					out.push_back(oper.back());
					oper.pop_back();
					if (oper.empty()) {
						std::cout << endl << "Error: mismatched parentheses 1";
						break;
					}
				}
				if (oper.back().type == leftpar) {
					oper.pop_back();
				}
				if (oper.empty() == false){
					if (oper.back().type == func || oper.back().type == negfunc) {
						out.push_back(oper.back());
						oper.pop_back();
					}
				}
			}
			else std::cout << endl << "Error: mismatched parentheses 3";
		}
	}
	while (oper.empty() == false){
		if (oper.back().type == leftpar || oper.back().type == rightpar) {
			std::cout << endl << "Error: mismatched parentheses 4";
			break;
		}
		out.push_back(oper.back());
		oper.pop_back();
		if (oper.empty()) break;
	}

	std::cout << endl<< "Your expression in postfix notation: ";
	for (int i = 0; i < out.size(); i++) {
		out[i].disp2();
	}

	/*~~~~~~~~~~~калькулятор~~~~~~~~~~~~*/

	double buf2{}, buf3{};
	for (int i = 0; i < out.size(); i++) {
		buf1 = out[i];
		if (buf1.type == num || buf1.type == negnum) {
			calc.push_back(stod(buf1.content));
		}
		else {
			switch(buf1.type) {
			case add:
				buf2 = calc.back();
				calc.pop_back();
				calc.back() += buf2;
				break;
			case sub:
				buf2 = calc.back();
				calc.pop_back();
				calc.back() -= buf2;
				break;
			case mult:
				buf2 = calc.back();
				calc.pop_back();
				calc.back() *= buf2;
				break;
			case divide:
				buf2 = calc.back();
				calc.pop_back();
				calc.back() /= buf2;
				break;
			case power:
				buf2 = calc.back();
				calc.pop_back();
				calc.back() = pow(calc.back(),buf2);
				break;
			case func:
				if (buf1.content == "sin") {
					buf2 = fmod(calc.back(), 360);
					if (buf2 > 270) buf2 -= 360;
					else if (buf2 > 90) buf2 = 180 - buf2;
					calc.back() = sin(buf2*(M_PI/180.0));
					break;
				}
				if (buf1.content == "cos") {
					buf2 = fmod(calc.back(), 360);
					if (buf2 > 270) buf2 -= 360;
					else if (buf2 > 90) buf2 = 360 - buf2;
					calc.back() = cos(buf2 * (M_PI / 180.0));
					break;
				}
				if (buf1.content == "tg") {
					buf2 = fmod(calc.back(), 360);
					if (buf2 > 270) buf2 -= 360;
					else if (buf2 > 90) buf2 = 180 - buf2;
					buf2 = sin(buf2 * (M_PI / 180.0));

					buf3 = fmod(calc.back(), 360);
					if (buf3 > 270) buf3 -= 360;
					else if (buf3 > 90) buf3 = 360 - buf3;
					calc.back() = buf2/cos(buf3 * (M_PI / 180.0));
					break;
				}
				if (buf1.content == "ln") {
					calc.back() = log(calc.back());
				}
				if (buf1.content == "sqrt") {
					if (calc.back() < 0) {
						std::cout << "domain error";
						i = out.size();
					}
					calc.back() = sqrtf(calc.back());
				}
			case negfunc:
				if (buf1.content == "-sin") {
					buf2 = fmod(calc.back(), 360);
					if (buf2 > 270) buf2 -= 360;
					else if (buf2 > 90) buf2 = 180 - buf2;
					calc.back() = 0-sin(buf2 * (M_PI / 180.0));
					break;
				}
				if (buf1.content == "-cos") {
					buf2 = fmod(calc.back(), 360);
					if (buf2 > 270) buf2 -= 360;
					else if (buf2 > 90) buf2 = 360 - buf2;
					calc.back() = 0-cos(buf2 * (M_PI / 180.0));
					break;
				}
				if (buf1.content == "-tg") {
					buf2 = fmod(calc.back(), 360);
					if (buf2 > 270) buf2 -= 360;
					else if (buf2 > 90) buf2 = 180 - buf2;
					buf2 = 0-sin(buf2 * (M_PI / 180.0));

					buf3 = fmod(calc.back(), 360);
					if (buf3 > 270) buf3 -= 360;
					else if (buf3 > 90) buf3 = 360 - buf3;
					calc.back() = 0-(buf2 / cos(buf3 * (M_PI / 180.0)));
					break;
				}
				if (buf1.content == "-ln") {
					calc.back() = 0-log(calc.back());
				}
				if (buf1.content == "-sqrt") {
					if (calc.back() < 0) {
						std::cout << "domain error";
						i = out.size();
					}
					calc.back() = 0-sqrtf(calc.back());
				}
			}

		}
	}
	std::cout << endl << "Result: " << calc.back();
}
