#include <iostream>
using namespace std;

/*
* * * *
* * * *
* * * *
* * * *
*/

void p1(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << "* ";
        }
        std::cout << std::endl;
    }
}

/*
*
* *
* * *
* * * *
* * * * *
*/
void p2(int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <= i; ++j) {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
1
1 2
1 2 3
1 2 3 4
1 2 3 4 5
*/
void p3(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << j << " ";
        }
        cout << endl;
    }
}

/*
1
2 2
3 3 3
4 4 4 4
5 5 5 5 5
*/
void p4(int n) {
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            cout << i << " ";
        }
        cout << endl;
    }
}

/*
* * * * *
* * * *
* * *
* *
*
*/


int main()
{
    p4(5);

    return 0;
}