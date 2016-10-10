#include "Array.h"
#include <iostream>

using namespace std;

int main()
{

Array myarray(3, 't');

myarray.resize(4);
myarray.fill('x');

cout << "WORKING METHODS" << endl;
cout << "---------------" << endl;
cout << myarray.get(0) << endl;
myarray.set (4, 'y');
cout << myarray.get(4) << endl;
cout << myarray.find('y') << endl;
cout << myarray.find('y', 2) << endl;
cout << myarray.operator [] (4) << endl;
cout << "---------------" << endl;

myarray.resize(6);
myarray.set(5, 'B');

cout << "Contents of myarray: ";
for (int i = 0; i < myarray.size(); i++)
{
    cout << myarray.get(i);
}

cout << endl;

myarray.resize(5);
myarray.fill('c');
Array testArray(5, 'd');

cout << "Contents of testArray: ";
for (int i = 0; i < myarray.size(); i++)
{
    cout << testArray[i];
}
cout << endl;

myarray = testArray;
cout << "Contents of myarray[1] after copying the contents of testArray: ";
cout << myarray.get(1) << endl;

cout << "Max size before resize: " << myarray.max_size() << endl;

myarray.resize(101);


cout << "Max size after resize: " << myarray.max_size() << endl;

for (int i = 5; i < 100; i++)
{
    myarray[i] = 'y';
}


for (int i = 0; i < myarray.size(); i++)
{
    cout << myarray.get(i);
}

myarray.set(6, 'B');

cout << endl;
cout << "----" << endl;
cout << myarray[6] << endl;
cout << "----" << endl;



cout << endl;






}
