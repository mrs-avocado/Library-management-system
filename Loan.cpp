#include "Loan.h"

Loan::Loan(string user, string resource) : userId(user), resourceId(resource) {
    borrowDate = time(nullptr);
    dueDate = borrowDate + 15 * 24 * 3600;
}

string Loan::serialize() const {
    return userId + "," + resourceId + "," + to_string(borrowDate);
}
