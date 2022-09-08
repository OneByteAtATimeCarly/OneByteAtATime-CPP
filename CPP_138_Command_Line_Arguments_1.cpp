//Command Line Arguments 1 - 2004 C. S. Germany

//The command line can be used to pass arguments to a program when starting it.
//The main() function of every program can be passed two arguments:

//     Argument 1 - (arg c) integer count of the number of arguments on the command line.
//     Argument 2 - (arg v) an array of pointers to character strings.

//In the case of argument 1, the program name itself counts as an argument, so there is always at least one argument.
//The first argument is most often called "arg c" for argument count, and the second argument is most often called
//"arg v" for argument vector.  In the case of the character array, argv[0] would be the name of the program, an so
//argv[1] would be the first argument.

//The example below will simply display each element in the argv[] array one by one. So, if five arguments were passed in,
//all five would be displayed as the loop iterates through each element in argv[i]

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream>

//---------------------------------------------------------------------------------------------------------------------------

int main(int argc, char **argv)
{
    std::cout << "I received " << argc << " arguments!\n";

    for(int i=0; i<argc; i++)
        std::cout << "Argument: " << i << ": " << argv[i] << std::endl;

    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------









