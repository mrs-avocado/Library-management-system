#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct DaySchedule {
    string day;
    string open;
    string close;
};

class LibrarySchedule {
    DaySchedule schedule[7] = {
        {"Sunday",    "09:00", "16:00"},
        {"Monday",    "09:00", "16:00"},
        {"Tuesday",   "09:00", "16:00"},
        {"Wednesday", "09:00", "16:00"},
        {"Thursday",  "09:00", "16:00"},
        {"Friday",    "closed", "closed"},
        {"Saturday",  "10:00", "16:00"},

    };

public:
    void displayHours() const {
        cout << "Library Operating Hours:\n";
        for (int i = 0; i < 7; ++i) {
            cout << schedule[i].day << ": " << schedule[i].open;
            if (schedule[i].open != "Closed")
                cout << " - " << schedule[i].close;
            cout << '\n';
        }
    }
};

struct Event {
    string title;
    string date;
    string time;
    string location;
};

class EventManager {
    vector<Event> events;

public:
    void addEvent(const string& title, const string& date, const string& time, const string& location) {
        events.push_back({title, date, time, location});
    }

    void displayEvents() const {
        cout << "Upcoming Library Events:\n";
        for (const auto& e : events) {
            cout << e.date << " @ " << e.time << " – " << e.title << " (" << e.location << ")\n";
        }
    }
};
