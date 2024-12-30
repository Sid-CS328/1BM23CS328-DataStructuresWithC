#include <stdio.h>
#include <stdlib.h>

#define MAX_EMPLOYEES 100


typedef struct {
    int key;       
    char name[30]; 
} Employee;


typedef struct {
    Employee *table[MAX_EMPLOYEES]; 
    int m;                      
} HashTable;


void initHashTable(HashTable *ht, int m) {
    ht->m = m;
    for (int i = 0; i < m; i++) {
        ht->table[i] = NULL;
    }
}


int hashFunction(int key, int m) {
    return key % m;
}


void insert(HashTable *ht, int key, char *name) {
    int index = hashFunction(key, ht->m);
    int originalIndex = index;
    
    Employee *emp = (Employee*) malloc(sizeof(Employee));
    emp->key = key;
    snprintf(emp->name, sizeof(emp->name), "%s", name);
    

    while (ht->table[index] != NULL) {
   
        if (ht->table[index]->key == key) {
            ht->table[index] = emp;
            return;
        }

        index = (index + 1) % ht->m;
        if (index == originalIndex) {
            printf("Hash table is full, cannot insert new record.\n");
            free(emp);
            return;
        }
    }
    

    ht->table[index] = emp;
    printf("Inserted %s at index %d\n", name, index);
}


Employee* search(HashTable *ht, int key) {
    int index = hashFunction(key, ht->m);
    int originalIndex = index;
    
 
    while (ht->table[index] != NULL) {
        if (ht->table[index]->key == key) {
            return ht->table[index];
        }
    
        index = (index + 1) % ht->m;
        if (index == originalIndex) {
            break;
        }
    }
    
    return NULL; 
}


void displayHashTable(HashTable *ht) {
    printf("Hash Table contents:\n");
    for (int i = 0; i < ht->m; i++) {
        if (ht->table[i] != NULL) {
            printf("Index %d: Key = %d, Name = %s\n", i, ht->table[i]->key, ht->table[i]->name);
        } else {
            printf("Index %d: Empty\n", i);
        }
    }
}

int main() {
    HashTable ht;
    int m;

    printf("Enter the size of the hash table (m): ");
    scanf("%d", &m);

    initHashTable(&ht, m);
    
    int choice, key;
    char name[30];
    
    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert Employee Record\n");
        printf("2. Search Employee by Key\n");
        printf("3. Display Hash Table\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                printf("Enter employee key (4-digit): ");
                scanf("%d", &key);
                printf("Enter employee name: ");
                scanf("%s", name);
                insert(&ht, key, name);
                break;
            case 2:
                printf("Enter employee key to search: ");
                scanf("%d", &key);
                Employee *emp = search(&ht, key);
                if (emp != NULL) {
                    printf("Employee found: Key = %d, Name = %s\n", emp->key, emp->name);
                } else {
                    printf("Employee with key %d not found.\n", key);
                }
                break;
            case 3:
                displayHashTable(&ht);
                break;
            case 4:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
    
    return 0;
}
