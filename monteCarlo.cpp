
#include <iostream>
#include <math.h>
#include <chrono>
#define SIZE 10000
using namespace std;

int main()
{
    int pointCircle = 0, pointSquare = 0;
    double x_random, y_random;
    srand(time(NULL));
    double pi;
    auto start = chrono::steady_clock::now();
    for(int i = 0; i < SIZE*SIZE; i++){

        x_random = (double) (rand() %  SIZE )/SIZE;
        y_random = (double) (rand() %  SIZE )/SIZE;

        double distance = pow(x_random, 2) + pow(y_random, 2);

        if(distance <= 1){
            pointCircle++;
        }
        pointSquare++;
        pi = (double)((4 * pointCircle)) / pointSquare;
    }
    cout<<pi<<endl;
    auto end = chrono::steady_clock::now();
     cout << "Elapsed time in milliseconds: "
        << chrono::duration_cast<chrono::milliseconds>(end - start).count()
        << " ms" << endl;
}