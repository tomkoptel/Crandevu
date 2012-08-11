#include <iostream>

using namespace std;

// how to get size of ptr. Useful for arrays.
size_t getSize(int *ptr);

int main(){
    int array[ 10 ] = { 0 };
    cout << "Size of int array[10] is: " << getSize( array ) << endl;
    cout << "Size of 'sizeof array / sizeof( int )': " << sizeof array / sizeof( int ) << endl;

    int b[ 5 ] = {0, 1, 2, 3, 4};
    int * bPtr;

    bPtr = b;
    cout << "Int the case 'bPtr = b;' then bPtr is " << bPtr << endl;
    bPtr = &b[ 0 ];
    cout << "Int the case 'bPtr = &b[ 0 ];' then bPtr is " << bPtr << endl;
    // The name of such approach is: pointer/offset
    cout << "The alternative of 'b[ 3 ]' is '*( b + 3)'" << *( b + 3) << endl;
    // The name of such approach is: pointer/index
    cout << "The alternative of 'b[ 3 ]' is 'bPtr[ 3 ]'" << bPtr[ 3 ] << endl;

    return 0;
}

size_t getSize(int *ptr){
    return sizeof( ptr );
}
