#include "Article.h"

Article::Article(string id, string title, string author, int year)
    : Resource(id, title, author, year) {}

string Article::getType() const { return "Article"; }
string Article::serialize() const {
    return getType() + id + ": " + title + " by " + author + " (" + to_string(year) + ")" +
           (available ? " [Available]" : " [Unavailable]");
}
