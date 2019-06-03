#pragma once
#include "cls_Decimal.h"
#include <cmath>
#include <iostream>
#include <string>

class cls_Hex
{
	unsigned char* m_Array;
	int m_Size;
	bool m_Sign; // true - знак положительный, false - отрицательный
public:
	cls_Hex();
	cls_Hex(int p_Size);
	cls_Hex(const cls_Hex& p_Hex);
	void setInt (int p_Num); //преобразовать целое десятичное число в шестнадцатеричное
	int toInt(); // преобразовать в целое десятичное
	void resetSize(int p_Size); // задать новый размер с обнуление всех цифр
	friend std::ostream& operator<< (std::ostream &out, const cls_Hex &p_Hex); // потоковый вывод
	friend std::istream& operator>> (std::istream &in, cls_Hex &p_Hex); // потоковый ввод
	const cls_Hex operator+(cls_Hex& p_Hex); // переопределение оператора сложения чисел
	const cls_Hex operator-(cls_Hex& p_Hex); // переопределение оператора разности чисел
	const cls_Hex operator*(cls_Hex& p_Hex); // переопределение оператора умножения чисел
	const bool operator>(cls_Hex& p_Hex); // переопределение оператора > для чисел
	const bool operator<(cls_Hex& p_Hex);  // переопределение оператора < для чисел
	const bool operator>=(cls_Hex& p_Hex);  // переопределение оператора >= для чисел
	const bool operator<=(cls_Hex& p_Hex);  // переопределение оператора =< для чисел
	const bool operator==(cls_Hex& p_Hex);  // переопределение оператора == для чисел
	~cls_Hex();
	class UnexpectedNum : public std::exception //определение класса исключений (символ отсутсвует в алфавите системы счисления)
	{
		std::string m_msg;
	public:
		UnexpectedNum(unsigned char p_Num)
		{
			char s[2];
			s[0] = p_Num;
			s[1] = '\0';
			m_msg.assign(" ОШИБКА : " + std::string(s) + " не является цифрой шестнадцатеричной системы счисления");
		}
		const char * what() const
		{
			return m_msg.c_str();
		}
			
	};
};

