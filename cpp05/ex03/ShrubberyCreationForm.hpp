#pragma once

#include <string>

#include "AForm.hpp"

class Bureaucrat;

class ShrubberyCreationForm : public AForm {
public:
  // Constructor & Destructor
  ShrubberyCreationForm(const std::string &target);
  virtual ~ShrubberyCreationForm();
  // Interface
  virtual void execute(Bureaucrat const &executor) const;

private:
  std::string target_;

  // Helper
  bool putShrubberyToTarget() const;
  bool fileExists(const std::string &fileName) const;

  // Forbidden OCF Functions
  ShrubberyCreationForm();
  ShrubberyCreationForm(const ShrubberyCreationForm &src);
  ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
};
