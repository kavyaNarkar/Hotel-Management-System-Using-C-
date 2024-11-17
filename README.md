# Hotel Management System Using C++

This is a simple hotel management system implemented in C++. It allows hotel staff to manage room reservations, view room status, cancel reservations, and track the availability of rooms. The system provides a text-based menu interface for easy interaction.

## Features

- Room Reservation**: Allows users to reserve an available room by providing a guest's name.
- Cancel Reservation**: Allows users to cancel an existing reservation.
- View Available Rooms**: Displays the number of available rooms.
- Room Status Display**: Displays the current status of all rooms (whether reserved or available).
- File Logging**: Saves reservations to a text file (`hotel_reservations.txt`) and room statuses to separate files (`hotel_display_<count>.txt`).

## Prerequisites

To run the project, you need a C++ compiler like GCC or MinGW.

- Operating System**: Windows, Linux, macOS
- Compiler: GCC, MinGW, or any C++ compiler supporting C++11 or later.

## Installation

1. Clone the repository to your local machine:
    ```bash
    git clone https://github.com/yourusername/Hotel-Management-System-Using-C-.git
    ```

2. Navigate to the project folder:
    ```bash
    cd Hotel-Management-System-Using-C-
    ```

3. Compile the code using your C++ compiler:
    ```bash
    g++ -o hotel_management main.cpp
    ```

4. Run the executable:
    ```bash
    ./hotel_management
    ```

## Usage

After running the program, you will be presented with a menu with the following options:

1. Make a Reservation: Reserve an available room by providing a guest's name.
2. Cancel a Reservation: Cancel an existing reservation by entering the room number.
3. Check Number of Empty Rooms: View the number of available rooms.
4. Display All Room Status: View the status of all rooms (whether reserved or available).
5. Exit: Exit the application.

### Example Workflow:

1. Select option 1 to make a reservation.
2. Enter the guest's name.
3. If rooms are available, the reservation will be made, and the room number will be assigned.
4. Select option 4 to view the current status of all rooms.
5. Select option 2 to cancel a reservation by entering the room number.

## File Structure

- `hotel_reservations.txt`: Contains the list of all reservations made (room number and guest name).
- `hotel_display_<count>.txt`: Contains the status of all rooms (room number, guest name, and availability).

## License

This project is licensed under the MIT License. See the `LICENSE` file for more details.

## Contributing

If you would like to contribute to this project, follow these steps:

1. Fork the repository.
2. Create a new branch (`git checkout -b feature-branch`).
3. Make your changes.
4. Commit your changes (`git commit -am 'Add feature'`).
5. Push to the branch (`git push origin feature-branch`).
6. Create a pull request.

## Acknowledgments

- Thanks to C++ for providing the tools to create this simple and effective hotel management system.
- This project is a great learning opportunity for beginners to practice file handling and dynamic memory management in C++.

