/**
 * Project Untitled
 */


#ifndef _MEMBERRECORD_H
#define _MEMBERRECORD_H

#include <string>
#include <vector>

class MemberRecord {
public: 
    int memberID;
    std::string name;
    std::string address;
    std::vector<int> borrowedBooks;
    
void displayMemberDetails();
};

#endif //_MEMBERRECORD_H