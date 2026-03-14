typedef struct {
    int k;
    int v;
} Pair;

typedef struct {
    Pair *map;
    int size;
} Ctx;

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Ctx ctx;

    ctx.map = malloc(sizeof(*ctx.map) * numsSize);
    if (!ctx.map) {
        return (NULL);
    }
    ctx.size = numsSize;

    *returnSize = 2;
    int* returnValues = malloc(sizeof(*returnValues) * *returnSize);
    if (!returnValues) {
        free(ctx.map);
        return (NULL);
    }

    for (int i = 0; i < numsSize; i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] == ctx.map[j].v) {
                returnValues[0] = ctx.map[j].k;
                returnValues[1] = i;
                free(ctx.map);
                return (returnValues);
            }
        }
        ctx.map[i] = (Pair){i, target - nums[i]};
    }

    free(ctx.map);
    free(returnValues);
    *returnSize = 0;
    return (NULL);
}