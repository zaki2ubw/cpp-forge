#include "Form.hpp"
#include "Bureaucrat.hpp"

// Constructor & Destructor
Form::Form(const std::string &name, int signGrade, int execGrade)
    : name_(name), signGrade_(signGrade), execGrade_(execGrade),
      isSigned_(false) {
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

const char *Form::FormAlreadySignedException::what() const throw() {
  return "This Form is already signed";
}

// Required Interface Functions
void Form::beSigned(const Bureaucrat &br) {
  if (this->isSigned_) {
    throw this->FormAlreadySignedException();
  } else if (br.getGrade() < this->signGrade_) {
    throw this->GradeTooLowException();
  } else {
    this->isSigned_ = true;
  }
}

int Form::getSignGrade() const { return this->signGrade_; }

int Form::getExecGrade() const { return this->execGrade_; }

std::ostream &operator<<(std::ostream &os, const Form &fo) {
  os << fo.getName() << ",  requires higher than " << fo.getSignGrade()
     << " grade to sign this" << ", and requires higher than "
     << fo.getExecGrade() << " grade to execute this";
  return os;
}
