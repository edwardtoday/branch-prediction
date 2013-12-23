/**
 * @file main.cpp
 * @brief This is to test the branch prediction behavior of compiled code
 * @author Pei Qing <edwardtoday@gmail.com>
 * @date 2013-12-23
 */

#include <algorithm>
#include <ctime>
#include <iostream>

void sorted() {
  std::cout << "Sorted:\n";
  // Generate data
  const unsigned arraySize = 32768;
  int data[arraySize];

  for (unsigned c = 0; c < arraySize; ++c)
    data[c] = std::rand() % 256;

  // !!! With this, the next loop runs faster
  std::sort(data, data + arraySize);

  // Test
  clock_t start = clock();
  long long sum = 0;

  for (unsigned i = 0; i < 100000; ++i)
  {
    // Primary loop
    for (unsigned c = 0; c < arraySize; ++c)
    {
      if (data[c] >= 128)
        sum += data[c];
    }
  }

  double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

  std::cout << elapsedTime << std::endl;
  std::cout << "sum = " << sum << std::endl;
}

void unsorted() {
  std::cout << "Unsorted:\n";
  // Generate data
  const unsigned arraySize = 32768;
  int data[arraySize];

  for (unsigned c = 0; c < arraySize; ++c)
    data[c] = std::rand() % 256;

  // Test
  clock_t start = clock();
  long long sum = 0;

  for (unsigned i = 0; i < 100000; ++i)
  {
    // Primary loop
    for (unsigned c = 0; c < arraySize; ++c)
    {
      if (data[c] >= 128)
        sum += data[c];
    }
  }

  double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

  std::cout << elapsedTime << std::endl;
  std::cout << "sum = " << sum << std::endl;
}

void sorted_swap() {
  std::cout << "Sorted swapped:\n";
  // Generate data
  const unsigned arraySize = 32768;
  int data[arraySize];

  for (unsigned c = 0; c < arraySize; ++c)
    data[c] = std::rand() % 256;

  // !!! With this, the next loop runs faster
  std::sort(data, data + arraySize);

  // Test
  clock_t start = clock();
  long long sum = 0;

  // Primary loop
  for (unsigned c = 0; c < arraySize; ++c)
  {
    if (data[c] >= 128)
      for (unsigned i = 0; i < 100000; ++i)
      {
        sum += data[c]*100000;
      }
  }

  double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

  std::cout << elapsedTime << std::endl;
  std::cout << "sum = " << sum << std::endl;
}

void unsorted_swap() {
  std::cout << "Unsorted swapped:\n";
  // Generate data
  const unsigned arraySize = 32768;
  int data[arraySize];

  for (unsigned c = 0; c < arraySize; ++c)
    data[c] = std::rand() % 256;

  // Test
  clock_t start = clock();
  long long sum = 0;

  // Primary loop
  for (unsigned c = 0; c < arraySize; ++c)
  {
    if (data[c] >= 128)
      for (unsigned i = 0; i < 100000; ++i)
      {
        sum += data[c];
      }
  }

  double elapsedTime = static_cast<double>(clock() - start) / CLOCKS_PER_SEC;

  std::cout << elapsedTime << std::endl;
  std::cout << "sum = " << sum << std::endl;
}

int main()
{
  sorted();
  unsorted();
  sorted_swap();
  unsorted_swap();

  return 0;
}
