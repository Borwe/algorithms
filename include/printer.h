#ifndef PRINER_HEADER_CUSTOM
#define PRINER_HEADER_CUSTOM


#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <cstring>

namespace DataHandler{

    class Printer{
    private:
        //private variables
        Printer()=default;
        Printer(const Printer &copy)=default;
        Printer(Printer &&moved)=default;

        static Printer printer;
    public:
        template<typename T>
        static Printer print(T &obj){
            std::cout<<obj;
            return Printer::printer;
        }

        template<typename T>
        static Printer println(T &obj){
            std::cout<<obj<<std::endl;
            return Printer::printer;
        }

        static Printer println(int argc,char **argv){
            print(argc,argv);
            std::cout<<std::endl;
            return Printer::printer;
        }

        static Printer  print(int argc,char **argv){
            std::stringstream stream("");
            for(int i=0;i<argc;i++){
                stream<<argv[i];
                stream<<", ";
            }

            std::string result=stream.str();

            //we remove the xtra ", " at the end
            if(argc>0){
                char finalResult[result.size()-2];
                const char *src=result.c_str();
                memcpy(finalResult,src,result.size()-2);
                finalResult[result.size()-3]='\0';
                result=finalResult;
            }

            std::cout<<result;
            return Printer::printer;
        }

        static std::string promptForReturn(std::string prompt){
            std::cin.clear();
            std::cin.clear();

            print(prompt);
            std::string result;
            std::cin>>result;

            return result;
        }
    };

};

#endif
