# Author: Diana Sanchez

# This Python file will calculate a solution of a first-order differential
# equation using Euler's Method for ordinary differential equations with a
# given initial condition and step size

import math


def main():
    loop = True
    while loop:
        # Dictionary of common math operators to identify in input
        math.e
        mathOp = {'.': '.', '*': '*', '+': '+', '-': '-', '/': '/', "pi":
                  "math.pi", "**": "**", "^": "**", "log": "math.log",
                  "log10": "math.log10", "log2": "math.log2", 'e': "math.e",
                  "sqrt": "math.sqrt", "sin": "math.sin", "cos": "math.cos",
                  "tan": "math.tan", "asin": "math.asin", "acos":
                  "math.acos", "atan": "math.atan", "(": "(", ")": ")",
                  " ": ""}
        try:
            # User Input
            print("y' = f(x,y) \ninitial condition: y(x0) = y0\n")

            while True:
                stepSize = float(input("Enter the step size h: "))
                if stepSize > 0:
                    break
                else:
                    print("Step size must be greater than 0")

            x0 = float((input("Enter the initial condition x0: ")))
            y0 = float(input("Enter the initial condition value y(%d) = "
                             % x0))
            y_t = float(input("Enter the end condition y(_): "))

            if y_t > x0:
                eq = str(input("Enter the function f(x,y). Use x and y as your"
                               " variables\navailable symbols:[*, /, +, -, "
                               "sqrt, **, pi, log, e, sin, cos, tan, asin, "
                               "acos, atan] : "))
                # convert user input into proper format to evaluate
                for symbol in mathOp:
                    eq = eq.replace(symbol, mathOp[symbol])

                try:
                    # test if the function inputted is valid
                    test_eq = eq
                    test_eq = test_eq.replace("x", str(x0))
                    test_eq = test_eq.replace("y", str(y0))
                    eval(test_eq)
                    loop = False
                    # Find solution using Euler's method
                    y_ti = compute_euler(stepSize, x0, y0, eq, y_t)
                    print("Answer:\n\ty(%s) = %s" % ("{:.1f}".format(y_t),
                          "{:.5f}".format(y_ti)))

                except (ValueError, SyntaxError, NameError) as e:
                    print("Unidentified symbol\n", e)
                    loop = True

            else:
                print("The end condition must be greater than the initial"
                      " condition x0: %d \n" % x0)
                loop = True

        except ValueError as e:
            print("invalid input", e)
            loop = True


# Use Euler's method using the given step size and initial condition to
# find solution
def compute_euler(stepSize, x0, y0, eq, y_t):
    print_intro(stepSize, x0, y0, eq)
    step = 1
    x_i = x0
    y_ti = y0
    while x_i < y_t:
        y_old = y_ti
        y_ti = y_ti + stepSize * eval_function(eq, x_i, y_ti)
        print_step(step, x_i, stepSize, y_old, y_ti)
        x_i = stepSize + x_i
        step = step + 1

    return y_ti


def eval_function(f, x, y):
    f = f.replace("x", str(x))
    f = f.replace("y", str(y))
    return eval(f)


def print_intro(stepSize, x0, y0, eq):
    function_p = eq
    function_p = function_p.replace("math.", "")
    print("\nEuler Method: \n\tx_i+1 = x_i + h\n\ty_i+1 = y_i + "
          "h * f(x_i, yi)\n")
    print("Given: \n\th = %s, x_0 = %s, y_0 = %s, and f(x,y) = "
          "%s\n" % ("{:.2f}".format(stepSize), "{:.1f}".format(x0),
                    "{:.1f}".format(y0), function_p))
    print("Solution:")


def print_step(step, x_i, stepSize, y_old, y_ti):
    print("Step %d\n\tx_%d = x_%d + h = %s + %s = %s"
          % (step, step, step - 1, "{:.2f}".format(x_i),
             "{:.2f}".format(stepSize),
             "{:.2f}".format(x_i + stepSize)))
    print("\n\ty_x%d = y_x%d + h * f(x_%d, y_x%d) \n\t  "
          "= %s + %s * f(%s, %s) = %s\n"
          % (step, step - 1, step - 1, step - 1,
             "{:.2f}".format(y_old), "{:.2f}".format(stepSize),
             "{:.2f}".format(x_i), "{:.2f}".format(y_old),
             "{:.4f}".format(y_ti)))


if __name__ == '__main__':
    main()
