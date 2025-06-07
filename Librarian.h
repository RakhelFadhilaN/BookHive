/**
 * Project Untitled
 */


#ifndef _LIBRARIAN_H
#define _LIBRARIAN_H

#include <string>
#include <vector>
#include "Book.h"
#include "MemberRecord.h"
#include "Transaction.h"
using namespace std;

class Librarian {
public: 
    int librarianID;
    std::string name;
    
    std::vector<Book> bookCollection;
    std::vector<MemberRecord> memberRecords;
    std::vector<Transaction> transactions;
    
void addBook(Book book);
    
void editBook();
    
void removeBook();
    
void registerMember();
    
void editMember();
    
void removeMember();
    
void issueBook();
    
void returnBook();

void displayAllBooks();
};

#endif //_LIBRARIAN_H