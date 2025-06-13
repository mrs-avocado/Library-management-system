#include "DigitalResource.h"

DigitalResource::DigitalResource(string id, string title, string author, int year) : Resource(id, title, author, year) {}

string DigitalResource::getType() const { return "DigitalResource"; }
string DigitalResource::serialize() const {
    return getType() + id + ": " + title + " by " + author + " (" + to_string(year) + ")" +
           (available ? " [Available]" : " [Unavailable]");
}
