// #include <algorithm>
// #include <iostream>
// #include <vector>

// int main() {
//     std::vector<int> v {3, 1, 4, 1, 5, 9, 2, 6};
//     std::pair<int, int> bounds = std::minmax(1, 6);

//     std::cout << "v[" << bounds.first << "," << bounds.second << "]: ";
//     for (int i = bounds.first; i < bounds.second; ++i) {
//         std::cout << v[i] << ' ';
//     }
//     std::cout << '\n';
// }
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v{3, 1, 4, 1, 5, 9, 2, 6};
    std::srand(std::time(0));
    std::pair<int, int> bounds =
        std::minmax(std::rand() % v.size(), std::rand() % v.size());

    std::cout << "v[" << bounds.first << "," << bounds.second << "]: ";
    for (int i = bounds.first; i < bounds.second; ++i) {
        std::cout << v[i] << ' ';
    }
    std::cout << '\n';
}