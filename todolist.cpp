#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

// Structure to represent a task
struct Task {
    string description;
    bool completed;

    // Constructor to initialize a task
    Task(const string& desc) : description(desc), completed(false) {}
};

// Function to add a task to the list
void addTask(vector<Task>& taskList, const string& description) {
    taskList.push_back(Task(description));
    cout << "Task added: " << description << endl;
}

// Function to view tasks
void viewTasks(const vector<Task>& taskList) {
    if (taskList.empty()) {
        cout << "No tasks in the list." << endl;
    } else {
        cout << "Task List:" << endl;
        cout << setw(5) << "ID" << setw(20) << "Description" << setw(15) << "Status" << endl;
        cout << "----------------------------------------" << endl;
        for (size_t i = 0; i < taskList.size(); ++i) {
            cout << setw(5) << i + 1 << setw(20) << taskList[i].description << setw(15) << (taskList[i].completed ? "Completed" : "Pending") << endl;
        }
        cout << "----------------------------------------" << endl;
    }
}

// Function to mark a task as completed
void markCompleted(vector<Task>& taskList, size_t taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        taskList[taskIndex].completed = true;
        cout << "Task marked as completed: " << taskList[taskIndex].description << endl;
    } else {
        cout << "Invalid task ID." << endl;
    }
}

// Function to remove a task from the list
void removeTask(vector<Task>& taskList, size_t taskIndex) {
    if (taskIndex >= 0 && taskIndex < taskList.size()) {
        cout << "Task removed: " << taskList[taskIndex].description << endl;
        taskList.erase(taskList.begin() + taskIndex);
    } else {
        cout << "Invalid task ID." << endl;
    }
}

int main() {
    vector<Task> taskList;

    while (true) {
        cout << "\nTo-Do List Manager\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                {
                    string taskDescription;
                    cout << "Enter task description: ";
                    cin.ignore();  // Clear the newline character from the buffer
                    getline(cin, taskDescription);
                    addTask(taskList, taskDescription);
                }
                break;

            case 2:
                viewTasks(taskList);
                break;

            case 3:
                {
                    size_t taskIndex;
                    cout << "Enter the ID of the task to mark as completed: ";
                    cin >> taskIndex;
                    markCompleted(taskList, taskIndex - 1);
                }
                break;

            case 4:
                {
                    size_t taskIndex;
                    cout << "Enter the ID of the task to remove: ";
                    cin >> taskIndex;
                    removeTask(taskList, taskIndex - 1);
                }
                break;

            case 5:
                cout << "Exiting program. Goodbye!\n";
                return 0;

            default:
                cout << "Invalid choice. Please enter a valid option.\n";
        }
    }

    return 0;
}
