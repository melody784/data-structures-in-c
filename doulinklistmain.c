#include "doulinklist.h"
int main() {
    dlinklist L;
    dlinklist_status status = dlinklist_init(&L);
    if (status != D_LINKLIST_OK) {
        printf("Failed to initialize the doubly linked list.\n");
        return 1;
    }
    // Insert elements into the doubly linked list
    for (int i = 1; i <= 5; i++) {
        status = dlinklist_insert(L, i, i * 10);
        if (status != D_LINKLIST_OK) {
            printf("Failed to insert element %d into the doubly linked list.\n", i * 10);
            return 1;
        }
    }
    // Print the elements in the doubly linked list
     dlinklist_print(L);
    // Update an element in the doubly linked list
    status = dlinklist_update(L, 3, 100);
    if (status != D_LINKLIST_OK) {
        printf("Failed to update the element at position 3 in the doubly linked list.\n");
        return 1;
    }
    // Print the elements in the doubly linked list after the update
   dlinklist_print(L);
    // Delete an element from the doubly linked list
    status = dlinklist_delete(L, 2);
    if (status != D_LINKLIST_OK) {
        printf("Failed to delete the element at position 2 from the doubly linked list.\n");
        return 1;
    }
    // Print the elements in the doubly linked list after the deletion
    dlinklist_print(L);
    // Clean up and destroy the doubly linked list
    status = dlinklist_destroy(&L);
    if (status != D_LINKLIST_OK) {
        printf("Failed to destroy the doubly linked list.\n");
        return 1;
    }
    return 0;
}