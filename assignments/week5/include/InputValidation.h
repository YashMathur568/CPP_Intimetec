#ifndef INPUTVALIDATION_H
#define INPUTVALIDATION_H

#include <string>

bool isValidAge(int age);
bool isValidEmail(const std::string &email);
bool isValidContact(const std::string &contact);
bool isValidPassword(const std::string &password);
void flushInputBuffer();
int getValidatedInt();
double getValidatedDouble();

#endif
