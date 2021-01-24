#include "Logger.h"

Logger::Logger(){
}
Logger::~Logger(){
}

std::string stringify(const LogSeverity severity){
	std::map<LogSeverity, std::string>S_SEVERITY_MAP = {
		{LogSeverity::error, "ERROR"},
		{LogSeverity::warning, "WARNING"},
		{LogSeverity::info, "INFO"},
		{LogSeverity::debug, "DEBUG"},
	};

	std::string result = "NONE";
	auto it = S_SEVERITY_MAP.find(severity);
	if(it != S_SEVERITY_MAP.end()){
		result = it->second;
	}
	return result;
}

void Logger::init(const std::string& filename, const LogOutput output){
	m_filename = filename;
	m_output = output;
}
void Logger::open(){
	if(m_output == LogOutput::everywhere || m_output == LogOutput::file){
		m_file.open(m_filename, std::ios::out);
		m_isOpened = m_file.is_open();

		if(!m_isOpened){
			throw std::runtime_error("Couldnt open a log file");
		}
	}
	m_isOpened = true;
}
void Logger::close(){
	if(m_output == LogOutput::everywhere || m_output == LogOutput::file){
		m_file.close();
	}
}
void Logger::flush(){
	if(m_output == LogOutput::everywhere || m_output == LogOutput::file){
		m_file.flush();
	}
}

void Logger::log(const std::string& msg, const LogSeverity severity){
	std::string result = timestamp() +
		" " + threadId() +
		" " + stringify(severity) +
		" " + msg;

	if(m_output == LogOutput::console){
		std::cout << result << std::endl;
	}
	if(m_output == LogOutput::file){
		m_file << result << std::endl;
	} else{
		std::cout << result << std::endl;
		m_file << result << std::endl;
	}
}

/////////////////// PRIVATE

std::string Logger::timestamp(){
	using namespace std::chrono;

	auto now = system_clock::now();
	time_t tt = system_clock::to_time_t(now);

	auto ms = duration_cast<milliseconds>(now.time_since_epoch()) % 1000;

	std::stringstream ss;
	ss << std::put_time(std::localtime(&tt), "%F %T");
	ss << "." << std::setfill('0') << std::setw(3) << ms.count();

	return ss.str();
}

std::string Logger::threadId(){
	std::stringstream ss;
	ss << std::this_thread::get_id();
	return ss.str();
}