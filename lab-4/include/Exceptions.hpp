#ifndef EXCEPTIONS_HPP
#define EXCEPTIONS_HPP

#include <exception>
#include <string>

class IndexOutOfRangeException : public std::exception {
private:
    std::string _msg;

public:
    explicit IndexOutOfRangeException(const std::string& msg);

    const char* what() const noexcept override;
};

class ArrayIsEmptyException : public std::exception {
private:
    std::string _msg;

public:
    explicit ArrayIsEmptyException(const std::string& msg);

    const char* what() const noexcept override;
};

class NotImplementedException : public std::exception {
private:
    std::string _msg;

public:
    explicit NotImplementedException(const std::string& msg);

    const char* what() const noexcept override;
};

class UninitializedException : public std::exception {
private:
    std::string _msg;

public:
    explicit UninitializedException(const std::string& msg);

    const char* what() const noexcept override;
};

class BadInputDataException : public std::exception {
private:
    std::string _msg;

public:
    explicit BadInputDataException(const std::string& msg);

    const char* what() const noexcept override;
};

#endif // EXCEPTIONS_HPP
