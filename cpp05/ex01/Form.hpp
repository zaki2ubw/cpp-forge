#pragma once

#include <exception>
#include <string>

class Bureaucrat;

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
  class FormAlreadySignedException : public std::exception {
  public:
    const char *what() const throw();
  };
  class LessGradeToSignException : public std::exception {
  public:
    const char *what() const throw();
  };

  // Required Interface Functions
  void beSigned(const Bureaucrat &br);
  int getSignGrade() const;
  int getExecGrade() const;

  const std::string &getName() const;
  bool getFormIsSigned() const;
  bool isAbleToSign(const Bureaucrat &br) const;

private:
  // Required Member valiable
  const std::string name_;
  bool isSigned_;
  const int signGrade_;
  const int execGrade_;

  // Forbidden OCF Functions
  Form();
  Form(const Form &src);
  Form &operator=(const Form &src);
};

std::ostream &operator<<(std::ostream &os, const Form &fo);
