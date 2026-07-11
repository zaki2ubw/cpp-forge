#include <iostream>
#include <sstream>

#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name_(name), grade_(grade) {
  if (this->grade_ < GRADEHIGHLIMIT)
    throw GradeTooHighException();
  if (this->grade_ > GRADELOWLIMIT)
    throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return this->name_; }

int Bureaucrat::getGrade() const { return this->grade_; }

void Bureaucrat::incrementGrade() {
  if (grade_ <= GRADEHIGHLIMIT) {
    throw GradeTooHighException();
  }
  --grade_;
  return;
}

void Bureaucrat::decrementGrade() {
  if (grade_ >= GRADELOWLIMIT) {
    throw GradeTooLowException();
  }
  ++grade_;
  return;
}

void Bureaucrat::signForm(Form &form) {
  try {
    form.beSigned(*this);
    std::cout << this->name_ << " signed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cout << this->name_ << " couldn't sign " << form.getName()
              << std::endl;
    std::cout << " [REASON] " << e.what() << std::endl;
  }
  return;
}

const char *Bureaucrat::GradeTooHighException::what() const throw() {
  return "[ERROR] Grade must be lower than 1";
}

const char *Bureaucrat::GradeTooLowException::what() const throw() {
  return "[ERROR] Grade must be higher than 150";
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat &br) {
  os << br.getName() << ", bureaucrat grade " << br.getGrade();
  return os;
}
