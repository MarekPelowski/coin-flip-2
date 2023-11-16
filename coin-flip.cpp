#include <iostream>
#include <ctime>

namespace vars{

    int flip;
    std::string status;
    int tails;
    int heads;
    int currentStreakTails;
    int currentStreakHeads;
    int bestStreakTails;
    int bestStreakHeads;
};

void status_check();
void chance();

int main()
{
    using namespace vars;

    time_t seed;

    time(&seed);
    srand(seed);

    std::cout << "Enter the amount of coin flips: ";
    std::cin >> flip;

    for(int i = 0; i < flip; i++){
        chance();
        status_check();
    }

    double tailsScore = (tails * 100.0) / flip;
    double headsScore = (heads * 100.0) / flip;

    std::cout << "tails: " << tailsScore << '%' << std::endl;
    std::cout << "heads: " << headsScore << '%' << std::endl;
    std::cout << "tails best streak: " << bestStreakTails << std::endl;
    std::cout << "heads best streak: " << bestStreakHeads << std::endl;

    return 0;
}

void status_check(){
    using namespace vars;

    if(status == "tails"){
        tails++;
        currentStreakTails++;
        if(currentStreakTails > bestStreakTails){
            bestStreakTails = currentStreakTails;
        }
        currentStreakHeads = 0;
    }
    else if(status == "heads"){
        heads++;
        currentStreakHeads++;
        if(currentStreakHeads > bestStreakHeads){
            bestStreakHeads = currentStreakHeads;
        }
        currentStreakTails = 0;
    }
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