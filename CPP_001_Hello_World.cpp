//Your first C++ program :-) - 2004/2022 C. S. Germany

/*

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

A. Object Oriented vs. Procedural Languages

C++, like Java, C# and Python, is object-oriented, and was the very first major OOP language. It is just one tool among many for today's developers.
It's primary advantage over other languages is that it can produce software with greater power, speed, and efficiency.  It gives the developer far more
control over memory management than other languages with pointers, reference, polymorphism, advanced indirection, bitwise manipulation, and precise 
control over objects stored on both the stack and the heap (free store). 

It's disadvantage is that it is less forgiving and can be more complex than other OOP languages that manage memory automatically. Many new object-oriented
languages like Python and PowerShell hide many of the most powerful object-oriented structures and functionality from the developer with the goal of
simplifying the language and hiding its complexity. But if you know C++ as a foundation OOP language, it can give you insight and creativity with the 
newer languages because C++ can give you the ability to peek "under the hood" and see what many of those languages are hiding from the developer.
This greatly increases development time.  Many projects can be developed faster in mor emodern languages, at the cost of efficiency in the finished
application. In choosing this language to develop in, one needs ample time and resources. It takes longer many times to develop projects in C++, but it
is still used today for projects that require speed and memory control and efficiency at run-time.

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

B. C++ is the Foundation from Which Most Modern Object-Oriented Languages Have Been Built

One of the things that sets C++ apart from C which gave birth to it as a language is its use of classes and structures, which provide "encapsulation". C++
was the pioneer, the first truly object-oriented language designed from its foundation with OOP structures and functionality. It was a major advancement
from all the languages which came before it. It has served as the foundation from which most new, modern object-oriented languages have been built. C++ is
like the "Latin" of modern computer languages. You may choose a more modern and less complex language to develop your projects in these days.

Whereas procedural languages such as C or FORTRAN would use functions in a more linear fashion, object-oriented languages attempt to emulate real world
systems and structures more closely than procedural programming. In the past computers weren't as powerful and memory was very expensive. As a result,
programs were largely console or command prompt based (i.e. DOS, Unix without X Windows). Software was written in a linear and procedural manner with the
primary goal of the developer being to optimize efficiency when running their software on slow processors. They had to squeeze every available iota of
usefulness out of limited, paltry and expensive amounts of memory.  Rich multimedia, power and vast capabilities weren't as important as simply coding
something that could run on a bare minimum of expensive hardware. But then - Moore's Law happened.

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

C. Moore's Law

Over time, computers exponentially increased in speed and sophistication in fulfillment of Gordon Moore's "Law of Accelerating Returns", theorized in 1965.
Moore's Law predicts that the number of transistors per integrated circuit doubles every 18 months.  Doubling transistors effectively means doubling the
binary on/off calculations per second in the same amount of space using the same amount of raw material. This miniaturization and resource efficiency both
increases speed and lowers the cost of production. Each cycle of development in technology feeds the subsequent wave, yielding an exponential increase.  

To illustrate this concept, look at a brief history of technological advancement:

1822 - Charles Babbage, "The Difference Engine"
1832 - Charles Babbage, "The Analytical Engine", 1st computer though never worked
1843 - Ada Lovelace, 1st programmer, Speculates on a computer's ability to emulate human intelligence.
1871 - Charles Babbage dies.
1877 - William Thomson (Lord Kelvin) demonstrates computers can be programmed
1927 - Heisenberg's uncertainty principle. 5 Years later Quantum Mechanics by Neils Bohr and Werner Heisenberg.
1928 - Minimax theorem, Jon Vann Neumann, used in game programs.
1928 - 1st television
1930 - 60% all houses have radio
1931 - incompleteness theorem
1931 - electron microscope
1937 - Alan Turing, Turing Machine
1937 - Turing and Church state that all problems that human can solve can be reduced to set of algorithms solved by machine
1940 - "ABC", 1st electronic non-programmable PC.
1940 - "Robinson", 1st operational computer, uses electro-mechanical relays to decode ENIGMA in WWII.
1941 - Z3, 1st programmable digital computer.
1943 - "Colossus", uses tubes 1,000 times faster than relays in "Robinson". Decodes more German code.
1944 - "Mark I", Howard Aiken, uses tubes and punch paper for programming, 1st programmable built by American.
1945 - Stored program concept published.
1946 - ENIAC, 1,000 times faster than Mark I, 1st electronic, programmable, general-purpose computer.
1946 - .02% of Americans own TV
1947 - transistor invented
1949 - EDSAC, 1st stored-program computer
1949 - George Orwell's "1984"
1950 - Alan Turing presents "Turing Test"
1950 - color TV 1st broadcast, B and W TV now trans-Atlantic
1951 - EDVAC, 1st computer to use stored-program concept
1952 - UNIVAC, owned by CBS television, successfully predicts election of Eisenhower
1952 - IBM 701, 1st computer for mass production
1953 - chemical structure of DNA
1955 - William Shockley Semiconductor laboratory founded starting silicon valley
1955 - U.S. Develops 1st design for industry robot
1955 - IPL II, 1st AI language
1956 - "The Logic Theorist", uses recursive search techniques
1956 - FORTRAN invented
1956 - MANIAC I, 1st computer to beat a human at chess
1956 - term "Artificial Intelligence" coined
1957 - General Problem Solver, uses recursive search to solve problems
1958 - 1st integrated circuit
1958 - LISP, AI language created
1958 - CDC 1604, Seymour Cray, builds 1st full transistor supercomputer.
1959 - computer beats humans at checkers
1959 - COBOL developed
1959 - 1st Xerox copier
1960 - 1st laser, ruby rod
1960 - 6,000 computers in operation in the US.
1956 - 72% of homes have television
1983 - 93% of homes have television

Note: You can see that technological advances increase exponentially and algorithmically.  Each advance increases the velocity of subsequent advances.
Since 1983 we have seen technology literally consume, envelop and re-define the world around us.  We can only assume that as all branches of science
and technology continue to build upon the works of others, computer technology will continue to transform our lives in ways we can't even imagine, and
that these changes will occur at an ever-increasing velocity.  How many of us have experienced the bitter sorrow of purchasing the fastest CPU or some
ultimate piece of computer hardware, only to find that before we can carry it home and take it out of the box there's something even more powerful,
compact, faster and cheaper being advertised in the evening newspaper?

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

D. 3. Event-based Programming and GUIS vs. Console Programming and Procedural Input

Today, most popular operating system environments employ a graphical user interface (GUI) such as are Microsoft's "Windows" and Linux's/Unix's window
manager, "X Windows". Both of these popular environments provide for "event based" input in a program. Event based input is random and unpredictable
input. A user no longer has to follow a linear path of commands typed at a command prompt to access a particular part of a program. She or he can now,
randomly and at will, access any part of a Windows or X Windows program from any other part. Event-based input adds great power, versatility, and
functionality to a program for the end-user. But for the programmer, it adds complexity and all sorts of logic and bullet-proofing issues to resolve.
Unpredictable sequences of events from the user must be foreseen and accounted for in the debugging process. Windows and X Windows graphical user
interfaces, event-based input, continuous production of faster and more powerful computers that are less and less expensive, and object oriented
programming have all combined to make possible the creation of software of a complexity never before imagined. 

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

E. The 4 Pillars of Object-Oriented Development

1. Encapsulation - doing one well-defined thing completely. This began with functions and methods, but C++ encapsulates more completely by combining
                   methods and data members into self-contained CLASSES.  Components should be built that have specific properties - a developer should
                   be able to plug them into his or her program as needed.  This treats data and procedures that act upon the data as a single "object"
                   - a self-contained entity with an identity and certain characteristics of its own.

2. Data Hiding - The inner workings of classes should be hidden. The prevailing philosophy for developing complex software is that you don't need to
                 know how all the library and foundation classes and precompiled code work, simply how to use them.  This enables adding complex functions
                 and routines to code without having to "re-invent the wheel", so to speak.  It speeds up development time through the use of encapsulated
                 libraries of code, functions and classes that each perform a specific task and snap together in a "Lego-like" fashion. They are then used
                 in constructing larger and more complex bodies of code that incorporate these functions and the whole becomes more than the sum of its
                 parts.  Data Hiding also provides greater security and flexibility by making it possible to examine relevant portions of source code
                 without seeing the source in its entirety.  Entire classes and libraries can be utilized by parts of a program through passing arguments
                 and parameters to accessor methods.

3. Inheritance - Reuse, reuse, reuse!  Don't reinvent the wheel.  A new type can be declared as an extension of an old type, a sub class of an existing
                 class, or derived types and classes from base classes.  In this way, methods and attributes can be incorporated into derived objects
                 without having to be repeated.

4. Polymorphism - different objects do the right things through function polymorphism and object polymorphism. It is multiple inheritance, derivatives
                  of the same object branching off into many forms.  This most closely models the "has-a" and "is-a" relationship of the real world.

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

F. Compiling C++ Code Basics

Unlike interpreted scripting languages like Python and PowerShell and intermediate byte-code languages like JAVA, C++ is a fully compiled language. So code
is written in ASCII text in the compiler or IDE (Integrated Development Environment), and then it must be compiled before it can be run or tested. You can
use free IDEs like Visual Studio Code, Netbeans or Bloodshed to compile your C++ projects. You can also use commercial IDEs that must be purchased like
Microsoft's Visual Studio. Below are some compiler terms you will become familiar with.

   compiler - produces an object file.
   linker - turns object file into executable program.
   LIBRARY = a collection of linkable files that were created, inherent in an OS or purchased.
   FUNCTION = a block of code that performs a service, one or more actions (adding 2 numbers or printing to the screen).
   CLASS = a collection of data and related functions.
   DEBUG = edit source code, recompile, re-link and rerun

Most compilers, such as Microsoft's Visual C++ compiler, combine the functions and processes of building, compiling and linking along with a set of standard
library classes and functions into a single piece of software. Design a program thoroughly before writing it. Begin by asking "What problem do I need to
solve?". Can this be accomplished without writing custom software? There are many relevant libraries and source code available for sale, many more are
available for free. These may save you countless heartache in your projects. Again, don't reinvent the wheel. A prevailing philosophy in the Linux open
source movement is to stand on the shoulders of those who have gone before you, and allow those who come after you to stand on your shoulders. There are
large amounts of source code on-line and libraries available that will perform specific aspects of a program that you can simply add to your projects.
This can save lots of money and months of costly development time.

After source code is compiled an object file is produced (usually named *.obj). Run your linker to create an executable program. C++ programs are created
by linking together 1 or more object files with 1 or more library files. In Microsoft's Visual C++ 6.0, all of these processes are integrated for you.

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

G. Artificial Intelligence (AI) 

AI is not as flamboyant in reality as it has been portrayed in science-fiction, but AI and machine-learning have already become a HUGE part of our lives.
One can only look with wonder at the evolution of neural networks, global data structures and intelligent search engines. AI, only a LISP fantasy 40 years 
ago, is infiltrating every aspect of modern software as routines and subroutines become more and more complex in our attempt to develop software that is
easier to use, more intuitive and forgiving of our mistakes. And yet this simultaneously makes it more complex and difficult to create. AI techniques are
employed in our databases and in our spreadsheet and word processing software. They are employed in modern development environments. They are used in all
of the latest and most popular games.  AI routines are largely made possible by object oriented programming, which is well adapted to deal with the
increasing complexity of AI techniques used in large, complex pieces of software composed of hundreds of thousands of lines of code. 

Object-oriented programming theory and C++ literally laid the foundation for the AI and machine-learning we have today. 
Minds as great as the late physicist Stephen Hawking and Billionaire Elon Musk have seen AI as a threatening menace to humanity. 
Others, such as Bill Gates and Ray Kurzweil, see it as the ultimate destiny of mankind to merge with his technology and better our species.
Gates expresses his own ideas concerning this subject in the book, "The Road Ahead". In Kurzweil's book, "The Age of Spiritual Machines" - 1999, 
Kurzweil defines 3 methods increasingly utilized with AI and machine-learning, sometimes simultaneously. These are methods used to create artificially
intelligent software that can make complex, human like decisiions based on the data they are given. We will look at these three methods in several
C++ games and projects we will code that employ a computer opponents, other playters and NPCs. Kurzweil's 3 Pillars of AI and machine-learning are:

1. Recursive Algorithms - Recursion involves taking a large and complex problem and reducing it repetitively into smaller and smaller sets of tasks.
   Iterations in a recursive algorithm may take the form of simple formulas that use the massive calculating potential of today's CPUs and memory
   (brute force). A recursive algorithm includes itself as part of its algorithm.  It is a function that invokes itself, and an object that creates
   an instance of itself by its own construction. Logistically, it says "For my next step take my next best step. If I'm done I'm done."  You can
   calculate the many permutations possible in a chess game by following simple rules: "Pick my next best move. If I win, I'm done".  Functions keep
   calling themselves in an ever-expanding TREE of moves and counter-moves that,  with enough raw computing power, can fathom all possible moves on
   the chess board at each step of the game.  If a move results in a win, the routine picks that move.  If a winning move is unavailable, but a tie
   is, then select that move.  If neither a win nor a tie is available, keep playing until the player wins or a possibility opens for a win or tie.
   This technique requires an escape mechanism (perhaps a sentinel value) telling the program when to abandon recursive expansion and a clear CODING
   of the problem.

2. Neural Net Algorithms - Neural nets must be taught, they must learn. Neural nets recognize patterns and relationships. They build strong and weak
   associations regarding data and unexpected situations by assigning and remembering a set of values for each experience.  These values can be complex
   objects or numerical in nature.  A neural net is always asking itself, "On a scale of 1 to 10, based on the data and history I have acquired, how
   likely is this pattern to occur?  How dangerous is this situation?"  It then answers itself, "7 times out of 10, this is what occurs."  These
   algorithms are built on the premise that, sometimes the easiest and most efficient way to learn the right way of doing something, is to do it the
   wrong way a few times.  They make associations over time.  This involves "layers" and "training" the neural net.  As with human beings, the amount
   of time spent learning and training directly affects the performance of neural net AI.  It mimics a human being's sense of intuition and wisdom,
   acquired through interaction and experience with its environment.  Though elementary today, neural nets, when combined with recursion, show great
   promise in the future.  In our chess game, the neural net algorithm will start off much as a child would - helpless against the player.  But after
   each subsequent game it plays, it stores with flawless memory each move of each player.  It categorizes and analyzes each move that led to a win, a
   tie or a loss.  The moves that lead to wins are given stronger values, the moves that lead to losses are given weaker values.  It will then select
   the moves given stronger values for each subsequent game.  It thus learns from every opponent that plays it, eventually selecting moves that allow
   it to win. 

3. Evolutionary Algorithms - Evolutionary algorithms create massive amounts of small programs, functions or objects focused on a certain specified
   task.  They are allowed to change and adapt, in much the same way that modern computer viruses and worms (Melissa.vbs, Lion, Happy.exe, etc.)
   adapt when released.  They enhance themselves and multiply when successful through adaptation, they eliminate themselves when unsuccessful.
   These techniques utilize aspects of Chaos Theory, recursion and fractalization.   The randomness in the environment becomes fodder for change. 
   You can find a good deal of information on virus and antivirus routines online at websites such as Astalavista.com.  You may watch their evolution
   taking place before your eyes.   A word of caution - programmer beware!  Evolutionary algorithms can be unpredictable, especially in the form of
   computer viruses, and the experimenter may get more than he or she bargains for.  Principles to follow are, "Do no harm", and one must think in
   terms of containment.  What one person considers a harmless practical joke or an experiment can be considered by others as a threat to society or
   even an act of terrorism, and many careers have been ruined by one single careless act of poor judgment.  In this third example, many chess routines
   of different algorithms would be written and allowed to compete against players and one another.  They would include within their instruction set
   implicit functions providing for random adaptation to their environment.  As the routines are allowed to run, some would become successful whereas
   others would fail miserably.  The ones that played most competitively would be allowed to continue and adapt further, starting the process over. 
   The ones that were unsuccessful would be retired.

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

H. Your First C++ Program

Let's create our first C++ program. This will be a "Console Program". We will use a simple color code in this example. Red is for source code that is 
typed into the compiler and compiled. Blue is for output rendered upon executing the compiled source code. Since the traditional "first program" of any
programming language is one that outputs the phrase "Hello World", let's create a short program in C++ that will render the output of "Hello World" to
the display.

//-------------------------------------------------------------------------------------------------------------------------------------------------------------

*/

//---------------------------------------------------------------------------------------------------------------------------

#include <iostream.h>

//---------------------------------------------------------------------------------------------------------------------------

int main()
{
     cout << "Hello World!\n";
     return 0;
}

//---------------------------------------------------------------------------------------------------------------------------

