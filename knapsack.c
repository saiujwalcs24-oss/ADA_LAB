#include<stdio.h>
struct Item {
    int profit;
    int weight;
    float ratio;
};
int main() {
    int n;
    int capacity;
    printf("Enter number of items: ");
    scanf("%d", &n);
    struct Item items[n];
    for (int i = 0; i < n; i++) {
    printf("Enter profit and weight of item %d: ", i + 1);
        scanf("%d %d", &items[i].profit, &items[i].weight);
        items[i].ratio = (float)items[i].profit / items[i].weight;
    }
    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);
       for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (items[i].ratio < items[j].ratio) {
                struct Item temp = items[i];
                items[i] = items[j];
                items[j] = temp;
            }
        }
    }
    float totalProfit = 0.0;
    int remainingCapacity = capacity;
    printf("\nSelected Items:\n");
    printf("Profit\tWeight\tFraction Taken\n");
    for (int i = 0; i < n; i++) {
        if (remainingCapacity == 0){
            break;
    }
     if (items[i].weight <= remainingCapacity) {
            totalProfit += items[i].profit;
            remainingCapacity -= items[i].weight;
            printf("%d\t%d\t1.0\n", items[i].profit, items[i].weight);
        } else {
            float fraction = (float)remainingCapacity / items[i].weight;
            totalProfit += items[i].profit * fraction;

            printf("%d\t%d\t%.2f\n", items[i].profit, items[i].weight, fraction);

            remainingCapacity = 0;
        }
    }
    printf("\nMaximum Profit = %.2f\n", totalProfit);
    return 0;
}
