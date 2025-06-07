/**
 * Project Untitled
 */


#ifndef _BOOK_H
#define _BOOK_H

#include <string>

class Book {
public: 
    int bookID;
    std::string title;
    std::string author;
    std::string status;
    
/**
 * @param newStatus
 */
void updateStatus(std::string newStatus);
    
void displayBookDetails();
};

#endif //_BOOK_H