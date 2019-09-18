#ifndef BIG_INT_H
#define BIG_INT_H

#include <string>

using namespace std;

class BigInt
{
    char m_nshan;
    int * m_arr;
    int m_size;
    BigInt unsignSum(const BigInt & sumer);
    int unsignmax(const BigInt & cmp);
    BigInt positivSubPositiv(const BigInt & suber);
    BigInt modulSub(const BigInt & suber);
    BigInt unsignMulBigIntDigitLevel(int digit, int level);
public:
    static int maxsize;
    BigInt();
    BigInt(const BigInt & copyer);
    BigInt(string arr);
    ~BigInt();
    void print();
    bool operator> (const BigInt & cmp);
    BigInt operator= (const BigInt & cop);
    bool operator>= (const BigInt & cmp);	
	bool operator<= (const BigInt & cmp);
    bool operator!= (const BigInt & cmp);		
    bool operator== (const BigInt & cmp);
    bool operator< (const BigInt & cmp);
    BigInt operator+ (const BigInt & sumer);
    BigInt operator- (const BigInt & suber);
    BigInt operator* (const BigInt & muler);
    BigInt operator/ (const BigInt & diver);
    BigInt operator% (const BigInt & diver);
	BigInt operator+= (const BigInt & sumer);
    BigInt operator-= (const BigInt & suber);
    BigInt operator*= (const BigInt & muler);
    BigInt operator/= (const BigInt & diver);
    BigInt operator%= (const BigInt & diver);
    BigInt& operator++();
    BigInt operator++(int);
	BigInt& operator--();
	BigInt operator--(int);
};


#endif // !BIG_INT_H
