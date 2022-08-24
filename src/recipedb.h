#ifndef RECIPEDB
#define RECIPEDB

#ifndef pinch
#define a 1

#endif // pinch

#ifndef RECIPE
#define RECIPE

typedef step char*;

class recipe {
    public:
        ingredient* allIngredients; // required ingredients
		int numberOfIngredients; // pointer for allIngrdients[]
        int* amounts; // required amounts
        char* units; // corresponding units
        step* steps; // steps
        char* backstory;
        FILE* backstory_file;
};

#endif // RECIPE

#ifndef INGREDIENT
#define INGREDIENT

class ingredient-recipe: public ingredient { // a recipe that is sometimes an ingredient
	// for instance, guac can be a recipe but also an ingredient in 
	// another recipe e.g. burrito
	public:
		ingredient-recipe(recipe, ingredient*, char*); // ctor which takes in
		// ingredients and recipe
};

class ingredient {
    public:
        char* description; // description of the ingredient
        ingredient(recipe, char*); // ctor with recipe and name
		ingredient(char*, char*);  // ctor with name and description
    protected:
        recipe* allRecipes; // all recipes
		int number_of_recipes; // number of recipes
    private:
        ~ingredient(); // destructor should almost never run
		int ingredient_id; // unique ID of ingredient
};

void free_ingredient(ingredient*); // removes ingredient from all recipes

#endif // INGREDIENT

#endif // RECIPEDB
