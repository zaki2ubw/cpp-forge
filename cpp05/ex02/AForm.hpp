#pragma once

#include <exception>
#include <string>

class Bureaucrat;

class AForm {
public:
  // Constructor & Destructor
  AForm(const std::string &name, int signGrade, int execGrade);
  ~AForm();
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
  // Required Interface Functions
  void beSigned(const Bureaucrat &br);
  int getSignGrade() const;
  int getExecGrade() const;
  virtual void execute(Bureaucrat const &executor) const = 0;

  const std::string &getName() const;
  bool getFormIsSigned() const;

private:
  // Required Member valiable
  const std::string name_;
  bool isSigned_;
  const int signGrade_;
  const int execGrade_;

  // Forbidden OCF Functions
  AForm();
  AForm(const AForm &src);
  AForm &operator=(const AForm &src);
};

std::ostream &operator<<(std::ostream &os, const AForm &fo);
