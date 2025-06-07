/**
 * Project Untitled
 */


#include "MemberRecord.h"
#include <iostream>

/**
 * MemberRecord implementation
 */


void MemberRecord::displayMemberDetails() {
    std::cout << "Member ID: " << memberID << std::endl;
    std::cout << "Name: " << name << std::endl;
    std::cout << "Address: " << address << std::endl;

    std::cout << "Borrowed Book IDs: ";
    if (borrowedBooks.empty()) {
        std::cout << "None";
    } else {
        for (int id : borrowedBooks) {
            std::cout << id << " ";
        }
    }
    std::cout << std::endl;
}