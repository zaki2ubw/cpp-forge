#include "Breaucrat.hpp"

Breaucrat::Breaucrat(const std::string& name, unsigned int grade)
	: name_(name), grade_(grade)
{
}

Breaucrat::~Breaucrat()
{
}

const std::string& Breaucrat::getName() const
{
	return this->name_;
}

std::string Breaucrat::getName()
{
	return this->name_;
}

unsigned int Breaucrat::getGrade()
{
	return this->grade_;
}

const std::string& Breaucrat::getGrade() const
{
	std::string result = intToStr(this->grade_);
	return result;
}

std::string Breaucrat::getGrade()
{
	std::string result = intToStr(this->grade_);
	return result;
}

void	Breaucrat::incrementGrade()
{
	--grade_;
	if (grade_ < 1)
	{
		throw GradeTooHighException();
	}
	return ;
}

void Breaucrat::decrementGrade()
{
	++grade_;
	if (grade_ > 150)
	{
		throw GradeTooLowException();
	}
	return ;
}

std::string&	Breaucrat::intToStr();
{

