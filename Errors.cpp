#include <Errors.hpp>

exit_program::exit_program(int __code):code(__code){}
exit_program::exit_program():code(0){}

int exit_program::getCode()const{
    return code;
}

