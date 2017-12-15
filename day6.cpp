/**
 * Day 6: Memory Reallocation
 * http://adventofcode.com/2017/day/6
 */

#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parse(string s) {
    istringstream stream(s);

    vector<int> values;
    int n;
    while (stream >> n) {
        values.push_back(n);
    }

    return values;
}

void step(vector<int> &values) {
    std::vector<int>::iterator result;
    size_t n = values.size();

    result = std::max_element(values.begin(), values.end());
    int value = *result;
    size_t offset = distance(values.begin(), result);

    for (size_t i = 0; i < values.size(); i++) {
        if (i == offset)
            values[i] = 0;
        values[i] += value / n;
        if ((i - offset - 1) % n < value % n) {
            values[i] += 1;
        }
    }
}

int main(int argc, char *argv[]) {
    // Floyd's cycle-finding algorithm
    vector<int> values = parse(argv[1]);
    vector<int> slow = values;
    vector<int> fast = values;

    int steps = 1;
    do {
        step(slow);
        step(fast);
        step(fast);
        steps++;
    } while (slow != fast);

    // Find steps till start of cycle
    int mu = 0;
    slow = values;
    do {
        step(slow);
        step(fast);
        mu++;
    } while (slow != fast);

    // Find the length of cycle
    int lam = 0;
    fast = slow;
    do {
        step(fast);
        lam++;
    } while (slow != fast);

    cout << "Part 1: " << mu + lam << endl;
    cout << "Part 2: " << lam << endl;
    return 0;
}
