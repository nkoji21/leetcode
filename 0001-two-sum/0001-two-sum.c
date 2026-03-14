typedef struct s_entry {
    int value;
    int index;
    struct s_entry *next;
} Entry;

typedef struct s_hashmap {
    Entry **entries;
    int size;
} HashMap;

static unsigned int hash(int value, int size) {
    return ((unsigned int)value % (unsigned int)size);
}

static HashMap *newHashMap(int size) {
    HashMap *hashmap = malloc(sizeof(*hashmap));
    if (!hashmap)
        return (NULL);

    hashmap->size = size;
    hashmap->entries = malloc(sizeof(*hashmap->entries) * size);
    if (!hashmap->entries)
        return (free(hashmap), NULL);

    for (int i = 0; i < size; i++) {
        hashmap->entries[i] = NULL;
    }

    return (hashmap);
}

static void freeHashMap(HashMap *hashmap) {
    if (!hashmap)
        return;
    
    for (int i = 0; i < hashmap->size; i++) {
        Entry *entry = hashmap->entries[i];
        while (entry != NULL) {
            Entry *next = entry->next;
            free(entry);
            entry = next;
        }
    }

    free(hashmap->entries);
    free(hashmap);
}

static int insertToHashMap(HashMap *hashmap, int value, int index) {
    unsigned int bucket = hash(value, hashmap->size);

    Entry *entry = hashmap->entries[bucket];
    while (entry != NULL) {
        if (entry->value == value) {
            entry->index = index;
            return (1);
        }
        entry = entry->next;
    }

    entry = malloc(sizeof(*entry));
    if (!entry)
        return (0);

    entry->value = value;
    entry->index = index;
    entry->next = hashmap->entries[bucket];
    hashmap->entries[bucket] = entry;

    return (1);
}

static int getIndexFromHashMap(const HashMap *hashmap, int value, int *out_index) {
    unsigned int bucket = hash(value, hashmap->size);

    Entry *entry = hashmap->entries[bucket];
    while (entry != NULL) {
        if (entry->value == value) {
            *out_index = entry->index;
            return (1);
        }
        entry = entry->next;
    }

    return (0);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;

    HashMap *hashmap = newHashMap(numsSize * 2 + 1);
    if (!hashmap)
        return (NULL);

    int* returnValues = malloc(sizeof(*returnValues) * *returnSize);
    if (!returnValues)
        return (freeHashMap(hashmap), NULL);

    int foundIndex;
    for (int i = 0; i < numsSize; i++) {
        int needed = target - nums[i];

        if (getIndexFromHashMap(hashmap, needed, &foundIndex)) {
            returnValues[0] = foundIndex;
            returnValues[1] = i;
            freeHashMap(hashmap);
            return (returnValues);
        }

        if (!insertToHashMap(hashmap, nums[i], i))
            return (free(returnValues), freeHashMap(hashmap), NULL);
    }

    return (free(returnValues), freeHashMap(hashmap), NULL);
}