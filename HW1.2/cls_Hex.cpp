#include "cls_Hex.h"



cls_Hex::cls_Hex() : m_Size(0), m_Sign(true)
{
	m_Array = new unsigned char[100];
	for (int i = 0; i <= 100; ++i)
		m_Array[i] = '0';
}

cls_Hex::cls_Hex(int p_Size) : m_Size(p_Size), m_Sign(true)
{
	m_Array = new unsigned char[100];
	for (int i = 0; i <= 100; ++i)
		m_Array[i] = '0';
}

cls_Hex::cls_Hex(const cls_Hex& p_Hex) : m_Size(p_Hex.m_Size), m_Sign(p_Hex.m_Sign)
{
	m_Array = new unsigned char[100];
	for (int i = 0; i <= p_Hex.m_Size; ++i)
		m_Array[i] = p_Hex.m_Array[i];
	for (int i = p_Hex.m_Size; i <= 100; ++i)
		m_Array[i] = '0';
}

int cls_Hex::toInt()
{
	int k, res = 0;
	for (int i = m_Size - 1; i >= 0; --i)
	{
		switch (m_Array[i])
		{
		case '0': k = 0; break;
		case '1': k = 1; break;
		case '2': k = 2;  break;
		case '3': k = 3;  break;
		case '4': k = 4;  break;
		case '5': k = 5;  break;
		case '6': k = 6;  break;
		case '7': k = 7;  break;
		case '8': k = 8;  break;
		case '9': k = 9;  break;
		case 'A': k = 10;  break;
		case 'B': k = 11;  break;
		case 'C': k = 12;  break;
		case 'D': k = 13;  break;
		case 'E': k = 14;  break;
		case 'F': k = 15;  break;
		}
		res += k * pow(16, i);
	}
	if(m_Sign == false) res*=(-1);
	return res;
}

void cls_Hex::resetSize(int p_Size)
{
	for (int i = 0; i <= 100; ++i)
		m_Array[i] = '0';
	m_Size = p_Size;
}

std::ostream& operator<< (std::ostream &out, const cls_Hex &p_Hex)
{
	if (p_Hex.m_Sign == false) out << "-";
	for (int i = p_Hex.m_Size - 1; i >= 0; --i)
		out << p_Hex.m_Array[i];
	return out;
}

std::istream& operator>> (std::istream &in, cls_Hex &p_Hex)
{
	std::string str = "0123456789ABCDEF";
	unsigned char k;
	in >> k;
	int i = p_Hex.m_Size - 1;
	if (k == '-')
		p_Hex.m_Sign = false;
	else
	{
		p_Hex.m_Sign = true;
		p_Hex.m_Array[p_Hex.m_Size - 1] = k;
		--i;
	}
		
	for (; i >= 0; --i)
	{
		in >> p_Hex.m_Array[i];
		if (str.find(p_Hex.m_Array[i]) == std::string::npos)
			throw cls_Hex::UnexpectedNum(p_Hex.m_Array[i]);
	}
		
	return in;
}

void cls_Hex::setInt(int p_Num)
{
	for (int i = 0; i <= 100; ++i)
		m_Array[i] = '0';
	if (p_Num == 0)
	{
		m_Size = 1;
		m_Sign = true;
		return;
	}
	int r, i = 0;
	if (p_Num < 0)
	{
		m_Sign = false;
		p_Num *= -1;
	}
	else m_Sign = true;
	while (p_Num != 0)
	{
		r = p_Num % 16;
		switch (r)
		{
		case 0: m_Array[i] = '0'; break;
		case 1: m_Array[i] = '1'; break;
		case 2: m_Array[i] = '2';  break;
		case 3: m_Array[i] = '3';  break;
		case 4: m_Array[i] = '4';  break;
		case 5: m_Array[i] = '5';  break;
		case 6: m_Array[i] = '6';  break;
		case 7: m_Array[i] = '7';  break;
		case 8: m_Array[i] = '8';  break;
		case 9: m_Array[i] = '9';  break;
		case 10: m_Array[i] = 'A';  break;
		case 11: m_Array[i] = 'B';  break;
		case 12: m_Array[i] = 'C';  break;
		case 13: m_Array[i] = 'D';  break;
		case 14: m_Array[i] = 'E';  break;
		case 15: m_Array[i] = 'F';  break;
		}
		++i;
		p_Num /= 16;
	}
	m_Size = i;
}

const cls_Hex cls_Hex::operator+(cls_Hex& p_Hex)
{
	cls_Hex Res;
	int Dec = toInt() + p_Hex.toInt();
	Res.setInt(Dec);
	return Res;
}

const cls_Hex cls_Hex::operator-(cls_Hex& p_Hex)
{
	cls_Hex Res;
	int Dec = toInt() - p_Hex.toInt();
	Res.setInt(Dec);
	return Res;
}

const cls_Hex cls_Hex::operator*(cls_Hex& p_Hex)
{
	cls_Hex Res;
	int Dec = toInt() * p_Hex.toInt();
	Res.setInt(Dec);
	return Res;
}

const bool cls_Hex::operator>(cls_Hex& p_Hex)
{
	return toInt() > p_Hex.toInt();
}

const bool cls_Hex::operator<(cls_Hex& p_Hex)
{
	return toInt() < p_Hex.toInt();
}

const bool cls_Hex::operator>=(cls_Hex& p_Hex)
{
	return toInt() >= p_Hex.toInt();
}

const bool cls_Hex::operator<=(cls_Hex& p_Hex)
{
	return toInt() <= p_Hex.toInt();
}

const bool cls_Hex::operator==(cls_Hex& p_Hex)
{
	return toInt() == p_Hex.toInt();
}

cls_Hex::~cls_Hex()
{
	delete m_Array;
}
