#pragma once
#include <string>
#include <vector>
#include "Facility.h"
#include "Plan.h"
#include "SelectionPolicy.h"
#include "Settlement.h"
#include "Auxiliary.h"

#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;
using std::string;
using std::vector;

class BaseAction;


class Simulation {
    public:
        Simulation(const string &configFilePath);
        Simulation(const Simulation &other);              
        Simulation &operator=(const Simulation &other);   
        Simulation(Simulation &&other) noexcept;
        Simulation &operator=(Simulation &&other) noexcept;
        ~Simulation(); 
        void start();
        void addPlan(const Settlement &settlement, SelectionPolicy *selectionPolicy);
        void addAction(BaseAction *action);
        bool addSettlement(Settlement *settlement);
        bool addFacility(FacilityType facility);
        bool isSettlementExists(const string &settlementName);
        bool isFacilityExists(const string &facilityName);
        bool isPlanExists(const int planId);
        Settlement &getSettlement(const string &settlementName);
        Plan &getPlan(const int planID);
        const std::vector<BaseAction*>& getActionsLog() const;
        void step();
        void close();
        void open();
        

    private:
        bool isRunning;
        int planCounter; 
        vector<BaseAction*> actionsLog;
        vector<Plan> plans;
        vector<Settlement*> settlements;
        vector<FacilityType> facilitiesOptions;
};