#include <fstream>
#include <iostream>

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target)
    : AForm("ShrubberyCreationForm", 145, 137), target_(target) {
  if (target_.empty())
    throw std::invalid_argument("Target must be set");
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
  if (!isAbleToExec(executor)) {
    throw AForm::LessGradeToExecuteException();
    return;
  } else if (!this->putShrubberyToTarget()) {
    std::cout << "Failed to create Shrubbery" << std::endl;
    return;
  } else {
    std::cout << "Shrubbery created successfully" << std::endl;
    return;
  }
}

bool ShrubberyCreationForm::putShrubberyToTarget() const {
  const std::string prefix = "./outfile/";
  const std::string suffix = "_shrubbery";
  const std::string fileName = prefix + this->target_ + suffix;
  if (fileExists(fileName)) {
    std::cout << "Shrubbery is already put" << std::endl;
    return false;
  }
  std::ofstream outfile(fileName.c_str());
  if (!outfile.is_open()) {
    std::cout << "Failed to Open NewFile" << std::endl;
    return false;
  }
  outfile << "      .ox%0%xo.\n"
          << "   .o0%%%0%%%0%o.\n"
          << " .o%0%%%0%%%0%%%0%o.\n"
          << ".0%0%%%0%%%0%%%0%%%0.\n"
          << "0%%%0%%%0%%%0%%%0%%%0\n"
          << " `0%0%%%0%%%0%%%0%0'\n"
          << "       ||   ||\n"
          << "  _____||___||_____\n";
  outfile.close();
  return true;
}

bool ShrubberyCreationForm::fileExists(const std::string &fileName) const {
  std::ifstream file(fileName.c_str());
  return file.is_open();
}
