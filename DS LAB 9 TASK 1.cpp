#include <iostream>
#include <string>
using namespace std;

class Applicant {
public:
    int applicant_id;
    float height;
    float weight;
    string eyesightVision;
    string testStatus;

    Applicant() {
        applicant_id = 0;
        height = 0;
        weight = 0;
        eyesightVision = "";
        testStatus = "Waiting";
    }

    Applicant(int id, float h, float w, string vision, string status) {
        applicant_id = id;
        height = h;
        weight = w;
        eyesightVision = vision;
        testStatus = status;
    }
};

class Node {
public:
    Applicant data;
    Node* next;
    Node* prev;

    Node(Applicant a) {
        data = a;
        next = NULL;
        prev = NULL;
    }
};

class ApplicantQueue {
private:
    Node* front;
    Node* rear;

public:
    ApplicantQueue() {
        front = rear = NULL;
    }

    // Check if queue is empty
    bool isEmpty() {
        return front == NULL;
    }

    // Insert applicant at end
    void enqueue(Applicant a) {
        Node* newNode = new Node(a);

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }

        cout << "Applicant ID " << a.applicant_id << " added to the line.\n";
    }

    // Remove applicant from front
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. No applicant to remove.\n";
            return;
        }

        Node* temp = front;
        cout << "Applicant ID " << front->data.applicant_id << " has given the test and left the line.\n";

        front = front->next;

        if (front != NULL)
            front->prev = NULL;
        else
            rear = NULL;

        delete temp;
    }

    // Remove 2nd applicant due to urgency
    void removeSecondApplicant() {
        if (isEmpty() || front->next == NULL) {
            cout << "Less than 2 applicants in line. Cannot remove second applicant.\n";
            return;
        }

        Node* temp = front->next; // second node
        cout << "Applicant ID " << temp->data.applicant_id << " left the line due to urgency.\n";

        front->next = temp->next;

        if (temp->next != NULL)
            temp->next->prev = front;
        else
            rear = front; // if second was rear

        delete temp;
    }

    // Display all applicants in queue
    void displayQueue() {
        if (isEmpty()) {
            cout << "\nQueue is empty.\n";
            return;
        }

        Node* temp = front;
        cout << "\n===== Applicants Waiting Line =====\n";
        while (temp != NULL) {
            cout << "Applicant ID: " << temp->data.applicant_id << endl;
            cout << "Height: " << temp->data.height << " ft" << endl;
            cout << "Weight: " << temp->data.weight << " kg" << endl;
            cout << "Eyesight Vision: " << temp->data.eyesightVision << endl;
            cout << "Test Status: " << temp->data.testStatus << endl;
            cout << "-----------------------------------\n";
            temp = temp->next;
        }
    }

    // Update test status of front applicant
    void markFrontApplicantTested() {
        if (isEmpty()) {
            cout << "Queue is empty.\n";
            return;
        }
        front->data.testStatus = "Completed";
        cout << "Applicant ID " << front->data.applicant_id << " status updated to Completed.\n";
    }
};

int main() {
    ApplicantQueue q;

    // Initially 7 applicants
    q.enqueue(Applicant(101, 5.8, 68, "-0.5", "Waiting"));
    q.enqueue(Applicant(102, 5.6, 62, "0.0", "Waiting"));
    q.enqueue(Applicant(103, 5.9, 75, "-1.0", "Waiting"));
    q.enqueue(Applicant(104, 5.7, 70, "0.0", "Waiting"));
    q.enqueue(Applicant(105, 6.0, 80, "-0.25", "Waiting"));
    q.enqueue(Applicant(106, 5.5, 58, "0.0", "Waiting"));
    q.enqueue(Applicant(107, 5.10, 77, "-0.75", "Waiting"));

    cout << "\nInitial Queue:\n";
    q.displayQueue();

    // New applicant enters at end
    cout << "\n--- New Applicant Arrives ---\n";
    q.enqueue(Applicant(108, 5.11, 72, "0.0", "Waiting"));
    q.displayQueue();

    // Front applicant gives test and leaves
    cout << "\n--- Front Applicant Gives Test ---\n";
    q.markFrontApplicantTested();
    q.dequeue();
    q.displayQueue();

    // 2nd applicant leaves due to urgency
    cout << "\n--- Second Applicant Leaves Due to Urgency ---\n";
    q.removeSecondApplicant();
    q.displayQueue();

    return 0;
}