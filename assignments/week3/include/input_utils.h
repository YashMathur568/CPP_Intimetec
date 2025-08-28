#ifndef INPUT_UTILS_H
#define INPUT_UTILS_H
#include <string>

void flushInputBuffer();
int getValidatedInput(const std::string &prompt);
void getDimensionsFromUser(const std::string &name, int &rows, int &cols);

#endif
