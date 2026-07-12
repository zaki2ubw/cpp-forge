#include <iostream>

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Constructor & Destructor
AForm::AForm(const std::string &name, int signGrade, int execGrade)
    : name_(name), isSigned_(false), signGrade_(signGrade),
      execGrade_(execGrade) {
  if (name_.empty())
    throw std::invalid_argument("Name must be set");
  if (signGrade_ < GRADEHIGHLIMIT || execGrade_ < GRADEHIGHLIMIT)
    throw AForm::GradeTooHighException();
  if (signGrade_ > GRADELOWLIMIT || execGrade_ > GRADELOWLIMIT)
    throw AForm::GradeTooLowException();
}

// Exception Class Definisions
const char *AForm::GradeTooHighException::what() const throw() {
  return "[ERROR] Grade must be lower than 1";
}

const char *AForm::GradeTooLowException::what() const throw() {
  return "[ERROR] Grade must be higher than 150";
}

const char *AForm::FormAlreadySignedException::what() const throw() {
  return "This Form is already signed";
}

const char *AForm::LessGradeToSignException::what() const throw() {
  return "To sign this, you must get higher grade than now";
}

const char *AForm::LessGradeToExecuteException::what() const throw() {
  return "To execute this, you must get higher grade than now";
}

// Required Functions
void AForm::beSigned(const Bureaucrat &br) {
  if (this->isSigned_) {
    throw FormAlreadySignedException();
    return;
  } else if (!this->isAbleToSign(br)) {
    throw LessGradeToSignException();
    return;
  } else {
    this->isSigned_ = true;
    return;
  }
}

int AForm::getSignGrade() const { return this->signGrade_; }

int AForm::getExecGrade() const { return this->execGrade_; }

const std::string &AForm::getName() const { return this->name_; }

bool AForm::getFormIsSigned() const { return this->isSigned_; }

bool AForm::isAbleToSign(const Bureaucrat &br) const {
  if (br.getGrade() <= this->signGrade_)
    return true;
  else
    return false;
}

bool AForm::isAbleToExec(const Bureaucrat &br) const {
  if (br.getGrade() <= this->execGrade_)
    return true;
  else
    return false;
}

std::ostream &operator<<(std::ostream &os, const AForm &fo) {
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
