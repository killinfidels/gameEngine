#include "../header-files/storage.h"

bool checkData(std::string *path)
{
	return false;
}

bool saveData(std::vector<int> &store, int datapointsN, std::string *path)
{
	bool success = true;

	//open file for writing
	SDL_RWops* file = SDL_RWFromFile(path->c_str(), "w");

	if (file != NULL)
	{
		//save data
		printf("Saving file\n");
		for (int i = 0; i < datapointsN; i++)
		{
			//std::cout << store[i] << std::endl;
			SDL_RWwrite(file, &store[i], sizeof(int), 1);
		}

		//close file
		SDL_RWclose(file);
	}
	else
	{
		printf("Error: Unable to save file. %s\n", SDL_GetError());
		success = false;
	}

	return success;
}

bool createData(std::vector<int> &store, int datapointsN, std::string *path)
{
	bool success = true;

	//open file for reading
	SDL_RWops* file = SDL_RWFromFile(path->c_str(), "r");

	//no file
	if (file == NULL)
	{
		printf("Creating file\n");

		//create file
		file = SDL_RWFromFile(path->c_str(), "w");

		if (file != NULL)
		{
			printf("File created\n");

			//store data
			for (int i = 0; i < datapointsN; i++)
			{
				SDL_RWwrite(file, &store[i], sizeof(int), 1);
			}

			printf("Data saved\n");

			//close file
			SDL_RWclose(file);
		}
		else
		{
			printf("Error: Unable to create file. SDL Error: %s\n", SDL_GetError());
			success = false;
		}
	}
	else //file exists
	{
		printf("File already exists\n");

		//close file
		SDL_RWclose(file);
	}

	return success;
}

bool loadData(std::vector<int> &store, int datapointsN, std::string *path)
{
	bool success = true;

	//open file
	SDL_RWops* file = SDL_RWFromFile(path->c_str(), "r");

	//no file
	if (file == NULL)
	{
		printf("Warning: Unable to open file. SDL Error: %s\n", SDL_GetError());

		success = false;
	}
	else //file exists
	{
		//load data
		printf("Reading file\n");
		for (int i = 0; i < datapointsN; i++)
		{
			SDL_RWread(file, &store[i], sizeof(int), 1);
			//std::cout << store[i] << std::endl;
		}

		//close file
		SDL_RWclose(file);
	}

	return success;
}