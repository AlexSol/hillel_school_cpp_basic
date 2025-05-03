#include "MenuCLI.hpp"

#include <iostream>
#include "Task.hpp"
#include <limits>
#include <iomanip>

#include "TaskManager.hpp"

void addTask()
{
    std::string titleTask;
    int completedOpt = -1;
    
    std::cout << "Введіть назву завдання: ";
    std::cin >> std::ws; // очищаємо пробіли перед введенням
    std::getline(std::cin, titleTask);
    
    while (true)
    {
        std::cout << "Введіть статус завдання (0 - не виконано, 1 - виконано): ";
        std::cin >> completedOpt;

        if (std::cin.fail() || (completedOpt != 0 && completedOpt != 1))
        {
            std::cin.clear(); // скидає помилковий стан
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // очищає буфер
            std::cout << "Некоректне введення. Введіть 0 або 1.\n";
        }
        else
        {
            break;
        }
    }

    const bool completed = completedOpt == '1';

    TaskManager::getInstance().addTask(titleTask, completed);
}

void listTasks()
{
    const std::vector<Task>& tasks = TaskManager::getInstance().listTasks();
    if(tasks.empty())
    {
        std::cout << "Завдань немає." << std::endl;
        return;
    }

    const int completedCount = std::count_if(tasks.begin(), tasks.end(), [](const Task& task) {
        return task.completed;
    });
    
    const int noCompletedCount = tasks.size() - completedCount;
    
    std::cout<< "Кількість завдань: " << tasks.size() << std::endl;
    std::cout<< "Кількість виконаних завдань: " << completedCount << std::endl;
    std::cout<< "Кількість невиконаних завдань: " << noCompletedCount << std::endl;
    std::cout << "Список завдань:" << std::endl;

    std::cout << "-------------------------" << std::endl;
    std::cout << "| ID | Завершено | Назва" << std::endl;
    std::cout << "-------------------------" << std::endl;

    const int widthColumnID = 5;
    const int widthColumnCompleted = 11;

    for (const Task& task : tasks)
    {
        std::cout << std::left 
        << std::setw(widthColumnID) <<  task.id 
        << " "
        << std::setw(widthColumnCompleted) << (task.completed ? "[+]" : "[-]") 
        << " " << task.title << std::endl;
    }
}

void completeTask() {
    // TODO: реалізувати завершення завдання
}

void deleteTask()
{
    // TODO: реалізувати видалення завдання
}

void exitApp()
{
    std::cout << "Програма завершує свою роботу." << std::endl;
    std::exit(0);
}

int main()
{
    MenuCLI menu;
    menu.addHandlerMenuOption("Вийти", exitApp, false);

    menu.addHandlerMenuOption("Додати завдання", addTask);
    menu.addHandlerMenuOption("Показати всі завдання", listTasks);
    menu.addHandlerMenuOption("Завершити завдання", completeTask);
    menu.addHandlerMenuOption("Видалити завдання", deleteTask);

    menu.show();

    return 0;
}