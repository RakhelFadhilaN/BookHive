/**
 * Project Untitled
 */


#include "Librarian.h"
#include "Book.h"
#include <iostream>
#include <algorithm>

/**
 * Llibrarian implementation
 */


void Librarian::addBook(Book book) {
    bookCollection.push_back(book);
    std::cout << "Book added: " << book.title << std::endl;
}

void Librarian::editBook() {
    int id;
    std::cout << "Enter Book ID to edit: ";
    std::cin >> id;

    for (auto& book : bookCollection) {
        if (book.bookID == id) {
            std::cout << "Editing Book: " << book.title << std::endl;
            std::cout << "Enter new title: ";
            std::cin.ignore(); // flush newline
            getline(std::cin, book.title);
            std::cout << "Enter new author: ";
            getline(std::cin, book.author);
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Librarian::removeBook() {
    int id;
    std::cout << "Enter Book ID to remove: ";
    std::cin >> id;

    for (auto it = bookCollection.begin(); it != bookCollection.end(); ++it) {
        if (it->bookID == id) {
            std::cout << "Removing Book: " << it->title << std::endl;
            bookCollection.erase(it);
            return;
        }
    }
    std::cout << "Book not found.\n";
}

void Librarian::registerMember() {
    MemberRecord member;
    std::cout << "Enter member ID: ";
    std::cin >> member.memberID;
    std::cin.ignore(); // flush newline
    std::cout << "Enter member name: ";
    getline(std::cin, member.name);
    std::cout << "Enter member address: ";
    getline(std::cin, member.address);

    memberRecords.push_back(member);
    std::cout << "Member registered.\n";
}

void Librarian::editMember() {
    int id;
    std::cout << "Enter Member ID to edit: ";
    std::cin >> id;
    std::cin.ignore();

    for (auto& member : memberRecords) {
        if (member.memberID == id) {
            std::cout << "Editing Member: " << member.name << std::endl;
            std::cout << "Enter new name: ";
            getline(std::cin, member.name);
            std::cout << "Enter new address: ";
            getline(std::cin, member.address);
            return;
        }
    }
    std::cout << "Member not found.\n";
}

void Librarian::removeMember() {
    int id;
    std::cout << "Enter Member ID to remove: ";
    std::cin >> id;

    for (auto it = memberRecords.begin(); it != memberRecords.end(); ++it) {
        if (it->memberID == id) {
            std::cout << "Removing Member: " << it->name << std::endl;
            memberRecords.erase(it);
            return;
        }
    }
    std::cout << "Member not found.\n";
}


void Librarian::issueBook() {
    int memberId, bookId;
    std::cout << "Enter Member ID: ";
    std::cin >> memberId;
    std::cout << "Enter Book ID: ";
    std::cin >> bookId;

    // Find member
    for (auto& member : memberRecords) {
        if (member.memberID == memberId) {
            // Find book
            for (auto& book : bookCollection) {
                if (book.bookID == bookId && book.status == "Available") {
                    // Mark book as borrowed
                    book.status = "Borrowed";
                    member.borrowedBooks.push_back(bookId);

                    // Create transaction
                    Transaction t;
                    t.transactionID = transactions.size() + 1;
                    t.bookID = bookId;
                    t.memberID = memberId;
                    t.transactionDate = "Today";  // You can update with real date
                    t.dueDate = "NextWeek";        // Likewise
                    t.status = "Borrowed";
                    transactions.push_back(t);

                    std::cout << "Book issued successfully.\n";
                    return;
                }
            }
            std::cout << "Book not found or already borrowed.\n";
            return;
        }
    }
    std::cout << "Member not found.\n";
}

void Librarian::returnBook() {
    int memberId, bookId;
    std::cout << "Enter Member ID: ";
    std::cin >> memberId;
    std::cout << "Enter Book ID to return: ";
    std::cin >> bookId;

    for (auto& t : transactions) {
        if (t.memberID == memberId && t.bookID == bookId && t.status == "Borrowed") {
            t.markAsReturned();

            for (auto& book : bookCollection) {
                if (book.bookID == bookId) {
                    book.status = "Available";
                    break;
                }
            }
            
            for (auto& member : memberRecords) {
                if (member.memberID == memberId) {
                    auto& borrowed = member.borrowedBooks;
                    borrowed.erase(std::remove(borrowed.begin(), borrowed.end(), bookId), borrowed.end());

                    break;
                }
            }

            std::cout << "Book returned successfully.\n";
            return;
        }
    }
    std::cout << "No matching borrowed transaction found.\n";
}



void Librarian::displayAllBooks() {
    std::cout << "===== Book List =====\n";
    for (auto& book : bookCollection) {
        book.displayBookDetails();
        std::cout << "---------------------\n";
    }
}