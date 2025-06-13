#include "ReservationManager.h"

void ReservationManager::addReservation(const string& resourceId, const string& userId) {
    reservations[resourceId].push(userId);
}

string ReservationManager::getNextUser(const string& resourceId) {
    if (!hasReservation(resourceId)) return "";
    string next = reservations[resourceId].front();
    reservations[resourceId].pop();
    return next;
}

bool ReservationManager::hasReservation(const string& resourceId) {
    return !reservations[resourceId].empty();
}

void ReservationManager::removeReservationsForResource(const string& resourceId) {
    reservations.erase(resourceId);
}

void ReservationManager::removeUserFromAllQueues(const string& userId) {
        for (auto& pair : reservations) {
            string resId = pair.first;
            queue<string>& Queue = pair.second;
            queue<string> newQueue;
            while (!Queue.empty()) {
                string uid = Queue.front();
                Queue.pop();
                if (uid != userId) {
                    newQueue.push(uid);
                }
            }
            Queue = newQueue;
    }
}
