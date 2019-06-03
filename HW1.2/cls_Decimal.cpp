#include "cls_Decimal.h"

cls_Decimal::cls_Decimal() : m_Size(0), m_Sign(true)
{
	m_Array = new unsigned char[100];
	for (int i = 0; i <= 100; ++i)
		m_Array[i] = '0';
}

cls_Decimal::cls_Decimal(int p_Size) : m_Size(p_Size), m_Sign(true)
{
	m_Array = new unsigned char[100];
	for (int i = 0; i <= 100; ++i)
		m_Array[i] = '0';
	m_Sign = true;
}

cls_Decimal::cls_Decimal(const cls_Decimal& p_Dec) : m_Size(p_Dec.m_Size), m_Sign(p_Dec.m_Sign)
{
	m_Array = new unsigned char[100];
	for (int i = 0; i <= p_Dec.m_Size; ++i)
		m_Array[i] = p_Dec.m_Array[i];
	for (int i = p_Dec.m_Size; i <= 100; ++i)
		m_Array[i] = '0';
}

int cls_Decimal::toInt()
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
		}
		res += k * pow(10, i);
	}
	if (m_Sign == false) res*=(-1);
	return res;
}

void cls_Decimal::setInt(int p_Num)
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
	while (p_Num != 0)
	{
		r = p_Num % 10;
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
		}
		++i;
		p_Num /= 10;
	}
	m_Size = i;
}

void cls_Decimal::resetSize(int p_Size)
{
	for (int i = 0; i <= 100; ++i)
		m_Array[i] = '0';
	m_Size = p_Size;
}

std::ostream& operator<< (std::ostream &out, const cls_Decimal &p_Dec)
{
	if (p_Dec.m_Sign == false) out << "-";
	for (int i = p_Dec.m_Size - 1; i >= 0; --i)
		out << p_Dec.m_Array[i];
	return out;
}

std::istream& operator>> (std::istream &in, cls_Decimal &p_Dec)
{
	std::string str = "0123456789";
	unsigned char k;
	in >> k;
	int i = p_Dec.m_Size - 1;
	if (k == '-')
		p_Dec.m_Sign = false;
	else
	{
		p_Dec.m_Sign = true;
		p_Dec.m_Array[p_Dec.m_Size - 1] = k;
		--i;
	}
	for (; i >= 0; --i)
	{
		in >> p_Dec.m_Array[i];
		if (str.find(p_Dec.m_Array[i]) == std::string::npos)
			throw cls_Decimal::UnexpectedNum(p_Dec.m_Array[i]);
	}
	return in;
}

const cls_Decimal cls_Decimal::operator+(cls_Decimal& p_Dec)
{
	cls_Decimal Res;
	int Num = toInt() + p_Dec.toInt();
	Res.setInt(Num);
	return Res;
}

const cls_Decimal cls_Decimal::operator-(cls_Decimal& p_Dec)
{
	cls_Decimal Res;
	int Num = toInt() - p_Dec.toInt();
	Res.setInt(Num);
	return Res;
}

const cls_Decimal cls_Decimal::operator*(cls_Decimal& p_Dec)
{
	cls_Decimal Res;
	int Num = toInt() * p_Dec.toInt();
	Res.setInt(Num);
	return Res;
}

const bool cls_Decimal::operator>(cls_Decimal& p_Dec)
{
	return toInt() > p_Dec.toInt();
}

const bool cls_Decimal::operator<(cls_Decimal& p_Dec)
{
	return toInt() < p_Dec.toInt();
}

const bool cls_Decimal::operator>=(cls_Decimal& p_Dec)
{
	return toInt() >= p_Dec.toInt();
}

const bool cls_Decimal::operator<=(cls_Decimal& p_Dec)
{
	return toInt() <= p_Dec.toInt();
}

const bool cls_Decimal::operator==(cls_Decimal& p_Dec)
{
	return toInt() == p_Dec.toInt();
}

cls_Decimal::~cls_Decimal()
{
	delete m_Array;
}
