#pragma once
#pragma warning(disable : 4996)
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <ctime>
#include <chrono>
#include <thread>
#include <time.h>

enum class LogSeverity{
	error,
	warning,
	info,
	debug
};

enum class LogOutput{
	console,
	file,
	everywhere
};

class Logger{
public:
	// Constructor & Destructor
	Logger();
	~Logger();

	void init(const std::string& filename, const LogOutput output = LogOutput::everywhere);

	void open();

	void close();

	void flush();

	void log(const std::string& msg, const LogSeverity severity);

private:
	static std::string timestamp();
	static std::string threadId();

	std::string m_filename;
	std::fstream m_file;
	LogOutput m_output = LogOutput::everywhere;

	bool m_isOpened = false;
};