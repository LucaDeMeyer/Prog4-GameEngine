#pragma once
#include <iostream>

class BaseCommand
{
public:
	virtual ~BaseCommand();
	virtual void Execute() = 0;
};

class JumpCommand : public BaseCommand {
public:
    void Execute() override {
        std::cout << "Jumping!" << std::endl;
        // Add jumping logic here
    }
};

class ShootCommand : public BaseCommand {
public:
    void Execute() override {
        std::cout << "Shooting!" << std::endl;
        // Add shooting logic here
    }
};