// This is Inheritance from std::exception version
#include <exception>
#include <string>

class Bureaucrat {
public:
  // Constructor & Destructor
  Bureaucrat(const std::string &name, unsigned int grade);
  ~Bureaucrat();

  // Getter
  const std::string &getName() const;
  std::string &getName();
  const std::string &getGrade() const;
  std::string &getGrade();

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
  unsigned int grade_;

  // Forbidden OCF Functions
  Bureaucrat();
  Bureaucrat(Bureaucrat &src);
  Bureaucrat &operator=(const Breaaucrat &src);
};

sstream &operator<<(

// This is Inheritance from std::logic_error version
#include <stdexcept>
#include <string>

class Bureaucrat {
public:
  // Constructor & Destructor
  Bureaucrat(const std::string &name, unsigned int grade);
  ~Bureaucrat();

  // Getter
  const std::string &getName() const;
  std::string &getName();
  const std::string &getGrade() const;
  std::string &getGrade();

  // Requirement Upper/Lower Functions
  void incrementGrade();
  void decrementGrade();

  // Exception class definition
  class GradeTooHighException : public std::logic_error {
  public:
    void tooHighException() const throw()
        : std::logic_err("[ERROR] Grade must be lower than 1") {};
  };
  class GradeTooLowException : public std::logic_error {
  public:
    void tooLowException() const throw()
        : std::logic_err("[ERROR] Grade must be Higher than 150") {};
  };

private:
  // Requirement Members
  const std::string name_;
  unsigned int grade_;

  // Forbidden OCF Functions
  Bureaucrat();
  Bureaucrat(Bureaucrat & src);
  Bureaucrat &operator=(const Breaaucrat &src);
};
