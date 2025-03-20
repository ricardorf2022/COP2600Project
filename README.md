[![OpenSSF Scorecard](https://api.scorecard.dev/projects/github.com/{ricardorf2022}/{COP2600Project}/badge)](https://scorecard.dev/viewer/?uri=github.com/{owner}/{repo})

Produce Stand Inventory Management System
Overview
This project is a simple inventory management system for a produce stand. It allows users to add, remove, find, update, view, save, and load product information. The program is built using C++ and uses file handling to save and retrieve inventory data.

Features
Add new products to the inventory
Remove existing products
Find products by ID
Update product details (name, category, price, quantity)
View all products in inventory
Save inventory to a file
Load inventory from a file

Technologies Used
C++
File handling (CSV format for saving and loading data)

Installation
Clone the repository:
git clone https://github.com/yourusername/produce-inventory.git

Navigate to the project directory:
cd produce-inventory

Compile the program using a C++ compiler:
g++ -o inventory inventory.cpp

Run the executable:
./inventory

Usage
Upon running the program, you will be presented with a menu:

Add a new product
Remove an existing product

Find an existing product
Update a product
View all products
Save inventory to file
Load inventory from file
Exit the program

Example Usage:
Adding a product:
Enter the product ID, name, category, price, and quantity.

Finding a product:
Enter the product ID to retrieve its details.

Updating a product:
Choose to update name, category, price, or quantity.

Saving/Loading:
Save inventory to a file and reload it later.

File Format
Inventory is saved in a CSV file (inventory.csv) with the format:
id,name,category,price,quantity

Example:
101,Apple,Fruit,0.99,50
102,Banana,Fruit,0.59,100

Contributing
Fork the repository.

Create a new branch:
git checkout -b feature-branch

Make your changes and commit:
git commit -m "Added a new feature"

Push to the branch:
git push origin feature-branch
