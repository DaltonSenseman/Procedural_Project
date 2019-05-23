# Procedural_Project
Procedural code project for F.G.C.U. COP 2001 Programming Methodology

#### Contained within is the source code

# Overview of the project
This project is for my COP-2001 Programming Methodology at Florida Gulf Coast University (F.G.C.U.) the aim of this project is to create a intentory system for a fictitious company called OraclProduction Ltd. The program is to be a console driven program using only procedural programming with no use of classes in C++.
Users should be able to create employee profiles in the system, increase product counts, add new products, display currect counts on each item and information on the item, new products can be added at any point, and production statistics can be veiwed. 

### Planning Outline 

#### Goals
* Effectively track and manage inventory

#### Success Criteria
* Pass tests in Repl.lt
* Constraints
* C++
* Procedural (no OOP)
* Individual project
* Assumptions

#### Stakeholders
* Reality: Professor, myself, potential employers
* Pretend: CTO, Users, customers, warehouse, help desk I.T., programmer
#### Timelines
* 6-week course
* Deliverable weekly


# Product Backlog(PBL)
   * The program will be a menu driven console program.  
   * The program must use procedural programming only, no classes. 
   * Employee accounts can be made.
   * Products that can be made: Music Player, Movie Player
   * Allow a user to Add a new product and to specify how many items of that product should be created. The program will then create these items and store them in a collection.
   * The collection can be displayed at any time.
   * New Products can be added at any time.
   * Production statistics can be displayed – Total items produced, number of each item, the number of unique products created etc.

## Sprints

#### Sprint 1 Backlog(SBL)
1. Output a greeting and menu in main. |Completed|

#### Sprint 2 Backlog(SBL)
Sprint 2 Backlog (SBL) - Conditions, Loops, Functions, Files intro. 

1. Only accept values that are listed in the menu
2. If the user selects a different value, they are asked to choose again
3. Menu is printed from a showMenu function
4. Menu choices result in calls to functions
5. After output of menu choice, show menu again
6. Add new products that are able to be produced:
  - Manufacturer, Name, and ItemType 
  - The user should be prompted to enter the Manufacturer, like Apple. Tip: while testing, you can comment out the line that   reads in the user's response and just assign to the variable. 
  - The user should be prompted to enter the Name, like iPod. Tip: while testing, you can comment out the line that reads in the user's response and just assign to the variable.
  - The user should be given a menu choice for ItemType: Audio ("MM"), Visual ("VI"), AudioMobile ("AM"), or VisualMobile ("VM").

  - Optional: save products that can be produced to a text file named catalog.txt
7. Track production of products
  - Be able to track production for at least one product. 
    1. Optional: Display the catalog to show the user available products. 
  - The record for the produced product should include the Manufacturer, Name, ItemType, ProductionNumber, and SerialNumber 
  - ProductionNumber should be unique, sequential for all products, and automatically assigned.
  - The SerialNumber should start with the first three letters of the Manufacturer, then the two letter ItemType code, then five digits (with leading 0s if necessary) that are unique and sequential for the item type. The entire Serial Number should be automatically assigned. 
  - Save records of production to a text file named production.txt in a format like Production Number: 1 Serial Number: AppAM00001
    1. Create a repl in repl.it demonstrating saving to a file and include a link to the repl in your README.

8. Optional: Music Players store AudioSpecification (the file format, like wav or mp3) and MediaType (what stores the audio file  like CD, DVD, Blu-Ray), both input by the user.
9. Optional: Movie Players store MonitorType, which is a Screen.
  1.Screen stores: resolution, refresh rate, response time.
