#pragma once

#include <exception>
#include <string>

class Form {
public:
  // Constructor & Destructor
  Form(const std::string &name, int signGrade, int execGrade);
  ~Form();
  // Exception Class Definisions
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  };
  // Required Interface Functions
  bool beSigned(const Bureaucrat &br);
  int getSignGrade() const;
  int getExecGrade() const;

private:
  // Required Member valiable
  const std::string name_;
  bool signed_;
  const int signGrade_;
  const int execGrade_;

  // Forbidden OCF Functions
  Form();
  Form(const Form &src);
  Form &operator=(const Form &src);
}
