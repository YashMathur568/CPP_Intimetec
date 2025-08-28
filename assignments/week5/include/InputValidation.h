#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <string>

bool isValidAge(int age);
bool isValidEmail(std::string &email);
bool isValidContact(std::string &contact);
bool isValidPassword(std::string &password);
void flushInputBuffer();
int getValidatedInt();
double getValidatedDouble();

#endif
