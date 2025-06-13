# 📚 Library Management System

The Object-Oriented C++ project for managing library resources, users, loans, and reservations.
Ensia 1st year , module OOP

## 🚀 Features

- Add, remove, and list:
  - Books
  - Articles
  - Theses
  - Digital Resources
- Manage users and their borrowed items
- Borrow and return resources
- Handle resource reservations via a queue system
- Store all data using class structures and dynamic memory

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

# ✅ Requirements

* C++11 or later
* A terminal / shell
* (Optional) IDE like VS Code or Replit

## 📌 Notes

* This project is educational and does not include file persistence (saving to disk).
* The `Loan` and `ReservationManager` classes operate with in-memory data.

## 📄 License
MIT License — use it freely for learning or improvement.

