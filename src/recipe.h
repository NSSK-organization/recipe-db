#ifndef RECIPE
#define RECIPE

namespace _cookbook {
	
	typedef char* step;

	class recipe {
    	public:
        	ingredient* allIngredients; // required ingredients
			int numberOfIngredients; // pointer for allIngrdients[]
        	int* amounts; // required amounts
        	char* units; // corresponding units
        	step* steps; // steps
    	    char* backstory;
	};

}

#endif // RECIPE

