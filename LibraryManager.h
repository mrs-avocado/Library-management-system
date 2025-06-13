#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include "Resource.h"
#include "User.h"
#include "Loan.h"
#include "ReservationManager.h"
using namespace std;

class LibraryManager {
    unordered_map<string, Resource*> resources;
    unordered_map<string, User*> users;
    vector<Loan> loans;
    ReservationManager reservationManager;

public:
    ~LibraryManager();

    void addResource(Resource* resource);
    void addUser(User* user);

    bool borrowResource(const string& userId, const string& resourceId);
    bool returnResource(const string& userId, const string& resourceId);
    void reserveResource(const string& userId, const string& resourceId);

    void listResources() const;
    void listUsers() const;

    void removeUser(const string& userId);
    void removeResource(const string& resourceId);
};
