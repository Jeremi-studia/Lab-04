// TASK 1: constexpr Power Function
// Write a constexpr function called 'power' that calculates base^exponent.
// Requirements:
// - Function signature: constexpr long int power(const int base, const int exponent)
// - Use iterative approach (loop)
// - Handle exponent = 0 (return 1)
// - Test with: power(2, 10), power(5, 3), power(3, 0)
// - Declare an array with size power(2, 4) to verify compile-time evaluation

// TASK 2: consteval Fibonacci
// Write a consteval function called 'fibonacci' that returns the nth Fibonacci number.
// Requirements:
// - Function signature: consteval long int fibonacci(const int n)
// - Use recursive approach
// - Fibonacci sequence: 0, 1, 1, 2, 3, 5, 8, 13, 21...
// - Test with compile-time constants: fibonacci(0), fibonacci(10), fibonacci(15)
// - Try calling it with a runtime variable and observe the compilation error

// TASK 3: Static Counter with Reset
// Write a function called 'counter' with a static variable that counts calls.
// Then write a second function called 'reset_counter' that resets the count to 0.
// Requirements:
// - Function signatures: 
//   int counter()
//   void reset_counter()
// - counter() increments and returns the current count
// - Test by calling counter() 5 times, then reset_counter(), then counter() 3 more times
// - Print all returned values to verify the reset works

// TASK 4: Function with Multiple Default Parameters
// Write a function called 'print_grade' that prints student information.
// Requirements:
// - Function signature: void print_grade(const std::string name, const int score, 
//                                        const std::string course = "Programming", 
//                                        const std::string semester = "Fall 2025")
// - Print format: "[name] scored [score] in [course] ([semester])"
// - Test with: 
//   - All 4 parameters provided
//   - Only name and score (use defaults for course and semester)
//   - Name, score, and course (use default for semester)

// TASK 5: Array Statistics Functions
// Write three functions to work with double arrays:
// Requirements:
// - double find_max(const double array[], const int length) - returns maximum value
// - double find_min(const double array[], const int length) - returns minimum value
// - double calculate_average(const double array[], const int length) - returns average
// - Test with an array: {23.5, 67.8, 12.3, 89.1, 45.6, 34.2}
// - Print all three statistics

// TASK 6: Vector Manipulation
// Write two functions that work with std::vector<int>:
// Requirements:
// - void remove_negatives(std::vector<int> & vec) - removes all negative numbers
// - int sum_elements(const std::vector<int> & vec) - returns sum of all elements
// - Test with vector: {10, -5, 20, -15, 30, -25, 40}
// - Print vector before and after removing negatives
// - Print sum before and after removing negatives
// Hint: To remove elements, create a new vector with only positive values, 
//       then use vec = new_vector

// TASK 7: String Vector Operations
// Write two functions for working with std::vector<std::string>:
// Requirements:
// - void print_strings(const std::vector<std::string> & vec) - prints all strings
//   with their index: "0: first_string\n1: second_string\n..."
// - std::string find_longest(const std::vector<std::string> & vec) - returns the longest string
//   (if multiple strings have same max length, return the first one)
// - Test with: {"C++", "Python", "JavaScript", "Go", "Rust", "Assembly"}
// - Print all strings and identify the longest one

// TASK 8: Combined Challenge
// Create a program that:
// Requirements:
// - Declares a std::vector<double> to store temperatures
// - Write function: void add_temperature(std::vector<double> & temps, double temp)
// - Write function: void print_statistics(const std::vector<double> & temps) that prints:
//   - Number of readings
//   - Highest temperature
//   - Lowest temperature
//   - Average temperature
// - In main: Add at least 7 temperature readings (use push_back or your add_temperature function)
// - Call print_statistics to display the results
// - Test with temperatures like: {20.5, 22.3, 19.8, 23.1, 21.7, 18.9, 24.2}


// INSTRUCTIONS:
// - Implement each task in order
// - Test your functions in the main() function
// - Use std::cout for output
// - Add comments to explain your logic
// - Make sure your code compiles without errors

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// TODO: TASK 1 - Write your power function here
constexpr long int power(const int base, const int exponent)
{
    if (!exponent)
    {
        return 1;
    }
    long int s = base;
    for (int i = exponent; i > 1; i--)
    {
        s *= base;
    }
    return s;
}

// TODO: TASK 2 - Write your fibonacci function here
consteval long int fibonacci(const int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci(n - 1) + fibonacci(n - 2);
}

// TODO: TASK 3 - Write your counter and reset_counter functions here
static int i = 0;
int counter()
{
    return ++i;
}
void reset_counter()
{
    i = 0;
}

// TODO: TASK 4 - Write your print_grade function here
void print_grade(const string name, const int score, const string course = "Programming", const string semester = "Fall 2025")
{
    cout << name << " scored " << score << " in " << course << " (" << semester << ")" << endl;
}

// TODO: TASK 5 - Write your array statistics functions here
double find_max(const double array[], const int length)
{
    double s;
    for (int i = 0; i < length; i++)
    {
        if (array[i] > s)
        {
            s = array[i];
        }
    }
    return s;
}
double find_min(const double array[], const int length)
{
    double s;
    for (int i = 0; i < length; i++)
    {
        if (array[i] < s)
        {
            s = array[i];
        }
    }
    return s;
}
double calculate_average(const double array[], const int length)
{
    double s;
    for (int i = 0; i < length; i++)
    {
        s += array[i];
    }
    return s / length;
}

// TODO: TASK 6 - Write your vector manipulation functions here
void remove_negatives(vector<int>& vec)
{
    vector<int> t;
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i] >= 0)
        {
            t.push_back(vec[i]);
        }
    }
    vec = t;
}
int sum_elements(const vector<int>& vec)
{
    int s = 0;
    for (int i = 0; i < vec.size(); i++)
    {
        s += vec[i];
    }
    return s;
}

// TODO: TASK 7 - Write your string vector functions here
void print_strings(const vector<string>& vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        cout << i << ": " << vec[i] << endl;
    }
}
string find_longest(const vector<string>& vec)
{
    string s = "";
    for (int i = 0; i < vec.size(); i++)
    {
        if (vec[i].size() > s.size())
        {
            s = vec[i];
        }
    }
    return s;
}

// TODO: TASK 8 - Write your temperature functions here
vector<double> temps;

void add_temperature(vector<double>& temps, double temp)
{
    temps.push_back(temp);
}
void print_statistics(const vector<double>& temps)
{
    double max_t;
    for (int i = 0; i < temps.size(); i++)
    {
        if (max_t < temps[i])
        {
            max_t = temps[i];
        }
    }
    double min_t;
    for (int i = 0; i < temps.size(); i++)
    {
        if (min_t > temps[i])
        {
            min_t = temps[i];
        }
    }
    double sum_t;
    for (int i = 0; i < temps.size(); i++)
    {
        sum_t += temps[i];
    }
    cout << "Number of readings: " << temps.size() << endl << "Highest temperature: " << max_t << endl << "Lowest temperature: " << min_t << endl << "Average temperature: " << sum_t / temps.size() << endl;
}

int main()
{
    std::cout << "=== FUNDAMENTALS OF COMPUTER PROGRAMMING - PRACTICE TASKS ===\n\n";

    // TODO: TASK 1 - Test power function
    std::cout << "TASK 1: constexpr Power Function\n";
    std::cout << "--------------------------------\n";
    cout << power(2, 10) << endl << power(5, 3) << endl << power(3, 0);
    long int power_array[power(2, 4)];
    std::cout << "\n";

    // TODO: TASK 2 - Test fibonacci function
    std::cout << "TASK 2: consteval Fibonacci\n";
    std::cout << "----------------------------\n";
    cout << fibonacci(0) << endl << fibonacci(10) << endl << fibonacci(15);
    std::cout << "\n";

    // TODO: TASK 3 - Test counter functions
    std::cout << "TASK 3: Static Counter with Reset\n";
    std::cout << "----------------------------------\n";
    cout << counter() << endl << counter() << endl << counter() << endl << counter() << endl << counter() << endl;
    reset_counter();
    cout << counter() << endl << counter() << endl << counter() << endl;
    std::cout << "\n";

    // TODO: TASK 4 - Test print_grade function
    std::cout << "TASK 4: Function with Default Parameters\n";
    std::cout << "-----------------------------------------\n";
    print_grade("Jeremi", 0);
    print_grade("Jeremi", 0, "Maths");
    std::cout << "\n";

    // TODO: TASK 5 - Test array statistics
    std::cout << "TASK 5: Array Statistics\n";
    std::cout << "------------------------\n";
    double arr[] = { 23.5, 67.8, 12.3, 89.1, 45.6, 34.2 };
    cout << find_max(arr, 7) << endl << find_min(arr, 7) << endl << calculate_average(arr, 7);
    std::cout << "\n";

    // TODO: TASK 6 - Test vector manipulation
    std::cout << "TASK 6: Vector Manipulation\n";
    std::cout << "---------------------------\n";
    vector<int> vec2 = {10, -5, 20, -15, 30, -25, 40};
	for (int i = 0; i < vec2.size(); i++)
	{
		cout << vec2[i] << endl;
	}
	cout << sum_elements(vec2);
	remove_negatives(vec2);
	cout << "\n\n";
	for (int i = 0; i < vec2.size(); i++)
	{
		cout << vec2[i] << endl;
	}
	cout << sum_elements(vec2);
    std::cout << "\n";

    // TODO: TASK 7 - Test string vector operations
    std::cout << "TASK 7: String Vector Operations\n";
    std::cout << "---------------------------------\n";
    print_strings({"C++", "Python", "JavaScript", "Go", "Rust", "Assembly"});
	cout << endl << find_longest({"C++", "Python", "JavaScript", "Go", "Rust", "Assembly"});
    std::cout << "\n";

    // TODO: TASK 8 - Test temperature statistics
    std::cout << "TASK 8: Temperature Statistics\n";
    std::cout << "------------------------------\n";
    add_temperature(temps, 20.5);
	add_temperature(temps, 22.3);
	add_temperature(temps, 19.8);
	add_temperature(temps, 23.1);
	add_temperature(temps, 21.7);
	add_temperature(temps, 18.9);
	add_temperature(temps, 24.2);
	print_statistics(temps);
    std::cout << "\n";

    return 0;
}