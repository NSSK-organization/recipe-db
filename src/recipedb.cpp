#include "recipedb.h"
#include <iostream>
#include <stdio.h>
#include <cstdlib>

using namespace _cookbook;

namespace _cookbook {
	char* default_description = "There is no set description for this ingredient.\n";

	char** allowed_units = {"tbsp.", "tsp.", "oz.", "lb.", "fl. oz.", "pinch", "cup", "cups"};

	char** ingredient_names;
	int ingredient_total = 0;

	bool new_ingredient(char* ingredient_name) {
		for(int i = 0; i < ingredient_total; i++) {
			if(ingredient_name == ingredient_names[i])
				return false; // not a new ingredient
		}
		ingredient_names[ingredient_total++] = ingredient_name;
		return true; // it is, in fact, a new ingredient
	}
}

// ingredient implementation begins here

ingredient::ingredient(recipe myRecipe, char* name) { // ctor with recipe and name

	this = new ingredient; // for destructor

	// exists if user decides to automatically introduce a previosly-unheard of ingredient
	
	if(new_ingredient(name) == false) {
		std::cerr << "Error: attempted to create a new ingredient that already exists (System Error).\n" << std::endl; 
		exit(-1);
	}
	// by default, _cookbook::new_ingredient should modify _cookbook::ingredient_list and add the new ingredient name to it.
	
	myRecipe.allIngredients[numberOfIngredients++] = this;
}


ingredient::ingredient(char* name, char* description = default_description) { // ctor with recipe and description

	this = new ingredient; // for destructor

	if(new_ingredient(name) == false) {
		std::cerr << "Error: attempted to create a new ingredient that already exists (User Error).\n" << std::endl;
		exit(-1);
	}
	// by default, _cookbook::new_ingredient should modify _cookbook::ingredient_list and add the new ingredient name to it.
	
	myRecipe.allIngredients[numberOfIngredients++] = this;
}

ingredient::~ingredient() { // destructor, should almost never be called
	delete this;
}

// ingredient-recipe implementation begins here

ingredient-recipe::ingredient-recipe(recipe firstRecipe, ingredient* ingredients, char* name) {
	this = new ingredient; // for destructor
						   
	if(new_ingredient(name) == false) {
		std::cerr << "Error: attempted to create a new ingredient that already exists (User Error)." << std::endl;
	}

	myRecipe.allIngredients[numberOfIngredients++] = this;
}

ingredient-recipe::~ingredient-recipe() {
	delete this;
}

// general functions

void free_ingredient(ingredient* ing) {
	for(int i = 0; i < number_of_recipes; i++) {
		recipe r = *ing->allRecipes[i]; // current recipe
		for(int j = 0; j < r.numberOfIngredients; j++) {
			if(r.allIngredients[j] == *this) {
				r.allIngredients[j] = NULL;
				break;
			}
			continue;
		}
	}

	for(int i = 0; i < number_of_recipes; i++)
		ing->allRecipes[i] = NULL;
}
