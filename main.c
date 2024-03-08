#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// SaveFile by Helixneek

struct Skill {
	char skillName[100];
	int skillLevel;
};

struct PlayerData {
	int playerLevel;
	struct Skill playerSkills[5];
	int playerSkillCount;
	int playerCoins;
	char playerClass[20];
};

void write_to_save(struct PlayerData playerData) {
	FILE *fp = fopen("savefile.naonwae", "w");
	if(fp != NULL) {
		fwrite(&playerData, sizeof(struct PlayerData), 1, fp);
		fclose(fp);
	}
}

struct PlayerData read_from_save() {
	struct PlayerData currentData;
	
	FILE *fp = fopen("savefile.naonwae", "r");
	if(fp != NULL) {
		fread(&currentData, sizeof(struct PlayerData), 1, fp);
		fclose(fp);
	}
	
	return currentData;
}

bool verifyData(struct PlayerData playerData) {
	if(playerData.playerLevel < 1 || playerData.playerLevel > 99) {
		return false;
	}
	
	if(playerData.playerCoins < 0 || playerData.playerCoins > 9999) {
		return false;
	}
	
	if(playerData.playerSkillCount > 5 || playerData.playerSkillCount < 0) {
		return false;
	}
	
	int num_skills = sizeof(playerData.playerSkills) / sizeof(playerData.playerSkills[0]);
	int i;
	
	for(i = 0; i < num_skills; i++) {
		if(playerData.playerSkills[i].skillLevel < 0 || playerData.playerSkills[i].skillLevel > 10) {
			return false;
		}
	}
	
	return true;
}

int main(int argc, char *argv[]) {
	struct PlayerData playerData = { // Example player data
		.playerLevel = 15,
		.playerSkills = {{"Eldritch Blast", 5}, {"Green-Flame Blade", 10}},
		.playerSkillCount = 2,
		.playerCoins = 453,
		.playerClass = "Warlock"
	};
	
	write_to_save(playerData);
	struct PlayerData loadedData = read_from_save();
	
	if(!verifyData(loadedData)) {
		printf("\nData is invalid\n");
		return 0;
	}

	int i;
	
	printf("Level: %d\n", loadedData.playerLevel);
    printf("\nSkills:\n");
    for (i = 0; i < loadedData.playerSkillCount; i++) {
    	if(loadedData.playerSkills[i].skillName == NULL && loadedData.playerSkills[i].skillLevel <= 0) { 
			break;
		}
		
        printf("- %s (Level %d)\n", loadedData.playerSkills[i].skillName, loadedData.playerSkills[i].skillLevel);
    }
    printf("\nCoins: %d\n", loadedData.playerCoins);
    printf("Class: %s\n", loadedData.playerClass);
    
    return 0;
}
