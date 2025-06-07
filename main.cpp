#include <iostream>
#include "Librarian.h"

void showMenu() {
    std::cout << "\n===== Library Management Menu =====\n";
    std::cout << "1. Add Book\n";
    std::cout << "2. Edit Book\n";
    std::cout << "3. Remove Book\n";
    std::cout << "4. Register Member\n";
    std::cout << "5. Edit Member\n";
    std::cout << "6. Remove Member\n";
    std::cout << "7. Issue Book\n";
    std::cout << "8. Return Book\n";
    std::cout << "9. Display All Books\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    Librarian librarian;
    int choice;

    while (true) {
        showMenu();
        std::cin >> choice;
        std::cin.ignore(); // To consume newline left in the buffer

        switch (choice) {
            case 1: {
                Book book;
                std::cout << "Enter Book ID: ";
                std::cin >> book.bookID;
                std::cin.ignore();
                std::cout << "Enter Title: ";
                getline(std::cin, book.title);
                std::cout << "Enter Author: ";
                getline(std::cin, book.author);
                book.status = "Available";
                librarian.addBook(book);
                break;
            }
            case 2:
                librarian.editBook();
                break;
            case 3:
                librarian.removeBook();
                break;
            case 4:
                librarian.registerMember();
                break;
            case 5:
                librarian.editMember();
                break;
            case 6:
                librarian.removeMember();
                break;
            case 7:
                librarian.issueBook();
                break;
            case 8:
                librarian.returnBook();
                break;
            case 9:
                librarian.displayAllBooks();
                break;
            case 0:
                std::cout << "Exiting...\n";
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
