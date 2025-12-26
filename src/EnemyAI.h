#pragma once
#include <mutex>
#include <vector>

struct Enemy
{

	int id;
	int decision;
};
class EnemyAI
{
public:


	void AIThread();
	std::atomic<bool> &GetbRunning() { return bRunning; }
	std::vector<Enemy>&GetEnemies() { return Enemies; }
	std::mutex &GetEnemyMutex() { return EnemyMutex; };
private:
	std::string AIName;
	std::string decisionName;
	std::vector<Enemy> Enemies;
	std::mutex EnemyMutex;
	std::atomic<bool> bRunning = true;


};

