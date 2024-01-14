#include <iostream>
#include <string>
#include "stdynschema.h"
#include "renderglwf.h"

int main(int argc, char *argv[])
{
    
    std::cout << "In Main"  << std::endl;
    std::string fileIn = argv[1];

     try
    {
        STDynSchema ds;
        ds.load("/Users/danypineault/Documents/Code/cpp/SysTinkDyn2/zFiles/" + fileIn + ".stdyn");
        ds.save("/Users/danypineault/Documents/Code/cpp/SysTinkDyn2/zFiles/" + fileIn + ".stdyn.out");
        std::cout << "Success\n";
    }
    catch (std::exception &e)
    {
        std::cout << "Error: " << e.what() << "\n";
    }

    renderGLFW("STDyn");

    return 0;
}
