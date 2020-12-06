waterboi. 11/28/2020
# DuckDuckGo

@everyone hey hey people, code challenge time, this time with a bit of a theme :duck:

Event lasts 2 weeks babey (28/11 - 12/12)

Submission rules: 
- Add the tag **#DuckDuckGo** .
- Don't post the solution directly in plaintext in the chat. Either:
  - Link to the submission to where I can view it directly, or
  - Spoiler the code (I don't recommend this), or
  - DM me your solution.

I've got this rubber duck sitting on my table. He's understanding, listening, and always there for me. One day, I realized that some people don't have this privilege. That's when I knew something needed to change drastically, starting with these challenges:

## 1. Feeding the masses (50 points)

You're tasked with buying bread for ducks in a pond. Bread is quite cheap, only costing **Y** for a loaf. Each loaf can feed **N** ducks. Given the amount of ducks **D**, calculate the total amount of money you need for feeding all ducks.

### Constraints:
- You can't buy half of a loaf.
- You don't have to account for 1/2 of a duck.
- Account for cents when buying bread (the bread can cost a decimal amount).

### Examples: 

80 ducks  
each loaf feeds 40 ducks  
a loaf costs 2.50  
return: 5  

1 duck  
each loaf feeds 100 ducks  
a loaf costs 3  
return: 3  

5 ducks  
each loaf feeds 2 ducks  
a loaf costs 6  
return: 18  

## 2. Crowd control (50 points)

Some idiot has thrown loaves of bread into a pond without breaking them into small chunks. Duck HQ has taken notice, and is sending out troops to allow for a hasty pickup. Each loaf of bread needs N ducks on each side of the loaf in the water (**excluding sides that touch the pond boundary!**). This also excludes diagonals.

Ducks can stand on top of bread, and duck groups can be placed on the same tile.

You're given a 2d array **A** (representing the pond) where 0 represents water and 1 represents bread and **N**: Calculate the amount of ducks that HQ needs to send out.

You can decide how you want to parse the array. If your language of choice has 2d array's then i'd suggest using that of course. If it doesn't, you can choose to add an extra parameter **S** to represent the size of the pond.

### Examples:

N: 1  
S: 3  
A:  
0 0 0   
0 1 0  
0 0 0  
return: 4  

N: 4  
S: 2  
A:  
0 1  
0 0  
return: 8  

N: 1  
S: 2  
A:  
1 1  
0 0  
return: 4 (ducks can stand on top of bread)  

N: 1  
S: 3  
A:  
0 0 0  
1 0 1  
0 0 0  

return: 6 (two duck groups can stand on the same tile)  

## 3. Build-your-own-duck (150 points)
Reference: https://en.wikipedia.org/wiki/Rubber_duck_debugging

This is this week's creative challenge, and since it's the first one of its type it will likely be updated as the challenge goes on (bear with me pls)

Your task: Create a Rubber Duck you can use for debugging! :D

This can take shape in any way you want! You can create a website, make an app, a Rubber Duck Rest API is also fine!

### Constraints:
- The submission must contain a duck of some form. (ASCII art is fine)
- The user must be able to input some information (text, audio, whatever) into the application.
- The user must be able to get a response from the duck. (doesn't necessarily have to be super specific to the input, but it'd be amazing)