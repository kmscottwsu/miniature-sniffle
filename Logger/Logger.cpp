#include "Logger.h"

LoggerInterface::LoggerInterface(LoggerInterface& logInterface, std::string name) {
  _name = logInterface._name + name;
  _isBase = false;
  _pLogger = logInterface._pLogger;
}

LoggerInterface::LoggerInterface(std::string fileName, std::string name) {
  _name = name;
  _isBase = true;
  _pLogger = new Logger(fileName);
}

LoggerInterface::~LoggerInterface() {
  if (_isBase) {
    delete _pLogger;
  }
}

void LoggerInterface::setLogLevel(LogLevel level) {
  self._logLevel = level;
}

void LoggerInterface::error(std::string log) {
  if (self._logLevel != LogLevel::NONE) {
    self.log(log);
  }
}

void LoggerInterface::debug(std::string log) {
  if (self._logLevel != LogLevel::NONE
    and self._logLevel != LogLevel::ERROR) {
    self.log(log);
  }
}

void LoggerInterface::info(std::string log) {
  if (self._logLevel == LogLevel::INFO) {
    self.log(log);
  }
}

std::string LoggerInterface::format(std::string log) {
  time = std::chrono::system_clock::now();
  return 
}

void Logger::log(std::string log) {
  std::lock_guard<std::mutex> lock_guard(_mutex);
  _fileStream << log;
}


