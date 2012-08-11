#include <iostream>
#include <cstdlib>

using namespace std;

// void *malloc(size);
// void *calloc(num, size);
// void *realloc(void *p, size);
// void free(void *p);
void display(float *a, int n)
{
    for(int i = 0; i < n; i++)
        *(a + i) = i;

    for(int i = 0; i < n; i++)
        cout << *(a + i)<< endl;
}

void displayDouble(float **array, int n)
{
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            array[i][j] = i + j;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cout << "row " << i << " column " << j
            << " result " << array[i][j] << endl;
        }
}


template <typename T> T **AllocateDynamicArray(int nRows, int nCols)
{
    T **dynamicArray;
    dynamicArray = new T*[nRows];
    for(int i = 0; i < nRows; i++)
        dynamicArray[i] = new T [nCols];
    return dynamicArray;
}


template <typename T> void FreeDynamicArray(T** dArray)
{
    delete [] *dArray;
    delete [] dArray;
}

int main(){
    float *array;
    int n = 5;
    cout << "(float *)malloc( n*sizeof(float) )\n";
    array = (float *)malloc( n*sizeof(float) );
    display(array, n);

    free(array);

    cout << "(float *)calloc( n, sizeof(float) )\n";
    array = (float *)calloc( n, sizeof(float) );
    display(array, n);

    free(array);

    cout << "new float[n]\n";
    array = new float[n];
    display(array, n);

    delete [] array;

    float **doubleArray = AllocateDynamicArray<float>(n, n);
    displayDouble(doubleArray, n);

    return 0;
}

