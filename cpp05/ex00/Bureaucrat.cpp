#include "Bureaucrat.hpp"
#include <sstream>

Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name_(name), grade_(grade) {
  if (name_.empty())
    throw std::invalid_argument("Name must be set");
  if (this->grade_ < 1)
    throw GradeTooHighException();
  if (this->grade_ > 150)
    throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const { return this->name_; }

int Bureaucrat::getGrade() const { return this->grade_; }

void Bureaucrat::incrementGrade() {
  if (grade_ <= 1) {
    throw GradeTooHighException();
  }
  --grade_;
  return;
}

void Bureaucrat::decrementGrade() {
  if (grade_ >= 150) {
    throw GradeTooLowException();
  }
  ++grade_;
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
