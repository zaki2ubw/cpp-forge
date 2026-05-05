/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 15:26:22 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/05 19:14:30 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Logger.hpp"


const char*	Logger::red = "\033[31m";
const char*	Logger::green = "\033[32m";
const char*	Logger::blue = "\033[34m";
const char*	Logger::yellow = "\033[33m";
const char*	Logger::cyan = "\033[36m";
const char*	Logger::magenta = "\033[35m";
const char*	Logger::reset = "\033[0m";

void		Logger::construct(const std::string& msg)
{
	appLog(CONSTRUCT, msg);
	return ;
}

void		Logger::destruct(const std::string& msg)
{
	appLog(DESTRUCT, msg);
	return ;
}

void		Logger::action(const std::string& msg)
{
	appLog(ACTION, msg);
	return ;
}

void		Logger::Info(const std::string& key, const std::string& str)
{
	appInfo(key, str);
	return ;
}

void		Logger::Info(const std::string& key, int num)
{
	std::stringstream ss;
	ss << num;
	appInfo(key, ss.str());
	return ;
}

void		Logger::sysInfo(const std::string& msg)
{
	sysLog(SYSINFO, msg);
	return ;
}

void		Logger::warning(const std::string& msg)
{
	sysLog(WARNING, msg);
	return ;
}

void		Logger::error(const std::string& msg)
{
	sysLog(ERROR, msg);
	return ;
}

void		Logger::sysLog(Level level, const std::string& msg)
{
	std::string	label = std::string("[") + levelName(level) + "]";

	std::cout << levelColor(level)
			  << std::left << std::setw(PREFIX_WIDTH)
			  << label << msg << reset << std::endl;
}

void		Logger::appLog(Level level, const std::string& msg)
{
	std::string	label = std::string("[") + levelName(level) + "]";

	std::cout << std::string(PREFIX_WIDTH, ' ')
			  << levelColor(level)
			  << std::left << std::setw(PREFIX_WIDTH)
			  << label << msg << reset << std::endl;
}

void		Logger::appInfo(const std::string& key, const std::string& val)
{
	std::cout << std::string(PREFIX_WIDTH, ' ')
			  << levelColor(APPINFO)
			  << std::left << std::setw(PREFIX_WIDTH)
			  << "[INFO]"
			  << std::left << std::setw(KEY_WIDTH)
			  << key << " : " << val << reset << std::endl;
}

const char*	Logger::levelName(Level level)
{
	switch (level)
	{
		case SYSINFO:
			return "SYSINFO";
		case WARNING:
			return "WARNING";
		case ERROR:
			return "ERROR";
		case CONSTRUCT:
			return "CONSTRUCT";
		case DESTRUCT:
			return "DESTRUCT";
		case ACTION:
			return "ACTION";
		case APPINFO:
			return "INFO";
		default:
			return "";
	}
}

const char*	Logger::levelColor(Level level)
{
	switch (level)
	{
		case ERROR:
			return red;
		case WARNING:
			return yellow;
		case SYSINFO:
			//fallthrough
		case APPINFO:
			return green;
		case CONSTRUCT:
			//fallthrough
		case DESTRUCT:
			return magenta;
		case ACTION:
			return cyan;
		default:
			return reset;
	}
}


Logger::Logger()
{
}

Logger::Logger(const Logger& src)
{
	(void)src;
}

Logger::~Logger()
{
}

Logger&		Logger::operator=(const Logger& src)
{
	(void)src;
	return *this;
}
