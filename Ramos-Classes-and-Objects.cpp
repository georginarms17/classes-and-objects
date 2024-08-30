#include <iostream>
using namespace std;

class Books {             
    private:                
        string bookName;
        string author;
        int year;

    public:
        // Constructors
        Books() : bookName(""), author(""), year(0) {}
        Books(string n, string a, int y) : bookName(n), author(a), year(y) {}

        void display() {
            cout << "Book Title: " << bookName << endl;
            cout << "Author: " << author << endl;
            cout << "Year: " << year << endl;
        }

        string getbName() {
            return bookName;
        }

        void setDetails(string n, string a, int y) {
            bookName = n;
            author = a;
            year = y;
        }

        //to display all the book details in a format
        void getDetails () {
            cout << bookName << "       " << author << "        " << year << endl;
        }
};
    
class Library { 
    private:
        static const int max_books = 100;
        Books books[max_books];
        int bookCount;

    public:                 
        Library() : bookCount(0) {}
        
        void addBook (const Books& book) {
            if (bookCount < max_books) {
                books[bookCount] = book;
                bookCount++;
                
                cout << endl << "Book added successfully!" << endl << endl;
            }
            else {
                cout << "Library is full. Unable to add more books." << endl;
            }
        }

        void allBooks () {
            if (bookCount == 0) {
                cout << "No books added into the Library." << endl << endl;
                return;
            }
            
            cout << "                  BOOK LIST                    " << endl;
            cout << "TITLE              AUTHOR              YEAR" << endl;
            for (int i = 0; i < bookCount; i++) {
                books[i].getDetails();
            }
        }

        void searchBook (string& bookName) {
            for (int i = 0; i < bookCount; i++) {
                if (books[i].getbName() == bookName) {
                    cout << "Book Found!" << endl << endl;
                    books[i].display();
                    cout << endl;
                    return;
                }
            }
            cout << endl << "Book not found. :(" << endl;
        }
};

int main () {
    Library lib;
    int choice;

    do {
        cout << "       LIBRARY MENU        " << endl;
        cout << "1 - Add a Book" << endl << "2 - Display Books" << endl << "3 - Search a Book" << endl << "4 - Exit" << endl;
        cout << endl << "Choice: ";
        cin >> choice;
        cout << endl;
            
            switch (choice) {
                case 1: {
                    string bookName, author;
                    int year;

                    cout << "               ADD A BOOK          " << endl;
                    cout << "Kindly enter the following information." << endl << endl;
                    cout << "Book Title: ";
                    cin.ignore();
                    getline(cin, bookName);

                    cout << "Author: ";
                    getline(cin, author);

                    cout << "Year: ";
                    cin >> year;

                    Books newBook(bookName, author, year);
                    lib.addBook(newBook);
                    break;
                }
                case 2:
                    lib.allBooks();
                    break;
                case 3: {
                    string searchTitle;

                    cout << "          SEARCH A BOOK          " << endl;
                    cout << "Search Book by its Title: ";
                    cin.ignore();
                    getline(cin, searchTitle);

                    lib.searchBook(searchTitle);
                    break;
                }
                case 4:
                    cout << "Exiting from the system." << endl;
                    break;
                default:
                    cout << "Invalid choice. Kindly try again and input numbers 1-4 only." << endl;
                }
    } while (choice != 4);

    return 0;
}