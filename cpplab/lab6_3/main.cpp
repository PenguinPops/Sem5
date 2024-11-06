#include <iostream>
#include <vector>
#include <numeric>    // For accumulate
#include <algorithm>  // For sort, for_each
#include <functional> // For std::bind
#include <boost/bind/bind.hpp>

using namespace std;
using namespace boost::placeholders;

// Function to print elements less than the mean
template <typename T>
void printLessThanMean(T x, T mean)
{
    if (x < mean)
        cout << x << " ";
}

// Function to print elements between mean and median
template <typename T>
void printBetweenMeanAndMedian(T x, T mean, T median)
{
    if ((x > mean && x < median) || (x > median && x < mean))
        cout << x << " ";
}

// Function to print positive elements
template <typename T>
void printPositive(T x)
{
    if (x > 0)
        cout << x << " ";
}

template <typename T>
void analyzeVector(const vector<T>& vec)
{
    if (vec.empty())
    {
        cout << "The vector is empty." << endl;
        return;
    }

    // Calculate the arithmetic mean
    T sum = accumulate(vec.begin(), vec.end(), T(0)); // T(0) is the initial value for the sum
    T mean = sum / vec.size();
    cout << "Mean: " << mean << endl;

    // Display elements less than the mean
    cout << "Elements less than the mean: ";
    for_each(vec.begin(), vec.end(), boost::bind(printLessThanMean<T>, _1, mean)); // Using bind to pass the mean value to the function
    cout << endl;

    // Calculate the median
    vector<T> sortedVec = vec;
    sort(sortedVec.begin(), sortedVec.end());
    T median;
    if (sortedVec.size() % 2 == 0)
        median = (sortedVec[sortedVec.size() / 2 - 1] + sortedVec[sortedVec.size() / 2]) / 2;
    else
        median = sortedVec[sortedVec.size() / 2];
    cout << "Median: " << median << endl;

    // Display elements between the mean and the median
    cout << "Elements between mean and median: ";
    for_each(vec.begin(), vec.end(), boost::bind(printBetweenMeanAndMedian<T>, _1, mean, median));
    cout << endl;

    // Display positive elements
    cout << "Positive elements: ";
    for_each(vec.begin(), vec.end(), boost::bind(printPositive<T>, _1));
    cout << endl;
}

int main()
{
    vector<int> numbers = {1, -2, 3, 5, 10, -6, 8, -1, 7};
    analyzeVector(numbers);
    return 0;
}
