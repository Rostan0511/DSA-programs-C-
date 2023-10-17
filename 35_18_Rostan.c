#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function to evaluate an expression
double evaluateExpression(const char *expression) {
    // Use sscanf to read the expression as a double
    double result;
    if (sscanf(expression, "%lf", &result) == 1) {
        return result; // If it's just a number, return it
    } else {
        // If it's not a simple number, try to evaluate it using math functions
        int n = 0;
        char operator;
        double operand;

        // Initialize result to the first number in the expression
        if (sscanf(expression, "%lf%n", &result, &n) != 1) {
            fprintf(stderr, "Invalid expression\n");
            exit(1);
        }

        while (sscanf(expression + n, " %c %lf%n", &operator, &operand, &n) == 2) {
            switch (operator) {
                case

