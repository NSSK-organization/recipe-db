#ifndef INGREDIENT
#define INGREDIENT

namespace _cookbook {

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

	class ingredient-recipe: public ingredient { // a recipe that is sometimes an ingredient
		// for instance, guac can be a recipe but also an ingredient in 
		// another recipe e.g. burrito
		public:
			ingredient-recipe(recipe, ingredient*, char*); // ctor which takes in
			// ingredients and recipe
	};

	void free_ingredient(ingredient*); // removes ingredient from all recipes

}

#endif // INGREDIENT
