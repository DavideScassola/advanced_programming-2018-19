#include<iostream>
#include <string>

std::string line_breaker(int line_length, std::string text)
{
    if(text.length()<=line_length) return text;//if the text is shorter than line_length, we are done
    
    std::string partial_result; //this will store the first line broken
    std::string remaining_text; //this will store the remaining text that will be broken recursively

    int last_word_position{0};

    for(int pos = 0; pos<line_length; pos++ )
    {
       if(text[pos] == '\n')//if there is a newline, there is no need to broke the line, so the problem simply continues for the remaining text
       {
           partial_result = text.substr(0,pos+1);         
           remaining_text = text.substr(pos+1,text.length());   
           return partial_result + line_breaker(line_length,remaining_text);      
       }
       if(text[pos]==' ') last_word_position=pos;//track the position of the last word (the starting) 
    }

    if(last_word_position==0) last_word_position = line_length-1; //this line handle the situation in wich the word is longer than the line_length

    partial_result = text.substr(0,last_word_position+1);
    remaining_text = text.substr(last_word_position+1,text.length());

    return partial_result + "\n" + line_breaker(line_length,remaining_text);
}

main()
{
    std::string testing_text =
    "123456789 011111111111111111111111111111111111111111111111111111111111111111111111111111111111111111The  Basel\n   problem is a problem in mathematical analysis with relevance to number theory,\n first posed by Pietro Mengoli in 1644 and solved by Leonhard Euler in 1734 and read on 5 December 1735 in The Saint Petersburg Academy of Sciences. It consists in finding the infinite sum 1^-2 + 2^-2 + 3^-2 + ...\n Since the problem had withstood the attacks of the leading mathematicians of the day, Euler's solution brought him immediate fame when he was twenty-eight. Euler generalised the problem considerably, and his ideas were taken up years later by Bernhard Riemann in his seminal 1859 paper \"On the Number of Primes Less Than a Given Magnitude\",                      in which he defined his zeta function and proved its basic properties. The problem is named after Basel, hometown of Euler as well as of the Bernoulli family who unsuccessfully attacked the problem. ";

    std::cout << line_breaker(25,testing_text);
}
