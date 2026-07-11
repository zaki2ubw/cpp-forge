#pragma once

#include <string>

#include "AForm.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm {
public:
  // Constructor & Destructor
  RobotomyRequestForm(const std::string &target);
  virtual ~RobotomyRequestForm();

  // Interface
  virtual void execute(Bureaucrat const &executor) const;

private:
  std::string target_;

  // Helper
  bool isRobotomizeSucceed() const;

  // Forbidden OCF Functions
  RobotomyRequestForm();
  RobotomyRequestForm(const RobotomyRequestForm &src);
  RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
};
