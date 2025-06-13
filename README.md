 C++-based Object-Oriented Programming project designed to simulate the core operations of a library system. Developed as part of an academic project for the OOP module in the first year at ENSIA.

✨ Key Functionalities
Perform operations such as adding, removing, and displaying:

Books

Academic Articles

Theses

Digital Media

Register and manage library users

Enable borrowing and returning of library materials

Implement a queue-based reservation mechanism

Leverages class-based design and dynamic memory allocation

## 🏗️ Project Structure



/LibraryManagementSystem
│
├── main.cpp
├── Resource.h / Resource.cpp
├── Book.h / Book.cpp
├── Article.h / Article.cpp
├── Thesis.h / Thesis.cpp
├── DigitalResource.h / DigitalResource.cpp
├── User.h / User.cpp
├── Loan.h / Loan.cpp
├── ReservationManager.h / ReservationManager.cpp
├── LibraryManager.h / LibraryManager.cpp
├── README.md



## 🧠 OOP Concepts Used

- **Inheritance**: `Book`, `Thesis`, `Article`, and `DigitalResource` inherit from `Resource`.
- **Polymorphism**: Abstract class `Resource` defines pure virtual functions like `serialize()` and `getType()`.
- **Composition**: `LibraryManager` contains and manages users, resources, loans, and reservations.
- **Encapsulation**: All class members are protected/private with public accessors and mutators.

## 🛠️ How to Run

### Compile:
g++ main.cpp Resource.cpp Book.cpp Article.cpp Thesis.cpp DigitalResource.cpp User.cpp Loan.cpp ReservationManager.cpp LibraryManager.cpp -o library


### Run:
./library

🔧 Prerequisites
C++ compiler (C++11 standard or newer)

Terminal or command-line interface

(Optional) Development environment like Replit or Visual Studio Code

## 📌 Notes

* This project is educational and does not include file persistence (saving to disk).
* The `Loan` and `ReservationManager` classes operate with in-memory data.

## 📄 License
Licensed under the MIT License. Feel free to use, adapt, or extend it for learning purposes.



