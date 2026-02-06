# 🚀 Space Mission Optimization

A high-performance **C++ analytical tool** designed to simulate and optimize space resource extraction missions. The application processes complex datasets regarding rockets, asteroids, and market trends to calculate the most profitable mission strategies.

## 📌 Project Overview
The goal of this project is to solve a complex optimization problem: **Maximizing net profit** from asteroid mining while minimizing fuel consumption and operational costs.

The algorithm takes into account multiple constraints:
* **Rocket Efficiency:** Fuel consumption vs. cargo capacity.
* **Dynamic Market:** Resource prices fluctuate based on supply thresholds.
* **Asteroid Composition:** Varying resource types and distances.

## 🛠️ Technical Implementation
Built with **Modern C++** and **Object-Oriented Programming (OOP)** principles.

### Core Architecture
* **Modular Design:** The system is structured into four distinct classes:
    * `Rocket` & `Asteroid`: Store physical attributes and capabilities.
    * `Market`: Handles resource pricing logic and dynamic devaluation.
    * `Mission`: Links entities to calculate specific mission outcomes.
* **Standard Template Library (STL):** Utilizes `std::vector` for dynamic memory management and efficient data storage.
* **Encapsulation:** Strict data protection using private members and public interfaces.

### 🧠 Key Algorithms
1.  **Efficiency Scoring:** Implemented a custom heuristic function `alegereRachetaEficienta` (Efficient Rocket Selection) that calculates a score based on profit-to-cost ratio.
2.  **Sorting & Filtering:** Rockets are sorted by efficiency to prioritize the most viable candidates for specific asteroids.
3.  **Data Processing:** The engine reads raw input data, processes the logic, and generates structured reports.

## 📊 Input & Output (File I/O)
The application parses command-line arguments to read input files and generates four detailed CSV reports:

* **Input:** Structured data files for Rockets, Asteroids, and Market prices.
* **Output:**
    * 📄 `misiuni.csv` - Detailed list of all scheduled missions.
    * 📄 `clasament_rachete.csv` - Rockets ranked by their operational efficiency.
    * 📄 `profit_total.csv` - The final calculated net profit of the simulation.
    * 📄 `profit_resursa.csv` - Breakdown of profit generated per resource type.

## ⚙️ How to Run
This project was developed using **Visual Studio Code** on **Windows**.

1.  **Compile the project:**
    ```bash
    g++ main.cpp misiuni.cpp -o SpaceMission.exe
    ```
2.  **Run the executable with input files:**
    ```bash
    ./SpaceMission.exe input_rockets.txt input_asteroids.txt input_market.txt
    ```
