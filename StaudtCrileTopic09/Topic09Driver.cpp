// Crile Staudt
// November 19, 2023
// CIS 2207 101
// This program is a priority TO-DO list.

#include "HeapPriorityQueue.h"
#include<iostream>
#include<string>

using namespace std;


int main() {
    
    string task = "";
    int prior = 0;
    HeapPriorityQueue<toDo> toDoHeapQueue;

    int userChoice = -1;

    while (userChoice != 4) {

        cout << "\n----------------Please select a choice----------------"
            << "\n1.) Add task"
            << "\n2.) Remove task"
            << "\n3.) Print tasks"
            << "\n4.) Exit"
            << "\n\nChoice : ";
        cin >> userChoice;

        switch (userChoice) {

        case 1: {

            cin.ignore();
            cout << "\nTask: ";
            getline(cin, task);
            cout << "\nPriority: ";
            cin >> prior;
            cin.ignore(); //

            toDo toDoObj = { task, prior };
            toDoHeapQueue.enqueue(toDoObj);

        }
              break;

        case 2: {

            if (toDoHeapQueue.dequeue())
                cout << "\nTask removed!";
            else
                cout << "\nFailed to remove task";


        }
              break;

        case 3: {

            toDoHeapQueue.traverse();

        }
              break;

        default: {



        }
               break;
        }
    }


    system("pause");
    return 0;


}