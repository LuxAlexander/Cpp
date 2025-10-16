#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

int main() {

    srand(time(0));
    //random number between 3 and 6
    int n = rand() % 4 + 3;
    int m = rand() % 4 + 3;
    int* matrix=[n*m];

    return 0;
}