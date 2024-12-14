[![Review Assignment Due Date](https://classroom.github.com/assets/deadline-readme-button-22041afd0340ce965d47ae6ef1cefeee28c7c493a6346c4f15d667ab976d596c.svg)](https://classroom.github.com/a/ZtnUc6k_)
[![Open in Codespaces](https://classroom.github.com/assets/launch-codespace-2972f46106e565e64193e422d61a12cf1da4916b45550586e14ef0a7c637dd04.svg)](https://classroom.github.com/open-in-codespaces?assignment_repo_id=17535741)
# Homework 7

## Assignment Goals
The goal of this project is to:
1.	Familiarize students with **graphs**
2.	Allow students a chance to **choose** their data structure storage method

## Program
### Overview
**The Traveling Salesman Problem**  
Consider 5 cities of interest:
1. Reno
2. San Francisco
3. Salt Lake City
4. Seattle
5. Las Vegas

Use information on available maps to determine the distance (in miles) from one city to the other. Assume a fixed fuel efficiency metric of 40 mpg (miles per gallon) and derive the cost of each path *in terms of gas*. 

## Requirements
Solve the Traveling Salesman Problem such that traveling salesman starts from Reno, visits all cities in the above list and returns to Reno. Solve this problem in the brute force-way, i.e. by identifying all possible paths. Use a graph (with each of its vertices corresponding to one of these cities and its edges being weighted by the associated miles for each trip) to determine the cost of each path.  

**Note:** if (and only if) to go from city A to B you must go through C then you must add one edge from A to C and one edge from C to B and there is no need to add an edge directly from A to B.

### Deliverables
The Graph Interface has already been provided for you in this repository. Your submission should include
- Your source code
  - a *modular* main driver
  - the **complete** implementation for your Graph Class
  - any additional class implementations (including other data structures)
- a .txt file with your initial values for the miles from one city to the other
- a .txt file which includes all possible paths and the best one selected by the algorithm

## Submission details
If you are usinng git from the command line, execute the following commands:
1.	After accepting the assignment invitation, copy the clone URL
2.	Type 
```git clone clone URL```
3.	cd into your new assignment directory
4.	After working on your files
5.	When you’re ready, type the following commands: 
```
git add .
git commit -m “your commit message”
git push
```
## Academic Honesty
Academic dishonesty is against university as well as the system community standards. Academic dishonesty includes, but is not limited to, the following:
Plagiarism: defined as submitting the language, ideas, thoughts or work of another as one's own; or assisting in the act of plagiarism by allowing one's work to be used in this fashion.
Cheating: defined as (1) obtaining or providing unauthorized information during an examination through verbal, visual or unauthorized use of books, notes, text and other materials; (2) obtaining or providing information concerning all or part of an examination prior to that examination; (3) taking an examination for another student, or arranging for another person to take an exam in one's place; (4) altering or changing test answers after submittal for grading, grades after grades have been awarded, or other academic records once these are official.
Cheating, plagiarism or otherwise obtaining grades under false pretenses constitute academic
dishonesty according to the code of this university. Academic dishonesty will not be tolerated and
penalties can include cancelling a student’s enrolment without a grade, giving an F for the course, or for the assignment. For more details, see the University of Nevada, Reno General Catalog.
