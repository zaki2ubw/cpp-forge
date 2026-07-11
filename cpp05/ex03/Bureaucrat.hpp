#pragma once

#include <exception>
#include <ostream>
#include <stdexcept>
#include <string>

#define GRADEHIGHLIMIT 1
#define GRADELOWLIMIT 150

class AForm;

// This is Inheritance from std::exception version
class Bureaucrat {
public:
  // Constructor & Destructor
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();

  // Getter
  const std::string &getName() const;
  int getGrade() const;

  // Requirement Functions
  void incrementGrade();
  void decrementGrade();
  void signForm(AForm &form);
  void executeForm(AForm const &form) const;

  // Exception class definition
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };

private:
  // Requirement Members
  const std::string name_;
  int grade_;

  // Forbidden OCF Functions
  Bureaucrat();
  Bureaucrat(const Bureaucrat &src);
  Bureaucrat &operator=(const Bureaucrat &src);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat &br);
