#include <iostream>
using namespace std;

class Book {
private:

public:
    string title;
    string author;
    int pages;
    Book(string aTitle = "None", string aAuthor = "None", int aPages = NULL){
        title = aTitle;
        author = aAuthor;
        pages = aPages;
    }
};

int main(){
    Book book1("Harry Potter", "JK Rowling", 500);
    cout << book1.title << endl;

    Book book2("Lord of the Rings", "Tolkein", 700);
    cout << book2.title << endl;

    Book book3("None");
    cout << book3.author << endl;
    return 0;
}