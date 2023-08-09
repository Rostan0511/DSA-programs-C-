#include <stdio.h>

#define MAX_SIZE 100

int main() {
    int array[MAX_SIZE];
    int size = 0;
    int choice, element, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Element\n");
        printf("2. Display Array\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (size < MAX_SIZE) {
                    printf("Enter the element : ");
                    scanf("%d", &element);
                    printf("Enter the position to insert (0 - %d): ", size);
                    scanf("%d", &position);

                    if (position < 0 || position > size) {
                        printf("Invalid position Insertion process failed.\n");
                    } else {
                        // Shift elements to make space for the new element
                        for (int i = size; i > position; i--) {
                            array[i] = array[i - 1];
                        }
                        array[position] = element;
                        size++;

                        printf("Element insertion is successfull.\n");
                    }
                } else {
                    printf("Array is full. Insertion failed.\n");
                }
                break;

            case 2:
                if (size > 0) {
                    printf("Array elements: ");
                    for (int i = 0; i < size; i++) {
                        printf("%d ", array[i]);
                    }
                    printf("\n");
                } else {
                    printf("Array is empty.\n");
                }
                break;

            case 3:
                printf("Exiting program.\n");
                return 0;

            default:
                printf("Invalid choice. Please select a valid option.\n");
        }
    }

    return 0;
}


