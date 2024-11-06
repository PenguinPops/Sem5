#include <iostream>
#include <boost/fusion/include/vector.hpp>
#include <boost/fusion/include/for_each.hpp>
#include <boost/fusion/include/make_vector.hpp>
#include <boost/fusion/include/at.hpp>
#include <boost/fusion/include/size.hpp>
#include <boost/fusion/include/iterator.hpp>
#include <map>
#include <typeinfo>
#include <string>

using namespace std;
namespace fusion = boost::fusion;

// Function to count types in a Fusion vector
template <typename FusionVector>
std::map<std::string, int> countTypes(const FusionVector& vec) {
    std::map<std::string, int> typeCount;

    // Lambda to process each element
    auto countLambda = [&](const auto& element) {
        const std::string typeName = typeid(element).name();
        ++typeCount[typeName]; // Increment the count for this type
    };

    // Iterate over elements in the Fusion vector
    fusion::for_each(vec, countLambda);

    return typeCount;
}

// Main function
int main() {
    // Creating a Fusion vector with mixed types
    auto fusionVec = fusion::make_vector(42, 3.14, 'c', true, 2.718f, false, 100);

    // Count the types in the Fusion vector
    auto typeCounts = countTypes(fusionVec);

    // Output the results
    for (const auto& [type, count] : typeCounts) {
        cout << "Type: " << type << ", Count: " << count << endl;
    }

    return 0;
}
