# include <stdio.h>
# include <string.h>

int monthly_sales(float sales[12], char month[12][10]){
    printf("\nMonthly Sales Report for 2024:\n");
    for(int i = 0; i < 12; i++){
        printf("%-15s $%5.2f\n", month[i], sales[i]);
    }
    return 0;
}

int sales_stats(float sales[12]){
    float total_sales = 0.0;
    float average_sales = 0.0;
    float max_sales = sales[0];
    float min_sales = sales[0];

    for(int i = 0; i < 12; i++){
        total_sales += sales[i];
        if(sales[i] > max_sales){
            max_sales = sales[i];
        }
        if(sales[i] < min_sales){
            min_sales = sales[i];
        }
    }
    average_sales = total_sales / 12;

    printf("\nSales Summary Report:\n");
    printf("Minimum Sales: $%.2f\n", min_sales);
    printf("Maximum Sales: $%.2f\n", max_sales);
    printf("Average Sales: $%.2f\n", average_sales);

    return 0;
}

int six_mth_moving_avg(float sales[12], char month[12][10]){
    printf("\nSix-Month Moving Average Report:\n\n");
    for(int i = 0; i < 7; i++){
        float sum = 0.0;
        for(int j = i; j < i + 6; j++){
            sum += sales[j];
        }
        float moving_avg = sum / 6;
        char month_range[20];
        snprintf(month_range, sizeof(month_range), "%s - %s", month[i], month[i + 5]);
        printf("%-20s $%-10.2f\n", month_range, moving_avg);
    }
    return 0;
}

int high_to_low_months(float sales[12], char month[12][10]){
    printf("\nSales Report (highest to lowest):\n\n");
    float sorted_sales[12];
    char sorted_months[12][10];
    // impliment insertion sort to sort sales and months in descending order
    for(int i = 2; i < 12; i++){
        float sales_key = sales[i];
        char month_key[10];
        strcpy(month_key, month[i]);

        int j = i - 1;
        while(j > 0 && sales[j] > sales_key){
            sales[j + 1] = sales[j];
            strcpy(month[j + 1], month[j]);
            j = j - 1;
        }
        sales[j + 1] = sales_key;
        strcpy(month[j + 1], month_key);
    }

    for(int i = 11; i >= 0; i--){
        printf("%-15s $%.2f\n", month[i], sales[i]);
    }
    return 0;
}

int main(){
    char month[12][10] = {
        "January",
        "February",
        "March",
        "April",
        "May",
        "June",
        "July",
        "August",
        "September",
        "October",
        "November",
        "December"
    };

    float input_1[12] = {
        23458.01,
        40112.00,
        56011.85,
        37820.88,
        37904.67,
        60200.22,
        72400.31,
        56210.89,
        67230.84,
        68233.12,
        80950.34,
        95225.22
    };

    monthly_sales(input_1, month);
    sales_stats(input_1);
    six_mth_moving_avg(input_1, month);
    high_to_low_months(input_1, month);

    return 0;
}