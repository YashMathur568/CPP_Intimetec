#include <iostream>
#include <string>

struct Student
{
    std::string name;
    int age;
    float marks;
};

Student createStudent()
{
    Student s;

    std::cout << "Enter name: ";
    std::getline(std::cin, s.name);

    std::cout << "Enter age: ";
    std::cin >> s.age;

    std::cout << "Enter marks: ";
    std::cin >> s.marks;

    return s;
}

int main()
{
    Student s1 = createStudent();

    std::cout << "\nStudent Details:\n";
    std::cout << "Name: " << s1.name << "\n";
    std::cout << "Age: " << s1.age << "\n";
    std::cout << "Marks: " << s1.marks << "\n";

    return 0;
}
