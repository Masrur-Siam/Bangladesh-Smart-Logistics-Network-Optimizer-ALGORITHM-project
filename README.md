# Bangladesh Smart-Logistics Network Optimizer (v3.2)

A professional C-based navigation and logistics optimization system designed to determine the shortest path between 10 major cities in Bangladesh using **Dijkstra's Algorithm**.

## 🚀 Overview
In modern supply chain systems, minimizing transportation cost and delivery time is essential. This project automates route planning for logistics services, providing:
- The absolute shortest distance between cities.
- Optimized route path tracking (e.g., Dhaka -> Cumilla -> Chittagong).
- Real-time travel time and fuel cost estimations based on vehicle types.

## ✨ Features
- **Smart Pathfinding:** Implements Dijkstra's Algorithm with a time complexity of $O(V^2)$.
- **Logistics Estimation:** Supports multiple transport modes:
  - 🚐 **Delivery Van:** 40km/h | 12 TK/km
  - 🚛 **Heavy Truck:** 30km/h | 25 TK/km
  - 🏍️ **Express Bike:** 60km/h | 5 TK/km
- **Robust Input Validation:** Handles invalid choices and non-numeric inputs gracefully without crashing.
- **Detailed Reporting:** Generates a formatted table showing distance, time, cost, and the specific route plan.

## 🛠️ Technology Stack
- **Language:** C
- **Algorithm:** Dijkstra's Shortest Path
- **Data Structure:** Adjacency Matrix & Structs
- **Tools:** GCC Compiler, VS Code / Code::Blocks

## 📝 How to Use
1. **Clone the repository:**
   ```bash
   git clone [https://github.com/Masrur-Siam/Bangladesh-Smart-Logistics-Network-Optimizer-ALGORITHM-project.git](https://github.com/Masrur-Siam/Bangladesh-Smart-Logistics-Network-Optimizer-ALGORITHM-project.git)
