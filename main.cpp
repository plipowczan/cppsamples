#include "Car.h"
#include <iostream>
#include <string>

using namespace std;

struct Person
{
    string firstName;
    string lastName;
    int gender;
    int age;
};

struct Marriage
{
    Person wife;
    Person husband;
    int age;
};

class PersonClass
{
  public:
    string firstName;
    string lastName;
    int gender;
    int age;

    PersonClass(string _firstName, string _lastName, int _gender, int _age)
    {
        firstName = _firstName;
        lastName = _lastName;
        gender = _gender;
        age = _age;
    }

    void IncreaseAge(int numberOfYears)
    {
        age += numberOfYears;
    }

    void PrintPersonData()
    {
        cout << "First name: " << firstName << endl;
        cout << "Last name: " << lastName << endl;
        if (gender == 0)
        {
            cout << "Gender: female" << endl;
        }
        else if (gender == 1)
        {
            cout << "Gender: male" << endl;
        }
        else
        {
            cout << "Gender: unknown" << endl;
        }
        cout << "Age: " << age << endl;
    }
};

class EmployeeClass : public PersonClass
{
  public:
    int hourSalary;

    EmployeeClass(string _firstName, string _lastName, int _gender, int _age, int _hourSalary) : PersonClass(_firstName, _lastName, _gender, _age)
    {
        hourSalary = _hourSalary;
    }

    int GetMonthSalary()
    {
        return 160 * hourSalary;
    }
};

namespace Animals
{
enum Animals
{
    CHICKEN,
    DOG,
    CAT,
    ELEPHANT,
    DUCK,
    SNAKE,
    MAX_ANIMALS
};
}

void Legs()
{
    int legs[Animals::MAX_ANIMALS] = {2, 4, 4, 4, 2, 0};

    std::cout << "An elephant has " << legs[Animals::ELEPHANT] << " legs.\n";
}

int ArrayTest()
{
    //int array[5]; // no initialization (undefined behaviour)
    //int array[5] = { 1, 2, 3, 4, 5 }; // initialize using the initializer list
    //int array[5] = {}; // initialize all elements to 0
    //int array[5] = { 1, 2, 3 }; // only initialize first 3 elements
    //int array[] = { 1, 2, 3, 4, 5 }; // let initializer list set length of the array
    int array[5]{1, 2, 3, 4, 5}; // use uniform initialization to initialize the fixed array

    std::cout << array[0] << '\n';
    std::cout << array[1] << '\n';
    std::cout << array[2] << '\n';
    std::cout << array[3] << '\n';
    std::cout << array[4] << '\n';
    std::cout << sizeof(array) << '\n';
    //array[7] = 100; // segmentation falut exception is thrown when you execute this (write out of bounds)

    return 0;
}

void OutputTest()
{
    cout << "Hello world" << endl;
    int test = 1;
    cout << test << endl;
    int test2;
    cout << test2 << endl;
}

void UserInput()
{
    OutputTest();
    string name = "";
    int age = 0;
    cout << "What is your name?" << endl;
    getline(cin, name);
    cout << "Nice to meet you " << name << endl;
    cout << "How old are you?" << endl;
    cin >> age;
    cout << "Oh you are " << age << " years old." << endl;

    return;
}

void PrintPersonData(Person person)
{
    cout << "First name: " << person.firstName << endl;
    cout << "Last name: " << person.lastName << endl;
    if (person.gender == 0)
    {
        cout << "Gender: female" << endl;
    }
    else if (person.gender == 1)
    {
        cout << "Gender: male" << endl;
    }
    else
    {
        cout << "Gender: unknown" << endl;
    }
    cout << "Age: " << person.age << endl;
}

void MarriageInfo(Marriage marriage)
{
    cout << marriage.husband.firstName << " is married with " << marriage.wife.firstName << " for " << marriage.age << " years" << endl;
}

// template <class T>
// T multiplication(T x, T y)
// {
//     return x * y;
// };

template <class T, class U>
T multiplication(T x, U y)
{
    return x * y;
}

//------------------------------------------------------------------------
// typedef and template classes
//------------------------------------------------------------------------

template <class T>
class MathOperations
{
  public:
    T add(T x, T y)
    {
        return x + y;
    }

    T subtract(T x, T y)
    {
        return x - y;
    }

    T divide(T x, T y)
    {
        return x / y;
    }

    T multiply(T x, T y)
    {
        return x + y;
    }
};

typedef MathOperations<int> MathOperationsInt;
typedef MathOperations<double> MathOperationsDouble;

//------------------------------------------------------------------------
// pass arguments by value or reference
//------------------------------------------------------------------------

void increaseNumberByValue(int number)
{
    number++;
}

void increaseNumberByReference(int &number)
{
    number++;
}

//------------------------------------------------------------------------
// pointers
//------------------------------------------------------------------------

void increaseNumberByPointer(int *ptr)
{
    (*ptr)++;
}

int main(int argc, char const *argv[])
{
    //------------------------------------------------------------------------
    // multiple files
    //------------------------------------------------------------------------

    Car c = Car();
    c.BlowHorn();

    //------------------------------------------------------------------------
    // pointers
    //------------------------------------------------------------------------

    // int myAge = 35;
    // cout << "My age: " << myAge << endl;
    // cout << "The address of my age " << &myAge << endl;

    // int *ptr = &myAge;
    // cout << "The address of my age (by pointer) " << ptr << endl;
    // cout << "My age (pointer): " << (*ptr) << endl;
    // (*ptr)++;
    // cout << "My age one year later (pointer): " << (*ptr) << endl;
    // increaseNumberByPointer(ptr);
    // cout << "My age one year later (pointer): " << (*ptr) << endl;

    //------------------------------------------------------------------------
    // pass arguments by value or reference
    //------------------------------------------------------------------------

    // int number = 5;
    // cout << "Number value: " << number << endl;
    // increaseNumberByValue(number);
    // cout << "Increased by value: " << number << endl;
    // increaseNumberByReference(number);
    // cout << "Increased by reference: " << number << endl;

    //------------------------------------------------------------------------
    // typedef and template classes
    //------------------------------------------------------------------------

    // MathOperationsInt mathOperationsInt = MathOperationsInt();
    // MathOperationsDouble mathOperationsDouble = MathOperationsDouble();

    // cout << "Lets count ints add: " << mathOperationsInt.add(10, 2) << endl;
    // cout << "Lets count double add: " << mathOperationsDouble.add(10.3, 2.1) << endl;

    //------------------------------------------------------------------------
    // template functions
    //------------------------------------------------------------------------

    // cout << "Lets count ints: " << multiplication(10, 2) << endl;
    // cout << "Lets count doubles " << multiplication(10.5, 2.5) << endl;
    // cout << "Lets count doubles " << multiplication(10.5, 2) << endl;

    //------------------------------------------------------------------------
    // inheritance derived class

    // EmployeeClass employee = EmployeeClass("Paweł", "Lipowczan", 1, 35, 100);
    // cout << employee.firstName << " " << employee.lastName << " earns: " << employee.GetMonthSalary() << endl;

    //------------------------------------------------------------------------
    // classes and structs
    //------------------------------------------------------------------------

    // Person pawel;
    // pawel.firstName = "Paweł";
    // pawel.lastName = "Lipowczan";
    // pawel.gender = 1;
    // pawel.age = 35;

    // PersonClass pawelClass = PersonClass("Paweł", "Lipowczan", 1, 35);

    // pawelClass.IncreaseAge(5);
    // pawelClass.PrintPersonData();

    // PrintPersonData(pawel);

    // Person kamil = {"Kaml", "Testowski", 1, 30};
    // Person agata = {"Agata", "Mala", 1, 25};

    // PrintPersonData(kamil);

    // Marriage marriage1 = {agata, kamil, 5};

    // MarriageInfo(marriage1);

    //ArrayTest();
    //Legs();
    //OutputTest();
    //UserInput();
    system("pause");
    return 0;
}
