/*
 * RPNCalc.cpp
 * 
 * CS 15 project 1, CalcYouLater
 * by Kirin Godhwani, 10/17/21
 *
 * Purpose: Implements the member functions of the RPNCalc class. These include 
 *          an RPNCalc constructor to initialize the RPNCalc object, a 
 *          destructor that destroys/deletes/recycles any heap-allocated data
 *          one may have used in the RPNCalc instance, a commandLoop function
 *          that reads in commands from standard input and performs operations
 *          based on the commands, and a run function that calls the
 *          commandLoop function and prints the thank you message to std::err.
 *          Implements the code to handle the logic of processing all of the
 *          commands from the input stream.
 *
 */
 

#include "RPNCalc.h"


/* default constructor
 *    Purpose: Initializes the RPNCalc object.
 */
RPNCalc::RPNCalc()
{
  
}

/* destructor 
 *    Purpose: Destroys/deletes/recycles any heap-allocated data you may
 *             have used in the RPNCalc instance.
 */
RPNCalc::~RPNCalc()
{
    
}

/* commandLoop
 *    Purpose: Reads in commands from an input stream and performs
 *             different operations based on each command.
 * Parameters: The stream to read input from.
 *    Returns: None
 *
 *       Notes: Each command can be read as a string and commands will be 
 *              separated by whitespace. Commands do not have to be on
 *              different lines. 
 */
void RPNCalc::commandLoop(std::istream &input)
{
    
    std::string cmd;
    while (input >> cmd) {
      
        try {

            int n;
            // number command
            if (got_int(cmd, &n)) {
                Datum d(n);
                stack.push(d);
            
            // boolean command
            } else if (cmd == "#t") {
                Datum d(true);
                stack.push(d);
            } else if (cmd == "#f") {
                Datum d(false);
                stack.push(d);
        
            // not command
            } else if (cmd == "not") {
                Datum d = stack.top();
                stack.pop();
                if (d.getBool() == true) {
                    Datum add(false);
                    stack.push(add);
                } else if (stack.top().getBool() == false) {
                    Datum add(true);
                    stack.push(add);
                }
            // print command
            } else if (cmd == "print") {
                std::cout << stack.top().toString() << std::endl;

            // clear command
            } else if (cmd == "clear") {
                stack.clear();
        
            // drop command
            } else if (cmd == "drop") {
                stack.pop();
                
            // dup command
            } else if (cmd == "dup") {
                Datum copy(stack.top());
                stack.push(copy);

            // swap command
            } else if (cmd == "swap") {
                Datum swap1(stack.top());
                stack.pop();
                Datum swap2(stack.top());
                stack.pop();
                stack.push(swap1);
                stack.push(swap2);

            // +, - , *, /, mod command
            } else if (cmd == "+") {
                Datum n1 = stack.top();
                stack.pop();
                Datum n2 = stack.top();
                stack.pop();
                int x = n1.getInt();
                int y = n2.getInt();
                int z = x + y;
                Datum d(z);
                stack.push(d);

            } else if (cmd == "*") {
                Datum n1 = stack.top();
                stack.pop();
                Datum n2 = stack.top();
                stack.pop();
                int x = n1.getInt();
                int y = n2.getInt();
                int z = x * y;
                Datum d(z);
                stack.push(d);
                    
            } else if (cmd == "-") {
                Datum n1 = stack.top();
                stack.pop();
                Datum n2 = stack.top();
                stack.pop();
                int x = n1.getInt();
                int y = n2.getInt();
                int z = y - x;
                Datum d(z);
                stack.push(d);
                
            } else if (cmd == "/") {
                Datum n1 = stack.top();
                stack.pop();
                Datum n2 = stack.top();
                stack.pop();
                int x = n1.getInt();
                int y = n2.getInt();
                if (x == 0) {
                   throw std::runtime_error("division by 0.");
                }
                int z = y / x;
                Datum d(z);
                stack.push(d);
      
            } else if (cmd == "mod") {
                Datum n1 = stack.top();
                stack.pop();
                Datum n2 = stack.top();
                stack.pop();
                int x = n1.getInt();
                int y = n2.getInt();
                if (x == 0) {
                   throw std::runtime_error("division by 0.");
                }
                int z = y % x;
                Datum d(z);
                stack.push(d);
                
            // <, >, <=, >=, or ==
            } else if (cmd == "<") {
                Datum n1 = stack.top();
                stack.pop();
                Datum n2 = stack.top();
                stack.pop();
                int x = n1.getInt();
                int y = n2.getInt();
                if (y < x) {
                    Datum d(true);
                    stack.push(d);
                } else {
                    Datum d(false);
                    stack.push(d);
                }  
            } else if (cmd == ">") {
                Datum n1 = stack.top();
                stack.pop();
                Datum n2 = stack.top();
                stack.pop();
                int x = n1.getInt();
                int y = n2.getInt();
                if (y > x) {
                    Datum d(true);
                    stack.push(d);
                } else {
                    Datum d(false);
                    stack.push(d);
                }  
            } else if (cmd == "<=") {
                Datum n1 = stack.top();
                stack.pop();
                Datum n2 = stack.top();
                stack.pop();
                int x = n1.getInt();
                int y = n2.getInt();
                if (y <= x) {
                    Datum d(true);
                    stack.push(d);
                } else {
                    Datum d(false);
                    stack.push(d);
                }  
            } else if (cmd == ">=") {
                Datum n1 = stack.top();
                stack.pop();
                Datum n2 = stack.top();
                stack.pop();
                int x = n1.getInt();
                int y = n2.getInt();
                if (y >= x) {
                    Datum d(true);
                    stack.push(d);
                } else {
                    Datum d(false);
                    stack.push(d);
                }  
            } else if (cmd == "==") {
                Datum n1 = stack.top();
                stack.pop();
                Datum n2 = stack.top();
                stack.pop();
                if (n2 == n1) {
                    Datum d(true);
                    stack.push(d);
                } else {
                    Datum d(false);
                    stack.push(d);
                }  
                
            // add rstring to stack
            } else if (cmd == "{") {
                std::string s = parseRString(input);
                Datum d(s);
                stack.push(d);
            
            // exec command
            } else if (cmd == "exec") {
                
                Datum exec = stack.top();
                stack.pop();
                
                if (exec.isRString()) {
                    
                    std::string s = exec.getRString();
                    
                    // delete the braces in the string
                    s.pop_back();
                    s.erase(0, 1);
                    
                    std::istringstream iss(s);
                    commandLoop(iss);
                    
                } else {
                    std::cerr << "Error: cannot execute non rstring\n";
                }
            
            // file command
            } else if (cmd == "file") {
                
                Datum file = stack.top();
                stack.pop();
                
                if (file.isRString()) {
                
                    std::string s = file.getRString();
                    
                    // delete the braces in the string and the extra spaces
                    s.pop_back();
                    s.erase(0, 1);
                    s.pop_back();
                    s.erase(0, 1);
                    
                    std::ifstream input_file;
                    
                    input_file.open(s);
                    if (not input_file.is_open()) {
                        std::cerr << "Unable to read "
                                  << s << std::endl;
                    } else {
                        commandLoop(input_file);
                        input_file.close();
                    }          
                } else {
                    std::cerr << "Error: file operand not rstring\n";
                }
            
            // if command
            } else if (cmd == "if") {                        
                // false case
                Datum falseCase = stack.top();
                stack.pop();
                // true case
                Datum trueCase = stack.top();
                stack.pop();
                // condition to test
                Datum condition = stack.top();
                stack.pop();
                if (not condition.isBool()) {
                    std::cerr << "Error: expected boolean in if test\n";
                } else if (not trueCase.isRString()) {
                    std::cerr<< "Error: expected rstring in if branch\n";
                } else if (not falseCase.isRString()) {
                    std::cerr<< "Error: expected rstring in if branch\n";
                } else if (condition.getBool() == false) {
                    // delete the braces in the string
                    std::string s = falseCase.getRString();
                    s.pop_back();
                    s.erase(0, 1);
                  
                    std::istringstream iss(s);
                    commandLoop(iss);                  
                } else {
                    // delete the braces in the string
                    std::string s = trueCase.getRString();
                    s.pop_back();
                    s.erase(0, 1);
                
                    std::istringstream iss(s);
                    commandLoop(iss);
                }
            
            // quit command
            } else if (cmd == "quit") {
                return;
              
            // unrecognized input
            } else {
                std::cerr << cmd << ": unimplemented" << std::endl;
            }
            
        } catch (std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }    
    }
}

/*
 * Return true if the string s can be interpreted as an integer
 * number, placing the associated integer into the location pointed to by
 * resultp.
 *
 * Return false if s cannot be interpreted as an integer leaving the
 * location pointed to by resultp unmodified.
 * 
 * Parameters: string to be tested to be an integer, address of an integer
 *             type variable to hold the new integer
 */
bool RPNCalc::got_int(std::string s, int *resultp)
{
        /* Holds the first non-whitespace character after the integer */
        char extra;

        return sscanf(s.c_str(), " %d %c", resultp, &extra) == 1;
}

/* parseRString
 *    Purpose: Called after an initial “{” has been read from the input stream
 *             passed as a parameter. parseRString reads input from the stream
 *             until all curly braces are matched or until it reaches the end
 *             of the input.
 * Parameters: The stream to read input from
 *    Returns: Returns an rstring (i.e, an std::string), with the
 *             specifications listed under the spec
 */
std::string RPNCalc::parseRString(std::istream &input) 
{
    std::string s;
    std::string build = "";
    std::vector<std::string> curlyStack;
    curlyStack.push_back("{");
    
    while (not curlyStack.empty()) { 
        
        input >> s;
        
        // add opening curly braces to the front of the stack
        if (s == "{") {
            curlyStack.push_back(s);
        }
        // closing brace-> remove opener at stack top
        if (s == "}") {
            curlyStack.pop_back();
        }
        build = build + s + " "; 
    }
    build = "{ " + build;
    build.pop_back();
    return build;    
}

/* run
 *    Purpose: Calls the commandLoop function and prints the thank you message
 *             to std::err.
 * Parameters: None
 *    Returns: None
 */
void RPNCalc::run() {

    commandLoop(std::cin);
    std::cerr << "Thank you for using CalcYouLater.\n";

}