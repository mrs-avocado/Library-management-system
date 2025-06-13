#pragma once
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class User {
protected:
    string id, name;
    vector<string> borrowedIDs;

public:
    User(string id, string name);

    void borrowResource(string resourceId);
    void returnResource(string resourceId);

    string getID() const;
    string getName() const;
    const vector<string>& getBorrowed() const;
};
