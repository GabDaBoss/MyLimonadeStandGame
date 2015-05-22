#include "main.h"
using namespace std;

int main(int argc, char *argv[])
{
   MyApp* myApp = new MyApp();

    while(myApp->run());
    return 0;
}
