#ifndef __Errors_hpp_2018_07_22_22_05
#define __Errors_hpp_2018_07_22_22_05

class exit_program{
    int code;
public:
    exit_program(int);
    exit_program();
    int getCode()const;
};


#endif