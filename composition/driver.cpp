#include "Array.h"
#include "Stack.h"
#include "Fixed_Array.h"
#include "Queue.h"
#include "Array_Base.h"
#include <iostream>

using namespace std;

int main()
{

    cout << "-------Start-------" << endl;

    Stack<char> myStack;
    myStack.push('a');
    myStack.push('b');
    myStack.push('c');

    Stack<int> calculator;
    calculator.push(0);
   // calculator.push(12);
    calculator.pop();
   // calculator.push(2);
    cout << "||||||| " << calculator.size() << endl;

    cout << "size method used on myStack: " << myStack.size() << endl;
    cout << "top of myStack: " << myStack.top() << endl;

    myStack.pop();
    cout << "size method used on myStack after pop: " << myStack.size() << endl;
    cout << "top of myStack after pop: " << myStack.top() << endl;

    cout << endl;

    Stack<char> newS;
    newS.push('X');
    newS.push('Y');

    myStack = newS;

    cout << "= operator overload - myStack copy of newS top: " << myStack.top() << endl;
    myStack.pop();
    cout << "= operator overload - myStack copy newS top after pop: " << myStack.top() << endl;
    cout << endl;

    Stack<char> selfStack;
    selfStack.push('p');
    selfStack.push('t');

    selfStack = selfStack;

    newS.clear();
    cout << "newS size after clear(): " << newS.size() << endl;
    newS.push('J');
    cout << "top of newS after push: " << newS.top() << endl;
    cout << "size of newS after push: " << newS.size() << endl;
    cout << endl;

    Stack<int> copyStack;
    copyStack.push(1992);
    copyStack.push(1993);
    copyStack.push(1994);
    copyStack.push(1995);
    copyStack.push(1996);
    cout << "copyStack (int type) size: " << copyStack.size() << endl;
    cout << "copyStack (int type) top: " << copyStack.top() << endl;

    Stack<int> intStack(copyStack);
    cout << "Copy Constructor: intStack size: "<< intStack.size() << endl;
    cout << "Copy Constructor: top of intStack: " << intStack.top() << endl;

    intStack.clear();
    cout << "intStack is empty after clear (1 for True, 0 for False): " << intStack.is_empty() << endl;
    cout << endl;

    Stack<int> largeStack;
    for (int i = 0; i < 10000; i++)
    {
        largeStack.push(i);
    }

    cout << "largeStack size: " << largeStack.size() << endl;
    cout << "largeStack top: " << largeStack.top() << endl;
    cout << "largeStack is empty after clear (1 for True, 0 for False): " << largeStack.is_empty() << endl;

    Stack<int> largeCopy(largeStack);
    cout << "largeCopy size: " << largeCopy.size() << endl;
    cout << "largeCopy top: " << largeCopy.top() << endl;


    cout << "-----End of Stack-----" << endl;

    Queue<char> myQ;

    for (int i = 0; i < 300; i++)
    {
        myQ.enqueue('B');
    }

    myQ.enqueue('c');
    //myQ.dequeue();

    cout << "Letter at the end: " << myQ.last() << endl;
    cout << "Size of queue: " << myQ.size() << endl;

    myQ.enqueue('x');

    cout << "------End of Queue-----" << endl;

    Fixed_Array<int, 2> myfixArray(0);

    cout << "Contents of myFixArray: ";
    for (int i = 0; i < myfixArray.size(); i++)
    {
        cout << myfixArray[i];
    }
    cout << endl;


    Fixed_Array<int, 2> equalArray(3);
    cout << "Contents of equalArray: ";
    for (int i = 0; i < equalArray.size(); i++)
    {
        cout << equalArray[i];
    }
    cout << endl;


    myfixArray = equalArray;



    cout << "Contents of myfixArray = equalArray: ";
    for (int i = 0; i < myfixArray.size(); i++)
    {
        cout << myfixArray[i];
    }

    cout << endl;

    cout << "Contents copyfix which copies my fixArray: ";
    Fixed_Array<int, 2> copyfix(myfixArray);

    for (int i = 0; i < copyfix.size(); i++)
    {
        cout << copyfix[i];
    }

    cout << endl;

    cout << "Size of copyFix: " << copyfix.size() << endl;

    cout << "-----End of Fixed_Array------" << endl;


    Array<char> myArray(12, 'c');

    myArray.resize(4);
    myArray.resize(8);
    myArray.fill('R');

    Array<char> testArray(myArray);

    for (int i = 0; i < testArray.size(); i++)
    {
    cout << testArray[i];
    }

    cout << endl;

    testArray.resize(4);
    testArray.fill('w');
    myArray = testArray;

    for (int i = 0; i < myArray.size(); i++)
    {
    cout << myArray[i];
    }

    cout << endl;

    myArray.resize(12);

    Array<char> sizeArray(300, 'K');
    cout << sizeArray.size() << endl;

    sizeArray.resize(263);

    cout << sizeArray.size() << endl;


    Array<int> a(2, 1);

    Array<int> b(4, 8);

    a = b;

    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i];
    }

    cout << endl;

    cout << "------End of Array-----" << endl;

    Array_Base<char> baseTest(10, 'x');

    baseTest.fill('R');

    Array_Base<char> copyBase(baseTest);

    for (int i = 0; i < copyBase.size(); i++)
    {
    cout << copyBase[i];
    }

    cout << endl;


   for (int i = 0; i < baseTest.size(); i++)
    {
    cout << baseTest[i];
    }

    cout << endl;



    Array_Base<char> sizeBase(300, 'K');
    cout << sizeBase.size() << endl;

    Array_Base<int> intbase(2, 1);


    for (int i = 0; i < intbase.size(); i++)
    {
        cout << intbase[i];
    }

    cout << endl;




} // END OF MAIN
