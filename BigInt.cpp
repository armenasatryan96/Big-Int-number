#include "BigInt.h"
#include <iostream>

using namespace std;

int BigInt::maxsize = 30;

BigInt::BigInt()
{
	m_size = 0;
	m_nshan = '+';
	m_arr = new int[maxsize];
	for (int i = 0; i < maxsize; i++)
		m_arr[i] = 0;
}

BigInt::BigInt(const BigInt& copyer)
{
	if (this == &copyer)
		return;
	m_arr = new int[maxsize];
	for (int i = 0; i < maxsize; i++)
	{
		m_arr[i] = 0;
	}
	m_nshan = copyer.m_nshan;
	m_size = copyer.m_size;
	for (int i = 0; i < m_size; i++)
	{
		m_arr[i] = copyer.m_arr[i];
	}
}

BigInt::BigInt(string arr)
{
	m_arr = new int[maxsize];
	for (int k = 0; k < maxsize; k++)
	{
		m_arr[k] = 0;
	}
	int i = 0;
	if (arr.size() != 0) 
	{
	    if (arr[0] == '-')
	    {
	    	if ((int)arr.size() > maxsize + 1)
	    	{
	    		cout << "mutqagreq chisht tiv";
	    		return;
	    	}
	    	m_nshan = '-';
	    	m_size = arr.size() - 1;
	    	i++;
	    }
		else
		{
			if ((int)arr.size() > maxsize)
			{
				cout << "mutqagreq chisht tiv";
				return;
			}
		}
	}
	m_nshan = '+';
	m_size = arr.size();
	if (arr.size() == 1 && arr[0] == '0')
	{
		m_size = 0;
	}
	for (int j = 0; j < m_size; j++)
	{
		m_arr[m_size - j - 1] = arr[j + i] - '0';
	}
}

BigInt:: ~BigInt()
{
	delete[] m_arr;
}

void BigInt::print()
{
	if (m_size == 0)
	{
		cout << "0";
		return;
	}
	if (m_nshan == '-') cout << "-";
	for (int i = m_size - 1; i >= 0; i--)
	{
		cout << m_arr[i];
	}
}

BigInt BigInt::unsignSum(const BigInt& sumer)
{
	BigInt Sum;
	int value;
	for (int i = 0; i < maxsize - 1; i++)
	{
		value = Sum.m_arr[i] + this->m_arr[i] + sumer.m_arr[i];
		Sum.m_arr[i] = value % 10;
		Sum.m_arr[i + 1] = value / 10;
	}
	value = Sum.m_arr[maxsize - 1] + this->m_arr[maxsize - 1] + sumer.m_arr[maxsize - 1];
	if (value > 9)
	{
		throw "sum is not possible!!!!";
	}
	else
		Sum.m_arr[maxsize - 1] = value;
	Sum.m_size = maxsize;
	while (Sum.m_arr[Sum.m_size - 1] == 0 && Sum.m_size > 0) Sum.m_size--;
	return Sum;
}

int BigInt::unsignmax(const BigInt& cmp)
{
	if (m_size == cmp.m_size)
	{
		for (int i = m_size - 1; i >= 0; i--)
		{
			if (this->m_arr[i] == cmp.m_arr[i])
				continue;
			int value = (this->m_arr[i] > cmp.m_arr[i]) ? 1 : 2;
			return value;
		}
		return 0;
	}
	int value = (m_size > cmp.m_size) ? 1 : 2;
	return value;
}

BigInt BigInt::positivSubPositiv(const BigInt& cmp)
{
	BigInt Sub;
	int value;
	Sub.m_nshan = '+';
	if (*this > cmp)
	{
		Sub.m_nshan = '+';
		for (int i = 0; i < maxsize; i++)
		{
			value = Sub.m_arr[i] + this->m_arr[i] - cmp.m_arr[i];
			if (value < 0)
			{
				Sub.m_arr[i] = value + 10;
				Sub.m_arr[i + 1]--;
			}
			else
				Sub.m_arr[i] = value;
		}
		Sub.m_size = maxsize;
		while (Sub.m_arr[Sub.m_size - 1] == 0 && Sub.m_size > 0)
			Sub.m_size--;
		return Sub;
	}
	Sub.m_nshan = '-';
	for (int i = 0; i < maxsize; i++)
	{
		value = Sub.m_arr[i] - this->m_arr[i] + cmp.m_arr[i];
		if (value < 0)
		{
			Sub.m_arr[i] = value + 10;
			Sub.m_arr[i + 1]--;
		}
		else
			Sub.m_arr[i] = value;
	}
	Sub.m_size = maxsize;
	while (Sub.m_arr[Sub.m_size - 1] == 0 && Sub.m_size > 0)
		Sub.m_size--;
	return Sub;
}

BigInt BigInt::modulSub(const BigInt& suber)
{
	BigInt Q1 = *this;
	BigInt Q2 = suber;
	Q1.m_nshan = '+';
	Q2.m_nshan = '+';
	BigInt Q3 = Q1.positivSubPositiv(Q2);
	Q3.m_nshan = '+';
	return Q3;
}

BigInt BigInt::unsignMulBigIntDigitLevel(int digit, int level)
{
	BigInt Mul;
	int value;
	for (int i = 0; i < m_size; i++)
	{
		value = m_arr[i] * digit + Mul.m_arr[i + level];
		if (value < 10)
		{
			if (i + level > maxsize - 1)
			{
				throw 187;
			}
			Mul.m_arr[i + level] = value % 10;
		}
		else
		{
			if (i + level + 1 > maxsize - 1)
			{
				throw 187;
			}
			Mul.m_arr[i + level] = value % 10;
			Mul.m_arr[i + 1 + level] = value / 10;
		}
	}
	Mul.m_nshan = '+';
	Mul.m_size = maxsize;
	while (Mul.m_arr[Mul.m_size - 1] == 0 && Mul.m_size > 0)
		Mul.m_size--;
	return Mul;
}

BigInt BigInt:: operator= (const BigInt& cop)
{
	m_nshan = cop.m_nshan;
	m_size = cop.m_size;
	for (int i = 0; i < m_size; i++)
	{
		m_arr[i] = cop.m_arr[i];
	}
	return *this;
}

bool BigInt:: operator> (const BigInt& cmp)
{
	if (this->m_nshan == '+')
		if (cmp.m_nshan == '-') return true;
		else return(this->unsignmax(cmp) == 1);
	if (cmp.m_nshan == '+') return false;
	return this->unsignmax(cmp) == 2;
}

bool BigInt:: operator==(const BigInt& cmp)
{
	if (this->m_nshan != cmp.m_nshan)
		return false;
	return this->unsignmax(cmp) == 0;
}

bool BigInt:: operator< (const BigInt& cmp)
{
	if (*this == cmp || *this > cmp)
		return false;
	return true;
}

bool BigInt:: operator>= (const BigInt& cmp)
{
	if (*this < cmp)
	{
		return false;
	}
	return true;
}

bool BigInt:: operator<= (const BigInt& cmp)
{
	if (*this > cmp)
	{
		return false;
	}
	return true;
}

bool BigInt:: operator!= (const BigInt& cmp)
{
	if (*this == cmp)
	{
		return false;
	}
	return true;
}

BigInt BigInt:: operator+= (const BigInt& sumer)
{
	*this = *this + sumer;
	return *this;
}

BigInt BigInt:: operator-= (const BigInt& suber)
{
	*this = *this - suber;
	return *this;
}

BigInt BigInt:: operator*= (const BigInt& muler)
{
	*this = *this * muler;
	return *this;
}

BigInt BigInt:: operator/= (const BigInt& diver)
{
	*this = *this / diver;
	return *this;
}

BigInt BigInt:: operator%= (const BigInt& diver)
{
	*this = *this % diver;
	return *this;
}

BigInt BigInt:: operator+ (const BigInt& sumer)
{
	if (m_nshan == '-' && sumer.m_nshan == '+')
	{
		BigInt  Sum = this->modulSub(sumer);
		if (this->unsignmax(sumer) == 1)
			Sum.m_nshan = '-';
		return Sum;
	}
	if (m_nshan == '+' && sumer.m_nshan == '-')
	{
		BigInt Sum = this->modulSub(sumer);
		if ((this->unsignmax(sumer)) == 2)
			Sum.m_nshan = '-';
		return Sum;
	}
	BigInt Sum = this->unsignSum(sumer);
	Sum.m_nshan = this->m_nshan;
	return Sum;
}

BigInt& BigInt:: operator++()
{
	if (m_nshan == '+')
	{
		int i = 0;
		while (m_arr[i] == 9 && i < maxsize - 1)
		{
			m_arr[i] = 0;
			i++;
		}
		if (i < maxsize - 1 || m_arr[i] < 9)
		{
			++m_arr[i];
			if ((m_arr[i] == 1 && i != 0) || m_size == 0)
			{
				m_size++;
			}
		}
		else
		{
			throw 187;
		}
	}
	else
	{
		m_nshan = '+';
		--(*this);
		if (this->m_size > 0)
			m_nshan = '-';
	}
	return *this;
}

BigInt BigInt:: operator++(int)
{
	BigInt B = *this;
	if (m_nshan == '+')
	{
		int i = 0;
		while (m_arr[i] == 9 && i < maxsize - 1)
		{
			m_arr[i] = 0;
			i++;
		}
		if (i < maxsize - 1 || m_arr[i] < 9)
		{
			++m_arr[i];
			if ((m_arr[i] == 1 && i != 0) || m_size == 0)
			{
				m_size++;
			}
		}
		else
		{
			throw 187;
		}
	}
	else
	{
		m_nshan = '+';
		(*this)--;
		if (this->m_size > 0)
			m_nshan = '-';
	}
	return B;
}

BigInt BigInt:: operator-(const BigInt& suber)
{
	if (this->m_nshan == '+')
		if (suber.m_nshan == '-')
			return this->unsignSum(suber);
		else
			return this->positivSubPositiv(suber);
	if (suber.m_nshan == '+')
	{
		BigInt Sub = this->unsignSum(suber);
		Sub.m_nshan = '-';
		return Sub;
	}
	BigInt Sub = this->modulSub(suber);
	Sub.m_nshan = '-';
	return Sub;
}

BigInt& BigInt:: operator--()
{
	if (m_nshan == '+' && m_size > 0)
	{
		int i = 0;
		while (m_arr[i] == 0 && i < maxsize - 1)
		{
			m_arr[i] = 9;
			i++;
		}
		--m_arr[i];
		if (m_arr[i] == 0 && i != 0)
		{
			m_size--;
		}
		return *this;
	}
	else
	{
		m_nshan = '+';
		++(*this);
		m_nshan = '-';
	}
	return *this;
}

BigInt BigInt:: operator--(int)
{
	BigInt B = *this;
	if (m_nshan == '+' && m_size > 0)
	{
		int i = 0;
		while (m_arr[i] == 0 && i < maxsize - 1)
		{
			m_arr[i] = 9;
			i++;
		}
		--m_arr[i];
		if (m_arr[i] == 0 && i != 0)
		{
			m_size--;
		}
		return *this;
	}
	else
	{
		m_nshan = '+';
		(*this)++;
		m_nshan = '-';
	}
	return B;
}

BigInt BigInt:: operator* (const BigInt& muler)
{
	BigInt Mul;
	for (int i = 0; i < muler.m_size; i++)
	{
		Mul = Mul + this->unsignMulBigIntDigitLevel(muler.m_arr[i], i);
	}
	if (m_nshan != muler.m_nshan)
		Mul.m_nshan = '-';
	return Mul;
}

BigInt BigInt:: operator/ (const BigInt& diver)
{
	BigInt Div;
	if (Div == diver)
	{
		cout << "0-i vra bajanel hnaravor che";
		return Div;
	}
	BigInt Sub1 = *this;
	BigInt Sub2 = diver;
	Sub1.m_nshan = '+';
	Sub2.m_nshan = '+';
	if (Sub1 < Sub2)
		return Div;
	if (m_size == 30)
	{
		maxsize++;
	}
	Div.m_size = Sub1.m_size - Sub2.m_size + 1;
	Div.m_arr[Div.m_size - 1] = 1;
	if ((Div * Sub2) > Sub1)
	{
		Div.m_arr[Div.m_size - 1]--;
		Div.m_size--;
		Div.m_arr[Div.m_size - 1]++;
	}
	for (int i = Div.m_size - 1; i >= 0; i--)
	{
		while (((Div * Sub2) < Sub1) && Div.m_arr[i] < 10)
			Div.m_arr[i]++;
		if ((Div * Sub2) == Sub1) break;
		Div.m_arr[i]--;
	}
	if (this->m_nshan != diver.m_nshan)
	{
		Div.m_nshan = '-';
	}
	if (m_size == 30)
	{
		maxsize--;
	}
	return Div;
}

BigInt BigInt:: operator% (const BigInt& diver)
{
	BigInt balance;
	balance = *this / diver;
	balance = *this - balance * diver;
	return balance;
}
