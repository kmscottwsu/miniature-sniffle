#ifndef LOGGER
#define LOGGER

#include <string>
#include <mutex>
#include <chrono>

enum class LogLevel {
  INFO,
  DEBUG,
  ERROR,
  NONE
};

class LoggerInterface {
public:
  LoggerInterface(Logger& pLower, std::string name);
  LoggerInterface(std::string fileName, std::string name);
  ~LoggerInterface();
  void info(std::string log);
  void debug(std::string log);
  void error(std::string log);
  void setLogLevel(LogLevel level);
protected:
  std::string _name{""};
  Logger* _pLogger{ nullptr };
private:
  std::string format(std::string log);

  bool _isBase{false};
  LogType _logLevel{LogLevel::NONE};
  std::chrono::time_point<std::chrono::system_clock> time;
};

class Logger {
public:
  Logger(std::string fileName);
  ~Logger();
  void log(std::string log);
protected:
private:
  std::mutex _mutex{ nullptr };
  std::string _fileName{ "text.log" };
};

#endif //LOGGER