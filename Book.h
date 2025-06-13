#pragma once
#include "Resource.h"

class Book : public Resource {
public:
    Book(string id, string title, string author, int year);

    string getType() const override;
    string serialize() const override;
};
