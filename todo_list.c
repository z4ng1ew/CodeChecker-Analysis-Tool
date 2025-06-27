#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TASKS 100
#define MAX_LENGTH 100

typedef struct {
    int id;
    char description[MAX_LENGTH];
    int completed;
} Task;

Task taskList[MAX_TASKS];
int taskCount = 0;
int nextId = 1;

void printMenu() {
    printf("\n==== TODO Меню ====\n");
    printf("1. Добавить задачу\n");
    printf("2. Показать задачи\n");
    printf("3. Завершить задачу\n");
    printf("4. Удалить задачу\n");
    printf("5. Выйти\n");
    printf("Выберите действие: ");
}

void addTask() {
    if (taskCount >= MAX_TASKS) {
        printf("⚠️  Превышено максимальное количество задач.\n");
        return;
    }

    char desc[MAX_LENGTH];
    printf("Введите описание задачи: ");
    getchar(); // очистка буфера после scanf
    fgets(desc, MAX_LENGTH, stdin);

    // Удалим символ новой строки
    desc[strcspn(desc, "\n")] = '\0';

    Task t;
    t.id = nextId++;
    strncpy(t.description, desc, MAX_LENGTH);
    t.completed = 0;

    taskList[taskCount++] = t;
    printf("✅ Задача добавлена.\n");
}

void listTasks() {
    if (taskCount == 0) {
        printf("📝 Задач пока нет.\n");
        return;
    }

    printf("\n📋 Список задач:\n");
    for (int i = 0; i < taskCount; i++) {
        printf("%d. [%s] %s\n", taskList[i].id,
               taskList[i].completed ? "✔" : " ", taskList[i].description);
    }
}

void completeTask() {
    int id;
    printf("Введите ID завершённой задачи: ");
    scanf("%d", &id);

    for (int i = 0; i < taskCount; i++) {
        if (taskList[i].id == id) {
            taskList[i].completed = 1;
            printf("✅ Задача помечена как завершённая.\n");
            return;
        }
    }
    printf("❌ Задача с таким ID не найдена.\n");
}

void deleteTask() {
    int id;
    printf("Введите ID задачи для удаления: ");
    scanf("%d", &id);

    int found = 0;
    for (int i = 0; i < taskCount; i++) {
        if (taskList[i].id == id) {
            found = 1;
        }
        if (found && i < taskCount - 1) {
            taskList[i] = taskList[i + 1];
        }
    }

    if (found) {
        taskCount--;
        printf("🗑 Задача удалена.\n");
    } else {
        printf("❌ Задача с таким ID не найдена.\n");
    }
}

int main() {
    int choice;

    while (1) {
        printMenu();
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask();
                break;
            case 2:
                listTasks();
                break;
            case 3:
                completeTask();
                break;
            case 4:
                deleteTask();
                break;
            case 5:
                printf("👋 До свидания!\n");
                return 0;
            default:
                printf("⚠️  Некорректный выбор.\n");
        }
    }

    return 0;
}
