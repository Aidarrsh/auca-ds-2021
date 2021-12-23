#include <bits/stdc++.h>
#include "../../au/algol.hpp"

using namespace std;

// support call operator: T t; t()

struct Student
{
    string mName;
    double mGpa;
    Student(const string &name, double gpa)
        : mName(name), mGpa(gpa)
    {
    }
};

struct isEven

{
    bool operator()(int value) const
    {
        return value % 2 == 0;
    }
};

struct cmpGpa
{
    bool operator()(const Student &s1, const Student &s2) const
    {
        return s1.mGpa < s2.mGpa;
    }
};

void p0101()
{
    int a[] = {3, 1, 20, 4, 7, 20, 5};
    vector<int> v = {3, -1, 20, 4, 7, 0, 5};

    auto itA = find(begin(a), end(a), 20);

    if (itA != end(a))
    {
        cout << "Position of 20 is " << itA - begin(a) << "\n";
    }
    else
    {
        cout << "20 not found\n";
    }

    auto itV = find(begin(v), end(v), -1);
    if (itV != end(v))
    {
        cout << "Position of -1 is " << itV - begin(v) << "\n";
    }
    else
    {
        cout << "-1 not found\n";
    }
}

void p0102()
{
    int a[] = {3, 1, 20, 4, 7, 20, 5};
    vector<int> v = {3, -1, 20, 4, 7, 0, 5};

    auto itA = auFind(begin(a), end(a), 20);

    if (itA != end(a))
    {
        cout << "Position of 20 is " << itA - begin(a) << "\n";
    }
    else
    {
        cout << "20 not found\n";
    }

    auto itV = auFind(begin(v), end(v), -1);
    if (itV != end(v))
    {
        cout << "Position of -1 is " << itV - begin(v) << "\n";
    }
    else
    {
        cout << "-1 not found\n";
    }
}

void p0201()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};

    // isEven functor;
    // auto itV = find_if(begin(v), end(v), isEven());
    // if (itV != end(v))
    // {
    //     cout << "Position of the first even number is " << itV - begin(v) << "\n";
    //     cout << "The number is " << *itV << "\n";
    // }
    // else
    // {
    //     cout << "even number not found\n";
    // }

    // lambda expression

    auto itV = find_if(begin(v), end(v), [](int value)
                       { return value % 2 == 0; });
    if (itV != end(v))
    {
        cout << "Position of the first even number is " << itV - begin(v) << "\n";
        cout << "The number is " << *itV << "\n";
    }
    else
    {
        cout << "even number not found\n";
    }
}

void p0202()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};
    // // isEven functor;
    // auto itV = auFind_if(begin(v), end(v), isEven());
    // if (itV != end(v))
    // {
    //     cout << "Position of the first even number is " << itV - begin(v) << "\n";
    //     cout << "The number is " << *itV << "\n";
    // }
    // else
    // {
    //     cout << "even number not found\n";
    // }

    // lambda expression

    auto itV = auFind_if(begin(v), end(v), [](int value)
                         { return value % 2 == 0; });
    if (itV != end(v))
    {
        cout << "Position of the first even number is " << itV - begin(v) << "\n";
        cout << "The number is " << *itV << "\n";
    }
    else
    {
        cout << "even number not found\n";
    }
}

struct GreaterThan
{
    int mData;

    GreaterThan(int data)
        : mData(data)
    {
    }
    bool opearator(int value) const
    {
        return value > mData;
    }
};

void p03()
{
    vector<int> v = {3, 1, 20, 4, 7, 0, 5};
    cout << "x = ";
    int x;
    cin >> x;

    // auto it = find_if(begin(v), end(v), GreaterThan(x));

    // if (it != end(v))
    // {
    //     cout << "the index " << it - begin(v) << "\n";
    //     cout << "the value " << *it << "\n";
    // }
    // else
    // {
    //     cout << "number not found\n";
    // }
    auto it2 = find_if(begin(v), end(v), [x](int value)
                       { return value > x; });

    if (it2 != end(v))
    {
        cout << "the index " << it2 - begin(v) << "\n";
        cout << "the value " << *it2 << "\n";
    }
    else
    {
        cout << "number not found\n";
    }
}
void p0401()
{
    int x;
    vector<int> v;
    while (cin >> x)
    {
        v.emplace_back(x);
    }

    auto it = min_element(begin(v), end(v));

    if (it != v.end())
    {
        cout << "the index " << it - begin(v) << "\n";
        cout << "the value " << *it << "\n";
    }
    else
    {
        cout << "number not found\n";
    }
}

void p0402()
{
    int x;
    vector<int> v;
    while (cin >> x)
    {
        v.emplace_back(x);
    }

    auto it = auMinElement(begin(v), end(v));

    if (it != v.end())
    {
        cout << "the index " << it - begin(v) << "\n";
        cout << "the value " << *it << "\n";
    }
    else
    {
        cout << "number not found\n";
    }
}

void p0501()
{
    vector<Student> stud;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        stud.emplace_back(name, gpa);
    }
    auto it = min_element(begin(stud), end(stud), [](const Student a, const Student b)
                          { return a.mGpa < b.mGpa; });
    if (it != stud.end())
    {
        cout << "Student with minimum gpa " << it->mName << " gpa is " << it->mGpa << "\n";
    }
    else
    {
        cout << "Student not found\n";
    }
    auto it2 = min_element(begin(stud), end(stud), [](const Student a, const Student b)
                           { return a.mName < b.mName; });
    if (it2 != stud.end())
    {
        cout << "Student with minimum name " << it2->mName << "\n";
    }
    else
    {
        cout << "Student not found\n";
    }
}
void p0502()
{
    vector<Student> stud;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        stud.emplace_back(name, gpa);
    }
    auto it = auMinElement_by(begin(stud), end(stud), [](const Student a, const Student b)
                              { return a.mGpa < b.mGpa; });
    if (it != stud.end())
    {
        cout << "Student with minimum gpa " << it->mName << ",gpa is " << it->mGpa << "\n";
    }
    else
    {
        cout << "Student not found\n";
    }
    auto it2 = auMinElement_by(begin(stud), end(stud), [](const Student a, const Student b)
                               { return a.mName < b.mName; });
    if (it2 != stud.end())
    {
        cout << "Student with minimum name is " << it2->mName << "\n";
    }
    else
    {
        cout << "Student not found\n";
    }
}

void p06()
{
    vector<Student> stud;
    string name;
    double gpa;
    while (cin >> name >> gpa)
    {
        //  stud.push_back(Student(name, gpa));
        stud.emplace_back(name, gpa);
    }
    sort(begin(stud), end(stud), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    for (const auto &s : stud)
    {
        cout << "{" << s.mName << ", " << s.mGpa << "}\n";
    }
    cout << "-----------\n";
    sort(begin(stud), end(stud), cmpGpa());
    for (const auto &s : stud)
    {
        cout << "{" << s.mName << ", " << s.mGpa << "}\n";
    }
}

void p07()
{
    vector<Student> students = {
        {"C", 3.45},
        {"Z", 4.00},
        {"X", 4.00},
        {"Y", 4.00},
        {"W", 4.00},
        {"R", 4.00},
        {"T", 4.00},
        {"D", 2.45},
        {"A", 4.00},
    };

    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mName < s2.mName; });

    for (const auto s : students)
    {
        cout << s.mName << ", " << s.mGpa << "\n";
    }

    cout << "-------------\n";
    sort(begin(students), end(students), [](const Student &s1, const Student &s2)
         { return s1.mGpa < s2.mGpa; });

    for (const auto s : students)
    {
        cout << s.mName << ", " << s.mGpa << "\n";
    }
    cout << "-------------\n";
    stable_sort(begin(students), end(students), [](const Student &s1, const Student &s2)
                { return s1.mName < s2.mName; });

    for (const auto s : students)
    {
        cout << s.mName << ", " << s.mGpa << "\n";
    }

    cout << "-------------\n";
    stable_sort(begin(students), end(students), [](const Student &s1, const Student &s2)
                { return s1.mGpa < s2.mGpa; });

    for (const auto s : students)
    {
        cout << s.mName << ", " << s.mGpa << "\n";
    }
}

void p08()
{
    string name;
    double gpa;
    vector<pair<string, double>> students;

    while (cin >> name >> gpa)
    {
        students.emplace_back(name, gpa);
    }
    sort(begin(students), end(students));

    for (const auto &it : students)
    {
        cout << it.first << ", " << it.second << "\n";
    }
}

void p09()
{
    using Employee = tuple<string, int, double>;

    string name;
    double salary;
    int age;
    vector<Employee> employees;

    while (cin >> name >> age >> salary)
    {
        employees.emplace_back(name, age, salary);
    }

    sort(
        begin(employees), end(employees), [](const Employee &e1, const Employee &e2)
        { return get<1>(e1) < get<1>(e2); });

    for (const auto &e : employees)
    {
        cout << get<0>(e) << ", " << get<1>(e) << ", " << get<2>(e) << "\n";
    }
}

void p1001()
{

    vector<int> v = {1, 4, 5, 10, 12, 20, 25, 40};
    for (int x; cin >> x;)
    {

        cout << (binary_search(begin(v), end(v), x) ? "Yes" : "No") << "\n";
    }
}

void p1002()
{
    vector<int> v = {1, 4, 5, 10, 12, 20, 25, 40};

    for (int x; cin >> x;)
    {

        cout << (auBinarySearch(begin(v), end(v), x) ? "Yes" : "No") << "\n";
    }
}

void p11()
{
    vector<int> v = {1, 4, 5, 10, 12, 20, 25, 40};
    for (int x; cin >> x;)
    {
        auto it = lower_bound(begin(v), end(v), x);

        if (it == end(v))
        {
            cout << "No element is equal or greater than " << x << "\n";
        }
        else if (*it == x)
        {
            cout << "Index of " << x << " is " << it - begin(v) << "\n";
        }
        else
        {
            cout << "Index of first element greater than " << x << " is " << it - begin(v) << "\n";
        }
    }
}

void p12()
{

    vector<int> v = {0, 0, 4, 5, 10, 10, 10, 12, 20, 25, 35, 25, 25, 40};
    for (int x; cin >> x;)
    {
        auto it = equal_range(begin(v), end(v), x);
        cout << "number of occurences of " << x << " is " << it.second - it.first << "\n";
    }
}
int main()
{
    // p0101();
    // p0102();
    // p0201();
    // p0202();
    p03();
    // p0401();
    // p0402();
    // p0501();
    // p0502();
    // p06();
    // p07();
    // p08();
    // p09();
    // p1001();
    // p1002();
    // p11();
    // p12();
}
