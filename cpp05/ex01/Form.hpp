#pragma once

#include <exception>
#include <string>

class Form {
public:
  Form(const std::string &name, int signGrade, int execGrade);
  ~Form();
  class GradeTooHighException : public std::exception {
  public:
    const char *what() const throw();
  };
  class GradeTooLowException : public std::exception {
  public:
    const char *what() const throw();
  } bool beSigned();
  int getSignGrade() const;
  int getExecGrade() const;

private:
  const std::string name_;
  bool signed_;
  const int signGrade_;
  const int execGrade_;
  Form();
  Form(const Form &src);
  Form &operator=(const Form &src);
}
