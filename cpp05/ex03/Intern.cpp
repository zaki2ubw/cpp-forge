#include <iostream>

#include "AForm.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

const std::string Intern::formList[Intern::FORMCOUNT] = {
    "invalid form", "shurbbery creation", "robotomy request",
    "presidential pardon"};

Intern::Intern() {}

Intern::~Intern() {}

AForm *Intern::makeForm(const std::string &formName,
                        const std::string &target) const {
  int formNumber = formNameToNumber(formList, formName);
  AForm *form = NULL;

  switch (formNumber) {
  case SHRUBBERY:
    form = new ShrubberyCreationForm(target);
    break;
  case ROBOTOMY:
    form = new RobotomyRequestForm(target);
    break;
  case PRESIDENT:
    form = new PresidentialPardonForm(target);
    break;
  default:
    std::cout << "[ERROR]: " << formName << " isn't existing form" << std::endl;
  }
  return form;
}

int Intern::formNameToNumber(const std::string formList[],
                             const std::string &formName) const {
  for (int i = 0; i < FORMCOUNT; ++i) {
    if (formList[i] == formName)
      return i;
  }
  return INVALIDFORM;
}
