#include <iostream>
#include <cstdlib>
using namespace std;

const int TOTAL = 30;

struct Passenger {
    int seatNo;
    char name[50];
    int age;
    char gender[10];
    Passenger* next;
};

int* seats = NULL;
Passenger* start = NULL;

// Function to book ticket
void bookTicket() {
    int i;

    for (i = 0; i < TOTAL; i++) {
        if (seats[i] == 0) {
            break;
        }
    }

    if (i == TOTAL) {
        cout << "No seats available!\n";
        return;
    }

    Passenger* p = (Passenger*)malloc(sizeof(Passenger));

    if (p == NULL) {
        cout << "Memory allocation failed!\n";
        return;
    }

    p->seatNo = i + 1;

    cout << "Enter name: ";
    cin >> p->name;

    cout << "Enter age: ";
    cin >> p->age;

    cout << "Enter gender: ";
    cin >> p->gender;

    p->next = start;
    start = p;

    seats[i] = 1;

    cout << "Ticket booked! Seat No: "
         << i + 1 << "\n";
}

// Function to cancel ticket
void cancelTicket() {
    int seat;

    cout << "Enter seat number to cancel: ";
    cin >> seat;

    if (seat < 1 || seat > TOTAL) {
        cout << "Invalid seat number!\n";
        return;
    }

    Passenger* current = start;
    Passenger* previous = NULL;

    while (current != NULL) {
        if (current->seatNo == seat) {
            if (previous == NULL) {
                start = current->next;
            }
            else {
                previous->next = current->next;
            }

            seats[seat - 1] = 0;
            free(current);

            cout << "Ticket cancelled!\n";
            return;
        }

        previous = current;
        current = current->next;
    }

    cout << "Booking not found!\n";
}

// Function to view train status
void trainStatus() {
    for (int i = 0; i < TOTAL; i++) {
        cout << "Seat " << i + 1 << ": ";

        if (seats[i] == 1) {
            cout << "Booked\n";
        }
        else {
            cout << "Available\n";
        }
    }
}

// Function to view passenger list
void passengerList() {
    Passenger* current = start;

    if (start == NULL) {
        cout << "No passengers booked!\n";
        return;
    }

    while (current != NULL) {
        cout << "Seat No: " << current->seatNo
             << " | Name: " << current->name
             << " | Age: " << current->age
             << " | Gender: " << current->gender
             << "\n";

        current = current->next;
    }
}

// Function to free all passenger nodes
void freePassengers() {
    Passenger* current = start;

    while (current != NULL) {
        Passenger* nextNode = current->next;

        free(current);

        current = nextNode;
    }

    start = NULL;
}

// Main function
int main() {
    int choice = 0;
    int n;

    // Dynamically allocate the seat array
    seats = (int*)malloc(TOTAL * sizeof(int));

    if (seats == NULL) {
        cout << "Memory allocation failed!\n";
        return 1;
    }

    // Initially all seats are available
    for (int i = 0; i < TOTAL; i++) {
        seats[i] = 0;
    }

    while (choice != 5) {
        cout << "\n--- Railway Reservation System ---\n";
        cout << "1. Book N Passengers\n";
        cout << "2. Cancel Ticket\n";
        cout << "3. View Train Status\n";
        cout << "4. View Passenger List\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        if (choice == 1) {
            cout << "Enter number of passengers: ";
            cin >> n;

            if (n < 1 || n > TOTAL) {
                cout << "Enter a number between 1 and 30.\n";
            }
            else {
                for (int i = 0; i < n; i++) {
                    cout << "\nPassenger " << i + 1 << "\n";
                    bookTicket();
                }
            }
        }
        else if (choice == 2) {
            cancelTicket();
        }
        else if (choice == 3) {
            trainStatus();
        }
        else if (choice == 4) {
            passengerList();
        }
        else if (choice == 5) {
            freePassengers();
            free(seats);
            seats = NULL;

            cout << "Program ended!\n";
        }
        else {
            cout << "Invalid choice!\n";
        }
    }

    return 0;
}