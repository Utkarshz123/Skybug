#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class ToDoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask{description, false};
        tasks.push_back(newTask);
        cout << "Task added: " << description << endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            cout << "No tasks available." << endl;
        } else {
            cout << setw(5) << "ID" << setw(25) << "Description" << setw(12) << "Status" << endl;
            cout << string(45, '-') << endl;
            for (size_t i = 0; i < tasks.size(); ++i) {
                cout << setw(5) << i + 1 << setw(25) << tasks[i].description << setw(12)
                     << (tasks[i].completed ? "Completed" : "Pending") << endl;
            }
        }
    }

    void markTaskAsCompleted(size_t taskId) {
        if (taskId >= 1 && taskId <= tasks.size()) {
            tasks[taskId - 1].completed = true;
            cout << "Task marked as completed: " << tasks[taskId - 1].description << endl;
        } else {
            cout << "Invalid task ID. Please enter a valid ID." << endl;
        }
    }

    void removeTask(size_t taskId) {
        if (taskId >= 1 && taskId <= tasks.size()) {
            cout << "Task removed: " << tasks[taskId - 1].description << endl;
            tasks.erase(tasks.begin() + taskId - 1);
        } else {
            cout << "Invalid task ID. Please enter a valid ID." << endl;
        }
    }
};

int main() {
    ToDoList toDoList;

    while (true) {
        cout << "========== To-Do List Manager ==========" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice (1-5): ";

        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Enter the task description: ";
                cin.ignore();
                string description;
                getline(cin, description);
                toDoList.addTask(description);
                break;
            }
            case 2:
                toDoList.viewTasks();
                break;
            case 3: {
                cout << "Enter the task ID to mark as completed: ";
                size_t taskId;
                cin >> taskId;
                toDoList.markTaskAsCompleted(taskId);
                break;
            }
            case 4: {
                cout << "Enter the task ID to remove: ";
                size_t taskId;
                cin >> taskId;
                toDoList.removeTask(taskId);
                break;
            }
            case 5:
                cout << "Exiting the program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please enter a valid option (1-5)." << endl;
        }
    }

    return 0;
}
