#pragma once
#include <string>
using namespace std;

class Resource {
protected:
    string id, title, author;
    int year;
    bool available;

public:
    Resource(string id, string title, string author, int year);
    virtual ~Resource() = default;

    virtual string getType() const = 0;
    virtual string serialize() const = 0;

    string getID() const;
    bool isAvailable() const;
    void setAvailability(bool state);
};
