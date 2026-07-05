#include <iostream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

// Constructor & Destructor
Form::Form(const std::string &name, int signGrade, int execGrade)
    : name_(name), isSigned_(false), signGrade_(signGrade),
      execGrade_(execGrade) {
  if (signGrade_ < GRADEHIGHLIMIT || execGrade_ < GRADEHIGHLIMIT)
    throw Form::GradeTooHighException();
  if (signGrade_ > GRADELOWLIMIT || execGrade_ > GRADELOWLIMIT)
    throw Form::GradeTooLowException();
}

Form::~Form() {}

// Exception Class Definisions
const char *Form::GradeTooHighException::what() const throw() {
  return "[ERROR] Grade must be lower than 1";
}

const char *Form::GradeTooLowException::what() const throw() {
  return "[ERROR] Grade must be higher than 150";
}

const char *Form::FormAlreadySignedException::what() const throw() {
  return "This Form is already signed";
}

// Required Interface Functions
void Form::beSigned(const Bureaucrat &br) {
  if (this->isSigned_) {
    throw FormAlreadySignedException();
  } else if (br.getGrade() > this->signGrade_) {
    std::cout << br.getName() << " has not enough grade to sign Form."
              << std::endl;
  } else {
    this->isSigned_ = true;
  }
}

int Form::getSignGrade() const { return this->signGrade_; }

int Form::getExecGrade() const { return this->execGrade_; }

const std::string &Form::getName() const { return this->name_; }

bool Form::getFormIsSigned() const { return this->isSigned_; }

std::ostream &operator<<(std::ostream &os, const Form &fo) {
  os << "This is the Form Named " << fo.getName() << std::endl
     << "It requires higher than " << fo.getSignGrade() << " grade to sign."
     << std::endl
     << "It requires higher than " << fo.getExecGrade() << " grade to execute."
     << std::endl;
  if (fo.getFormIsSigned())
    os << "This Form is Already signed.";
  else
    os << "This Form is not signed yet.";
  return os;
}
