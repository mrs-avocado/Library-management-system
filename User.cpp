#include "User.h"

User::User(string id, string name) : id(id), name(name) {}

void User::borrowResource(string resourceId) {
    borrowedIDs.push_back(resourceId);
}

void User::returnResource(string resourceId) {
    borrowedIDs.erase(remove(borrowedIDs.begin(), borrowedIDs.end(), resourceId), borrowedIDs.end());
}

string User::getID() const { return id; }
string User::getName() const { return name; }
const vector<string>& User::getBorrowed() const { return borrowedIDs; }
