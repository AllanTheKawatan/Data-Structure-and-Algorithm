#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <thread>
#include <chrono>
#include <algorithm>

using namespace std;

class Person {
public:
    string name;
    int ticket_number;

    Person(string name, int ticket_number) : name(name), ticket_number(ticket_number) {}
};

class Queue {
private:
    queue<Person> q;
    unordered_map<string, int> name_to_position;
    unordered_map<int, int> ticket_to_position;
    int ticket_counter = 1;

public:
    void Enqueue(const string& name) {
        Person person(name, ticket_counter);
        q.push(person);
        name_to_position[name] = q.size();
        ticket_to_position[ticket_counter] = q.size();
        cout << name << " added to the queue with Ticket #" << ticket_counter << endl;
        ticket_counter++;
    }

    void AutoDequeue() {
        if (!q.empty()) {
            cout << "After one minute...." << endl;
            Person person = q.front();
            q.pop();
            cout << "Dequeue: " << person.name << " received a ticket (Ticket #" << person.ticket_number << ")" << endl;
            name_to_position.erase(person.name);
            ticket_to_position.erase(person.ticket_number);
            UpdatePositions();
        }
    }

    bool IsEmpty() const {
        return q.empty();
    }

    int Size() const {
        return q.size();
    }

    void Peek() const {
        if (!q.empty()) {
            Person person = q.front();
            cout << "Next in line: " << person.name << " (Ticket #" << person.ticket_number << ")" << endl;
        } else {
            cout << "The queue is empty." << endl;
        }
    }

    int Position(const string& identifier) const {
        if (name_to_position.find(identifier) != name_to_position.end()) {
            return name_to_position.at(identifier);
        } else if (all_of(identifier.begin(), identifier.end(), ::isdigit)) {
            int ticket_number = stoi(identifier);
            if (ticket_to_position.find(ticket_number) != ticket_to_position.end()) {
                return ticket_to_position.at(ticket_number);
            }
        }
        return -1; // Not found
    }

private:
    void UpdatePositions() {
        queue<Person> temp = q;
        int position = 1;
        while (!temp.empty()) {
            Person person = temp.front();
            temp.pop();
            name_to_position[person.name] = position;
            ticket_to_position[person.ticket_number] = position;
            position++;
        }
    }
};

void AutoDequeueTask(Queue& queue) {
    while (true) {
        this_thread::sleep_for(chrono::minutes(1));
        queue.AutoDequeue();
    }
}

int main() {
    Queue queue;
    thread auto_dequeue_thread(AutoDequeueTask, ref(queue));
    auto_dequeue_thread.detach();

    cout << "Welcome to Olivia Rodrigo's Concert Ticketing System!" << endl;
    int option;
    while (true) {
        cout << "1. Enqueue a person" << endl;
        cout << "2. Check your position in the queue" << endl;
        cout << "3. Exit" << endl;
        cout << "Choose an option: ";
        cin >> option;

        if (option == 1) {
            string name;
            cout << "Enter the name: ";
            cin >> name;
            queue.Enqueue(name);
            cout << "Queue size: " << queue.Size() << endl;
        } else if (option == 2) {
            string identifier;
            cout << "Enter your name or ticket number: ";
            cin >> identifier;
            int position = queue.Position(identifier);
            if (position != -1) {
                cout << identifier << " is currently at position " << position << " in the queue." << endl;
            } else {
                cout << identifier << " not found in the queue." << endl;
            }
        } else if (option == 3) {
            break;
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }

    return 0;
}