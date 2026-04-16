#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <stdbool.h>

#define MAX 10
#define INF INT_MAX

typedef struct {
    char name[30];
} City;

int getMinDistance(int dist[], bool visited[], int n) {
    int min = INF, min_index = -1;
    for (int v = 0; v < n; v++) {
        if (!visited[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printPath(int parent[], int j, City cities[]) {
    if (parent[j] == -1) return;
    printPath(parent, parent[j], cities);
    printf(" -> %s", cities[j].name);
}

void runLogisticsOptimizer(int graph[MAX][MAX], int src, int n, City cities[], float fuelRate, int speed) {
    int dist[MAX];
    bool visited[MAX];
    int parent[MAX];

    for (int i = 0; i < n; i++) {
        dist[i] = INF;
        visited[i] = false;
        parent[i] = -1;
    }

    dist[src] = 0;

    for (int count = 0; count < n - 1; count++) {
        int u = getMinDistance(dist, visited, n);
        if (u == -1) break; 
        visited[u] = true;

        for (int v = 0; v < n; v++) {
            if (!visited[v] && graph[u][v] && dist[u] != INF 
                && dist[u] + graph[u][v] < dist[v]) {
                parent[v] = u;
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printf("\n%-15s | %-8s | %-10s | %-12s | %-30s\n", "Destination", "Dist.", "Est. Time", "Fuel Cost", "Optimized Route");
    printf("------------------------------------------------------------------------------------------------\n");
    
    for (int i = 0; i < n; i++) {
        if (i == src) continue;
        
        if (dist[i] == INF) {
            printf("%-15s | %-8s | %-10s | %-12s | %-30s\n", cities[i].name, "N/A", "N/A", "N/A", "No Route Found");
        } else {
            float time = (float)dist[i] / speed;
            float cost = (float)dist[i] * fuelRate;
            
            printf("%-15s | %-3d km  | %-6.2f hrs | %-7.2f TK  | %s", 
                   cities[i].name, dist[i], time, cost, cities[src].name);
            printPath(parent, i, cities);
            printf("\n");
        }
    }
}

int main() {
    City cities[MAX] = {
        {"Dhaka"}, {"Chittagong"}, {"Sylhet"}, {"Rajshahi"}, {"Khulna"},
        {"Barishal"}, {"Rangpur"}, {"Mymensingh"}, {"Cumilla"}, {"Gazipur"}
    };

    int graph[MAX][MAX] = {
        {0, 248, 240, 250, 220, 180, 300, 120, 100, 25},
        {248, 0, 0, 0, 0, 0, 0, 0, 150, 0},
        {240, 0, 0, 0, 0, 0, 0, 0, 160, 0},
        {250, 0, 0, 0, 0, 0, 110, 0, 0, 0},
        {220, 0, 0, 0, 0, 120, 0, 0, 0, 0},
        {180, 0, 0, 0, 120, 0, 0, 0, 0, 0},
        {300, 0, 0, 110, 0, 0, 0, 200, 0, 0},
        {120, 0, 0, 0, 0, 0, 200, 0, 0, 100},
        {100, 150, 160, 0, 0, 0, 0, 0, 0, 0},
        {25, 0, 0, 0, 0, 0, 0, 100, 0, 0}
    };

    int sourceChoice, vehicleChoice;
    float fuelRate = 0;
    int speed = 0;

    printf("====================================================================\n");
    printf("     BANGLADESH SMART-LOGISTICS NETWORK OPTIMIZER (v3.2)            \n");
    printf("====================================================================\n");
    
    printf("Select Starting Distribution Hub:\n");
    for (int i = 0; i < MAX; i++) {
        printf("[%d] %-12s ", i + 1, cities[i].name);
        if ((i + 1) % 2 == 0) printf("\n");
    }

    while (1) {
        printf("\nEnter Option (1-10): ");
        if (scanf("%d", &sourceChoice) != 1) {
            printf("Error: Invalid input! Please enter a valid NUMBER (1-10).\n");
            while(getchar() != '\n'); 
            continue;
        }

        if (sourceChoice >= 1 && sourceChoice <= MAX) {
            break; 
        } else {
            printf("Error: Out of range! Please enter a city number between 1 and 10.\n");
        }
    }

    printf("\nSelect Transport Mode for Cost & Time Estimation:\n");
    printf("1. Delivery Van (Speed: 40km/h, Fuel: 12 TK/km)\n");
    printf("2. Heavy Truck  (Speed: 30km/h, Fuel: 25 TK/km)\n");
    printf("3. Express Bike (Speed: 60km/h, Fuel: 5 TK/km)\n");

    while (1) {
        printf("Enter Choice (1-3): ");
        if (scanf("%d", &vehicleChoice) != 1) {
            printf("Error: Invalid input! Please enter 1, 2, or 3.\n");
            while(getchar() != '\n'); 
            continue;
        }

        if (vehicleChoice >= 1 && vehicleChoice <= 3) {
            break;
        } else {
            printf("Error: Invalid choice! Choose between 1, 2, or 3.\n");
        }
    }

    if (vehicleChoice == 1) { speed = 40; fuelRate = 12.0; }
    else if (vehicleChoice == 2) { speed = 30; fuelRate = 25.0; }
    else { speed = 60; fuelRate = 5.0; }

    printf("\n>>> Processing Optimal Routes from %s...\n", cities[sourceChoice - 1].name);
    
    runLogisticsOptimizer(graph, sourceChoice - 1, MAX, cities, fuelRate, speed);
    
    printf("\n====================================================================\n");
    printf("Optimization finished.\n");

    return 0;
}