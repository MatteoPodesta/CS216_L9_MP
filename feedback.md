
**5/26/2025**
*  **feedback.md is for instructor use only. DO NOT change the feedback.md**; make a copy if needed
* class definition style & standards:  first, member vars  none per line and do not forget to initialize them;  second functions: separate group of functions  by a blank line; either matching setter/getter pairs or list all setters back to back and list all getters back to back; start with a default c’tor, followed by  copy c’tor (if any), then other c’tors in the order of increased number of arguments, d’tor- right after c’tor(s), overloaded functions- list them back to back in the order of increased number of arguments;  all accessor/getter functions should be const; all functions with more than one statement should be normal (defined externally, outside of the class and below main()), no inline functions with more than one statement; initialize all member variables to appropriate default values at the time of definition; all member variables must be private; classes must provide a strong exception guarantee; must have default c’tor; implement Rule of Three when necessary
* DMA handling -15
* 387 and like: what if numbers change? if it is not 1 or 0 make it const; in case of ASCII values, use chars, e.g., temp>’a’   -5
* inadequate and/ insufficient test data/ not all possible scenarios and edge cases have been tested; e.g., each record has 4 pieces of data; pow(2,4)->16  possible combinations of valid/invalid and only one of them is a valid record; all menu options should be tested;  no zeros, negative numbers, etc; must test all created functions -5
*  595, 531 both armies will be pointing to the same creatures -5 
* missing operator = -5
* 62-72  and like should call appropriate parent  c’tor -5
* if a class is a parent, the destructor should be virtual -5
* 228 and like: must handle exception before leaving a c’tor; should never abruptly terminate c’tor due to an exception; otherwise, you will have a var Id or reference and no object; if another function throws an uncaught exception while called by a c’tor and the c’tor cannot handle it, the c’tor will terminate prematurely;  having a setter function that sets all member variables, handles all possible exception,   and  is called by all other  setter function, including c’tors, reduces the number of  the catch blocks needed in other functions, like c’tors -5
* 409 what for? redundant logic that results in unnecessary function calls; function calls are computational expense; going through the same array twice instead of once is unnecessary computation expense;  why not do it in line 401; e.g. p= new MyClass(3,5,6) ; -2
* 398 and like: should initialize all pointers to nullptr at the time of definition/allocation; this helps with debugging, DMA, and providing a strong exception guarantee -2
* 417 if you use delete on something that was not dynamically allocated, a compiler might throw an exception; check first, then use delete; new does not return nullptr if fails- it throws bad_alloc exception -2

* 344 and like:  two attack getDamage() + getDamage(); double damage getDamage()*2; -2
* 61 what for ? -2


