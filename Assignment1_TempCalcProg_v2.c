#include <stdio.h>

typedef struct {
    const char *name;
    double scale;
    double offset;
} Conversion;

Conversion conversions[] = {
    {"Celsius to Kelvin", 1.0, 273.15},
    {"Kelvin to Celsius", 1.0, -273.15},
    {"Fahrenheit to Celsius", 5.0 / 9.0, -32.0 * 5.0 / 9.0},
    {"Celsius to Fahrenheit", 9.0 / 5.0,  32.0},
    {"Kelvin to Fahrenheit", 9.0 / 5.0, -459.67},
	{"Fahrenheit to Kelvin", 5.0 / 9.0, 255.37222},   // (-32 * 5/9) + 273.15
};

double convert(double value, int choice) {
    double result = value * conversions[choice].scale + conversions[choice].offset;
    return(result);
}

int main(void) {
    int count = sizeof(conversions) / sizeof(conversions[0]);

    for (int i = 0; i < count; i++) {
        printf("%d) %s\n", i + 1, conversions[i].name);
    }

    int choice;
    double value;
    printf("Choose: ");
    scanf("%d", &choice);
    printf("Value: ");
    scanf("%lf", &value);

    if (choice < 1 || choice > count) {
        printf("Invalid choice\n");
        return 1;
    }

    printf("Result: %.2f\n", convert(value, choice - 1));
    return 0;
}