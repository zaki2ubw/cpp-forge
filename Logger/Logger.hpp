/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Logger.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohyamaz <sohyamaz@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/05 14:38:12 by sohyamaz          #+#    #+#             */
/*   Updated: 2026/05/05 19:18:05 by sohyamaz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <string>
# include <iostream>
# include <iomanip>
# include <sstream>

class Logger
{
	public :
		//APPLOG
		static void			construct(const std::string& msg);
		static void			destruct(const std::string& msg);
		static void			action(const std::string& msg);
		static void			Info(const std::string& key, const std::string& str);
		static void			Info(const std::string& key, int num);

		//SYSTEMLOG
		static void			sysInfo(const std::string& msg);
		static void			warning(const std::string& msg);
		static void 		error(const std::string& msg);

	private :
		//LogLevel
		enum Level
		{
			SYSINFO,
			WARNING,
			ERROR,
			CONSTRUCT,
			DESTRUCT,
			APPINFO,
			ACTION
		};

		enum
		{
			PREFIX_WIDTH = 12,
			KEY_WIDTH = 5
		};

		//Constructor & Destructor
		Logger();
		Logger(const Logger& src);
		~Logger();
		Logger&				operator=(const Logger& src);

		//Funcitons
		static void			sysLog(Level level, const std::string& msg);
		static void			appLog(Level level, const std::string& msg);
		static void			appInfo(const std::string& key, const std::string& val);
		static const char*	levelName(Level level);
		static const char*	levelColor(Level level);

		//Static Variables
		static const char*	red;
		static const char*	green;
		static const char*	blue;
		static const char*	yellow;
		static const char*	cyan;
		static const char*	magenta;
		static const char*	reset;
};
