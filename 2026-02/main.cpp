#include <iostream>
#include <vector>
#include <algorithm>


int main() {
    std::clog << "Hello world!" << std::endl;


    if (true) {
        std::cout << "True!" << std::endl;
    } else {
        std::cout << "False!" << std::endl;
    }

    std::vector<int> numbers = {5, 2, 9, 1, 5, 6};
    std::sort(numbers.begin(), numbers.end());

    // step 3/
    
    for (const auto& num : numbers) {
        std::cout << num << " ";
    }
}