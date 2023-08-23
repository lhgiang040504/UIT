#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    float a = 1.3;
    float b = 1.3489;
    // fixed << setprecision(2)
    cout << setprecision(3) << a;
    return 0;
}