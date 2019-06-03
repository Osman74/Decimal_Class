#pragma once
#include <iostream>
#include <string>

class cls_Decimal
{
	unsigned char* m_Array;
	int m_Size;
	bool m_Sign;
public:
	cls_Decimal();
	cls_Decimal(int p_Size);
	cls_Decimal(const cls_Decimal& p_Dec);
	int toInt();
	void setInt(int p_Num);
	void resetSize(int p_Size);
	friend std::ostream& operator<< (std::ostream &out, const cls_Decimal &p_Dec);
	friend std::istream& operator>> (std::istream &in, cls_Decimal &p_Dec);
	const cls_Decimal operator+(cls_Decimal& p_Dec);
	const cls_Decimal operator-(cls_Decimal& p_Dec);
	const cls_Decimal operator*(cls_Decimal& p_Dec);
	const bool operator>(cls_Decimal& p_Dec);
	const bool operator<(cls_Decimal& p_Dec);
	const bool operator>=(cls_Decimal& p_Dec);
	const bool operator<=(cls_Decimal& p_Dec);
	const bool operator==(cls_Decimal& p_Dec);
	~cls_Decimal();
	class UnexpectedNum : public std::exception
	{
		std::string m_msg;
	public:
		UnexpectedNum(unsigned char p_Num)
		{
			char s[2];
			s[0] = p_Num;
			s[1] = '\0';
			m_msg.assign(" ОШИБКА : " + std::string(s) + " не является цифрой десятичной системы счисления");
		}
		const char * what() const
		{
			return m_msg.c_str();
		}

	};
};

