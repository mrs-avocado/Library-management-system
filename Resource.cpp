#include "Resource.h"

Resource::Resource(string id, string title, string author, int year): id(id), title(title), author(author), year(year), available(true) {}

string Resource::getID() const { return id; }
bool Resource::isAvailable() const { return available; }
void Resource::setAvailability(bool state) { available = state; }
