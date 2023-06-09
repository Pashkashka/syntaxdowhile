#include "iostream"
#include <string>
#include <fstream>
#include <vector>
#include<locale.h>
#include<stdio.h>
#include<stdlib.h>
#include <stack>
using namespace std;
//int rekur(string s, int ch_do);
int check_do(string s, int ok, int ch_do)
{
	int i, position1 = ch_do, ok1 = 0;
	for (i = ch_do; s[i] != '\0'; i++)
	{
		if (i == 0) {
			if ((s[i] == 'd') && (s[i + 1] == 'o'))
			{
				ok = 1;
				position1 = i + 1;
				break;
			}
		}
		if (s[i] == 'd')
		{
			if ((!isalpha(s[i - 1])) && (!isalpha(s[i + 2])))
				if (s[i + 1] == 'o') {
					position1 = i + 1;
					ok = 1;
					break;
				}


		}

	}
	while (s[position1] != '\0')
	{
		if ((isalpha(s[position1 + 1])) || (s[position1 + 1] == ':') || (isdigit(s[position1 + 1]))) {
			if ((s[position1] == 'o') && (s[position1 - 1] == 'd')) {
				continue;
			}
			ok1 = 0;
			//printf("���������� ������ ������ ����� {");
			break;
		}
		if (s[position1] == '{') {
			ok1 = 1;
			break;
		}
		position1++;

	}
	if ((ok == 1) && (ok1 == 1)) {
		//printf("do ������ � �����\n");
		return position1;
	}
	else {
		//printf("do �� ������ � �����\n");
		return 0;
	}
}
bool balanced(const std::string& s) {
	std::stack<char> stack;
	for (char c : s) {
		switch (c) {

		case '(': stack.push(')'); break;
		case '[': stack.push(']'); break;
		case '{': stack.push('}'); break;
			//case '<': stack.push('>'); break;

		case ')':
		case ']':
		case '}':
			//case '>':
			if (stack.empty() || stack.top() != c) {
				return false;
			}
			stack.pop();
			break;
		default:
			break;
		}
	}
	return stack.empty();
}
int test(const std::string& s) {
	std::cout << '"' << s << "\" " << (balanced(s) ? "������ ������� �����" : "������ ������� �� �����") << '\n';
	if (balanced(s))
		return 1;
	else return 0;
}
int chek_skob(string s, int ok, int ch_do)
{
	int i, posfigure, poscircul, possquar, posfigureend, poscirculend, possquarend;
	int pf = 0, pfe = 0, pc = 0, pce = 0, ps = 0, pse = 0, position1 = ch_do;
	string s2;
	for (i = ch_do; s[i] != '\0'; i++)
	{
		//s2[i] = s[i];
		if (s[i] == '{')
		{
			//if ((!isalpha(s[i-1])) || ((s[i - 1] == 'o') && (s[i - 2] == 'd'))) {
			posfigure = i;
			pf++;
			//}

		}
		if (s[i] == '}') {
			posfigureend = i;
			pfe++;
		}
		if (s[i] == '(')
		{
			poscircul = i;
			pc++;

		}
		if (s[i] == ')') {
			poscirculend = i;
			pce++;
		}
		if (s[i] == '[')
		{
			possquar = i;
			ps++;

		}
		if (s[i] == ']') {
			possquarend = i;
			pse++;
		}

		position1++;
	}
	if (pfe == pf)
	{
		if (pc == pce)
			if (ps == pse) {
				//printf("������ ������� �����\n");
				//std::cout << '"' << s << "\" " << (balanced(s) ? "������ ������� �����" : "������ ������� �� �����") << '\n';
				ok = test(s);
				if (ok == 1)
					return position1;
				else return 0;

			}

			else {
				printf("��������� ���������� ������\n");
				return 0;
			}
		else {
			printf("��������� ������� ������\n");
			return 0;
		}
	}
	else {
		printf("��������� �������� ������\n");
		return 0;
	}




}
int check_while(string s, int ok, int ch_do, char prov)
{

	int i, position1 = ch_do, ok1 = 0, ok2 = 0, ok3 = 0;
	for (i = ch_do; (s[i] != prov); i++)
	{
		if (i == 0) {
			if ((s[i + 1] == 'w') && (s[i + 2] == 'h') && (s[i + 3] == 'i') && (s[i + 4] == 'l') && (s[i + 5] == 'e'))
			{
				ok1 = 1;
				position1 = i + 6;
				break;
			}
		}
		if (s[i + 1] == 'w')
		{
			if ((!isalpha(s[i])) && (!isalpha(s[i + 6])))
				if ((s[i + 2] == 'h') && (s[i + 3] == 'i') && (s[i + 4] == 'l') && (s[i + 5] == 'e')) {
					position1 = i + 6;
					ok1 = 1;
					break;
				}


		}

	}
	while (s[position1] != prov)
	{
		if ((isalpha(s[position1])) || (s[position1] == ':') || (isdigit(s[position1]))) {
			if ((s[position1 - 1] != 'e') && (s[position1 - 2] != 'l') && (s[position1 - 3] != 'i') && (s[position1 - 4] != 'h') && (s[position1 - 5] != 'w')) {
				if (ok == 1)
					goto q;

				ok = 0;
				//printf("���������� ������ ������ ����� (");
				break;
			}
		}
	q:
		if (s[position1] == '(') {
			ok = 1;
		}
		if (s[position1] == ')') {
			ok2 = 1;
		}
		if (s[position1 + 1] == ';') {
			ok3 = 1;
		}
		if ((ok == 1) && (ok1 == 1) && (ok2 == 1) && (ok3 == 1))
			break;

		position1++;

	}
	if ((ok == 1) && (ok1 == 1) && (ok2 == 1) && (ok3 == 1)) {
		//printf("do ������ � �����\n");
		return position1;
	}
	else {
		//printf("do �� ������ � �����\n");
		return 0;
	}
}

int rekur(string s, int ch_do)
{
	int numberRound = 0, i, position = 0, ok = 0;
	int numberFigure = 0;
	char prov = ' ';
	int  ch_sk = 0, ch_wh = 0, cdw = 0, k = 1;
	//while (1) {
	ch_do = check_do(s, ok, ch_do);
	if (ch_do > 0) {
		printf("do ������ � �����\n");
		ch_sk = chek_skob(s, ok, ch_do);
		if (ch_sk == 0)
			return 0;
		else
		{
			int one = 0;
			while (1)
			{
				one++;
				ch_do = check_do(s, ok, ch_do);
				if (ch_do > 0) {
					prov = 'w';
					ch_wh = ch_do;
					ch_wh = check_while(s, ok, ch_do, prov);
					if (ch_wh > 0)
					{
						printf("��������� ���� %d �������� ���������\n", one);
						//ch_sk = chek_skob(s, ok, ch_do);
						//if (ch_sk == 0)
							//return 0;
						//break;
					}
					else {
						printf("��������� ���� %d �������� �� ���������\n", one);
						return 0;
					}
				}
				else if (ch_do == 0) {
					printf("���������� ����� %d ���,��� ��� do �� ������ \n", one);
					break;

				}

			}

		}

	}
	else {
		printf("do �� ������ � �����\n");
		return 0;
	}
	if (ch_wh > 0)
	{
		prov = '\0';
		ch_do = check_while(s, ok, ch_wh, prov);
		if (ch_do > 0)
		{
			printf("���� �������� ���������\n");
			//return ch_wh;
		}
		else {
			printf("���� �������� �� ���������\n");
			return 0;
		}

	}
	else
	{
		prov = '\0';
		ch_do = check_while(s, ok, ch_do, prov);
		if (ch_do > 0)
		{
			printf("���� �������� ���������\n");
			//return ch_do;
		}
		else {
			printf("���� �������� �� ���������\n");
			return 0;
		}


	}

	/*if (ch_do > 0)
	{
		printf("��������� %d ����� ������ �������\n", k);
		printf("=========================================\n");
	}
	else {
		printf("� ��������� %d ����� ��������� ������\n", k);
		return 0;
	}
	k++;*/
	//}
}
bool balanced2(const std::string& s) {
	std::stack<char> stack;
	for (char c : s) {
		switch (c) {

		case 'd': stack.push('w'); break;
			//case '<': stack.push('>'); break;

		case 'w':
			//case '>':
			if (stack.empty() || stack.top() != c) {
				return false;
			}
			stack.pop();
			break;
		default:
			break;
		}
	}
	return stack.empty();
}
int test2(const std::string& s) {
	std::cout << '"' << s << "\" " << (balanced2(s) ? " " : "�������� ����� ����� ����� �������") << '\n';
	if (balanced2(s)) {
		return 1;
	}
	else {
		//printf("�������� ����� ����� ����� �������\n");
		return 0;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	ifstream file("code1.txt");
	string s1, s;
	int ch_do = 0, ch_sk = 0, ch_wh = 0, cdw = 0;;
	char c;
	char str[80];
	int  i, position = 0, ok = 0, k = 1, getposition;
	char prov = ' ';
	while (!file.eof()) {
		file.get(c);
		s.push_back(c);
	}
	file.close();
	cout << s << endl;
	std::string::difference_type count = std::count(s.begin(), s.end(), 'd');
	cdw = test2(s);
	if (cdw == 0)
		return 0;
	getposition = ch_do;
	ch_do = rekur(s, getposition);
	/*while (1) {
		ch_do = rekur(s, getposition);
		getposition = ch_do;
		if (getposition > 0)
		{
			printf("��������� %d ����� ������ �������\n", k);
			printf("=========================================\n");
		}
		else {
			printf("� ��������� %d ����� ��������� ������\n", k);
			return 0;
		}
		k++;
	}*/



	return 0;
}