#include "Book.h"

Book::Book(string id, string title, string author, int year)
    : Resource(id, title, author, year) {}

string Book::getType() const { return "Book"; }
string Book::serialize() const {
    return getType() + id + ": " + title + " by " + author + " (" + to_string(year) + ")" +
           (available ? " [Available]" : " [Unavailable]");
}
