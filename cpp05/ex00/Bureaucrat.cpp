#include "Bureaucrat.hpp"
#include <sstream>

// This is Inheritance from std::exception version
Bureaucrat::Bureaucrat(const std::string &name, int grade)
    : name_(name), grade_(grade) {
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

//// This is Inheritance from std::logic_error version
// Bureaucrat::Bureaucrat(const std::string &name, int grade)
//     : name_(name), grade_(grade) {
//   if (this->grade_ > 150 || this->grade_ < 1)
//     throw OutOfRangeException(this->grade_);
// }
//
// Bureaucrat::~Bureaucrat() {}
//
// const std::string &Bureaucrat::getName() const { return this->name_; }
//
// int Bureaucrat::getGrade() const { return this->grade_; }
//
// void Bureaucrat::incrementGrade() {
//   if (grade_ <= 1) {
//     throw OutOfRangeException(grade_);
//   }
//   --grade_;
//   return;
// }
//
// void Bureaucrat::decrementGrade() {
//   if (grade_ >= 150) {
//     throw OutOfRangeException(grade_);
//   }
//   ++grade_;
//   return;
// }
//
// Bureaucrat::OutOfRangeException::OutOfRangeException(int grade)
//     : std::logic_error(makeErrMsg(grade)) {}
//
// std::string Bureaucrat::makeErrMsg(int grade) {
//   std::ostringstream oss;
//   oss << "Invalid Grade: " << grade;
//   return oss.str();
// }

std::ostream &operator<<(std::ostream &os, const Bureaucrat &br) {
  os << br.getName() << ", bureaucrat grade " << br.getGrade();
  return os;
}
