#ifndef _TRANSACTION_H
#define _TRANSACTION_H

#include <string>
using namespace std;

class Transaction {
public: 
    int transactionID;
    std::string transactionDate;
    int bookID;
    int memberID;
    std::string dueDate;
    std::string status;
    
void markAsReturned();
    
void markAsOverdue();
};

#endif