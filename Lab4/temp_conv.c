#include <stdio.h>


int c_advisory(int temp) {

    if (temp < 0) {
        printf("Advisory: Freezing. Stay indoors and keep warm.\n");
    } else if (temp >= 0 && temp < 10) {
        printf("Advisory: Cold. Wear a coat and be cautious of icy conditions.\n");
    } else if (temp >= 10 && temp < 25) {
        printf("Advisory: Comfortable. A light jacket may be needed.\n");
    } else if (temp >= 25 && temp < 35) {
        printf("Advisory: Hot. Stay hydrated and avoid prolonged exposure to the sun.\n");
    } else if (temp >= 35) {
        printf("Advisory: Extreme Heat. Stay hydrated and stay indoors if possible.\n");
    }
    return 0;
}

int c_to_f(int c) {
    return (c * 9 / 5) + 32;
}

int f_to_c(int f) {
    return (f - 32) * 5 / 9;
}

int c_to_k(int c) {
    return c + 273.15;
}

int k_to_c(int k) {
    return k - 273.15;
}

int f_to_k(int f) {
    return (f-32) * 5 / 9 + 273.15;
}

int k_to_f(int k) {
    return (k-273.15) * 9 / 5 + 32;
}

int main(){
    char start_temp_type;
    char end_temp_type;
    int temp_value;
    while (start_temp_type != 'C' && start_temp_type != 'F' && start_temp_type != 'K') {
        printf("Enter the temperature type (C, F, or K): ");
        scanf("%c", &start_temp_type);
    }
    // Error handling for invalid temperature type input included in this while loop
    while(end_temp_type != 'C' && end_temp_type != 'F' && end_temp_type != 'K' && end_temp_type != start_temp_type) {
        printf("Enter the temperature type to convert to (C, F, or K): ");
        printf("Note: The temperature type to convert to cannot be the same as the starting temperature type.\n");
        scanf(" %c", &end_temp_type);
    }

    printf("Enter the temperature value: ");
    scanf("%d", &temp_value);

    // Error handling for invalid temperature values
    if(start_temp_type == 'K' && temp_value < 0) {
        printf("Invalid temperature value. Kelvin cannot be negative.\n");
        return 1;
    }

    // Perform the appropriate conversion based on the starting and ending temperature types
    if (start_temp_type == 'C' && end_temp_type == 'F') {
        printf("%d degrees Celsius is equal to %d degrees Fahrenheit.\n", temp_value, c_to_f(temp_value));
        c_advisory(temp_value);
    } else if (start_temp_type == 'C' && end_temp_type == 'K') {
        printf("%d degrees Celsius is equal to %d degrees Kelvin.\n", temp_value, c_to_k(temp_value));
        c_advisory(temp_value);
    } else if (start_temp_type == 'F' && end_temp_type == 'C') {
        printf("%d degrees Fahrenheit is equal to %d degrees Celsius.\n", temp_value, f_to_c(temp_value));
        c_advisory(f_to_c(temp_value));
    } else if (start_temp_type == 'F' && end_temp_type == 'K') {
        printf("%d degrees Fahrenheit is equal to %d degrees Kelvin.\n", temp_value, f_to_k(temp_value));
        c_advisory(f_to_c(temp_value));
    } else if (start_temp_type == 'K' && end_temp_type == 'C') {
        printf("%d degrees Kelvin is equal to %d degrees Celsius.\n", temp_value, k_to_c(temp_value));
        c_advisory(k_to_c(temp_value));
    } else if (start_temp_type == 'K' && end_temp_type == 'F') {
        printf("%d degrees Kelvin is equal to %d degrees Fahrenheit.\n", temp_value, k_to_f(temp_value));
        c_advisory(k_to_c(temp_value));
    }
}
