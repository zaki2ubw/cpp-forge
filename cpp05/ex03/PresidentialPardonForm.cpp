#include <iostream>

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string &target)
    : AForm("PresidentialPardonForm", 25, 5), target_(target) {
  if (target_.empty())
    throw std::invalid_argument("Target must be set");
}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const {
  if (!isAbleToExec(executor))
    throw AForm::LessGradeToExecuteException();
  else
    std::cout << this->target_ << " has been pardoned by Zaphod Beeblebrox"
              << std::endl;
  return;
}
