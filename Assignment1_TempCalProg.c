#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int InTmp;
int OutTmp;

int CtK();
int KtC();
int CtF();
int FtC();

const char* tmpSelect(int a){
	const char *units[] = {"Celsius", "Kelvin", "Fahrenheit"};
	
	if (a < 0 || a >= 3){
		return ("Unknown");
	} else {
		return(units[a]);
	}
}

void clearBuffer(void){
	int c;
	while ((c = getchar()) != '\n' && c != EOF); 
}
	
void invalidInput(void){		
	printf("\nValue is invalid.. \nReturning to start... \n\n"); 
}

int main(void){
	bool running = true;
	
	while (running){

		printf("Select a Input Temperature: Celcius[0], Kelvin[1], Fahrenheit[2]: ");
		if (scanf("%d", &InTmp) == 0) {
			clearBuffer();
			invalidInput();
			
			continue; 
		}
		
		const char* inUnits = tmpSelect(InTmp);
	
		if (strcmp(inUnits, "Unknown") == 0){
			invalidInput();
			
			continue; 
		} else {
			printf("You've selected %s \n\n", inUnits);
		}
		
		printf("Select a Output Temperature: Celcius[0], Kelvin[1], Fahrenheit[2]: ");
		if (scanf("%d", &OutTmp) == 0) {
			clearBuffer();
			invalidInput();
			
			continue; 
		}
		
		const char* outUnits = tmpSelect(OutTmp);
		
		if (strcmp(outUnits, "Unknown") == 0){
			invalidInput();
			
			continue; 
		} else {
			printf("You've selected %s \n\n", outUnits);
		}
	}
}


