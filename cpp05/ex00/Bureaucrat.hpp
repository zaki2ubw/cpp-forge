#pragma once

#include <exception>
#include <ostream>
#include <stdexcept>
#include <string>

// This is Inheritance from std::exception version
class Bureaucrat {
public:
  // Constructor & Destructor
  Bureaucrat(const std::string &name, int grade);
  ~Bureaucrat();

  // Getter
  const std::string &getName() const;
  int getGrade() const;

  // Requirement Upper/Lower Functions
  void incrementGrade();
  void decrementGrade();

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

//// This is Inheritance from std::logic_error version
// class Bureaucrat {
// public:
//   // Constructor & Destructor
//   Bureaucrat(const std::string &name, int grade);
//   ~Bureaucrat();
//
//   // Getter
//   const std::string &getName() const;
//   int getGrade() const;
//
//   // Requirement Upper/Lower Functions
//   void incrementGrade();
//   void decrementGrade();
//
//   // Exception class definition
//   class OutOfRangeException : public std::logic_error {
//   public:
//     OutOfRangeException(int grade);
//   };
//
// private:
//   // Requirement Members
//   const std::string name_;
//   int grade_;
//
//   // Exception Helper
//   static std::string makeErrMsg(int grade);
//
//   // Forbidden OCF Functions
//   Bureaucrat();
//   Bureaucrat(const Bureaucrat &src);
//   Bureaucrat &operator=(const Bureaucrat &src);
// };

std::ostream &operator<<(std::ostream &os, const Bureaucrat &br);
