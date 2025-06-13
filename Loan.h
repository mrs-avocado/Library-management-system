#pragma once
#include <string>
#include <ctime>
using namespace std;

struct Loan {
    string userId;
    string resourceId;
    time_t borrowDate;
    time_t dueDate;

    Loan(string user, string resource);

    string serialize() const;
};
