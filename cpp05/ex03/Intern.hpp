#pragma once

#include <string>

#include "AForm.hpp"

class Intern {
public:
  // Constructor & Destructor
  Intern();
  ~Intern();
  // Requirement Functions
  AForm *makeForm(const std::string &formName, const std::string &target) const;

private:
  int formNameToNumber(const std::string formList[],
                       const std::string &formName) const;
  enum e_forms { INVALIDFORM = 0, SHRUBBERY, ROBOTOMY, PRESIDENT, FORMCOUNT };

  static const std::string formList[FORMCOUNT];

  // Forbidden OCF Functions
  Intern(const Intern &src);
  Intern &operator=(const Intern &src);
};
