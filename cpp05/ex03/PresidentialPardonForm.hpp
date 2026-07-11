#pragma once

#include <string>

#include "AForm.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm {
public:
  // Constructor & Destructor
  PresidentialPardonForm(const std::string &target);
  virtual ~PresidentialPardonForm();
  // Interface
  virtual void execute(Bureaucrat const &executor) const;

private:
  std::string target_;

  // Forbidden OCF Functions
  PresidentialPardonForm();
  PresidentialPardonForm(const PresidentialPardonForm &src);
  PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
};
