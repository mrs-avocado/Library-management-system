#pragma once
#include "Resource.h"

class DigitalResource : public Resource {
public:
    DigitalResource(string id, string title, string author, int year);

    string getType() const override;
    string serialize() const override;
};
