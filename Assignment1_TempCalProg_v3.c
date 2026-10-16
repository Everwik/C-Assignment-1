#include <stdio.h>
#include <stdbool.h>

typedef struct {
    const char *name;
    const char *units;
    double scale;
    double offset;
} Conversion;

Conversion conversions[] = {
    {"Celsius to Kelvin",	"K",	1.0,	273.15},
    {"Kelvin to Celsius",	"C",	1.0,	-273.15},
    {"Fahrenheit to Celsius",	"C",	5.0 / 9.0,	-32.0 * 5.0 / 9.0},
    {"Celsius to Fahrenheit",	"F",	9.0 / 5.0,	32.0},
    {"Kelvin to Fahrenheit",	"F",	9.0 / 5.0,	-459.67},
	{"Fahrenheit to Kelvin",	"K",	5.0 / 9.0,	255.37222}, 
};

double convert(double value, int choice) {
    return value * conversions[choice].scale + conversions[choice].offset;
}

void clearBuffer(void){
	int c;
	while ((c = getchar()) != '\n' && c != EOF); 
}
	
void invalidInput(void){		
	printf("\nValue is invalid.. \nReturning to start... \n\n"); 
}

int main(void){
	int choice;
    double value;
    
	int count = sizeof(conversions) / sizeof(conversions[0]);
	bool running = true;
	
	while (running){
		for (int i =0; i < count; i++){
			printf("[%d] %s\n", i+1, conversions[i].name);
		}
		
		printf("Choose by Num: ");
		if (scanf("%d", &choice) == 0){
			clearBuffer();
			invalidInput();
			
			continue; 
		}
		
		printf("Insert Input Value: ");
		if (scanf("%lf", &value) == 0){
			clearBuffer();
			invalidInput();
			
			continue; 
		}
		
		printf("Result: %.2f %s\n\n\n", convert(value, choice - 1), conversions[choice - 1].units);
	}
}


