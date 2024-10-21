#ifndef GET_SECONDS_H
#define GET_SECONDS_H
// Return current epoch time in seconds
double get_seconds();

// Implementation
#include <chrono>
double get_seconds()
{
  return 
    std::chrono::duration<double>(
      std::chrono::system_clock::now().time_since_epoch()).count();
}

double get_steady_seconds()
{
  static const auto start_time = std::chrono::steady_clock::now();
  const auto now = std::chrono::steady_clock::now();
  return std::chrono::duration<double>(now - start_time).count();
}
#endif
