#ifndef LOGGER
#define LOGGER

#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <chrono>
#include <ctime>
#include <format>
#include <memory> 

enum class LogLevel {
  INFO,
  DEBUG,
  ERROR,
  NONE
};

class LoggerInterface {
public:
  LoggerInterface(LoggerInterface& logInterface, std::string name);
  LoggerInterface(std::string fileName, std::string name);
  ~LoggerInterface();
  void info(std::string log);
  void debug(std::string log);
  void error(std::string log);
  void setLogLevel(LogLevel level);
protected:
  std::string _name{""};
  std::shared_ptr<Logger> _pLogger{ nullptr };
private:
  std::string format(std::string msg);
  LogLevel _logLevel{LogLevel::NONE};
};

class Logger {
public:
  Logger(std::string fileName);
  ~Logger();
  void log(std::string log);
protected:
private:
  std::mutex _mutex;
  std::ofstream _fileStream;
};

#endif //LOGGER