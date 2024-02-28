#include <stdio.h>
#define max 10 
int hashTable[max] = {0}; 
void insertIntoHashTable(int key, int m) {
    int hashValue = key % m;
    while (hashTable[hashValue] != 0) {
        hashValue = (hashValue + 1) % m;
    }
    hashTable[hashValue] = key;
}
void displayHashTable(int m) {
    printf("\nHash Table:\n");
    printf("Address\tKey\n");
    for (int i = 0; i < m; i++) {
        printf("%d\t", i);
        if (hashTable[i] != 0) {
            printf("%d", hashTable[i]);
        }
        printf("\n");
    }
}

int main() {
    int m = max;
    int employeeKeys[] = {1234, 5678, 9876, 4321, 8765};
    for (int i = 0; i < sizeof(employeeKeys) / sizeof(employeeKeys[0]); i++) {
        insertIntoHashTable(employeeKeys[i], m);
    }
    displayHashTable(m);
    return 0;
}
