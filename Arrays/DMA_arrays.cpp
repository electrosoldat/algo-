// 1D dynamic memory allocation and deallocation in C++
#include <iostream>
using namespace std;
int main() {

    int n;
    cin >> n;

    int* a = new int(30);
    int* b = new int;
    int* c = new int[30];

    for(int i=0;i<30;i++)
    {
        c[i] = i;
    }

    cout << *a << endl;
    cout << *b << endl;

    for(int i=0;i<30;i++)
    {
        cout << c[i] << " ";
    }

    delete a;
    delete b;
    delete []c;

    return 0;
}
