#include "Thesis.h"

Thesis::Thesis(string id, string title, string author, int year)
    : Resource(id, title, author, year) {}

string Thesis::getType() const { return "Thesis"; }
string Thesis::serialize() const {
    return getType() + id + ": " + title + " by " + author + " (" + to_string(year) + ")" +
           (available ? " [Available]" : " [Unavailable]");
}
