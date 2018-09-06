#pragma once
#include "basics.h"

//bool checkData(std::string path);

bool saveData(std::vector<int> &store, int datapointsN, std::string *path);

bool createData(std::vector<int> &store, int datapointsN, std::string *path);

bool loadData(std::vector<int> &store, int datapointsN, std::string *path);