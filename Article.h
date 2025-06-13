#pragma once

#include "Resource.h"

class Article : public Resource {
public:
    Article(string id, string title, string author, int year);

    string getType() const override;
    string serialize() const override;
};
