#include <iostream>
#include <ctime>

namespace vars{

    double flip;
    int status;
    int tails = 0;
    int heads = 0;
    int currentStreakTails = 0;
    int currentStreakHeads = 0;
    int bestStreakTails = 0;
    int bestStreakHeads = 0;
};

void status_check();
void chance();

int main()
{
    srand(time(NULL));

    using namespace vars;

    std::cout << "Enter the amount of coin flips: ";
    std::cin >> flip;

    for(int i = 0; i < flip; i++){
        chance();
        status_check();
        //std::cout << "#" << i + 1 << " ";
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

    if(status == 0){
        tails = tails + 1;
        currentStreakTails++;
        if(bestStreakTails < currentStreakTails){
            bestStreakTails = currentStreakTails;
        }
        currentStreakHeads = 0;
    }
    else if(status == 1){
        heads = heads + 1;
        currentStreakHeads++;
        if(bestStreakHeads < currentStreakHeads){
            bestStreakHeads = currentStreakHeads;
        }
        currentStreakTails = 0;
    } else {
        // Add these lines to reset streaks in case status is neither "tails" nor "heads"
        currentStreakTails = 0;
        currentStreakHeads = 0;
    }
}

void chance() {
    using namespace vars;

    int x = rand() % 10 + 1;

    if (x <= 5) {
        status = 0;
    }
    else {
        status = 1;
    }
}