#include "Logger.h"

LoggerInterface::LoggerInterface(LoggerInterface& logInterface, std::string name) {
  _name = logInterface._name + name;
  _pLogger = logInterface._pLogger;
}

LoggerInterface::LoggerInterface(std::string fileName, std::string name) {
  _name = name;
  _pLogger = std::make_shared<Logger>(fileName);
}

LoggerInterface::~LoggerInterface() {

}

void LoggerInterface::setLogLevel(LogLevel level) {
  _logLevel = level;
}

void LoggerInterface::error(std::string msg) {
  if (_logLevel != LogLevel::NONE) {
    _pLogger->log(format(msg));
  }
}

void LoggerInterface::debug(std::string msg) {
  if (_logLevel != LogLevel::NONE
      && _logLevel != LogLevel::ERROR) {
    _pLogger->log(format(msg));
  }
}

void LoggerInterface::info(std::string msg) {
  if (_logLevel == LogLevel::INFO) {
    _pLogger->log(format(msg));
  }
}

std::string LoggerInterface::format(std::string msg) {
  return "[" + _name + "]: " + msg;
}

void Logger::log(std::string log) {
  std::lock_guard<std::mutex> lock_guard(_mutex);
  _fileStream << log;
}

Logger::Logger(std::string fileName) {
  _fileStream.open(fileName);
}

Logger::~Logger() {
  _fileStream.close();
}