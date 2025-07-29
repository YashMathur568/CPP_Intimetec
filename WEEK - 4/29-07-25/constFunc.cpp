#include <iostream>
#include <string>

struct Book
{
    std::string title;
    std::string author;
    int pages;

    void displayTitle() const
    {
        std::cout << "Title: " << title << "\n";
    }
    void updateTitle(const std::string &newTitle)
    {
        title = newTitle;
    }
};

int main()
{
    const Book b1 = {"human history", "Yash Mathur", 255};

    b1.displayTitle();
    // b1.updateTitle("New Title");
    return 0;
}
