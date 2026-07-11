#include <cstdlib>
#include <ctime>
#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main(void) {
  std::srand(std::time(NULL));
  try {
    {
      std::cout << "===CASE1===" << std::endl;
      AForm *form1 = new ShrubberyCreationForm("target1");
      AForm *form2 = new RobotomyRequestForm("target1");
      AForm *form3 = new PresidentialPardonForm("target1");
      Bureaucrat test1("Akamatsu", 150);
      test1.signForm(*form1);
      test1.executeForm(*form1);
      test1.signForm(*form2);
      test1.executeForm(*form2);
      test1.signForm(*form3);
      test1.executeForm(*form3);
      delete form1;
      delete form2;
      delete form3;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    }
    {
      std::cout << "===CASE2===" << std::endl;
      AForm *form1 = new ShrubberyCreationForm("target2");
      AForm *form2 = new RobotomyRequestForm("target2");
      AForm *form3 = new PresidentialPardonForm("target2");
      Bureaucrat test2("Denda", 142);
      test2.signForm(*form1);
      test2.executeForm(*form1);
      test2.signForm(*form2);
      test2.executeForm(*form2);
      test2.signForm(*form3);
      test2.executeForm(*form3);
      delete form1;
      delete form2;
      delete form3;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    }
    {
      std::cout << "===CASE3===" << std::endl;
      AForm *form1 = new ShrubberyCreationForm("target3");
      AForm *form2 = new RobotomyRequestForm("target3");
      AForm *form3 = new PresidentialPardonForm("target3");
      Bureaucrat test3("Endou", 136);
      test3.signForm(*form1);
      test3.executeForm(*form1);
      test3.signForm(*form2);
      test3.executeForm(*form2);
      test3.signForm(*form3);
      test3.executeForm(*form3);
      delete form1;
      delete form2;
      delete form3;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    }
    {
      std::cout << "===CASE4===" << std::endl;
      AForm *form1 = new ShrubberyCreationForm("target4");
      AForm *form2 = new RobotomyRequestForm("target4");
      AForm *form3 = new PresidentialPardonForm("target4");
      Bureaucrat test4("Fuwa", 71);
      test4.signForm(*form1);
      test4.executeForm(*form1);
      test4.signForm(*form2);
      test4.executeForm(*form2);
      test4.signForm(*form3);
      test4.executeForm(*form3);
      delete form1;
      delete form2;
      delete form3;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    }
    {
      std::cout << "===CASE5===" << std::endl;
      AForm *form1 = new ShrubberyCreationForm("target5");
      AForm *form2 = new RobotomyRequestForm("target5");
      AForm *form3 = new PresidentialPardonForm("target5");
      Bureaucrat test5("Gouda", 42);
      test5.signForm(*form1);
      test5.executeForm(*form1);
      test5.signForm(*form2);
      test5.executeForm(*form2);
      test5.signForm(*form3);
      test5.executeForm(*form3);
      delete form1;
      delete form2;
      delete form3;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    }
    {
      std::cout << "===CASE6===" << std::endl;
      AForm *form1 = new ShrubberyCreationForm("target6");
      AForm *form2 = new RobotomyRequestForm("target6");
      AForm *form3 = new PresidentialPardonForm("target6");
      Bureaucrat test6("Honekawa", 21);
      test6.signForm(*form1);
      test6.executeForm(*form1);
      test6.signForm(*form2);
      test6.executeForm(*form2);
      test6.signForm(*form3);
      test6.executeForm(*form3);
      delete form1;
      delete form2;
      delete form3;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    }
    {
      std::cout << "===CASE7===" << std::endl;
      AForm *form1 = new ShrubberyCreationForm("target7");
      AForm *form2 = new RobotomyRequestForm("target7");
      AForm *form3 = new PresidentialPardonForm("target7");
      Bureaucrat test7("Iida", 3);
      test7.signForm(*form1);
      test7.executeForm(*form1);
      test7.signForm(*form2);
      test7.executeForm(*form2);
      test7.signForm(*form3);
      test7.executeForm(*form3);
      delete form1;
      delete form2;
      delete form3;
      std::cout << "===========" << std::endl;
      std::cout << std::endl;
    }
  } catch (const std::exception &e) {
    std::cout << e.what() << std::endl;
  }
  return 0;
}
