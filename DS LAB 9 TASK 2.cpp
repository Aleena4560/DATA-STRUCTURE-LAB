#include <iostream>
#include <string>
using namespace std;

// ================= NODE CLASS =================
class Node {
public:
    int truck_id;
    Node* next;

    Node(int id) {
        truck_id = id;
        next = NULL;
    }
};

// ================= ROAD QUEUE =================
class RoadQueue {
private:
    Node* front;
    Node* rear;

public:
    RoadQueue() {
        front = rear = NULL;
    }

    bool isEmpty() {
        return front == NULL;
    }

    void enqueue(int id) {
        Node* newNode = new Node(id);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }

        Node* temp = front;
        int id = temp->truck_id;
        front = front->next;

        if (front == NULL)
            rear = NULL;

        delete temp;
        return id;
    }

    int peek() {
        if (isEmpty())
            return -1;
        return front->truck_id;
    }

    void showRoad() {
        if (isEmpty()) {
            cout << "Road Vehicle: Empty" << endl;
            return;
        }

        cout << "Road Vehicle: ";
        Node* temp = front;
        while (temp != NULL) {
            cout << temp->truck_id;
            if (temp->next != NULL)
                cout << "_";
            temp = temp->next;
        }
        cout << endl;
    }
};

// ================= GARAGE STACK =================
class GarageStack {
private:
    Node* top;

public:
    GarageStack() {
        top = NULL;
    }

    bool isEmpty() {
        return top == NULL;
    }

    void push(int id) {
        Node* newNode = new Node(id);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            return -1;
        }

        Node* temp = top;
        int id = temp->truck_id;
        top = top->next;
        delete temp;
        return id;
    }

    int peek() {
        if (isEmpty())
            return -1;
        return top->truck_id;
    }

    void showGarage() {
        if (isEmpty()) {
            cout << "Garage Vehicle: Empty" << endl;
            return;
        }

        int arr[100];
        int i = 0;
        Node* temp = top;

        while (temp != NULL) {
            arr[i++] = temp->truck_id;
            temp = temp->next;
        }

        cout << "Garage Vehicle: ";
        for (int j = i - 1; j >= 0; j--) {
            cout << arr[j];
            if (j != 0)
                cout << "_";
        }
        cout << endl;
    }
};

// ================= TRUCK SYSTEM =================
class TruckSystem {
private:
    RoadQueue road;
    GarageStack garage;

public:
    void On_road(int truck_id) {
        road.enqueue(truck_id);
    }

    void Enter_garage(int truck_id) {
        if (road.isEmpty()) {
            cout << "Error: Road is empty." << endl;
            return;
        }

        if (road.peek() != truck_id) {
            cout << "Error: " << truck_id << " No. Vehicle cannot enter into garage." << endl;
            return;
        }

        road.dequeue();
        garage.push(truck_id);
    }

    void Exit_garage(int truck_id) {
        if (garage.isEmpty()) {
            cout << "Error: Garage is empty." << endl;
            return;
        }

        if (garage.peek() != truck_id) {
            cout << "Error: Truck is not near garage door." << endl;
            return;
        }

        garage.pop();
        cout << truck_id << " No. vehicle leaving garage" << endl;
    }

    void Show_trucks(string place) {
        if (place == "road") {
            road.showRoad();
        } else if (place == "garage") {
            garage.showGarage();
        } else {
            cout << "Invalid option!" << endl;
        }
    }
};

// ================= MAIN FUNCTION =================
int main() {
    TruckSystem t;

    // Sample Input
    t.On_road(2);
    t.On_road(5);
    t.On_road(10);
    t.On_road(9);
    t.On_road(22);

    t.Show_trucks("road");
    t.Show_trucks("garage");

    t.Enter_garage(2);

    t.Show_trucks("road");
    t.Show_trucks("garage");

    t.Enter_garage(10);
    t.Enter_garage(5);

    t.Exit_garage(2);
    t.Exit_garage(5);

    t.Show_trucks("garage");

    return 0;
}