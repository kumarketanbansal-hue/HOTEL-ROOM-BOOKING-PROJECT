# 🏨 Hotel Room Booking System (Akka Hotels)

A C++ Console Application built for a **Semester 2 Object-Oriented Programming (OOPs)** course project. This program handles customer registrations, room allocation based on user preferences, time calculations, billing with dynamic hourly/daily rates, and real-time room status updating.

---

## 🚀 Key Features

* **Interactive Booking System:** Allows guests to choose bedding preferences (Single, Twin, Double) and comfort options (Standard, AC, Deluxe).
* **Automatic Room Assignment:** Uses 2D static tracking arrays to assign unique room numbers (e.g., `111`, `212`, `331`) and track availability.
* **Flexible Rental Calculation:** Calculates total fees based on full-day rentals vs. hourly charges depending on Check-In (> 08:00) and Check-Out (< 20:00) times.
* **Receipt Generation:** Automatically computes 10% tax and displays an itemized bill detailing daily fees, hourly fees, and final totals.
* **Friend Function Integration:** Features a `room_status()` friend function to dynamically evaluate and clear occupied rooms based on current dates and times.

---

## 🛠️ OOPs Concepts Applied

* **Inheritance Hierarchy:** Multi-level inheritance structure:
  `Customer` (Base Class) $\rightarrow$ `Book` (Derived Class) $\rightarrow$ `Calculate` (Derived Class).
* **Friend Functions:** Used `friend void room_status(Book b)` to access protected/private members of the `Book` class for external status validation.
* **Static Class Members:** Shared 2D static arrays (`single_[2][5]`, `twin_[2][5]`, `double_[3][5]`) to maintain global room occupancy states across instances.
* **Pointers & Memory:** Pointers (`int* room_no`) used to bind and modify specific matrix elements directly.
* **Encapsulation & Access Modifiers:** Member variables protected/privatized to restrict unauthorized global modifications.
* **Function Overriding / Hiding:** Explicit scope resolution (`c1.Book::time()`) used to manage specialized member functions across inherited levels.
