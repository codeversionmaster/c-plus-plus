#include <iostream>
#include <algorithm>
#include <execution>
#include <vector>

int main() {
  std::vector<int> v = {2, 1, 5, 3, 4};

  for(auto it:v) { std::cout << it << " "; }
  std::cout << std::endl;

  // Use the parallel execution policy to sort the vector
  std::sort(std::execution::par, v.begin(), v.end());

  for(auto it:v) { std::cout << it << " "; }
  std::cout << std::endl;

  return 0;
}

