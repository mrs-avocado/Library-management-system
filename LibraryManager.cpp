#include "LibraryManager.h"
#include <iostream>
#include <algorithm>
using namespace std;

LibraryManager::~LibraryManager() {
    for (auto& pair : resources) delete pair.second;
    for (auto& pair : users) delete pair.second;
}

void LibraryManager::addResource(Resource* resource) {
    resources[resource->getID()] = resource;
}

void LibraryManager::addUser(User* user) {
    users[user->getID()] = user;
}

bool LibraryManager::borrowResource(const string& userId, const string& resourceId) {
    if (!resources.count(resourceId))
        throw invalid_argument("Resource ID '" + resourceId + "' does not exist.");
    if (!users.count(userId))
        throw invalid_argument("User ID '" + userId + "' does not exist.");

    Resource* res = resources[resourceId];
    if (res->isAvailable()) {
        res->setAvailability(false);
        users[userId]->borrowResource(resourceId);
        loans.push_back(Loan(userId, resourceId));
        return true;
    } else {
        reservationManager.addReservation(resourceId, userId);
        return false;
    }
}

bool LibraryManager::returnResource(const string& userId, const string& resourceId) {
    if (!resources.count(resourceId))
        throw invalid_argument("Resource ID '" + resourceId + "' does not exist.");
    if (!users.count(userId))
        throw invalid_argument("User ID '" + userId + "' does not exist.");

    Resource* res = resources[resourceId];
    if (!res->isAvailable()) {
        res->setAvailability(true);
        users[userId]->returnResource(resourceId);

        if (reservationManager.hasReservation(resourceId)) {
            string nextUser = reservationManager.getNextUser(resourceId);
            borrowResource(nextUser, resourceId);
        } else {
            for (auto it = loans.begin(); it != loans.end(); ++it) {
                if (it->userId == userId && it->resourceId == resourceId) {
                    loans.erase(it);
                    break;
                }
            }
        }
        return true;
    }

    return false;
}

void LibraryManager::reserveResource(const string& userId, const string& resourceId) {
    if (resources.count(resourceId) && users.count(userId)) {
        reservationManager.addReservation(resourceId, userId);
    }
}

void LibraryManager::listResources() const {
    for (const auto& pair : resources) {
        cout << pair.second->serialize() << endl;
    }
}

void LibraryManager::listUsers() const {
    for (const auto& pair : users) {
        cout << "User " << pair.second->getName() << " (ID: " << pair.first << ")\n";
    }
}

void LibraryManager::removeUser(const string& userId) {
    if (!users.count(userId)) {
        cout << "User " << userId << " not found.\n";
        return;
    }

    for (const string& resId : users[userId]->getBorrowed()) {
        if (resources.count(resId)) {
            resources[resId]->setAvailability(true);
        }
    }

    loans.erase(
        remove_if(loans.begin(), loans.end(),
            [&userId](const Loan& loan) {
                return loan.userId == userId;
            }),
        loans.end()
    );

    reservationManager.removeUserFromAllQueues(userId);

    delete users[userId];
    users.erase(userId);

    cout << "User " << userId << " and all their records removed.\n";
}

void LibraryManager::removeResource(const string& resourceId) {
    if (!resources.count(resourceId)) {
        throw invalid_argument(
            "Resource ID  " + resourceId + " does not exist " );
        
        return;
    }

    loans.erase(remove_if(loans.begin(), loans.end(),
                         [&resourceId](const Loan& loan) {
                             return loan.resourceId == resourceId;
                         }),
                loans.end());

    for (auto& [uid, user] : users) {
        user->returnResource(resourceId);
    }

    reservationManager.removeReservationsForResource(resourceId);

    delete resources[resourceId];
    resources.erase(resourceId);

    cout << "Resource " << resourceId << " and related data removed.\n";
}
