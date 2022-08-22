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
        int* amounts; // required amounts
        char* units; // corresponding units
        step* steps; // steps
        char* backstory;
        FILE* backstory_file;
};

#endif // RECIPE

#ifndef INGREDIENT
#define INGREDIENT

class ingredient {
    public:
        char* description; // description of the ingredient
        ingredient(recipe, char*); // ctor
    protected:
        recipe* allRecipes; // all recipes
    private:
        ~ingredient(); // destructor should almost never run
};

#endif // INGREDIENT

#endif // RECIPEDB