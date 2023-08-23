#include<iostream>
#include<vector>
#include<algorithm>
class Solution {
public:
    public:
    int leastInterval(vector<char>& tasks, int n) {
        // Count the frequency of each task
        // constrain all uppercase letter
        // Step 1: create a map to store the frequency of each task
        unordered_map<char, int> task_freq;
        for (char task : tasks) {
            task_freq[task]++;
        }

        // Sort the tasks by frequency in descending order
        // iter.second : second part of eac pair
        vector<int> freq_list;
        for (auto iter : task_freq) {
            freq_list.push_back(iter.second);
        }
        sort(freq_list.begin(), freq_list.end(), std::greater<int>());

        // Calculate the number of idle slots required
        int max_freq = freq_list[0];
        int num_idle_slots = (max_freq - 1) * n;

        // Place the tasks in the idle slots
        for (int i = 1; i < freq_list.size(); i++) {
            int freq = freq_list[i];
            num_idle_slots -= min(max_freq - 1, freq);
        }

        // Add extra slots if necessary
        int num_extra_slots = max(num_idle_slots, 0);
        int num_total_slots = tasks.size() + num_extra_slots;

        return num_total_slots;
    }
};