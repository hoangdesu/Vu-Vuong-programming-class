In this exercise you will write C++ code that is part of a Recipe Management System.. The system involves a base class Recipe, a derived class DessertRecipe, and a RecipeCollection class to manage the catalog. The tasks for you to complete are detailed below.

You are provided with the following files:

main.cpp: this contains code which you can use to develop your code. It will not be used in the unit tests.

Base class:

Recipe.h: (header file) you will add assessed C++ code in this file
Recipe.cpp: contains the member function definitions and implementation details (this file is hidden)
Derived class:

DessertRecipe.h: (header file) you will add assessed C++ code in this file
DessertRecipe.cpp: you will write assessed C++ code in this file
Class to manage the catalog of recipes:

RecipeCollection.h: header file (read only)
RecipeCollection.cpp: you will write assessed C++ code in this file
utilities.h - includes escapeString to print representation of a string to show special characters e.g. \n

Task 1

Given the base class Recipe (see file Recipe.h) complete the derived class DessertRecipe with the constructor:

DessertRecipe(std::string name = "Unknown", int prepTime = 0, 
              int servings = 0, bool isGlutenFree = false);
This constructor has 4 parameters:
name, prepTime, servings, and isGlutenFree
The parameter values should be assigned to the respective data members
Task 2

Override the info function in the DessertRecipe class.

std::string info() const;
This function should:

return a string containing details about the recipe (format shown in example below)
HINT

the info function will override the definition in the base class Recipe so you will need to declare it as virtual in the Recipe class (header file)
Example for the following:

DessertRecipe cake = DessertRecipe("Chocolate Cake", 60, 8, false);
cake.info();
should return the following string:

"Dessert Recipe: Chocolate Cake, Prep Time: 60 mins, Servings: 8, Gluten-Free: No"
NOTE all separating spaces such as between Dessert and Recipe are single (i.e. one space character ' ')

Task 3 Implement the following function:

std::string listAllRecipes() const;
This function should:

return a formatted string containing details of all recipes
use the format shown in the example below
Example

For the following:

RecipeCollection collection;
collection.addRecipe(new Recipe("Spaghetti Carbonara"));
collection.addRecipe(new DessertRecipe("Chocolate Cake", 60, 8, false));
collection.addRecipe(new DessertRecipe("Fruit Salad", 15, 4, true));
collection.listAllRecipes();
should return the following string:

"Recipe: Spaghetti Carbonara\nDessert Recipe: Chocolate Cake, Prep Time: 60 mins, Servings: 8, Gluten-Free: No\nDessert Recipe: Fruit Salad, Prep Time: 15 mins, Servings: 4, Gluten-Free: Yes\n"
NOTE

all separating spaces are single (i.e. the character ' ')
whilst the definition of the member functions for the base class Recipe are hidden, they are available for use in your code. For example, as shown above for addRecipe. The same is true for the info function of the base class Recipe.



#include <iostream>
#include "Recipe.h"
#include "Recipe.cpp" // you can use this class (hidden)  
#include "DessertRecipe.h"
#include "RecipeCollection.h"
#include "utilities.h" // contains escapeString to show escape characters e.g. \n (hidden)


int main() {
   DessertRecipe cake = DessertRecipe("Chocolate Cake", 60, 8, false);
   std::string cake_str = cake.info();
   std::cout << escapeString(cake_str) << "\n"; 
   
   RecipeCollection collection;
   collection.addRecipe(new Recipe("Spaghetti Carbonara"));
   collection.addRecipe(new DessertRecipe("Chocolate Cake", 60, 8, false));
   collection.addRecipe(new DessertRecipe("Fruit Salad", 15, 4, true));
   std::string list = collection.listAllRecipes();
   std::cout <<  escapeString(list);
   
   return EXIT_SUCCESS;
}



#ifndef RECIPE_H
#define RECIPE_H

#include <string>

class Recipe {
protected:
   std::string name;
public:
   Recipe(std::string name = "Unknown");
   virtual std::string info() const;
   std::string getName() const { return name; }
};

#endif 


#ifndef DESSERTRECIPE_H
#define DESSERTRECIPE_H

#include "Recipe.h"

class DessertRecipe : public Recipe {
private:
   int prepTime;        
   int servings;        
   bool isGlutenFree;   

public:
   DessertRecipe(std::string name = "Unknown", int prepTime = 0, int servings = 0, bool isGlutenFree = false);
   std::string info() const override;
};

#endif 

#include "DessertRecipe.h"
#include <iomanip>
#include <sstream>

using namespace std;


DessertRecipe::DessertRecipe(std::string name , int prepTime , 
              int servings, bool isGlutenFree)
         :  Recipe(name), prepTime(prepTime), servings(servings), isGlutenFree(isGlutenFree) {}


// DessertRecipe::DessertRecipe(std::string name , int prepTime , int servings, bool isGlutenFree) {
//    this.name = name;
// }
         
         
string DessertRecipe::info() const {
   std::ostringstream os;
   os << std::left;
   os << "Dessert Recipe: " << name << ", "; 
   os << "Prep Time: " << prepTime << " mins, ";
   os << "Servings: " << servings << ", ";
   
   if (!isGlutenFree) {
   os << "Gluten-Free: " << "No";
   } else if (isGlutenFree) {
      os << "Gluten-Free: " << "Yes" ;
   }
   return os.str();
}


#ifndef RECIPECOLLECTION_H
#define RECIPECOLLECTION_H

#include "Recipe.h"
#include <vector>
#include <string>
#include <sstream> 

class RecipeCollection {
private:
   std::vector<Recipe*> recipes;
public:
   void addRecipe(Recipe* recipe);
   std::string listAllRecipes() const;
};

#endif 


#include "RecipeCollection.h"
using namespace std;

void RecipeCollection::addRecipe(Recipe* recipe) {
    recipes.push_back(recipe);
}


std::string RecipeCollection::listAllRecipes() const {
   std::ostringstream os;
   
   for (const auto& recipe : recipes) {
        os << recipe->info() << "\n" ;
   }
   return os.str();
   
}

