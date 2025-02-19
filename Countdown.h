#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <string>
#include <sstream>
#include <vector>

// this is provided code for the last part of the README

std::string intToString(const int x) {
    std::ostringstream str;
    str << x;
    return str.str();
}

class CountdownSolution {
  
private:
    std::string solution;
    int value;
    
public:
    
    CountdownSolution() : solution(), value(0) {}
    CountdownSolution(const std::string & solutionIn, const int valueIn)
        : solution(solutionIn), value(valueIn) {
    }
    
    const std::string & getSolution() const {
        return solution;
    }
    
    int getValue() const {
        return value;
    }
    
};

// Do not edit above this line

// TODO: write code here:
// evaluateCountdown FUNCTION

double evaluateCountdown(const std::string &RPN) {
    std::vector<double> numbers;
    std::stringstream ss(RPN);
    std::string token;

    while (ss >> token) {
        std::stringstream tokenStream(token);
        double number;
        if (tokenStream >> number) {
            numbers.push_back(number);
        } else {
            if (numbers.size() >= 2 && (token == "+" || token == "-" || token == "*" || token == "/")) {
                double num1 = numbers.back();
                numbers.pop_back();
                double num2 = numbers.back();
                numbers.pop_back();

                double result;
                if (token == "+") result = num2 + num1;
                else if (token == "-") result = num2 - num1;
                else if (token == "*") result = num2 * num1;
                else if (token == "/") {
                    if (num1 != 0) result = num2 / num1;
                    else return -1;
                }
                numbers.push_back(result);
            } else {
                return -1;
            }
        }
    }

    return numbers.size() == 1 && numbers.back() == static_cast<int>(numbers.back())? numbers.back() : -1;
}

// solveCountdownProblem FUNCTION

CountdownSolution bestSolution;

void findSolution(std::vector<int> remaining, std::string expression, int cur, int target, bool isFirst) {
    if (std::abs(target - cur) < std::abs(target - bestSolution.getValue())) {
        bestSolution = CountdownSolution(expression, cur);
    }

    if (remaining.empty() || cur == target) {
        return;
    }
    
    for (size_t i = 0; i < remaining.size(); ++i) {
        std::vector<int> rest = remaining;
        rest.erase(rest.begin() + i);
        std::stringstream ss;

        if (isFirst) {
            ss << expression << remaining[i];
            findSolution(rest, ss.str(), cur + remaining[i], target, false);
        } else {
            ss << expression << " " << remaining[i];
            findSolution(rest, ss.str() + " +", cur + remaining[i], target, false);
            findSolution(rest, ss.str() + " -", cur - remaining[i], target, false);
            findSolution(rest, ss.str() + " *", cur * remaining[i], target, false);
            if (remaining[i] != 0) {
                findSolution(rest, ss.str() + " /", cur / remaining[i], target, false);
            }
        }
    }
}

CountdownSolution solveCountdownProblem(const std::vector<int> &numbers, int target) {
    bestSolution = CountdownSolution("", 0);

    findSolution(numbers, "", 0, target, true);

    return bestSolution;
}
// Do not edit below this line


#endif
