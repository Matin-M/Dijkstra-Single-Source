#include "util.h"

using namespace std;
using namespace util;

void Util::swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}