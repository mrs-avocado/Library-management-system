#pragma once
#include "Resource.h"

class Thesis : public Resource {
public:
    Thesis(string id, string title, string author, int year);

    string getType() const override;
    string serialize() const override;
};
