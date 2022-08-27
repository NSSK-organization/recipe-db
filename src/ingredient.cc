#include <stdio.h>
#include <iostream>
#include "ingredient.h"

using namespace _cookbook;

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

// general-use functions relating to ingredient and ingredient-recipe
 
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
