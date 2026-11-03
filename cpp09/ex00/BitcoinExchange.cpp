#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>
#include <string>
#include <utility>

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
    : rates(src.rates) {}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &src) {
  if (this != &src)
    rates = src.rates;
  return *this;
}

BitcoinExchange::~BitcoinExchange() {}

double BitcoinExchange::findRate(const std::string &date) const {
  std::map<std::string, double>::const_iterator it = rates.lower_bound(date);

  if (it != rates.end() && it->first == date)
    return it->second;

  if (it == rates.begin())
    throw std::runtime_error("Error: no earlier date available.");

  --it;
  return it->second;
}

void BitcoinExchange::loadDatabase(const std::string &filename) {
  std::ifstream ifs(filename.c_str());

  if (!ifs.is_open())
    throw std::runtime_error("Error: could not open database.");

  std::string line;

  if (!std::getline(ifs, line))
    throw std::runtime_error("Error: invalid database.");

  if (line != "date,exchange_rate")
    throw std::runtime_error("Error: invalid database header.");

  while (std::getline(ifs, line)) {
    if (line.empty())
      throw std::runtime_error("Error: invalid database line.");

    std::string::size_type comma = line.find(',');
    if (comma == std::string::npos)
      throw std::runtime_error("Error: invalid database line.");

    std::string date = line.substr(0, comma);
    std::string rateString = line.substr(comma + 1);

    if (date.empty() || rateString.empty())
      throw std::runtime_error("Error: invalid database line.");

    if (!isValidDate(date))
      throw std::runtime_error("Error: invalid database date.");

    std::stringstream ss(rateString);
    double rate;

    if (!(ss >> rate))
      throw std::runtime_error("Error: invalid database rate.");

    char extra;
    if (ss >> extra)
      throw std::runtime_error("Error: invalid database rate.");

    if (rate < 0)
      throw std::runtime_error("Error: invalid database rate.");

    if (!rates.insert(std::make_pair(date, rate)).second)
      throw std::runtime_error("Error: duplicate database date.");
  }

  if (!ifs.eof())
    throw std::runtime_error("Error: database read failure.");

  if (rates.empty())
    throw std::runtime_error("Error: database is empty.");
}

bool BitcoinExchange::parseInputLine(const std::string &line, std::string &date,
                                     double &value) const {
  std::string::size_type sep = line.find('|');

  if (sep == std::string::npos)
    return false;

  date = line.substr(0, sep);
  std::string valueString = line.substr(sep + 1);

  while (!date.empty() && date[date.size() - 1] == ' ')
    date.erase(date.size() - 1);

  while (!valueString.empty() && valueString[0] == ' ')
    valueString.erase(0, 1);

  if (date.empty() || valueString.empty())
    return false;

  std::stringstream ss(valueString);

  if (!(ss >> value))
    return false;

  char extra;
  if (ss >> extra)
    return false;

  return true;
}

bool BitcoinExchange::isValidDate(const std::string &date) const {
  if (date.size() != 10)
    return false;

  if (date[4] != '-' || date[7] != '-')
    return false;

  for (std::string::size_type i = 0; i < date.size(); ++i) {
    if (i == 4 || i == 7)
      continue;

    if (date[i] < '0' || date[i] > '9')
      return false;
  }

  int year;
  int month;
  int day;
  char dash1;
  char dash2;

  std::stringstream ss(date);

  if (!(ss >> year >> dash1 >> month >> dash2 >> day))
    return false;

  char extra;
  if (ss >> extra)
    return false;

  if (dash1 != '-' || dash2 != '-')
    return false;

  if (month < 1 || month > 12)
    return false;

  int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  bool isLeapYear = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);

  if (isLeapYear)
    daysInMonth[1] = 29;

  if (day < 1 || day > daysInMonth[month - 1])
    return false;

  return true;
}

void BitcoinExchange::processInput(const std::string &filename) const {
  std::ifstream ifs(filename.c_str());

  if (!ifs.is_open())
    throw std::runtime_error("Error: could not open file.");

  std::string line;

  if (!std::getline(ifs, line))
    return;

  if (line != "date | value")
    throw std::runtime_error("Error: invalid input header.");

  while (std::getline(ifs, line)) {
    try {
      std::string date;
      double value;

      if (!parseInputLine(line, date, value))
        throw std::runtime_error("Error: bad input => " + line);

      if (!isValidDate(date))
        throw std::runtime_error("Error: bad input => " + line);

      if (value < 0)
        throw std::runtime_error("Error: not a positive number.");

      if (value > 1000)
        throw std::runtime_error("Error: too large a number.");

      double rate = findRate(date);

      std::cout << date << " => " << value << " = " << value * rate
                << std::endl;

    } catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

  if (!ifs.eof())
    throw std::runtime_error("Error: input file read failure.");
}
