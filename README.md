# Calendar App 
 > Authors: [Charles Hong](https://github.com/Charles-Hong520), 
 > [Kunal Mittal](https://github.com/KunalMittal322), 
 > [Zhiyuan Wen](https://github.com/zhiyuanwen)

## Project Description
 > We decided to do a calendar because with the current outside situation, calendars have become an important tool in managing everyday lives. Our plans for the calendar are to just add events(pre-made) at the user’s request and later on, we can determine how busy the user is per day, week, or month providing more information and recommending possible alterations to their schedule.
 > * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
 >   * [Qt](https://www.qt.io/) - GUI tool, will only use this provided we're ahead of schedule
 >   * [OpenGL](http://www.opengl-tutorial.org/) - GUI tool, will only use this provided we're ahead of schedule
 > * What will be the input/output of your project?
 >   * Command line Interface(input and output)
 >     * Input: We can have a simple line by line or specifically formatted prompt for the user to enter, or we can use an algorithm to parse the user's request to add an event to the calendar. This will be easier for the user, but harder to implement.
 >     * Output: multiple lines of printing the calendar events. They can be displayed in different ways chosen by the user.
 >   * Possibly GUI interface(input and output) <- this is only if we finish the command line interface first
 > * What are the three design patterns you will be using. Explain in 3 - 5 sentences why you picked this pattern and what feature you will implement with it
 >     * Strategy: This design pattern is rather simple and is probably present in many, many projects. We're planning on using an algorithm that determines how busy you are in a day, depending on how busy you are the calendar will give you suggestions. Aside from this, strategy may have more instances of itself if we decide to implement more algorithms
 >     * Observer: Depending on what point of "view" the user has, the output must be different. Similar to how the apple calendar expresses it's events to the viewers depending on if you're in month, week, or day. For example, if we look at a day, we should able to seem the specific time slots per day, whereas if we looked at it from a month point of view, all you should see is if you have a meeting on that day. In addition, we're planning on making labels of appointments. meetings, or breaks so depending on what label you have, that can alter what pops up e.g: if it's a busy day just show the events, if it's a day filled with breaks maybe suggest moving your workload around.
 >     * Abstract Factory: Originally we were considering using the Singleton method but we instead decided to switch to this as this design as more uses/functionality. Like we mentioned before, we are planning on creating a multitude of labels which are derived from an event. This means that we are going to try and make "Events" abstract and made subclasses like "Break", "Appointment", etc. 

 ### Design Document
 
 > ![PDF of Diagram](https://github.com/cs100/final-project-chong039-kmitt006-zwen012/blob/master/CS100P2.pdf)
 > * Strategy Pattern (Busyness Index)
 >   * Our strategy pattern will incorporate a class that determines what to do based on how busy you are that day, week, month
 >   * The strategy pattern will have an abstract class with a subclass that returns the business index based on day, week, or month. For example, if you wish to know how busy you are in a day, it would use an algorithm that calculates how busy you are within a 24 hr period, for example you could have like 5 events each taking up half an hour and you wouldn’t be that busy. If you wanted to check how busy you were in a week you would use a similar algorithm to that of day, but instead you would assume that your events and times are evenly distributed and that may return a different output rather than just focusing on one day, the same applies to a month.
 > * Observer Pattern (Time State)
 >   * This pattern determines how the user determines what view they’re looking at for the calendar, eg day, week, or month
 >   * The Observer pattern will be similar to the strategy pattern in the sense that there will be an abstract class that is in charge of determining the unit of time (day, week, and month) through an abstract class with subclasses like day, week, and month. The point of this class is to just set the state of the viewpoint for the user similar to that of the apple calendar so when the user enters what they want to see, we change the state just like that through the observer class.
> * Abstract Factory Pattern (Making all the objects and stuff)
>   * This pattern basically determines how we’re going to make events for people which can vary from doctor’s appointments to basic meetings
>   * The abstract factory pattern will create an event, but rather than just making it a chunk of time with a string description we will have premade events for the user to select from so they can just ask for the event and it’s automatically generated similar to how we choose classes at UCR. In addition to this, since the class is a creation based abstract factory class we can choose to add more and more events and nothing should have any major changes.

 
## Class Diagram
 > ![PDF of Final OMT Diagram](https://github.com/cs100/final-project-chong039-kmitt006-zwen012/blob/master/CS100FinalOMT.pdf)
 >
 > See above Design Document explanations for the 3 design patterns
 ## Screenshots
 > * BusynessIndex and Adding Event tests
 > ![Busyness and Event tests](https://github.com/cs100/final-project-chong039-kmitt006-zwen012/blob/master/Screen%20Shot%202020-12-09%20at%208.54.03%20PM.png)
 > * Observer display tests
 >
 > ![Display test 1](https://github.com/cs100/final-project-chong039-kmitt006-zwen012/blob/master/Screen%20Shot%202020-12-09%20at%208.59.07%20PM.png)
 > ![Display test 2](https://github.com/cs100/final-project-chong039-kmitt006-zwen012/blob/master/Screen%20Shot%202020-12-09%20at%208.59.28%20PM.png)
 >
 > ![Display test 3](https://github.com/cs100/final-project-chong039-kmitt006-zwen012/blob/master/Screen%20Shot%202020-12-09%20at%208.59.34%20PM.png)
 > * User input file example
 > ![User input file example](https://github.com/cs100/final-project-chong039-kmitt006-zwen012/blob/master/Screen%20Shot%202020-12-09%20at%208.32.25%20PM.png)
 > * User output file example
 > ![User output1](https://github.com/cs100/final-project-chong039-kmitt006-zwen012/blob/master/Screen%20Shot%202020-12-09%20at%208.36.31%20PM.png)
 > ![User output2](https://github.com/cs100/final-project-chong039-kmitt006-zwen012/blob/master/Screen%20Shot%202020-12-09%20at%208.36.43%20PM.png)
 ## Installation/Usage
 > * Install on your computer with git clone --recursive https://github.com/cs100/final-project-chong039-kmitt006-zwen012
 > * cmake3 . and make to generate test files
 > * ./test will run test cases for making events and testing busyness, ./print_test will give examples of displaying events, ./main will run the entire program as a whole.
 > * You can also run ./main < {input file} to have all inputs on seperate lines as shown in User input file example instead of having to input one by one.
 ## Testing
 > For the classes in our OMT diagram, with the exception of the client, we used googletest and eventually fit all of our tests into one big test file that we can run in one command with ./main.
 > For our final product we just used an input file as our client input, and the client code took care of the rest. From our perspective, it was a success although there are more things to implement.
