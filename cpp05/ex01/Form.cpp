#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor & Destructor
Form::Form(const std::string &name, int signGrade, int execGrade)
    : name_(name), signGrade_(signGrade), execGrade_(execGrade) {
  if (signGrade_ < GRADEHIGHLIMIT || execGrade_ < GRADEHIGHLIMIT)
    throw Form::GradeTooHighException();
  if (signGrade_ > GRADELOWLIMIT || execGrade_ > GRADELOWLIMIT)
    throw Form::GradeTooHighException();
}

Form::~Form() {}

// Exception Class Definisions
const char *Form::GradeTooHighException::what() const throw() {
  return "[ERROR] Grade must be lower than 1";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "[ERROR] Grade must be higher than 150";
}

// Required Interface Functions
bool Form::beSigned(const Bureaucrat &br) {
  if (br.getGrade() < this->signGrade_)
    throw this->GradeTooLowException();
}

int Form::getSignGrade() const {}

int Form::getExecGrade() const {}
