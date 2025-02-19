# Countdown

Welcome to the Countdown game solver! This program is designed to solve the Countdown numbers game, a challenging mathematical puzzle. The goal is to use a set of six integer numbers and basic mathematical operators to achieve a result as close as possible to a target integer.

## The Game

The Countdown numbers game is specified as follows:

Players are given six integer numbers and a target integer number. The six numbers should be combined using the mathematical operators `+`, `-`, `*`, and `/` in a way that gets as close as possible to the target number. Each number can only be used once at most, but it is okay not to use any given number(s). Divisions by zero can be discarded. For example, if the numbers are `(100, 4, 17, 9, 3, 2)` and the target is `37`, then one way to solve it is `((100 / (3 + 2)) + 17)`.

## How to Use

To run this code, you can use the following example:

```cpp
#include <iostream>
#include <vector>
#include "Countdown.h"  // Include the header file for the Countdown solver

int main() {
    // Define the input numbers and target
    std::vector<int> numbers{1, 2, 3, 4, 5, 6};
    int target = 123;

    // Solve the Countdown problem
    CountdownSolution answer = solveCountdownProblem(numbers, target);

    // Display the solution
    std::cout << "Countdown Solution: " << answer.expression << " = " << answer.result << std::endl;

    return 0;
}
```

Make sure to include the appropriate header file, in this case, `Countdown.h`, and replace the example numbers and target with your desired input.

Feel free to explore and customise the code to suit your needs. Happy Countdown solving!

