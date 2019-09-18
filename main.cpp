#include <iostream>
#include "BigInt.h"
#include <time.h>
#include <string>

using namespace std;

int main(void)
{
    clock_t t = clock();
    string arr1 ="14";
    string arr2 ="-14";
    //cout << arr1.size() << endl;
    //cin >> arr1;
    BigInt A1(arr1);
	A1.print();
    BigInt A2(arr2);
    //A1 = (A1 + A2);
    BigInt C;// = A1 + A2;
    //A1 %= A2;
    cout << endl;
    cout << "A1 = ";
    A1.print();
    cout << endl;
    cout << "A2 = ";
    A2.print();
    cout << endl;
    C = A1--;
    cout << "C = ";
    C.print();
	cout << endl;
     cout << "A1 = ";
    A1.print();
    cout << endl;
    cout << "A1 + A2 = ";
    (A1 + A2).print();
    cout << endl;
    //if(A1 - A2 == 0) cout << "kara" << endl;
    cout << "A1 - A2 = ";
    (A1 - A2).print();
    cout << endl;
    cout << "A1 * A2 = ";
    (A1 * A2).print();
    cout << endl;
    cout << "A1 / A2 = ";
    (A1 / A2).print();
    cout << endl;
    cout << "A1 % A2 = ";
    (A1 % A2).print();
    cout << endl;
    //A1>A2? A1.m_print():A2.m_print();
    //A1>A2? cout << "A1" : cout << "A2";
    //cout << (A1 == A2) << endl;
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    cout << time_taken << " seconds";
	system("pause");
    return 0;
}