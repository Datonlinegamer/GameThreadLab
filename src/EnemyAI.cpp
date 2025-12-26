#include "EnemyAI.h"
#include <print>
#include <iostream>
void EnemyAI::AIThread()
{
	AIName = "[Ai] Enemies";
	decisionName = "decision";
	while (bRunning)
	{
		std::lock_guard<std::mutex> lock(EnemyMutex);
		for (auto& enemy : Enemies)
		{
			enemy.decision = rand() % 3;

			
		}
	}

	std::this_thread::sleep_for(std::chrono::milliseconds(500));
}
