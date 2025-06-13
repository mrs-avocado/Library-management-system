#pragma once
#include <string>
#include <unordered_map>
#include <queue>
using namespace std;

class ReservationManager {
    unordered_map<string, queue<string>> reservations;

public:
    void addReservation(const string& resourceId, const string& userId);
    string getNextUser(const string& resourceId);
    bool hasReservation(const string& resourceId);
    void removeReservationsForResource(const string& resourceId);
    void removeUserFromAllQueues(const string& userId);
};
