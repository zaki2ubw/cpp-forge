#include <cstdlib>
#include <iostream>

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(const std::string &target)
    : AForm("RobotomyRequestForm", 72, 45), target_(target) {
  if (target_.empty())
    throw std::invalid_argument("Target must be set");
}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
  if (!this->isAbleToExec(executor))
    throw AForm::LessGradeToExecuteException();
  else if (!this->isRobotomizeSucceed())
    std::cout << this->target_ << " has not been robotomized, sorry"
              << std::endl;
  else
    std::cout << this->target_ << " has been robotomized successfully"
              << std::endl;
  return;
}

bool RobotomyRequestForm::isRobotomizeSucceed() const {
  if (std::rand() % 2 == 0)
    return true;
  else
    return false;
}
