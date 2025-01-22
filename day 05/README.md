# Day 05

## What I Learned Today

Two Sum problem

This is a simple problem were you should the indices of 2 values in an array that when added should equal to the target input. 

## Key Concepts

- solution is faster if we use a hash or dictionary to store the number and keep the indices as value.
- Instead of looking for the sum, a better approach is to look for the compliment which is by getting the difference of the target and the current number where the solution would be at O(n) time complexity instead of O(n^2)

### Quick Links

---

https://leetcode.com/problems/two-sum/

## Code Snippets

```tsx
function twoSum(nums: number[], target: number): number[] {

    const hash = {};
    for (let i = 0; i < nums.length; i++) {
        const compliment = target - nums[i];
        if (compliment in hash) {
            return [hash[compliment], i];
        }

        hash[nums[i]] = i;

    }

    return [];

};
```

## Challenges Experienced

- initial submissions had time complexity which took 47ms to execute which is quite slow due to using O(n^2) implementations. Good thing there is an editorial guide.

## Resources Used

https://leetcode.com/problems/two-sum/