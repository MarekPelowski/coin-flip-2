#include <iostream>
#include <ctime>

namespace vars{

    int flip;
    std::string status;
    int tails;
    int heads;
    int CurrentStreakTails;
    int CurrentStreakHeads;
    int BestStreakTails;
    int BestStreakHeads;
}

void status_check();
void chance();

int main()
{
    using namespace vars;

    std::cout << "Enter the amount of coin flips: ";
    std::cin >> flip;

    for(int i = 0; i < flip; i++){
        chance();
        status_check();
    }

    return 0;
}
void status_check(){
    
}
void chance(){
    using namespace vars;

    int x = rand() % 2;

    if(!x){
        status = "tails";
    }
    else if(x){
        status = "heads";
    }
}