#pragma once
#include "cls_Decimal.h"
#include <cmath>
#include <iostream>
#include <string>

class cls_Hex
{
	unsigned char* m_Array;
	int m_Size;
	bool m_Sign; // true - ���� �������������, false - �������������
public:
	cls_Hex();
	cls_Hex(int p_Size);
	cls_Hex(const cls_Hex& p_Hex);
	void setInt (int p_Num); //������������� ����� ���������� ����� � �����������������
	int toInt(); // ������������� � ����� ����������
	void resetSize(int p_Size); // ������ ����� ������ � ��������� ���� ����
	friend std::ostream& operator<< (std::ostream &out, const cls_Hex &p_Hex); // ��������� �����
	friend std::istream& operator>> (std::istream &in, cls_Hex &p_Hex); // ��������� ����
	const cls_Hex operator+(cls_Hex& p_Hex); // ��������������� ��������� �������� �����
	const cls_Hex operator-(cls_Hex& p_Hex); // ��������������� ��������� �������� �����
	const cls_Hex operator*(cls_Hex& p_Hex); // ��������������� ��������� ��������� �����
	const bool operator>(cls_Hex& p_Hex); // ��������������� ��������� > ��� �����
	const bool operator<(cls_Hex& p_Hex);  // ��������������� ��������� < ��� �����
	const bool operator>=(cls_Hex& p_Hex);  // ��������������� ��������� >= ��� �����
	const bool operator<=(cls_Hex& p_Hex);  // ��������������� ��������� =< ��� �����
	const bool operator==(cls_Hex& p_Hex);  // ��������������� ��������� == ��� �����
	~cls_Hex();
	class UnexpectedNum : public std::exception //����������� ������ ���������� (������ ���������� � �������� ������� ���������)
	{
		std::string m_msg;
	public:
		UnexpectedNum(unsigned char p_Num)
		{
			char s[2];
			s[0] = p_Num;
			s[1] = '\0';
			m_msg.assign(" ������ : " + std::string(s) + " �� �������� ������ ����������������� ������� ���������");
		}
		const char * what() const
		{
			return m_msg.c_str();
		}
			
	};
};

