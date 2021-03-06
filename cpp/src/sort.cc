/* Sort array in either decreasing or increasing order.
 * Educational program.
 *
 * @author Nikolai Kostromitin
 */

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

#include "utils.h"

void sort(int ar[], int size, bool desc = false);

int main()
{
    const int size = 10;
    int a[size];

    srand(time(NULL));
    fill(a, size, -100, 100);

    const int width = 5;
    std::cout << "Before sort: ";
    print(a, size, width);
    std::cout << std::endl;

    bool desc = false;
    if (desc)
        std::cout << "... sorting in decreasing order\n";
    else
        std::cout << "... sorting in increasing order\n";
    sort(a, size, desc);

    std::cout << "After sort: ";
    print(a, size, width);
    std::cout << std::endl;
}

typedef bool (*cmp_t)(int, int);

void sort(int a[], int size, cmp_t cmp)
{
    for (int i = 0; i < size; ++i) {
        bool swapped = false;
        for (int j = 0; j < size - i - 1; ++j)
            if (cmp(a[j], a[j+1])) {
                swap(&a[j], &a[j+1]);
                swapped = true;
            }
        if (!swapped)
            return;
    }
}

bool cmp_lt(int a, int b) { return a < b; }

bool cmp_gt(int a, int b) { return a > b; }

void sort(int a[], int size, bool desc)
{
    if (desc)
        sort(a, size, [] (int a, int b) { return a < b; });
    else
        sort(a, size, [] (int a, int b) { return a > b; });
}
