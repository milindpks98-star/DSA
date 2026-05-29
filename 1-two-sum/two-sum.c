/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
//////milind/////
//  int find(int i,int x,int *nums,int size)
// {
//     for(int j=i+1;j<size;j++)
//     {
//         if(x==nums[j])
//         {
//             return j;
//         }
//     }
//     return -1;
// }
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;
#define HASH_SIZE 20011 // A prime number helps distribute keys evenly

// Simple absolute modulo hash function
int hash(int key) {
    int h = key % HASH_SIZE;
    return h < 0 ? h + HASH_SIZE : h;
}

// Insert a key-value pair into the hash table
void insert(Node** hashTable, int key, int value) {
    int index = hash(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = hashTable[index]; // Insert at the head of the chain
    hashTable[index] = newNode;
}

// Search for a key and return its index, or -1 if not found
int search(Node** hashTable, int key) {
    int index = hash(key);
    Node* current = hashTable[index];
    while (current != NULL) {
        if (current->key == key) {
            return current->value;
        }
        current = current->next;
    }
    return -1;
}

// Free memory allocated for the hash table
void freeHashTable(Node** hashTable) {
    for (int i = 0; i < HASH_SIZE; i++) {
        Node* current = hashTable[i];
        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    // Allocate the hash table buckets initialized to NULL
    Node** hashTable = (Node**)calloc(HASH_SIZE, sizeof(Node*));
    
    // Allocate the result array
    int* result = (int*)malloc(2 * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        // Check if the complement is already in the hash table
        int complementIndex = search(hashTable, complement);
        if (complementIndex != -1) {
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            
            freeHashTable(hashTable);
            free(hashTable);
            return result;
        }
        
        // If not found, insert the current number and its index
        insert(hashTable, nums[i], i);
    }

    // Clean up if no solution is found (though LeetCode guarantees one)
    freeHashTable(hashTable);
    free(hashTable);
    return NULL;
}