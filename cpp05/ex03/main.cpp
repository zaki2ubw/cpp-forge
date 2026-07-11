#include <cstdlib>
#include <ctime>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  std::srand(std::time(NULL));
  try {
    {
      std::cout << "===CASE1===" << std::endl;
      Intern intern;
      AForm *scf;
      AForm *rrf;
      AForm *ppf;
      AForm *inv;
      scf = intern.makeForm("shurbbery creation", "target1");
      rrf = intern.makeForm("robotomy request", "target1");
      ppf = intern.makeForm("presidential pardon", "target1");
      inv = intern.makeForm("42Toyko", "target1");
      Bureaucrat test1("Endou", 136);
      if (scf != NULL) {
        test1.signForm(*scf);
        test1.executeForm(*scf);
      }
      if (rrf != NULL) {
        test1.signForm(*rrf);
        test1.executeForm(*rrf);
      }
      if (ppf != NULL) {
        test1.signForm(*ppf);
        test1.executeForm(*ppf);
      }
      if (inv != NULL) {
        test1.signForm(*inv);
        test1.executeForm(*inv);
      }
      delete scf;
      delete rrf;
      delete ppf;
      delete inv;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    }
    {
      std::cout << "===CASE2===" << std::endl;
      Intern intern;
      AForm *scf;
      AForm *rrf;
      AForm *ppf;
      AForm *inv;
      scf = intern.makeForm("shurbbery creation", "target2");
      rrf = intern.makeForm("robotomy request", "target2");
      ppf = intern.makeForm("presidential pardon", "target2");
      inv = intern.makeForm("42Toyko", "target2");
      Bureaucrat test2("Gouda", 42);
      if (scf != NULL) {
        test2.signForm(*scf);
        test2.executeForm(*scf);
      }
      if (rrf != NULL) {
        test2.signForm(*rrf);
        test2.executeForm(*rrf);
      }
      if (ppf != NULL) {
        test2.signForm(*ppf);
        test2.executeForm(*ppf);
      }
      if (inv != NULL) {
        test2.signForm(*inv);
        test2.executeForm(*inv);
      }
      delete scf;
      delete rrf;
      delete ppf;
      delete inv;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    }
    {
      std::cout << "===CASE3===" << std::endl;
      Intern intern;
      AForm *scf;
      AForm *rrf;
      AForm *ppf;
      AForm *inv;
      scf = intern.makeForm("shurbbery creation", "target3");
      rrf = intern.makeForm("robotomy request", "target3");
      ppf = intern.makeForm("presidential pardon", "target3");
      inv = intern.makeForm("42Toyko", "target3");
      Bureaucrat test3("Iida", 3);
      if (scf != NULL) {
        test3.signForm(*scf);
        test3.executeForm(*scf);
      }
      if (rrf != NULL) {
        test3.signForm(*rrf);
        test3.executeForm(*rrf);
      }
      if (ppf != NULL) {
        test3.signForm(*ppf);
        test3.executeForm(*ppf);
      }
      if (inv != NULL) {
        test3.signForm(*inv);
        test3.executeForm(*inv);
      }
      delete scf;
      delete rrf;
      delete ppf;
      delete inv;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    }
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
