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

1. Only accept values that are listed in the menu  |Completed|
2. If the user selects a different value, they are asked to choose again |Completed|
3. Menu is printed from a showMenu function |Completed|
4. Menu choices result in calls to functions |Completed|
5. After output of menu choice, show menu again |Completed|
6. Add new products that are able to be produced:
  - Manufacturer, Name, and ItemType 
  - The user should be prompted to enter the Manufacturer, like Apple. Tip: while testing, you can comment out the line that   reads in the user's response and just assign to the variable. |Completed|
  - The user should be prompted to enter the Name, like iPod. Tip: while testing, you can comment out the line that reads in the user's response and just assign to the variable. |Completed|
  - The user should be given a menu choice for ItemType: Audio ("MM"), Visual ("VI"), AudioMobile ("AM"), or VisualMobile ("VM"). |Completed|

  - Optional: save products that can be produced to a text file named catalog.txt |Completed|
7. Track production of products |Completed|
  - Be able to track production for at least one product. |Completed|
    1. Optional: Display the catalog to show the user available products. |Completed|
  - The record for the produced product should include the Manufacturer, Name, ItemType, ProductionNumber, and SerialNumber |Completed|
  - ProductionNumber should be unique, sequential for all products, and automatically assigned.|Completed|
  - The SerialNumber should start with the first three letters of the Manufacturer, then the two letter ItemType code, then five digits (with leading 0s if necessary) that are unique and sequential for the item type. The entire Serial Number should be automatically assigned. |Completed|
  - Save records of production to a text file named production.txt in a format like Production Number: 1 Serial Number: AppAM00001
    1. Create a repl in repl.it demonstrating saving to a file and include a link to the repl in your README.
    LINK: https://repl.it/@DaltonSenseman/Saveing-to-a-file |Completed|

8. Optional: Music Players store AudioSpecification (the file format, like wav or mp3) and MediaType (what stores the audio file  like CD, DVD, Blu-Ray), both input by the user. |Completed|
9. Optional: Movie Players store MonitorType, which is a Screen. |Completed|
  1.Screen stores: resolution, refresh rate, response time. |Mostly Completed|


#### Sprint 3 - Arrays and Vectors, Searching and Sorting

   1. Store the products that are able to be produced in a collection. |Completed|
   2.  When tracking production of products, the user should be prompted to enter the product to be produced from the collection of products that are able to be produced. |Completed|
   3. The record of products produced should be stored in a collection. |Completed|
   4. Output the products that can be produced sorted by name. |Completed|
   5. Given a Serial Number, output the Production Number   |Completed|
   
#### Sprint 4 - Pointers, Characters, Strings, Recursion

   1. Create an Employee account. 
      * Allow user to input full name in format FirstName LastName.  |Completed|
      * Generate user id, which is their first initial and surname in all lowercase |Completed|
   2. Allow user to input a password for the user |Completed|
      * The password must contain at least one digit, at least one lowercase letter, and at least one uppercase letter. The password cannot contain a space or any other symbols.  |Completed|
      * Use a recursive function to encrypt the password.  |Completed|
   3. Optional: Require users to log in. Track which employee recorded production.
