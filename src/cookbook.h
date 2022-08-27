#ifndef COOKBOOK
#define COOKBOOK

// _cookbook namespace, meant for user customization.
// For instance, the user can add new units, change the default description
// for ingredients, etc.
//
// These are, essentially, global variables.

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

#endif // COOKBOOK
