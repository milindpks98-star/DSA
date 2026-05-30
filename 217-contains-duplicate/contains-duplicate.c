bool containsDuplicate(int* nums, int numsSize)
{
    int size = numsSize * 2 + 1;

    int *table = (int *)calloc(size, sizeof(int));
    bool *used = (bool *)calloc(size, sizeof(bool));

    for (int i = 0; i < numsSize; i++)
    {
        int key = nums[i];
        int idx = ((key % size) + size) % size;

        while (used[idx])
        {
            if (table[idx] == key)
            {
                free(table);
                free(used);
                return true;
            }

            idx = (idx + 1) % size;
        }

        table[idx] = key;
        used[idx] = true;
    }

    free(table);
    free(used);

    return false;
}