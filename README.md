## Wellfounded model generator - Datalog evaluator
This project is a generator of compilation-based evaluators for Datalog problems and Wellfounded models for ASP normal encodings.
The typical workflow is the following:
1. Create a generator for logic program
2. Compile the generator
3. Run the generator with a specific instance(facts) for the problem

<!-- USAGE EXAMPLES -->
### Usage
  Compilation of generator
  ```sh
  ./output/main compile encoding 
  ```
  ```sh
  ./output/main generate instance
  ```
  
### Writing your own tests
A simple perl file is contained in the test folder of the project. Such file was used to perform black-box testing of the system.
Anyway, that script should be enough general to allow the user to extend tests if he wants to check that our prototype is generating
the correct results. You can try to make it work following the given steps.

1. Create a folder with the name of you problem under encodings
2. Add you encoding file into that directory
3. Create a folder with the same name of the problem under instances
3. insert how many instances you want in that folder
4. run the script with ./test/testingScript.pl and ,hopefully, it will do the rest

