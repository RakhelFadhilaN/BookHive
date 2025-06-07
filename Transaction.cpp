#include "Transaction.h"

/**
 * Transaction implementation
 */


void Transaction::markAsReturned() {
    status = "Returned";
}

void Transaction::markAsOverdue() {
    status = "Overdue";
}