/**
 * Project Untitled
 */


#include "Book.h"
#include <iostream>

/**
 * Book implementation
 */


/**
 * @param newStatus
 * @return void
 */
void Book::updateStatus(std::string newStatus) {
    status = newStatus;
    return;
}

/**
 * @return void
 */
void Book::displayBookDetails() {
    std::cout << "Book ID: " << bookID << std::endl;
    std::cout << "Title: " << title << std::endl;
    std::cout << "Author: " << author << std::endl;
    std::cout << "Status: " << status << std::endl;
    return;
}