/*
* File: EratosthenesSieve.cpp
* Author: Robert Crawford
* Date: 2022-04-22
* Version: 1.0
* Description: Prompts the user to enter two positive integers less than one
* billion and outputs the sum of all the prime numbers between n1 and n2.
* The program also prints all twin primes. Two prime numbers are said to 
* be twin primes when the difference between them is 2.
* Reference: https://en.wikipedia.org/wiki/Sieve_of_Eratosthenes
* 
TODO: 
1. Make the output more pretty with one of these:
- https://github.com/p-ranav/tabulate
- https://github.com/seleznevae/libfort
- ncurses
2. Figure out a better algorithm for finding twin primes:
- https://mathworld.wolfram.com/TwinPrimes.html
3. Refactor Code:
- Figure out what the hell is going on
- Add comments
- what the hell
*/

#include <iostream>
#include <vector>
using namespace std;

void print_header();
unsigned get_number();
void sieve(vector<bool>& primes, int upper_bound);
void make_integer_vector(vector<bool>&, vector<int>&);
void shorten_prime_list(vector<int>&, vector<int>&, int);
void get_sum(vector<int>&, int&);
int get_twin_primes(vector<int>&);

int main()
{
    print_header();
    
    cout << "Enter the first number: ";
    unsigned num1 = get_number();

    cout << "Enter the second number: ";
    unsigned num2 = get_number();

    int lower_bound = min(num1, num2);
    int upper_bound = max(num1, num2);

    vector<bool> primes;
    sieve(primes, upper_bound);

    vector<int> full_prime_list;
    make_integer_vector(primes, full_prime_list);

    vector<int> short_prime_list;
    shorten_prime_list(full_prime_list, short_prime_list, lower_bound);

    int sum = 0;
    get_sum(short_prime_list, sum);
    cout << "The sum of the primes between " << lower_bound << " and " 
        << upper_bound << " is: " << sum << '\n' << endl;

    int no_twin_primes = get_twin_primes(short_prime_list);
    cout << "The number of twin prime pairs: " << no_twin_primes << endl;
    
    return 0;
}

void print_header()
{
    cout << "=======================================================" << endl;
    cout << "| A program that takes two integers between 1 and 1   |" << endl;
    cout << "| billion and calculates the sum of the prime numbers |" << endl;
    cout << "|  between them. It will also output all of the twin  |" << endl;
    cout << "|    primes and display how many twin primes the 2    |" << endl;
    cout << "|               numbers have in common.               |" << endl;
    cout << "|=====================================================|" << endl;
    cout << "|        Algorithm Used : Sieve of Eratosthenes       |" << endl;
    cout << "=======================================================" << endl;
    cout << endl;
}

unsigned get_number()
{
    int num;
    while (!(cin >> num) || num <= 1)
    {
        cout << "Invalid input - please try again." << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter number: ";
    }
    return num;
}

void sieve(vector<bool>& primes, int upper_bound)
{
    primes.resize(upper_bound, true);

    for (int i = 3; i * i < upper_bound; i += 2) {
        for (int j = 3; j * i < upper_bound; j += 2) {
            primes[j * i] = false;
        }
    }
}

void make_integer_vector(vector<bool>& primes, vector<int>& full_prime_list)
{
    //Manually push 2 to the integer vector
    //because our for loop starts at i=3
    full_prime_list.push_back(2);

    for (int i = 3; i < primes.size(); i += 2) {
        if (primes[i] == true)
            full_prime_list.push_back(i);
    }
}

void shorten_prime_list(vector<int>& full_prime_list, vector<int>& short_prime_list, int n)
{
    for (int i = 0; i < full_prime_list.size(); i++) {
        if (full_prime_list[i] >= n)
            short_prime_list.push_back(full_prime_list[i]);
    }
}

void get_sum(vector<int>& short_prime_list, int& sum)
{
    for (int prime : short_prime_list) {
        cout << prime << " ";
        sum += prime;
    }
    cout << endl << endl;
}

int get_twin_primes(vector<int>& short_prime_list)
{
    int count = 0;
    for (int i = 0; i < short_prime_list.size() - 1; i++) {
        if (short_prime_list[i + 1] - short_prime_list[i] == 2) {
            ++count;
            cout << "[" << short_prime_list[i] << " and " 
                << short_prime_list[i + 1] << "] ";
        }
    }
    cout << endl;
    return count;
}
