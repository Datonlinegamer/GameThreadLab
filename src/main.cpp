#include "EnemyAI.h"
#include <thread>
#include <chrono>
#include <print>
#include <iostream>

#define LOG(x) std::cout << x << std::endl;
int main()
{
    EnemyAI AI;

   
    for (int i = 0; i < 5; ++i)
    {
        AI.GetEnemies().push_back({i, 0});
    }

    std::thread AIWorker(&EnemyAI::AIThread, &AI);


    for (int frame = 0; frame < 10; ++frame)
    {
        {
            std::lock_guard<std::mutex> lock(AI.GetEnemyMutex());

            for (auto& enemy : AI.GetEnemies())
            {
                LOG( "[GAME] Enemy " << enemy.id << " decision = "<< enemy.decision);
            }
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    
    AI.GetbRunning() = false;
    AIWorker.join();

    return 0;
}
