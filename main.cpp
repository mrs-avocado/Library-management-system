
#include "Book.h"
#include "LibraryManager.h"
#include "User.h"
#include <iostream>

using namespace std;

int main() {
  LibraryManager lib;
  lib.addResource(new Book("B001", "1984", "George Orwell", 1949));
  lib.addResource(new Book("B002", "Brave New World", "Aldous Huxley", 1932));

  lib.addUser(new User("U001", "Alice"));
  lib.addUser(new User("U002", "Bob"));

  lib.borrowResource("U001", "B001");
  lib.borrowResource("U002", "B001");
  lib.returnResource("U001", "B001");

  lib.listResources();
  lib.listUsers();

  lib.removeUser("U002");
  lib.removeResource("B002");

  return 0;
}
