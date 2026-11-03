#pragma once

#include <map>
#include <string>

class BitcoinExchange {
public:
  BitcoinExchange();
  BitcoinExchange(const BitcoinExchange &src);
  BitcoinExchange &operator=(const BitcoinExchange &src);
  ~BitcoinExchange();

  void loadDatabase(const std::string &filename);
  void processInput(const std::string &filename) const;

private:
  std::map<std::string, double> rates;

  bool parseInputLine(const std::string &line, std::string &date,
                      double &value) const;

  bool isValidDate(const std::string &date) const;
  double findRate(const std::string &date) const;
};
